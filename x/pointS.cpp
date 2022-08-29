

#include "pointS.h"

pointS::pointS(double x, double y, double z,  double  w) {
    this->x =x;
    this->y =y;
    this->z =z;
    this->w =w;
}

pointS::pointS() {
    this->x =0;
    this->y =0;
    this->z =0;
    this->w =0;
}

double pointS::getX() {
    return this->x;
}

double pointS::getY() {
    return this->y;
}

double pointS::getZ() {
    return this->z;
}

double pointS::getW() {
    return this->w;
}

double pointS::manhattanD(pointS p) {
    return abs(this->x - p.getX()) + abs(this->y - p.getY()) + abs(this->z - p.getZ()) + abs(this->w - p.getW());
}

double pointS::chebyshevD(pointS p) {
    return max(max(abs(this->x - p.getX()), abs(this->y - p.getY())),max(abs(this->z - p.getZ()), abs(this->w - p.getW())));
}

double pointS:: euclideanD(pointS p) {
    return sqrt(pow(this->x - p.getX(),2) + pow(this->y - p.getY() ,2)+pow(this->z - p.getZ() ,2) +
                pow(this->w -p.getW() ,2) );
};