#include <Windows.h>
#ifdef __APPLE__


#else
#include <GL/glut.h>
#endif // __APPLE__
#include <stdlib.h>
#include <math.h> // Tambahkan header math.h
#include <stdlib.h>

void init(void);
void display(void);
void ngon(int n, float cx, float cy, float radius, float rotAngle);

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
    glOrtho(-100.0, 100.0, -100.0, 100.0, -100.0, 100.0);
}

// N-GON SIMETRIX
void ngon(int n, float cx, float cy, float radius, float rotAngle) {
    double angle, angleInc;
    int k;

    if (n < 3) return;
    angle = rotAngle * 3.14159265 / 180;
    angleInc = 2 * 3.14159265 / n;

    // titik awal
    glVertex2f(radius * cos(angle) + cx, radius * sin(angle) + cy);

    // titik berikutnya
    for (k = 0; k < n; k++) {
        angle += angleInc;
        glVertex2f(radius * cos(angle) + cx, radius * sin(angle) + cy);
    }
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // Garis dengan GL_LINE_STRIP
    glColor3f(1.0, 1.0, 1.0); // PUTIH
    glBegin(GL_LINE_STRIP);
    glVertex2i(-60, 80);
    glVertex2i(-30, 80);
    glVertex2i(-60, 40);
    glVertex2i(-30, 40);
    glEnd();

    // GL LINE LOOP
    glColor3f(1.0, 0.0, 1.0); // PINK
    glBegin(GL_LINE_LOOP);
    glVertex2i(60, 80);
    glVertex2i(30, 80);
    glVertex2i(60, 40);
    glVertex2i(30, 40);
    glEnd();

    // Poligon dengan ngon
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 1.0, 0.0); // HIJAU
    ngon(60, 0, 0, 30, 60);

    glEnd();
    glutSwapBuffers();
}
