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
        Project1_Starter_Code/Token.h Project1_Starter_Code/MatcherAutomaton.h Project1_Starter_Code/MatcherAutomaton.cpp Project1_Starter_Code/IDAutomaton.cpp Project1_Starter_Code/IDAutomaton.h Project1_Starter_Code/StringAutomaton.cpp Project1_Starter_Code/StringAutomaton.h Project1_Starter_Code/BlockComment.cpp Project1_Starter_Code/BlockComment.h Project1_Starter_Code/LineComment.cpp Project1_Starter_Code/LineComment.h )
