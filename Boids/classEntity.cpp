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
    glBegin(GL_LINE_LOOP);
    glColor3d(255,0,0);

    glVertex2f(position.x-2,position.y-2);
    glVertex2f(position.x-2,position.y+6);

    glVertex2f(position.x-2,position.y+6);
    glVertex2f(position.x+4,position.y+3);
    glEnd();
}