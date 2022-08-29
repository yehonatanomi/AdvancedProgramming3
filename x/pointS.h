/**
 * The point class, contains 4 values.
 */

#ifndef ADVANCEDPROGRAMMING1_POINTS_H
#define ADVANCEDPROGRAMMING1_POINTS_H

#include <string>
#include <cmath>
using namespace std;
class pointS {
private:
    double x,y, z ,w;

public:
    pointS(double x, double y, double z,double w);

    pointS();
    //distance functions
    double chebyshevD(pointS p);
    double manhattanD(pointS p);
    double euclideanD(pointS p);
    //getters
    double getX();
    double getY();
    double getZ();
    double getW();

};


#endif //ADVANCEDPROGRAMMING1_POINTS_H
