#include "Lexer.h"
#include "MatcherAutomaton.h"
#include "IDAutomaton.h"
#include "StringAutomaton.h"
#include "LineComment.h"
#include "BlockComment.h"
#include "UndefinedAutomaton.h"
#include <cctype>
#include <iostream>

Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    // TODO: need to clean up the memory in `automata` and `tokens`
}

void Lexer::CreateAutomata() {
    automata.push_back(new MatcherAutomaton(",", TokenType::COMMA));
    automata.push_back(new MatcherAutomaton(".", TokenType::PERIOD));
    automata.push_back(new MatcherAutomaton("?", TokenType::Q_MARK));
    automata.push_back(new MatcherAutomaton("(", TokenType::LEFT_PAREN));
    automata.push_back(new MatcherAutomaton(")", TokenType::RIGHT_PAREN));
    automata.push_back(new MatcherAutomaton(":", TokenType::COLON));
    automata.push_back(new MatcherAutomaton(":-", TokenType::COLON_DASH));
    automata.push_back(new MatcherAutomaton("*", TokenType::MULTIPLY));
    automata.push_back(new MatcherAutomaton("+", TokenType::ADD));
    automata.push_back(new MatcherAutomaton("Schemes", TokenType::SCHEMES));
    automata.push_back(new MatcherAutomaton("Facts", TokenType::FACTS));
    automata.push_back(new MatcherAutomaton("Rules", TokenType::RULES));
    automata.push_back(new MatcherAutomaton("Queries", TokenType::QUERIES));
    automata.push_back(new IDAutomaton());
    automata.push_back(new StringAutomaton());
    automata.push_back(new BlockCommentAutomaton());
    automata.push_back(new UndefinedAutomaton());
    automata.push_back(new LineCommentAutomaton());

}

void Lexer::Run(std::string& input) {

    int lineNumber = 1;
    // While there are more characters to tokenize
    while (!input.empty()) {
        int maxRead = 0;
        Automaton* maxAutomaton = automata.at(0);

        // Handling whitespace between tokens
        if (input[0] == '\r') {
            input.erase(0, 1);
            continue;
        }

        while (isspace(input[0])) {
            if (input[0] == '\n') {
                lineNumber++;
            }
            input.erase(0, 1);
        }
        if (input.empty()) {
            break;
        }

        // Here is the "Parallel" part of the algorithm
        //   Each automaton runs with the same input
        for (size_t i = 0; i < automata.size(); i++) {
            int inputRead = automata.at(i)->Start(input);
            if (inputRead > maxRead) {
                maxRead = inputRead;
                maxAutomaton = automata.at(i);
            }
        }

        // Here is the "Max" part of the algorithm
        if (maxRead > 0) {
            Token* newToken = maxAutomaton->CreateToken(input.substr(0, maxRead), lineNumber);
            lineNumber += maxAutomaton->NewLinesRead();
            tokens.push_back(newToken);
        }
//        else {
//            maxRead = 1;
//            std::string undefinedDescription = "";
//            undefinedDescription.push_back(input[0]);
//            Token* newToken = new Token(TokenType::UNDEFINED, undefinedDescription, lineNumber);
//            tokens.push_back(newToken);
//        }

        // Update `input` by removing characters read to create Token
        input.erase(0, maxRead);
    }

    // Add an end of file token
    Token* eofToken = new Token(TokenType::END_FILE, "", lineNumber);
    tokens.push_back(eofToken);

}
