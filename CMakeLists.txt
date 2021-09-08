cmake_minimum_required(VERSION 3.17)
project(project_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(Project1_Starter_Code)

add_executable(project_1
        Project1_Starter_Code/Automaton.h
        Project1_Starter_Code/ColonAutomaton.cpp
        Project1_Starter_Code/ColonAutomaton.h
        Project1_Starter_Code/ColonDashAutomaton.cpp
        Project1_Starter_Code/ColonDashAutomaton.h
        Project1_Starter_Code/Lexer.cpp
        Project1_Starter_Code/Lexer.h
        Project1_Starter_Code/main.cpp
        Project1_Starter_Code/Token.cpp
        Project1_Starter_Code/Token.h)
