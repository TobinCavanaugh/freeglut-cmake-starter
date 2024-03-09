// Sample code from https://cs.lmu.edu/~ray/notes/openglexamples/

#include <GL/glut.h>

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);
    {
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(-0.6f, -0.75f, 0.5f);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(0.6f, -0.75f, 0.0f);

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(0.0f, 0.75f, 0.0f);
    }
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(80, 80);
    glutInitWindowSize(400, 300);
    glutCreateWindow("FreeGLUT Application");

    glutDisplayFunc(display);

    glutMainLoop();
}
