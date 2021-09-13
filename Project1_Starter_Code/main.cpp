#include "Lexer.h"
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv) {

    Lexer* lexer = new Lexer();

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

//    //TESTING reading in the input file
//    std::cout << input;
//
//    //TESTING the toString() function
//    Token testToken(TokenType::COLON_DASH, ":-", 6);
//    std::cout << testToken.toString();

    //TESTING run and automata
    lexer->Run(input);
    std::vector<Token*> tokens = lexer->getTokens();

    for (size_t i = 0; i < tokens.size(); i++) {
        std::cout << tokens.at(i)->toString() << std::endl;
    }

    std::cout << "Total Tokens = " << tokens.size() << std::endl;

    delete lexer;

    fileContents.close();

    return 0;
}