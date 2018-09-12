#define GLUT_DISABLE_ATEXIT_HACK	
//#include <windows.h>
#include <cmath>
#include "GL/glut.h"

#define KEY_ESC 27

double degToRad(double deg){
	return deg * M_PI / 180.0;
}

//dibuja un simple gizmo
void displayGizmo()
{
	glBegin(GL_LINE);
	glColor3d(255,0,0);
	glVertex2d(0, 0);
	glVertex2d(1, 0);
	glColor3d(0, 255, 0);
	glVertex2d(0, 0);
	glVertex2d(0, 1);
	glEnd();
}

void displayEnix(int centerX, int centerY, int vertexSize)
{
	glBegin(GL_LINE_LOOP);
	glColor3d(0, 255, 0);
	int originX = centerX - vertexSize/2;
	int originY = centerY - vertexSize/2;
	glVertex2d(originX, originY);
	glVertex2d(originX, originY + vertexSize);
	glVertex2d(originX + vertexSize, originY + vertexSize);
	glVertex2d(originX + vertexSize, originY);
	glEnd();
}

void displayCircle(int centerX, int centerY, int radius)
{
	glBegin(GL_POINTS);
	glColor3d(0, 255, 0);

	for(float i = 0; i < 360; i+= 0.01)
	{
		glVertex2d( radius * cos(degToRad(i)) + centerX, radius * sin(degToRad(i)) + centerY );  
	}

	glEnd();
}

void displayMultiCircle(float centerX, float centerY, float radius)
{
	glBegin(GL_POINTS);
	glColor3d(0, 255, 0);

	for (int i = 0; i < 5; i++)
	{
		for (float j = 0; j < 360; j+= 0.01)
		{
			glVertex2d((radius + i * 5) * cos(degToRad(j)) + centerX, (radius + i * 5) * sin(degToRad(j)) + centerY);
		}
		centerX += radius/2;
	}

	glEnd();
}

void displayMultiCircle(int centerX, int centerY, int radius, int quantity, float ratio)
{
	glBegin(GL_POINTS);
	glColor3d(0, 255, 0);

	ratio = 1 - ratio;
	centerX = -35;
	centerY = 0;

	for (int i = 0; i < quantity; i++)
	{
		for (float j = 0; j < 360; j+=0.01)
		{
			glVertex2d(radius * cos(degToRad(j)) + centerX, radius * sin(degToRad(j)) + centerY);
		}
		centerX += radius;
		radius *= ratio;
		centerX += radius;		
	}

	glEnd();
}

void displayMultiCircle(float centerX, float centerY, float radius, int quantity, float ratio, float angle)
{
	glBegin(GL_POINTS);
	glColor3d(0, 255, 0);

	angle = degToRad(angle);
	ratio = 1 - ratio;
	centerX = -35;
	centerY = 0;

	for (int i = 0; i < quantity; i++)
	{
		for (float j = 0; j < 360; j+= 0.01)
		{
			glVertex2d(radius * cos(degToRad(j)) + centerX, radius * sin(degToRad(j)) + centerY);
		}
		centerX += radius * cos(angle);	
		centerY	+= radius * sin(angle);
		radius = radius * ratio;
		centerX += radius * cos(angle);	
		centerY	+= radius * sin(angle);
	}

	glEnd();
}

//
//funcion llamada a cada imagen
void glPaint(void) {

	//El fondo de la escena al color initial
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //(R, G, B, transparencia) en este caso un fondo negro
	glLoadIdentity();
	
	
	//dibuja el gizmo
	//displayGizmo();
	displayEnix(0, 0, 50);
	displayCircle(0, 0, 10);
	displayMultiCircle(0, 0, 10);
	displayMultiCircle(0, 0, 15, 5, 0.15);
	displayMultiCircle(0, 0, 15, 5, 0.15, 90);
	//doble buffer, mantener esta instruccion al fin de la funcion
	glutSwapBuffers();
}

//
//inicializacion de OpenGL
//
void init_GL(void) {
	//Color del fondo de la escena
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //(R, G, B, transparencia) en este caso un fondo negro

	//modo projeccion 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

//en el caso que la ventana cambie de tama�o
GLvoid window_redraw(GLsizei width, GLsizei height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	glOrtho(-50.0f,  50.0f,-50.0f, 50.0f, -1.0f, 1.0f); 
	// todas la informaciones previas se aplican al la matrice del ModelView
	glMatrixMode(GL_MODELVIEW);
}

GLvoid window_key(unsigned char key, int x, int y) {
	switch (key) {
	case KEY_ESC:
		exit(0);
		break;

	default:
		break;
	}

}
//
//el programa principal
//
int main(int argc, char** argv) {

	//Inicializacion de la GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600); //tama�o de la ventana
	glutInitWindowPosition(100, 100); //posicion de la ventana
	glutCreateWindow("TP1 OpenGL : hello_world_OpenGL"); //titulo de la ventana

	init_GL(); //funcion de inicializacion de OpenGL

	glutDisplayFunc(glPaint); 
	glutReshapeFunc(&window_redraw);
	// Callback del teclado
	glutKeyboardFunc(&window_key);

	glutMainLoop(); //bucle de rendering

	return 0;
}
