#include "Header.h"

Header::Header() {

}

Header::~Header() {

}

void Header::setAttributes(std::vector<std::string> attributes) {
    this->attributes = attributes;
}

std::vector<std::string> Header::getAttributes() {
    return attributes;
}
