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
    //glColor3f(0.0, 0.0, 1.0);
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

    // Poligon dengan perulangan
    
    glColor3f(0.0, 1.0, 0.0); // HIJAU
    int bentuk = 2000;
    for (int a = 20; a > 10; a -= 2) {
        glBegin(GL_LINE_LOOP);
            ngon(bentuk, -40, 40, a, 60);
        glEnd();
    }
    
     
    int bentukk = 6;
    for (int a = 40; a >= 15; a -= 5) {
        if(bentukk % 2 == 0) {
            glBegin(GL_LINE_LOOP);
                glColor3f(0.0, 1.0, 0.0);//hijau
                ngon(bentukk, 0, -50, a, 45);
            glEnd();
        }
        else {
            
            glBegin(GL_LINE_LOOP);
                glColor3f(1.0, 0.0, 0.0);
                ngon(bentukk, 0, -50, a, 45);
            glEnd();    
        }
        bentukk--;
    }

    int data[3][2] = { {20,-10},{0,20},{40,40} };
    glBegin(GL_LINE_LOOP);
    for (int s = 0; s < 3; s++) {
        glColor3f(1.0, 0.0, 1.0);
        glVertex2i(data[s][0], data[s][1]);

    }
    glEnd();
    glutSwapBuffers();
}
