
#ifndef ADVANCEDPROGRAMMING1_KNN_H
#define ADVANCEDPROGRAMMING1_KNN_H
#include <iostream>
#include <fstream>
#include <sstream>
#include<list>
#include "flower.h"
#include "distanceN.h"
using namespace std;
/**
 * getting the name of the file and adding the flowers to a list.
 * @param empty list
 * @param name of the file
 * @return list of flower
 */
void flowerL(list<flower>* l,string fname );
/**
 * Creating 3 lists, each one matched to a different type of distance.
 * @param classified list of flowers
 * @param unclassified an unclassified flower
 * @param dL pointer to 3 lists of distances
 * @return void
 */
void distanceL(list<flower> classified, flower unclassified , list<distanceN>* dl);
/**
 * finding the type of the unclassified flower
 * @param l list of distanceN (contains the type)
 * @param k the chosen value for the algorithm
 * @return the type of the unclassified flower
 */
string groupKnn(list<distanceN> l ,int k);
/**
 * Sorting the array by distance.
 * @param arr the array
 * @param n array size
 */
void bubbleSort(distanceN arr[], int n);
/**
 * making the output data in lists.
 * @param classified list of classified flowers
 * @param unclassified list of unclassified flowers
 * @param k the chosen value for the algorithm
 * @param output pointer for several lists, each one contains the types of the unclassified by different distance
 */
void knn(list<flower> classified,list<flower> unclassified, int k,list<flower>* output);
/**
 * Making the output file from the list that was created in knn
 * @param output list of flowers after they were classified
 * @param fileN the name of the output file
 */
void outFile(list<flower> output ,string fileN);
/**
 * getting an array from a list
 * @param d the list
 * @param arr array
 * @param size list size
 */
void fromArrToList(list<distanceN>* d, distanceN arr[], int size);


/**
 * convert from string of flower to list of flower.
 * @param string
 * @return list
 */
list<flower> fromStoL(string s);
/**
 * convert from list of flower  to string of flower.
 * @param l
 * @return
 */
string fromLtoS(list<flower> l);

void flowerLFromPath(list<flower>* l,string fname);
#endif //ADVANCEDPROGRAMMING1_KNN_H
