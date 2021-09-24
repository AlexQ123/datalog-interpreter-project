#include "Lexer.h"
#include "Parser.h"
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv) {
    //Make lexer and parser
    Lexer* lexer = new Lexer();
    Parser* parser = new Parser();

    if (argc < 2) {
        std::cout << "No file name was given." << std::endl;
    }

    std::string inputFileName = argv[1];

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

    //Run the parser
    try {
        parser->Parse(tokens);
    }
    catch (Token* token) {
        std::cout << "Failure!\n  ";
        std::cout << token->toString();
        return 1;
    }
    // if successful
    std::cout << "Success!" << std::endl;
    parser->printDatalogProgram();

    //Printing out the tokens for project 1
//    for (size_t i = 0; i < tokens.size(); i++) {
//        std::cout << tokens.at(i)->toString() << std::endl;
//    }
//
//    std::cout << "Total Tokens = " << tokens.size();

    delete lexer;

    fileContents.close();

    return 0;
}