#include "BlockComment.h"

void BlockCommentAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
        S1(input);
    }
}

void BlockCommentAutomaton::S1(const std::string& input) {
    if (input[index] == '|') {
        inputRead++;
        index++;
        S2(input);
    }
}

void BlockCommentAutomaton::S2(const std::string& input) {
    if (input[index] == '|') {
        inputRead++;
        index++;
        S3(input);
    }
    else if (index == input.size()) {
        Serr();
    }
    else {
        inputRead++;
        index++;
        S2(input);
    }
}

void BlockCommentAutomaton::S3(const std::string& input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
        S4(input);
    }
    else if (index == input.size()) {
        Serr();
    }
    else {
        inputRead++;
        index++;
        S2(input);
    }
}

void BlockCommentAutomaton::S4(const std::string& input) {

}