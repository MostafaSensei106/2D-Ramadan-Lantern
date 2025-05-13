#include <GL\glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    // resets the current  Matrix
    glLoadIdentity();
    // draw our objects
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
    glColor3f(1, 1, 0);
    glVertex2f(-0.3, -0.1);
    glVertex2f(0.3, -0.1);
    glVertex2f(0.5, -0.4);
    glVertex2f(-0.5, -0.4);


    glEnd();

    glFlush();
}
void changeColor() {
    glClearColor(0.0, 0.0, 1.0, 0.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Ramadn lantern");
    changeColor();

    glutDisplayFunc(display);
    glutMainLoop();
}