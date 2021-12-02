#ifndef MATCHERAUTOMATON_H
#define MATCHERAUTOMATON_H

#include "Automaton.h"

class MatcherAutomaton : public Automaton
{
private:
    std::string toMatch;

public:
    MatcherAutomaton(std::string toMatch, TokenType tokenType);

    void S0(const std::string& input);

};

#endif
