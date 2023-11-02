#include <iostream>
#include <GL/freeglut.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(400, 250);    // Koordinat pojok kanan bawah
	glVertex2f(400, 350);    // Koordinat pojok kanan atas
	glVertex2f(100, 350);    // Koordinat pojok kiri atas
	glVertex2f(100, 250);    // Koordinat pojok kiri bawah
	glEnd();
	glFlush();

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2f(400, 150);    // Koordinat pojok kanan bawah
	glVertex2f(400, 250);    // Koordinat pojok kanan atas
	glVertex2f(100, 250);    // Koordinat pojok kiri atas
	glVertex2f(100, 150);    // Koordinat pojok kiri bawah
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
	glutCreateWindow("Points");
	glutDisplayFunc(display);

	myinit();
	glutMainLoop();

	return 0;
}