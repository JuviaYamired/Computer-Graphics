#include "red.h"

class classEntity {
    public:
        float radius;
        float bodySize;
        float visionAngle;

        vector3d position;        
        vector3d velocity;
        vector3d direction;
        
        classEntity();
        classEntity(vector3d mPosition);
        classEntity(float mRadius, float mVisionAngle, float mDirection, vector3d mPosition);
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