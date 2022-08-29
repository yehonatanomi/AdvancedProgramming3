#include "flower.h"

   flower::flower(string type ,  double sepalLength ,double sepalWidth ,double petalLength ,double petalWidth){
        this-> type = type;
        this-> point = pointS(sepalLength,petalWidth, petalLength, petalWidth);
    };
    flower::flower(string type ,pointS point){
        this-> type = type;
        this->point =point;
    }
pointS flower::getPoint() {
    return this->point;
};
double flower::euclideanD(flower f) {
    return this->point.euclideanD(f.getPoint());
}

double flower::chebyshevD(flower f) {
    return this->point.chebyshevD(f.getPoint());
}

double flower::manhattanD(flower f) {
    return this->point.manhattanD(f.getPoint());
}


string flower::getType() {
    return this->type;
}

void flower::setType(string s) {
    this->type = s;
}

flower::flower() {

}

string flower::toString() {
    string s = to_string(this->getPoint().getX()) + "," + to_string(this->getPoint().getY()) + ","
    + to_string(this->getPoint().getZ()) + "," + to_string(this->getPoint().getW()) + "," + this->type;
    return s;
}





