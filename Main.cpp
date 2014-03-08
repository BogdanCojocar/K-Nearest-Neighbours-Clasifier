/* 
 * File:   main.cpp
 * Author: Bogdan
 *
 * Created on March 4, 2014, 9:22 PM
 */

#include <cstdlib>

#include "KNearestKneighbours.h"
#include <iostream>

using namespace std;


enum Type {
    GOOD,
    EVIL
};

int main(int argc, char** argv) {
    
    KNearestNeighbours<Type,3> clasifier;
    
    std::array<double, 3> a = {1, 2, 3};
    std::array<double, 3> b = {2, 3, 4};

    //cout << clasifier.calculateDistance(a, b);
    
    return 0;
}

