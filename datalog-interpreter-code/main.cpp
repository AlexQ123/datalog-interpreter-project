#include "Lexer.h"
#include "Parser.h"
#include "Interpreter.h"
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv) {
    //create lexer and parser
    Lexer* lexer = new Lexer();
    Parser* parser = new Parser();

    //make sure file is given
    if (argc < 2) {
        std::cout << "No file name was given." << std::endl;
    }

    std::string inputFileName = argv[1];

    //read in contents of file
    std::ifstream fileContents(inputFileName);
    if (!fileContents.is_open()) {
        std::cout << inputFileName << std::endl;
        return 1;
    }

    std::string input = "";

    while (!fileContents.eof()) {
        std::string nextLine = "";
        getline(fileContents, nextLine);
        input.append(nextLine);
        input.append("\n");
    }

    input.pop_back();


    //run the lexer and store tokens in vector tokens
    lexer->Run(input);
    std::vector<Token*> tokens = lexer->getTokens();

    //get rid of tokens with TokenType COMMENT
    for (size_t i = 0; i < tokens.size(); i++) {
        if (tokens.at(i)->getType() == TokenType::COMMENT) {
            tokens.erase(tokens.begin() + i);
            i--;
        }
    }

    //run the parser to see if it is a valid datalog program
    try {
        parser->Parse(tokens);
    }
    catch (Token* token) {
        std::cout << "Failure!\n  ";
        std::cout << token->toString();
        return 1;
    }

    //if the parse is successful, run the interpreter: note that interpreterOutput is just the query output
    //the rest of the output is handled and couted in the actual interpreter itself: see Interpreter.cpp
    DatalogProgram* datalogProgram = parser->getDatalogProgram();
    Interpreter* interpreter = new Interpreter(datalogProgram);
    std::string interpreterOutput = interpreter->Interpret();
    std::cout << interpreterOutput;

//    //Printing output for project 2 if successful
//    std::cout << "Success!" << std::endl;
//    parser->printDatalogProgram();

//PROJECT 3 TESTING BELOW

//    //testing Relation toString
//    std::string testName = "testName";
//    std::vector<std::string> testAttributes = {"X", "Y", "Z"};
//    Header testHeader;
//    testHeader.setAttributes(testAttributes);
//    Relation testRelation(testName, testHeader);
//
//    std::set<Tuple> testTuples;
//
//    std::vector<std::string> testTupleOne = {"a", "b", "b"};
//    std::vector<std::string> testTupleTwo = {"a", "a", "a"};
//    testTuples.insert(testTupleOne);
//    testTuples.insert(testTupleTwo);
//
//    testRelation.setTuples(testTuples);
//    std::cout << std::endl << "toString():\n" << testRelation.toString() << std::endl;
//
//    //testing Relation select1
//    Relation testSelectOne = testRelation.select(2, "b");
//    std::cout << "select1:\n" << testSelectOne.toString() << std::endl;
//
//    //testing Relation select2
//    std::vector<int> testIndices = {0,1,2};
//    Relation testSelectTwo = testRelation.select(testIndices);
//    std::cout << "select2:\n" << testSelectTwo.toString() << std::endl;
//
//    //testing Relation project
//    std::vector<int> testIndicesP = {1,2,0};
//    Relation testProject = testRelation.project(testIndicesP);
//    std::cout << "project:\n" << testProject.toString() << std::endl;
//
//    //testing Relation rename
//    std::vector<std::string> testNewAttributes = {"A", "B", "C"};
//    Relation testRename = testRelation.rename(testNewAttributes);
//    std::cout << "rename:\n" << testRename.toString() << std::endl;

//PROJECT 4 TESTING BELOW

//    //testing Relation join
//    std::string testName = "testName";
//    std::vector<std::string> testAttributes = {"A", "B", "C"};
//    Header testHeader;
//    testHeader.setAttributes(testAttributes);
//    Relation testRelation(testName, testHeader);
//
//    std::set<Tuple> testTuples;
//
//    std::vector<std::string> testValues1 = {"1", "2", "3"};
//    std::vector<std::string> testValues0 = {"1", "2", "2"};
//    Tuple testTuple(testValues1);
//    Tuple testTuple0(testValues0);
//
//    testTuples.insert(testTuple);
//    testTuples.insert(testTuple0);
//
//
//    testRelation.setTuples(testTuples);
//
//    std::string testName2 = "testName2";
//    std::vector<std::string> testAttributes2 = {"A", "B", "D"};
//    Header testHeader2;
//    testHeader2.setAttributes(testAttributes2);
//    Relation testRelation2(testName2, testHeader2);
//
//    std::set<Tuple> testTuples2;
//
//    std::vector<std::string> testValues2 = {"3", "4", "5"};
//    std::vector<std::string> testValues3 = {"6", "5", "4"};
//    std::vector<std::string> testValues4 = {"1", "2", "3"};
//    Tuple testTuple2(testValues2);
//    Tuple testTuple3(testValues3);
//    Tuple testTuple4(testValues4);
//    testTuples2.insert(testTuple2);
//    testTuples2.insert(testTuple3);
//    testTuples2.insert(testTuple4);
//
//    testRelation2.setTuples(testTuples2);
//
//     Relation testJoin = testRelation.join(testRelation2);
//     std::cout << "testRelation:\n" << testRelation.toString() << std::endl;
//     std::cout << "testRelation2:\n" << testRelation2.toString() << std::endl;
//     std::cout << "Join:\n" << testJoin.toString() << std::endl;
//
//     //testing Relation union
//     std::string testNameUnion = "testNameUnion";
//     std::vector<std::string> testAttributesUnion = {"A", "B", "C"};
//     Header testHeaderUnion;
//     testHeaderUnion.setAttributes(testAttributesUnion);
//     Relation testRelationUnion(testNameUnion, testHeaderUnion);
//     std::set<Tuple> testTuplesUnion;
//     std::vector<std::string> testValuesUnion = {"1", "2", "3"};
//     std::vector<std::string> testValuesUnion2 = {"4", "5", "6"};
//     std::vector<std::string> testValuesUnion3 = {"7", "8", "9"};
//     Tuple testTupleUnion(testValuesUnion);
//     Tuple testTupleUnion2(testValuesUnion2);
//     Tuple testTupleUnion3(testValuesUnion3);
//     testTuplesUnion.insert(testTupleUnion);
//     testTuplesUnion.insert(testTupleUnion2);
//     testTuplesUnion.insert(testTupleUnion3);
//     testRelationUnion.setTuples(testTuplesUnion);
//
//     bool added = testRelation.unionRelations(testRelationUnion);
//    std::cout << "To Union:\n" << testRelationUnion.toString() << std::endl;
//     std::cout << "Union:\n" << testRelation.toString() << std::endl;

    //Printing out the tokens for project 1
//    for (size_t i = 0; i < tokens.size(); i++) {
//        std::cout << tokens.at(i)->toString() << std::endl;
//    }
//
//    std::cout << "Total Tokens = " << tokens.size();

    delete lexer;
    delete parser;
    delete datalogProgram;
    delete interpreter;

    fileContents.close();

    return 0;
}