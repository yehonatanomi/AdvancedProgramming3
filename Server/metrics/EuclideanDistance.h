#include "Distance.h"
#include "vector"
#include <cstdio>
#include <cmath>

#ifndef CLIENT_EUCLIDEANDISTANCE_H
#define CLIENT_EUCLIDEANDISTANCE_H

template<class T>
class EuclideanDistance : public Distance<T> {
public:
    double distance(T t1, T t2) const override {
        //Get the coordiantes
        std::vector<double> t1Coordinates = t1.getVector();
        std::vector<double> t2Coordinates = t2.getVector();
        if (t2Coordinates.size() != t1Coordinates.size()) {
            perror("Vector lengths have to be equal");
        }
        if (t2Coordinates.empty()) {
            perror("Vector can't be empty");
        }
        //Calculate the distance
        double res = 0;
        for (int i = 0; i < t1Coordinates.size(); i++) {
            res += std::pow(t1Coordinates.at(i) - t2Coordinates.at(i), 2);
        }
        res = std::pow(res, 0.5);
        return res;
    }

    std::string toString() const override {
        return "EUC";
    }
};


#endif //CLIENT_EUCLIDEANDISTANCE_H
