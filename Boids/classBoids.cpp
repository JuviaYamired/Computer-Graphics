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

}