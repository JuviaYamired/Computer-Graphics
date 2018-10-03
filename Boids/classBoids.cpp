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
    for(int i = 0; i < boidsQuantity; ++i){
        //vector2 = rule2();
        //vector3 = rule3();
        Boids[i]->velocity.add( rule1(i) );//vector1 + vector2 + vector3;
        Boids[i]->position.add( Boids[i]->position ) ; 
    }
}

vector3d classBoids::rule1(int pos){
    vector3d centerOfMass(0, 0, 0);
    for(int i = 0; i < Boids.size; ++i){
        if(i != pos)
            centerOfMass.add( Boids[i]->position );
    } 
    centerOfMass.div(Boids.size - 1);
    centerOfMass.sub(Boids[pos]->position);
    centerOfMass.div(100);
    return centerOfMass;
}