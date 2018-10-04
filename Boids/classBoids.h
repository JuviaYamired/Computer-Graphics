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
        float Xmin,Xmax,Ymin,Ymax,Zmin,Zmax;


        classBoids();
        classBoids(int mBoidsQuantity);
        void initialize();
        void drawBoids();
        void update();
        void applyForce(vector3d  a,int j);
        void limit_velocity(int j);
        vector3d Bound_position(int i);
        vector3d rule1();
        vector3d rule2(int j);
        vector3d rule3(int j);


};
#endif