#include "Lexer.h"
#include "Parser.h"
#include "Interpreter.h"
#include "Relation.h"
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv) {
    //Make lexer and parser
    Lexer* lexer = new Lexer();
    Parser* parser = new Parser();

    //Make sure file is given
    if (argc < 2) {
        std::cout << "No file name was given." << std::endl;
    }

    std::string inputFileName = argv[1];

    //Read in contents of file
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


    //Run the lexer and store tokens in vector tokens
    lexer->Run(input);
    std::vector<Token*> tokens = lexer->getTokens();

    //Get rid of tokens with TokenType COMMENT
    for (size_t i = 0; i < tokens.size(); i++) {
        if (tokens.at(i)->getType() == TokenType::COMMENT) {
            tokens.erase(tokens.begin() + i);
            i--;
        }
    }

    //Run the parser to see if it is a valid datalog program
    try {
        parser->Parse(tokens);
    }
    catch (Token* token) {
        std::cout << "Failure!\n  ";
        std::cout << token->toString();
        return 1;
    }

    //If the parse is successful, run the interpreter
    DatalogProgram* datalogProgram = parser->getDatalogProgram();
    Interpreter* interpreter = new Interpreter(datalogProgram);
    std::string interpreterOutput = interpreter->Interpret();
    std::cout << interpreterOutput;

//    //Printing output for project 2 if successful
//    std::cout << "Success!" << std::endl;
//    parser->printDatalogProgram();
//
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


    //Printing out the tokens for project 1
//    for (size_t i = 0; i < tokens.size(); i++) {
//        std::cout << tokens.at(i)->toString() << std::endl;
//    }
//
//    std::cout << "Total Tokens = " << tokens.size();

    delete lexer;
    delete parser;

    fileContents.close();

    return 0;
}