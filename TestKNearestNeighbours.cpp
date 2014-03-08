/* 
 * File:   TestKNearestNeighbours.cpp
 * Author: Bogdan Cojocar
 *
 */
#include <gtest/gtest.h>
#include "KNearestKneighbours.h"

TEST(NearestNeighboursTest, test1) {
    enum Bird {
      SMALL = 0,
      MIDDLE,
      BIG
    }; 
    KNearestNeighbours<Bird, 3>::FeatureSet featureSet;
    
    // weight, height, peck size
    KNearestNeighbours<Bird, 3>::Array s1 = {2, 10, 0.3};
    KNearestNeighbours<Bird, 3>::Array s2 = {2.3, 12, 0.33};
    featureSet.push_back(std::make_pair(s1, SMALL));
    featureSet.push_back(std::make_pair(s2, SMALL));
    
    KNearestNeighbours<Bird, 3>::Array m1 = {4, 15, 1};
    KNearestNeighbours<Bird, 3>::Array m2 = {4.5, 17.2, 0.97};
    featureSet.push_back(std::make_pair(m1, MIDDLE));
    featureSet.push_back(std::make_pair(m2, MIDDLE));
    
    KNearestNeighbours<Bird, 3>::Array b1 = {7, 23, 1.5};
    KNearestNeighbours<Bird, 3>::Array b2 = {8.5, 22.5, 2.1};
    featureSet.push_back(std::make_pair(b1, BIG));
    featureSet.push_back(std::make_pair(b2, BIG));
    
    KNearestNeighbours<Bird, 3> clasifier1;
    KNearestNeighbours<Bird, 3>::Array sample1 = {1.7, 11.6, 0.4};
    clasifier1.computeDistances(featureSet, sample1);
    EXPECT_EQ(clasifier1.getBestClass(), SMALL);
    
    KNearestNeighbours<Bird, 3> clasifier2;
    clasifier2.setDistance(KNearestNeighbours<Bird, 3>::CHEBYSHEV);
    KNearestNeighbours<Bird, 3>::Array sample2 = {4.1, 16.3, 1.1};
    clasifier2.computeDistances(featureSet, sample2);
    EXPECT_EQ(clasifier2.getBestClass(), MIDDLE);
    
    KNearestNeighbours<Bird, 3> clasifier3;
    clasifier3.setDistance(KNearestNeighbours<Bird, 3>::MANHATTAN);
    KNearestNeighbours<Bird, 3>::Array sample3 = {9, 20, 2.21};
    clasifier3.computeDistances(featureSet, sample3);
    EXPECT_EQ(clasifier3.getBestClass(), BIG);
} 