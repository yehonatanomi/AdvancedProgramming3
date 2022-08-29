

#ifndef ADVANCEDPROGRAMMING1_DISTANCEN_H
#define ADVANCEDPROGRAMMING1_DISTANCEN_H
#include <string>
using namespace std;
class distanceN {
private:
    string type;
    double d;
public:
    distanceN(string s, double d);
    //getters
    string getType();
    double getD();
    //setter
    void  setD(double x);
    distanceN();
};


#endif //ADVANCEDPROGRAMMING1_DISTANCEN_H
