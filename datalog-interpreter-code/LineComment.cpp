#include "LineComment.h"

void LineCommentAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
        S1(input);
    }
}

void LineCommentAutomaton::S1(const std::string& input) {
    if (index == input.size()) {
        S2(input);
    }
    else if (input[1] == '|') {
        Serr();
    }
    else if (input[index] == '\n' || input[index] == '\r') {
        S2(input);
    }
    else if (input[index] != '\n') {
        inputRead++;
        index++;
        S1(input);
    }
}

void LineCommentAutomaton::S2(const std::string& input) {

}
