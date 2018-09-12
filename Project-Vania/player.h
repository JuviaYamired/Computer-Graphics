#include "red.h"

class player{
    private:

    public:
        player();
        const bool LEFT = true;
        const bool RIGHT = false;
        float velocity = 0;
        float position[2];
        bool walking;
        float acceleration = 0.2;
        void friction();
        void draw();
        void walk(bool direction);
        void attack();
        void jump();
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