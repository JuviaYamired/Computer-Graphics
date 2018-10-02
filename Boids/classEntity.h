#include "red.h"

class classEntity {
    public:
        float radius;
        float position[2];
        float visionAngle;
        float velocity;
        float direction;
        float bodySize;
        classEntity();
        classEntity(float mPositionX, float mPositionY);
        classEntity(float  mRadius, float mPositionX, float mPositionY, float mVisionAngle, float mDirection);
        void draw();
        void displayEnix(int centerX, int centerY, int vertexSize)
        {
            glBegin(GL_LINE_LOOP);
            glColor3d(0, 255, 0);
            int originX = centerX - vertexSize / 2;
            int originY = centerY - vertexSize / 2;
            glVertex2d(originX, originY);
            glVertex2d(originX, originY + vertexSize);
            glVertex2d(originX + vertexSize, originY + vertexSize);
            glVertex2d(originX + vertexSize, originY);
            glEnd();
        }
};