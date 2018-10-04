#include "classEntity.h"

classEntity::classEntity(){
    position.x = 0;
    position.y = 0;
    position.z = 0;
}

classEntity::classEntity(vector3d mPosition){
    position.x = mPosition.x;
    position.y = mPosition.y;
    position.z = mPosition.z;
}

classEntity::classEntity(float mRadius, float mVisionAngle, float mDirection, vector3d mPosition){
    radius = mRadius;
    visionAngle = mVisionAngle;
    position.x = mPosition.x;
    position.y = mPosition.y;
    position.z = mPosition.z;
}

void classEntity::draw(){
}