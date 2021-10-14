#ifndef PROJECT_1_TUPLE_H
#define PROJECT_1_TUPLE_H

#include <vector>
#include <string>

class Tuple
{
private:
    std::vector<std::string> values;

public:
    Tuple(std::vector<std::string> values);
    ~Tuple();
    std::vector<std::string> getValues();

    bool operator< (const Tuple &rhs) const {
        return values < rhs.values;
    }
};

#endif //PROJECT_1_TUPLE_H
