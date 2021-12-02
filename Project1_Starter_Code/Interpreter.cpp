#include "Interpreter.h"
#include <iostream>

Interpreter::Interpreter(DatalogProgram *datalogProgram) {
    this->datalogProgram = datalogProgram;
}

Interpreter::~Interpreter() {

}

Relation Interpreter::evaluatePredicate(Predicate p) {
    //create the relation that we eventually want to return, completely empty
    Header dummyHeader;
    std::vector<std::string> emptyAttributes;
    dummyHeader.setAttributes(emptyAttributes);
    Relation myRelation("", dummyHeader);
    //get the relation with the same name as the current query
    std::map<std::string, Relation*> tablesToCheck = database.getTables();
    myRelation = *(tablesToCheck.at(p.getName()));

    //begin relational algebra operations to evaluate the predicate
    std::vector<Parameter*> currentParameters = p.getParameters();
    std::set<std::string> alreadySeen;
    std::vector<int> variableColumns;
    std::vector<int> selectVariableColumns;
    std::vector<std::string> renameAttributes;
    for (size_t i = 0; i < currentParameters.size(); i++) {
        std::string currentParameter = currentParameters.at(i)->toString();
        //select for each constant
        if (currentParameter[0] == '\'') {
            myRelation = myRelation.select(i, currentParameter);
        }
        //for each variable, store its index. if duplicate, do select type 2 and remove its index so it isn't printed
        else {
            variableColumns.push_back(i);
            renameAttributes.push_back(currentParameter);
            if (alreadySeen.find(currentParameter) != alreadySeen.end()) {
                selectVariableColumns.push_back(i);
                myRelation = myRelation.select(selectVariableColumns);
                variableColumns.pop_back();
                renameAttributes.pop_back();
            }
            else {
                alreadySeen.insert(currentParameter);
                selectVariableColumns.push_back(i);
            }
        }
    }

    //project
    myRelation = myRelation.project(variableColumns);

    //rename
    myRelation = myRelation.rename(renameAttributes);

    return myRelation;
}

