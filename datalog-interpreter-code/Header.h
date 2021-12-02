#ifndef PROJECT_1_HEADER_H
#define PROJECT_1_HEADER_H

#include <vector>
#include <string>

class Header
{
private:
    std::vector<std::string> attributes;

public:
    Header();
    ~Header();
    void setAttributes(std::vector<std::string> attributes);
    std::vector<std::string> getAttributes();
};

#endif //PROJECT_1_HEADER_H
