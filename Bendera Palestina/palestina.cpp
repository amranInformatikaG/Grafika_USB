#include <iostream>
#include <GL/freeglut.h>
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);


	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(400.0, 290.0);
	glVertex2f(400.0, 350.0);
	glVertex2f(100.0, 350.0);
	glVertex2f(100.0, 290.0);
	glEnd();
	glFlush();

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2f(400.0, 230.0);
	glVertex2f(400.0, 290.0);
	glVertex2f(100.0, 290.0);
	glVertex2f(100.0, 230.0);
	glEnd();
	glFlush();

	glColor3f(0.0, 0.5, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(400.0, 170.0);
	glVertex2f(400.0, 230.0);
	glVertex2f(100.0, 230.0);
	glVertex2f(100.0, 170.0);
	glEnd();
	glFlush();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(100.0, 170.0);
	glVertex2f(200.0, 260.0);
	glVertex2f(100.0, 350.0);
	glEnd();
	glFlush();
}

void myinit() {
	glClearColor(1.0, 1.0, 0.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("points");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
	return 0;

}