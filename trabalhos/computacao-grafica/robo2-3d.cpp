#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

#define troncoX 10.0
#define troncoY 30.0
#define troncoZ 10.0

#define raioEsfera 5.0

#define pescocoX 8.0
#define pescocoY 8.0
#define pescocoZ 10.0


void tronco()
{
    glColor3f(1.0, 0.0, 0.0);
    glPushMatrix();
            glScalef(troncoX, troncoY, troncoZ);
            glutSolidCube(1.0);
    glPopMatrix();
}
void pescoco()
{
    glColor3f(1.0, 0.0, 0.0);
    glPushMatrix();
        glScalef(pescocoX, pescocoY, pescocoZ);
        glutSolidCube(1.0);
    glPopMatrix();
}

void desenharArticulacao()
{
    glPushMatrix();
        glColor3f(0.0,1.0,0.0);
        glutSolidSphere(raioEsfera, 20, 20);
    glPopMatrix();

}
void desenharRobo()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    tronco();
    glTranslatef(0.0, (troncoY/2+raioEsfera), 0.0);
    desenharArticulacao();
    glTranslatef(0.0, (raioEsfera*2), 0.0);
    pescoco();
    glTranslatef(0.0,pescocoY,0.0);
    desenharArticulacao();
    glTranslatef()

    glutSwapBuffers();
}

void resize(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(120.0, (GLdouble)w / h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.00, 20.0, 60.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Robô 3D com 9 articulações");
    glutReshapeFunc(resize);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(desenharRobo);
    glutMainLoop();
    return 0;
}
