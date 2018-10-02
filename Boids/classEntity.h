#include "red.h"

class classEntity {
    public:
        float radius;
        float position[2];
        float visionAngle;
        float direction;
        classEntity();
        classEntity(float mPositionX, float mPositionY);
        classEntity(float  mRadius, float mPositionX, float mPositionY, float mVisionAngle, float mDirection);
};