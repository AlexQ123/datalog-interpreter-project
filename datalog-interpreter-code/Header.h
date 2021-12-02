#ifndef HEADER_H
#define HEADER_H

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

#endif
