#include "classEntity.h"

classEntity::classEntity(){
    position[0] = 0;
    position[1] = 0;
}


classEntity::classEntity(float mPositionX, float mPositionY){
    position[0] = mPositionX;
    position[1] = mPositionY;
}

classEntity::classEntity(float  mRadius, float mPositionX, float mPositionY, float mVisionAngle, float mDirection){
    radius = mRadius;
    position[0] = mPositionX;
    position[1] = mPositionY;
    visionAngle = mVisionAngle;
    direction = mDirection;
}

void classEntity::draw(){
    displayEnix(position[0], position[1], bodySize);
}