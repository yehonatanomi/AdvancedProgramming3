/**
 * The distance class, used to classify flowers.
 */
#include "distanceN.h"

distanceN::distanceN(string s, double d) {
    this->type =s;
    this->d =d;
}

string distanceN::getType() {
    return this->type;
}

double distanceN::getD() {
    return this->d;
}

void distanceN::setD(double x) {
    this->d = x;
}

distanceN::distanceN() {

}

