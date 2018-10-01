#define GLUT_DISABLE_ATEXIT_HACK	
#include <cmath>
#include "GL/glut.h"
#include "ClassPlayer.h"
#include "Red.h"

#define KEY_ESC 27


float TIME = 0;
float NEWTIME = 0;
float DTTIME = 0;

ClassPlayer player1;

//
//funcion llamada a cada imagen
void glPaint(void) {
	TIME = glutGet(GLUT_ELAPSED_TIME);
	DTTIME = (TIME - NEWTIME)/10000;	
	//El fondo de la escena al color initial
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //(R, G, B, transparencia) en este caso un fondo negro
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	player1.executeAction();
	player1.move();
	player1.draw();
	//doble buffer, mantener esta instruccion al fin de la funcion
	glutSwapBuffers();
	NEWTIME = TIME;
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
	case 'x':
		player1.actions[2] = true;
		//player1.jump();
		break;
	default:
		break;
	}

}

GLvoid NormalKeys(unsigned char key, int x, int y) {
	switch (key) {
	case 'x':
		player1.actions[2] = false;
		//player1.jump();
		break;
	default:
		break;
	}

}

GLvoid SpecialKeys(int key, int x, int y)
{
    switch (key)
	{
		case GLUT_KEY_LEFT:
			player1.direction = LEFT;
			player1.actions[1] = true;
			//player1.walk();
			break;
		case GLUT_KEY_RIGHT:
			player1.direction = RIGHT;
			player1.actions[1] = true;
			//player1.walk();
			break;
		case GLUT_KEY_UP:
			break;
		case GLUT_KEY_DOWN:
			break;
	}
}

GLvoid SpecialUpKeys(int key, int x, int y)
{
    switch (key)
	{
		case GLUT_KEY_LEFT:
			player1.actions[1] = false;
			player1.lastDirection = LEFT;
			break;
		case GLUT_KEY_RIGHT:
			player1.actions[1] = false;
			player1.lastDirection = RIGHT;
			break;
		case GLUT_KEY_UP:
			break;
		case GLUT_KEY_DOWN:
			break;
	}
}
GLvoid idle(){
	glutPostRedisplay();
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
	glutIdleFunc(&idle);
	init_GL(); //funcion de inicializacion de OpenGL

	glutDisplayFunc(glPaint); 
	glutReshapeFunc(&window_redraw);
	// Callback del teclado
	glutKeyboardFunc(&window_key);
	glutKeyboardUpFunc(&NormalKeys);
	glutSpecialFunc(SpecialKeys);
	glutSpecialUpFunc(SpecialUpKeys);

	glutMainLoop(); //bucle de rendering

	return 0;
}
