#include "classEntity.h"

classEntity::classEntity(){
    position[0] = 0;
    position[1] = 0;
}

classEntity(vector3d mPosition);
        classEntity( float mRadius, vector3d mDirection, vector3d mPosition );

classEntity::classEntity(vector3d mPosition){
    position[0] = mPositionX;
    position[1] = mPositionY;
}

classEntity::classEntity(float mRadius, float mVisionAngle, float mDirection, vector3d mPosition){
    radius = mRadius;
    visionAngle = mVisionAngle;
    position = mPosition;
}

void classEntity::draw(){
    displayEnix(position[0], position[1], bodySize);
}