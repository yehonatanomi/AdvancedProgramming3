#include "vector"
#include "string"

#ifndef TESTING_MATRIX_H
#define TESTING_MATRIX_H


class Matrix {
private:
    std::vector<std::vector<std::string>> entries;
    std::vector<std::string> types;
    std::string separator = "    ";

public:
    Matrix(std::vector<std::vector<std::string>> entries, std::vector<std::string> types);

    std::string toString();

};


#endif //TESTING_MATRIX_H
