#ifndef CLASSBOIDS_H
#define CLASSBOIDS_H
#include "classEntity.h"
#include "vector3d.h"
#include "red.h"
#include <vector>
#include <math.h>

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
        vector3d rule2(int j);
        vector3d rule3(int j);


};
#endif