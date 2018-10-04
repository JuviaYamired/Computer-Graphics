#ifndef RED_H_
#define RED_H_

#include "vector3d.h"
#include <cmath>
#include "GL/glut.h"
#include <stdio.h>

const bool LEFT = false;
const bool RIGHT = true;
const float MAXJUMPHEIGHT = 20;
//const float MINJUMPHEIGHT = 2;
//const float MAXJUMPTIME = 0.44;
const float GRAVITY = -2;
//const float JUMPVELOCITY = sqrtf(2 * GRAVITY * MAXJUMPHEIGHT);

extern float TIME;
extern float NEWTIME;
extern float DTTIME;

static double degToRad(double deg){
	return deg * M_PI / 180.0;
}
static float randome(float a,float b)
{
	return ((b - a) * ((float)rand() / RAND_MAX)) + a;
}

//**********************extras
static float dist(vector3d a, vector3d b){
      float tmpX=b.x-a.x;
      float tmpY=b.y-a.y;
      float tmpZ=b.z-a.z;

      return sqrt(tmpX*tmpX+tmpY*tmpY+tmpZ*tmpZ);
}

#endif