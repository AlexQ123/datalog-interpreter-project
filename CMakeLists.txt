cmake_minimum_required(VERSION 3.16.3)
project(datalog-interpreter-code)

set(CMAKE_CXX_STANDARD 14)

include_directories(datalog-interpreter-code)

add_executable(project_1
        datalog-interpreter-code/Automaton.h
        datalog-interpreter-code/Lexer.cpp
        datalog-interpreter-code/Lexer.h
        datalog-interpreter-code/main.cpp
        datalog-interpreter-code/Token.cpp
        datalog-interpreter-code/Token.h
        datalog-interpreter-code/MatcherAutomaton.h
        datalog-interpreter-code/MatcherAutomaton.cpp
        datalog-interpreter-code/IDAutomaton.cpp
        datalog-interpreter-code/IDAutomaton.h
        datalog-interpreter-code/StringAutomaton.cpp
        datalog-interpreter-code/StringAutomaton.h
        datalog-interpreter-code/BlockComment.cpp
        datalog-interpreter-code/BlockComment.h
        datalog-interpreter-code/LineComment.cpp
        datalog-interpreter-code/LineComment.h
        datalog-interpreter-code/Parser.cpp
        datalog-interpreter-code/Parser.h
        datalog-interpreter-code/Parameter.cpp
        datalog-interpreter-code/Parameter.h
        datalog-interpreter-code/Predicate.cpp
        datalog-interpreter-code/Predicate.h
        datalog-interpreter-code/Rules.cpp
        datalog-interpreter-code/Rules.h
        datalog-interpreter-code/DatalogProgram.cpp
        datalog-interpreter-code/DatalogProgram.h
        datalog-interpreter-code/Tuple.cpp
        datalog-interpreter-code/Tuple.h
        datalog-interpreter-code/Header.cpp
        datalog-interpreter-code/Header.h
        datalog-interpreter-code/Relation.cpp
        datalog-interpreter-code/Relation.h
        datalog-interpreter-code/Database.cpp
        datalog-interpreter-code/Database.h
        datalog-interpreter-code/Interpreter.cpp
        datalog-interpreter-code/Interpreter.h
        datalog-interpreter-code/Graph.cpp
        datalog-interpreter-code/Graph.h)
