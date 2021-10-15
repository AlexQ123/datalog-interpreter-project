cmake_minimum_required(VERSION 3.16.3)
project(project_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(Project1_Starter_Code)

add_executable(project_1
        Project1_Starter_Code/Automaton.h
        Project1_Starter_Code/Lexer.cpp
        Project1_Starter_Code/Lexer.h
        Project1_Starter_Code/main.cpp
        Project1_Starter_Code/Token.cpp
        Project1_Starter_Code/Token.h Project1_Starter_Code/MatcherAutomaton.h Project1_Starter_Code/MatcherAutomaton.cpp Project1_Starter_Code/IDAutomaton.cpp Project1_Starter_Code/IDAutomaton.h Project1_Starter_Code/StringAutomaton.cpp Project1_Starter_Code/StringAutomaton.h Project1_Starter_Code/BlockComment.cpp Project1_Starter_Code/BlockComment.h Project1_Starter_Code/LineComment.cpp Project1_Starter_Code/LineComment.h Project1_Starter_Code/Parser.cpp Project1_Starter_Code/Parser.h Project1_Starter_Code/Parameter.cpp Project1_Starter_Code/Parameter.h Project1_Starter_Code/Predicate.cpp Project1_Starter_Code/Predicate.h Project1_Starter_Code/Rules.cpp Project1_Starter_Code/Rules.h Project1_Starter_Code/DatalogProgram.cpp Project1_Starter_Code/DatalogProgram.h Project1_Starter_Code/Tuple.cpp Project1_Starter_Code/Tuple.h Project1_Starter_Code/Header.cpp Project1_Starter_Code/Header.h Project1_Starter_Code/Relation.cpp Project1_Starter_Code/Relation.h Project1_Starter_Code/Database.cpp Project1_Starter_Code/Database.h Project1_Starter_Code/Interpreter.cpp Project1_Starter_Code/Interpreter.h)
