// Sample code from https://cs.lmu.edu/~ray/notes/openglexamples/

#include <GL/glut.h>
#include <unistd.h>
#include "../lib/freeglut/src/fg_internal.h"
#include "fstr/fstr.h"
#include "stb_image.h"
#include "ansi_escapes.h"
#include <omp.h>
// #include "sw.h"

int pixLen;
char* pixels;
fstr* working;
#define u8 uint8_t

int frameCount = 0;

float rotationAngle = 5.0f;  // Variable to store the current rotation angle

void apply(char* to, int toOffset, int r) {
    to[0 + toOffset] = '0';
    to[1 + toOffset] = '0';
    to[2 + toOffset] = '0';

    char tmp[4];
    itoa(r, tmp, 10);

    if (r >= 100) {
        to[0 + toOffset] = tmp[0];
        to[1 + toOffset] = tmp[1];
        to[2 + toOffset] = tmp[2];
        return;
    }

    if (r >= 10) {
        to[1 + toOffset] = tmp[0];
        to[2 + toOffset] = tmp[1];
        return;
    }

    if (r >= 1) {
        to[2 + toOffset] = tmp[0];
    }
}
char* workingBuf;

void display(void) {
    struct timespec a;
    clock_gettime(CLOCK_MONOTONIC, &a);
    double start = a.tv_nsec;

    //    double s = sw_start_us();

    glPopMatrix();
    glPushMatrix();

    glClear(GL_COLOR_BUFFER_BIT);

    // Apply rotation transformation
    glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f);  // Rotate around the z-axis

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

    // Update the rotation angle for the next frame
    //    rotationAngle += 1.0f;

    glEnd();
    glFlush();

    glReadPixels(0, 0, 640, 480, GL_RGB, GL_UNSIGNED_BYTE, pixels);

    move00();

    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);
    //    fstr_pad(working, w * h, ' ', 1);

    int len = strlen(workingBuf);
    int off = 0;
    int mul = 3;
    int pixSize = 3;

    for (int y = h; y > 0; y -= pixSize * mul) {
        for (int x = 0; x < w; x += pixSize * mul) {
            int i = y * w + x;

            u8 r = pixels[i * pixSize];
            u8 g = pixels[i * pixSize + 1];
            u8 b = pixels[i * pixSize + 2];
            //            u8 a = pixels[i * pixSize + 3];

            apply(workingBuf, 7, r);
            apply(workingBuf, 11, g);
            apply(workingBuf, 15, b);

            fstr_overwrite_C(working, off, workingBuf);

            off += len;

            //            fstr_append_C(working, workingBuf);
        }

        //        fstr_append_C(working, "\n");
        fstr_overwrite_C(working, off, "\n");
        off++;
        //        printf("\033[0m\n");
        //        puts("\033[0m\n");
        rotationAngle += 0.1f;
    }

    fstr_print(working);

    printf("\033[0m\n");
    //    sw_stop_us(s);

    printf("frameCount: %d\n", ++frameCount);

    clock_gettime(CLOCK_MONOTONIC, &a);
    printf("frame took: %fms\n", fabs(start - a.tv_nsec) / 1000000.0);
}

void timer(int) {
    glutPostRedisplay();
    const int fps = 30;
    glutTimerFunc(1000 / fps, timer, 0);
}

int main(int argc, char** argv) {
    char* tmp = "\x01b[48;2;000;000;000m   ";
    workingBuf = malloc(strlen(tmp) + 1);
    strcpy(workingBuf, tmp);

    setupConsole();

    hideCursor();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(80, 80);
    glutInitWindowSize(640, 480);
    glutCreateWindow("FreeGLUT Application");

    glutDisplayFunc(display);

    pixLen = glutGet(GLUT_WINDOW_WIDTH) * glutGet(GLUT_WINDOW_HEIGHT) * 4;

    pixels = malloc(pixLen);
    working = fstr_from_C("");

    //    glutHideWindow();
    timer(20);
    glutMainLoop();
}
