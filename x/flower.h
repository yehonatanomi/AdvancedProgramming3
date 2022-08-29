/**
 * The flower class, contains the type and data about the flower.
 */

#ifndef ADVANCEDPROGRAMMING1_FLOWER_H
#define ADVANCEDPROGRAMMING1_FLOWER_H


#include "pointS.h"
using namespace std;
class flower {
private:
    string  type ;
   pointS   point;
public:
    flower(string type ,  double sepalLength ,double sepalWidth ,double petalLength ,double petalWidth);
    flower(string type , pointS pointS);
    //getters
    pointS getPoint();
    string getType();
    //calculating the distance with a different flower
    double euclideanD(flower f);
    double chebyshevD(flower f);
    double manhattanD(flower f);
    //setter
    void setType(string s);
    string toString();
    flower();
};

#endif //ADVANCEDPROGRAMMING1_FLOWER_H