std::string Interpreter::Interpret() {
    //CREATE A NEW RELATION FROM EACH SCHEME
    std::vector<Predicate*> schemes = datalogProgram->getSchemes();
    for (size_t i = 0; i < schemes.size(); i++) {
        std::string newName = schemes.at(i)->getName();
        Header newHeader;
        std::vector<std::string> newAttributes;
        std::vector<Parameter*> currentParameters = schemes.at(i)->getParameters();
        for (size_t i = 0; i < currentParameters.size(); i++) {
            std::string currentAttribute = currentParameters.at(i)->toString();
            newAttributes.push_back(currentAttribute);
        }
        newHeader.setAttributes(newAttributes);
        Relation* newRelation = new Relation(newName, newHeader);
        database.addTable(newName, newRelation);
    }

    //MAKE A TUPLE FOR EACH FACT AND ADD IT TO THE CORRESPONDING RELATION
    std::vector<Predicate*> facts = datalogProgram->getFacts();
    for (size_t i = 0; i < facts.size(); i++) {
        std::vector<std::string> newValues;
        std::vector<Parameter*> currentParameters = facts.at(i)->getParameters();
        for (size_t i = 0; i < currentParameters.size(); i++) {
            std::string currentValue = currentParameters.at(i)->toString();
            newValues.push_back(currentValue);
        }
        Tuple newTuple(newValues);
        std::map<std::string, Relation*> tablesToCheck = database.getTables();
        std::map<std::string, Relation*>::iterator it;
        for (it = tablesToCheck.begin(); it != tablesToCheck.end(); it++) {
            if (it->first == facts.at(i)->getName()) {
                it->second->addTuple(newTuple);
            }
        }
    }


    //EVALUATE THE RULES (AND COUT PROPER OUTPUT) -- RUN THE FIXED POINT ALGORITHM ON EACH SCC
    std::vector<Rules*> rules = datalogProgram->getRules();

    //getting SCCs
    Graph graph(rules);
    graph.createDependencyGraph();
    graph.createReverseGraph();
    Graph reverseGraph(graph.getReverseAdjacencyList());
    std::string graphToString = graph.graphToString();
    std::string reverseGraphToString = reverseGraph.graphToString();
    reverseGraph.DFSForest();
    std::vector<int> reversePostorder = reverseGraph.getReversePostorder();
    graph.DFSForestPostorder(reversePostorder);
    std::vector<std::vector<int>> forest = graph.getForest();
    std::vector<std::set<int>> forestSet;
    for (std::vector<int> tree: forest) {
        std::set<int> SCC;
        for (size_t j = 0; j < tree.size(); j++) {
            SCC.insert(tree.at(j));
        }
        forestSet.push_back(SCC);
    }

    //some couting for output
    std::cout << graph.graphToString() << std::endl;
    std::cout << "Rule Evaluation\n";

    //run the fixed-point algorithm for each SCC
    for (size_t i = 0; i < forest.size(); i++) {
        std::cout << "SCC: ";
        std::string ruleList = "";
        std::vector<int> tree = forest.at(i);
        std::set<int> SCC = forestSet.at(i);

        //some code for output format
        size_t m = 0;
        for (int node : SCC) {
            ruleList.append("R");
            ruleList.append(std::to_string(node));
            if (m == tree.size() - 1) {
                ruleList.append("\n");
            }
            else {
                ruleList.append(",");
            }
            m++;
        }
        std::cout << ruleList;

        //now onto the actual algorithm
        //if an SCC has only 1 rule and that rule does not depend on itself, do only 1 pass
        bool selfDependent = false;
        std::vector<Predicate*> predicatesToCheck = rules.at(forest.at(i).at(0))->getPredicates();
        for (size_t k = 0; k < predicatesToCheck.size(); k++) {
            if ( rules.at(forest.at(i).at(0))->getHeadPredicate()->getName() ==  rules.at(forest.at(i).at(0))->getPredicates().at(k)->getName() ) {
                selfDependent = true;
            }
        }

        if ( (tree.size() == 1) && !(selfDependent) ) {
            for (int node : SCC) {
                //add rule to output
                std::cout << rules.at(node)->toString() << "\n";

                //for each rule, evaluate the predicates on the right hand side
                std::vector<Relation> relationsToJoin;
                std::vector<Predicate*> currentPredicates = rules.at(node)->getPredicates();
                for (size_t i = 0; i < currentPredicates.size(); i++) {
                    Predicate predicateToPass = *currentPredicates.at(i);
                    Relation resultingRelation = evaluatePredicate(predicateToPass);
                    relationsToJoin.push_back(resultingRelation);
                }

                //join the resulting relations
                Relation joinedRelation = relationsToJoin.at(0);
                for (size_t i = 1; i < relationsToJoin.size(); i++) {
                    joinedRelation = joinedRelation.join(relationsToJoin.at(i));
                }

                //project the columns that appear in the head predicate
                std::vector<int> indicesToProject;
                Predicate ruleHeadPredicate = *(rules.at(node)->getHeadPredicate());
                for (size_t i = 0; i < ruleHeadPredicate.getParameters().size(); i++) {
                    std::string lookFor = ruleHeadPredicate.getParameters().at(i)->toString();
                    for (size_t i = 0; i < joinedRelation.getHeader().getAttributes().size(); i++) {
                        if (joinedRelation.getHeader().getAttributes().at(i) == lookFor) {
                            indicesToProject.push_back(i);
                        }
                    }
                }
                joinedRelation = joinedRelation.project(indicesToProject);

                //rename to header of relation in DB
                std::map<std::string, Relation*> tablesToCheck = database.getTables();
                Relation *relationInDB = (tablesToCheck.at(ruleHeadPredicate.getName()));
                std::vector<std::string> correctAttributes = relationInDB->getHeader().getAttributes();
                joinedRelation = joinedRelation.rename(correctAttributes);

                //union with relation in DB
                bool added = relationInDB->unionRelations(joinedRelation);
                if (added) {

                }
            }
            std::cout << "1" << " passes: " << ruleList;
        }

        //otherwise, run as normal
        else {
            bool continueToEvaluateRules = true;
            int passThroughCounter = 0;
            while (continueToEvaluateRules) {
                continueToEvaluateRules = false;

                for (int node : SCC) {
                    //add rule to output
                    std::cout << rules.at(node)->toString() << "\n";

                    //for each rule, evaluate the predicates on the right hand side
                    std::vector<Relation> relationsToJoin;
                    std::vector<Predicate*> currentPredicates = rules.at(node)->getPredicates();
                    for (size_t i = 0; i < currentPredicates.size(); i++) {
                        Predicate predicateToPass = *currentPredicates.at(i);
                        Relation resultingRelation = evaluatePredicate(predicateToPass);
                        relationsToJoin.push_back(resultingRelation);
                    }

                    //join the resulting relations
                    Relation joinedRelation = relationsToJoin.at(0);
                    for (size_t i = 1; i < relationsToJoin.size(); i++) {
                        joinedRelation = joinedRelation.join(relationsToJoin.at(i));
                    }

                    //project the columns that appear in the head predicate
                    std::vector<int> indicesToProject;
                    Predicate ruleHeadPredicate = *(rules.at(node)->getHeadPredicate());
                    for (size_t i = 0; i < ruleHeadPredicate.getParameters().size(); i++) {
                        std::string lookFor = ruleHeadPredicate.getParameters().at(i)->toString();
                        for (size_t i = 0; i < joinedRelation.getHeader().getAttributes().size(); i++) {
                            if (joinedRelation.getHeader().getAttributes().at(i) == lookFor) {
                                indicesToProject.push_back(i);
                            }
                        }
                    }
                    joinedRelation = joinedRelation.project(indicesToProject);

                    //rename to header of relation in DB
                    std::map<std::string, Relation*> tablesToCheck = database.getTables();
                    Relation *relationInDB = (tablesToCheck.at(ruleHeadPredicate.getName()));
                    std::vector<std::string> correctAttributes = relationInDB->getHeader().getAttributes();
                    joinedRelation = joinedRelation.rename(correctAttributes);

                    //union with relation in DB
                    bool added = relationInDB->unionRelations(joinedRelation);
                    /* if there are multiple rules, we must keep running the loop as long as one of them
                    returns true, so as we're iterating through each rule for each passThrough, us OR to
                    preserve any TRUE values */
                    continueToEvaluateRules = continueToEvaluateRules || added;
                    // database.addTable(ruleHeadPredicate.getName(), relationInDB);
                }
                //increment passThroughCounter
                passThroughCounter += 1;
            }
            std::cout << std::to_string(passThroughCounter) << " passes: " << ruleList;
        }
    }

    std::cout << std::endl;

    //ALL OF THIS IS FROM PROJECT 4
//    bool continueToEvaluateRules = true;
//    int passThroughCounter = 0;
//    while (continueToEvaluateRules) {
//        continueToEvaluateRules = false;
//
//        for (size_t i = 0; i < rules.size(); i++) {
//            //add rule to output
//            std::cout << rules.at(i)->toString() << "\n";
//
//            //for each rule, evaluate the predicates on the right hand side
//            std::vector<Relation> relationsToJoin;
//            std::vector<Predicate*> currentPredicates = rules.at(i)->getPredicates();
//            for (size_t i = 0; i < currentPredicates.size(); i++) {
//                Predicate predicateToPass = *currentPredicates.at(i);
//                Relation resultingRelation = evaluatePredicate(predicateToPass);
//                relationsToJoin.push_back(resultingRelation);
//            }
//
//            //join the resulting relations
//            Relation joinedRelation = relationsToJoin.at(0);
//            for (size_t i = 1; i < relationsToJoin.size(); i++) {
//                joinedRelation = joinedRelation.join(relationsToJoin.at(i));
//            }
//
//            //project the columns that appear in the head predicate
//            std::vector<int> indicesToProject;
//            Predicate ruleHeadPredicate = *(rules.at(i)->getHeadPredicate());
//            for (size_t i = 0; i < ruleHeadPredicate.getParameters().size(); i++) {
//                std::string lookFor = ruleHeadPredicate.getParameters().at(i)->toString();
//                for (size_t i = 0; i < joinedRelation.getHeader().getAttributes().size(); i++) {
//                    if (joinedRelation.getHeader().getAttributes().at(i) == lookFor) {
//                        indicesToProject.push_back(i);
//                    }
//                }
//            }
//            joinedRelation = joinedRelation.project(indicesToProject);
//
//            //rename to header of relation in DB
//            std::map<std::string, Relation*> tablesToCheck = database.getTables();
//            Relation *relationInDB = (tablesToCheck.at(ruleHeadPredicate.getName()));
//            std::vector<std::string> correctAttributes = relationInDB->getHeader().getAttributes();
//            joinedRelation = joinedRelation.rename(correctAttributes);
//
//            //union with relation in DB
//            bool added = relationInDB->unionRelations(joinedRelation);
//            /* if there are multiple rules, we must keep running the loop as long as one of them
//            returns true, so as we're iterating through each rule for each passThrough, us OR to
//            preserve any TRUE values */
//            continueToEvaluateRules = continueToEvaluateRules || added;
//            // database.addTable(ruleHeadPredicate.getName(), relationInDB);
//        }
//        //increment passThroughCounter
//        passThroughCounter += 1;
//    }
    //ALL OF THIS IS FROM PROJECT 4


    //EVALUATE EACH QUERY AND STORE IN STRING FOR OUTPUT -- SEE MAIN.CPP
    std::string queryOutput = "Query Evaluation\n";
    std::vector<Predicate*> queries = datalogProgram->getQueries();
    for (size_t i = 0; i < queries.size(); i++) {
        queryOutput.append(queries.at(i)->toString());
        queryOutput.append("? ");
        Predicate predicateToEvaluate = *queries.at(i);
        Relation resultingRelation = evaluatePredicate(predicateToEvaluate);
        if (resultingRelation.getTuples().size() == 0) {
            queryOutput.append("No\n");
        }
        else {
            queryOutput.append("Yes(");
            queryOutput.append(std::to_string(resultingRelation.getTuples().size()));
            queryOutput.append(")\n");
        }
        queryOutput.append(resultingRelation.toString());
    }

    return queryOutput;
}
