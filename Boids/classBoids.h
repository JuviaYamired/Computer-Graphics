#ifndef CLASSBOIDS_H_
#define CLASSBOIDS_H_

#include "red.h"
#include "classEntity.h"
#include <vector>

class classBoids{
    public:
        int boidsQuantity;
        std::vector<classEntity*> Boids;
        classBoids();
        classBoids(int mBoidsQuantity);
        void initialize();
        void drawBoids();
        void update();
        vector3d rule1(int pos);
};

#endif