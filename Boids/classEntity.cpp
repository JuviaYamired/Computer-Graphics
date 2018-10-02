#include "classEntity.h"

classEntity::classEntity(){
    
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