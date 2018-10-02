#include "classBoids.h"

classBoids::classBoids(){
    boidsQuantity = 10;    
}

classBoids::classBoids(int mBoidsQuantity){
    boidsQuantity = mBoidsQuantity;
}

void classBoids::initialize(){
    for(int i=0; i < boidsQuantity; ++i){
        Boids.push_back( new classEntity );
    }   
}

void classBoids::drawBoids(){
    for(int i=0; i < boidsQuantity; ++i){
        Boids[i]->draw();
    }
}

void classBoids::update(){
    float vector1[3], vector2[3], vector3[3];
    for(int i=0; i < boidsQuantity; ++i){
        //vector1 = rule1();
        //vector2 = rule2();
        //vector3 = rule3();
        Boids[i]->velocity += 0;//vector1 + vector2 + vector3;
        Boids[i].position += velocity 
    }
}