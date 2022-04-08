# datalog-interpreter-project

I built a Datalog interpreter that implements advanced discrete mathematics concepts, relational databases, and graph theory to evaluate any file containing datalog code.

This project was created in 5 parts:
1. A lexer that reads a sequence of characters from a text file, identifies the Datalog language tokens found in the file, and stores the tokens.
2. A recursive-descent parser that parses the tokens to ensure they follow the rules of the Datalog grammar.
3. An interpreter that uses relational database operations (select, project, rename) to evaluate the queries of the Datalog program (this step only uses the 'facts' to evaluate the queries).
4. Adding the natural join and union operation functionalities to the relational database, and using these new operations to evaluate the rules in a Datalog Program.
5. Optimizing rule evaluation by building a dependency graph for the rules of the Datalog program. DFS, DFS forests, and SCCs (strongly connected components) are used to improve evaluation of the rules.
