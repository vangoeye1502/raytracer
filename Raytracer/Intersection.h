//
// Created by Jannes Van Goeye on 25/10/2019.
//

#ifndef UNTITLED1_INTERSECTION_H
#define UNTITLED1_INTERSECTION_H


#include <vector>
#include "HitInfo.h"

class Intersection {
public:
#define maxNumberOfHits 8
    int numberOfHits;
    std::vector<HitInfo> hits;

    Intersection() {
        numberOfHits = 0;
    }

    void set(Intersection& intersection) {
        hits.clear();
        numberOfHits = intersection.numberOfHits;
        for(int i = 0; i < numberOfHits; i++) {
            hits.push_back(intersection.hits[i]);
        }
    }
};


#endif //UNTITLED1_INTERSECTION_H
