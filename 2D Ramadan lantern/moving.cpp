#define NOMINMAX
#define GLUT_DISABLE_ATEXIT_HACK  // Prevent 'exit' redefinition error
#include <stdlib.h>  // Use this instead of <cstdlib>
#include <GL\glut.h>
#include <Windows.h>


float xposition = 0.5f, deltaX = 0.3f, ratio, width, height;
float scaleFactor = 1.5f; // Scale factor to enlarge the shape

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Apply translation and scaling
    glTranslatef(xposition, 0, 0);
    glScalef(scaleFactor, scaleFactor, 1.0f);

    glBegin(GL_POLYGON);
    glColor3f(0, 1, 0);
    glVertex2f(-0.5, 0.6);
    glVertex2f(0, 0.95);
    glVertex2f(0.5, 0.6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);
    glVertex2f(-0.5, 0.6);
    glVertex2f(0.5, 0.6);
    glVertex2f(0.3, -0.1);
    glVertex2f(-0.3, -0.1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1, 0.8431372549019608, 0);
    glVertex2f(-0.3, -0.1);
    glVertex2f(0.3, -0.1);
    glVertex2f(0.5, -0.4);
    glVertex2f(-0.5, -0.4);
    glEnd();

    glutSwapBuffers();
    glFlush();
}

void changeColor() {
    glClearColor(0, 0.455, 0.455, 0);
}

void timer(int v) {
    glutPostRedisplay();
    glutTimerFunc(1000 / 30, timer, 0);

    xposition += deltaX;

    if (xposition > width - 1 || xposition < -width + 1) {
        deltaX = -deltaX;
    }
}

void reshape(int w, int h) {
    if (h == 0) h = 1;
    ratio = (float)w / h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (w >= h) {
        gluOrtho2D(-10 * ratio, 10 * ratio, -10, 10);
        width = 10 * ratio;
        height = 10;
    }
    else {
        gluOrtho2D(-10, 10, -10 / ratio, 10 / ratio);
        width = 10;
        height = 10 / ratio;
    }
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);
    glutInitWindowSize(screenWidth, screenHeight);
    glutCreateWindow("Moving & Enlarged Shapes");

    changeColor();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(1000 / 30, timer, 0);

    glutMainLoop();
    return 0;
}