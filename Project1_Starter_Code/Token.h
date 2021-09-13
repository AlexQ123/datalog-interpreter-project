#ifndef TOKEN_H
#define TOKEN_H
#include <string>

enum class TokenType {
    COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    COLON,
    COLON_DASH,
    MULTIPLY,
    ADD,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    STRING,
    COMMENT,
    UNDEFINED,
    END_FILE
};

class Token
{
private:
    TokenType type;
    std::string description = "";
    int line = 0;
    std::string typeToString(TokenType type);

public:
    Token(TokenType type, std::string description, int line);
    std::string toString();
};

#endif // TOKEN_H

