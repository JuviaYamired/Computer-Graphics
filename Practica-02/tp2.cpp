#define GLUT_DISABLE_ATEXIT_HACK
//#include <windows.h>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "GL/glut.h"
using namespace std;

#define RED 0
#define GREEN 0
#define BLUE 0
#define ALPHA 1

#define ECHAP 27
void init_scene();
void render_scene();
GLvoid initGL();
GLvoid window_display();
GLvoid window_reshape(GLsizei width, GLsizei height);
GLvoid window_key(unsigned char key, int x, int y);

//function called on each frame
GLvoid window_idle();

double degToRad(double deg){
	return deg * M_PI / 180.0;
}

GLfloat sunCenterX, sunCenterY = 0;
GLfloat earthCenterX, earthCenterY = 0;
GLfloat moonCenterX, moonCenterY = 0;
GLfloat vTt = 2;
GLfloat vLt = 2 * vTt;

GLfloat vS = 3;;
GLfloat vT = 3 * vS;
GLfloat vL = 1.5 * vS;

GLfloat vMt = vTt;
GLfloat vM = vS;

GLfloat angleT = 0;
GLfloat angleM = 0;  

int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);


	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("TP 2 : Transformaciones");


	initGL();
	init_scene();

	glutDisplayFunc(&window_display);

	glutReshapeFunc(&window_reshape);

	glutKeyboardFunc(&window_key);

	//function called on each frame
	glutIdleFunc(&window_idle);

	glutMainLoop();

	return 1;
}



GLvoid initGL()
{
	GLfloat position[] = { 0.0f, 5.0f, 10.0f, 0.0 };
	//glutGet()onLaunch
	//glpaint
	//->glutget(FLAPS)
	//->dt = frame1 - frame 2 / 1000
	//enable light : try without it
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glEnable(GL_LIGHTING);
	//light 0 "on": try without it
	glEnable(GL_LIGHT0);

	//shading model : try GL_FLAT
	glShadeModel(GL_SMOOTH);

	glEnable(GL_DEPTH_TEST);

	//enable material : try without it
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);

	glClearColor(RED, GREEN, BLUE, ALPHA);
}

GLvoid displayTeapot(GLfloat x, GLfloat y, GLfloat radius, GLfloat angle){
	GLfloat mCenterX = x;
	GLfloat mCenterY = y;
	GLfloat mRadius = radius;
	GLfloat mAngle = 0;
	GLfloat mTraslation = 0;
	GLfloat mTraslationFactor = 0.05;
	glMatrixMode(GL_PROJECTION);
	for (GLfloat i = 0.0; ; i += 3.0)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
		glLoadIdentity();
		glOrtho(-25.0f, 25.0f, -25.0f, 25.0f, -25.0f, 25.0f);


		if(mTraslation > 8 or mTraslation < -8){
			mTraslationFactor *= -1;
		}
		
		mTraslation += mTraslationFactor;
		mAngle = std::fmod(i,360.0);	
		x = mTraslation;

		mCenterX = mRadius * cos(degToRad(mAngle)) + x;
		mCenterY = mRadius * sin(degToRad(mAngle));

		glPushMatrix();
		glColor3d(0,0,100);
		//glRotatef(0,0,0,0);
		glTranslatef(x, 0, 0);
		glutSolidSphere(1,4,4);
		glPopMatrix();	
		glColor3d(50,10,25);
		
		glPushMatrix();
		glColor3d(50,0,0);
		GLfloat cubCenterX = x;
		GLfloat cubCenterY = mCenterY;
		glTranslatef(cubCenterX,cubCenterY,0);	
		glRotatef(mAngle, 1, 0, 0);	
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
		glColor3d(100,50,20);	
		glTranslatef(mCenterX, mCenterY, 0);
		glRotatef(mAngle, 0, 0, 1);		
		glutSolidTeapot(1);
		glPopMatrix();

		glPushMatrix();
		glColor3d(0,20,0);
		GLfloat torCenterX = (mRadius* 0.55) * cos(degToRad(mAngle)) + mCenterX;
		GLfloat torCenterY = (mRadius* 0.55) * cos(degToRad(mAngle)) + mCenterY;
		glTranslatef(torCenterX,torCenterY,0);	
		glRotatef(mAngle, 0, 1, 0);	
		glutSolidTorus(0.25,1,4,4);
		glPopMatrix();

		glutSwapBuffers();
		glFlush();
	}
}

GLvoid displaySun(){
	
	glPushMatrix();
	glColor3d(150,120,0);
	glTranslatef(0,0,0);
	glutSolidSphere(2.5,16,16);
	glPopMatrix();

	//Earth Calcultations
	glPushMatrix();
	angleT+= vTt;
	earthCenterX = 10 * cos(degToRad(angleT));
	earthCenterY = 10 * sin(degToRad(angleT));
	glColor3d(1,1,12);
	glTranslatef(earthCenterX, earthCenterY, 0);
	glRotatef(angleT,0,0,1);
	glutSolidSphere(1.5,16,16);
	glPopMatrix();

	//Moon Calcultations
	glPushMatrix();
	angleM+= vLt;
	glColor3d(1,1,2);
	moonCenterX = 4 * cos(degToRad(angleM)) + earthCenterX;
	moonCenterY = 4 * sin(degToRad(angleM)) + earthCenterY;
	glTranslatef(moonCenterX, moonCenterY , 0);
	glRotatef(angleM,0,0,1);
	glutSolidSphere(1,16,16);
	glPopMatrix();

	//Mars Calcultations
	glPushMatrix();
	glColor3d(12,1,1);
	glRotatef(angleT,0,0,1);
	glTranslatef(18, 0, 0);
	glutSolidSphere(1.2,16,16);
	glPopMatrix();
}

GLvoid window_display()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-25.0f, 25.0f, -25.0f, 25.0f, -25.0f, 25.0f);

	displayTeapot(0, 0, 8, 0);
	//displaySun();

	glutSwapBuffers();
	glFlush();
}

GLvoid window_reshape(GLsizei width, GLsizei height)
{
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-25.0f, 25.0f, -25.0f, 25.0f, -25.0f, 25.0f);

	glMatrixMode(GL_MODELVIEW);
}



void init_scene()
{

}

GLvoid window_key(unsigned char key, int x, int y)
{
	switch (key) {
	case ECHAP:
		exit(1);
		break;

	default:
		printf("La touche %d non active.\n", key);
		break;
	}
}


//function called on each frame
GLvoid window_idle()
{
	glutPostRedisplay();
}
