#include <Windows.h>
#ifdef __APPLE__


#else
#include <GL/glut.h>
#endif // __APPLE__
#include <stdlib.h>


#include <stdlib.h>

void init(void);
void display(void);

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(250, 250);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("My First OpenGL Application");
    init();
    glutDisplayFunc(display);  // Register the display callback function
    glutMainLoop();  // Enter the GLUT event loop
    return 0;
}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);  // Set the background color to black
    glColor3f(0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0, 10.0, -10.0, 10.0,-10.0, 10.0);

}


void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    // Add your OpenGL drawing code here
    // gl points (membuat titik)
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    glVertex3i(4, 6, 10);
    glVertex3i(2, 6, 10);
    glEnd();

    // gl lines (membuat garis)
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINES);
    glVertex3i(5, 5, 10);
    glVertex3i(1, 5, 10);
    glEnd();

    // gl Triangles (membuat Segitiga)
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex3i(4, 2, 0 );
    glVertex3i(2, 2, 0 );
    glVertex3i(3, 4, 0 );
    glEnd();

    // gl Persegi (membuat Persegi)
    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3i(4, -1, 0);
    glVertex3i(4, 1, 0);
    glVertex3i(2, 1, 0);
    glVertex3i(2, -1, 0);
    glEnd();

    // gl Polygon (membuat polygon)
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3i(-1, 1, 0);
    glVertex3i(0, 2, 0);
    glVertex3i(-1, 3, 0);
    glVertex3i(-2, 3, 0);
    glVertex3i(-3, 2, 0);
    glVertex3i(-2, 1, 0);
    glEnd();
    //Triangle Stripp
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(7, 1);
    glVertex2f(7, 3);
    glVertex2f(5, 1);
    glVertex2f(5, 3);
    glEnd();
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(7, 1);
    glVertex2f(5, 3);
    glVertex2f(7, 3);
    glVertex2f(5, 1);
    glEnd();
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(7, 1);
    glVertex2f(5, 1);
    glVertex2f(6, 2);
    glEnd();




    glutSwapBuffers();
}
