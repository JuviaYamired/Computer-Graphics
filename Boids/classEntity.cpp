#include "classEntity.h"

classEntity::classEntity(){
    position.x = 0;
    position.y = 0;
    position.z = 0;
}

classEntity::classEntity(vector3d mPosition){
    position.x = mPosition.x;
    position.x = mPosition.y;
    position.x = mPosition.z;
}

classEntity::classEntity(float mRadius, float mVisionAngle, float mDirection, vector3d mPosition){
    radius = mRadius;
    visionAngle = mVisionAngle;
    position.x = mPosition.x;
    position.x = mPosition.y;
    position.x = mPosition.z;
}

void classEntity::draw(){
    displayEnix(position.x, position.y, 3);
}