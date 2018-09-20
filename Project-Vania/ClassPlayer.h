#include "Red.h"
#include <stdio.h>
#include <iostream>
#include <thread>

class ClassPlayer{
    private:

    public:
        ClassPlayer();
        bool direction = LEFT; 
        bool lastDirection = LEFT;
        /**
         *  0 : waiting;
         *  1 : walking;
         *  2 : jumping;
         *  3 : sliding;
         *  4 : dodging;
         *  5 : attacking;
         **/
        volatile bool actions[6];
        
        float velocity[2];
        float position[2];

        float acceleration = 0.1;

        void executeAction();
        void walk();
        void attack();
        void jump();
        
        void draw();
        void friction();
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