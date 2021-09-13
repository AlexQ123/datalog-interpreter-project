#include "UndefinedAutomaton.h"

void UndefinedAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
        S1(input);
    }
    else if (input[index] == '\'') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        inputRead = 1;
    }
}

void UndefinedAutomaton::S1(const std::string& input) {
    if (input[index] == '|') {
        inputRead++;
        index++;
        S2(input);
    }
}

void UndefinedAutomaton::S2(const std::string& input) {
    if (index != input.size()) {
        if (input[index] == '|') {
            Serr();
        }
        if (input[index] == '\n') {
            newLines++;
        }
        inputRead++;
        index++;
        S2(input);
    }
}
