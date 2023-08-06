#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

void desenharRobo() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //TRONCO
    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0);
    glTranslatef(20.0, 20.0, 0.0);
    glScalef(10.0, 30.0, 2.0);
    glutSolidCube(1.0);
    glPopMatrix();

    //Articulação pescoço
    glPushMatrix();
    glColor3f(0.0,1.0,0.0);
    glTranslatef(20.0, 40.0, 0.0);
    glutSolidSphere(5.0, 20, 20);
    glPopMatrix();

    //pescoco
    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0);
    glTranslatef(20.0, 48.0, 0.0); // Ajuste a posição para que o cubo rosa fique acima do cubo vermelho
    glScalef(4.0, 5.0, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

     //cabeca
    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(20.0, 62.0, 0.0);
    glutSolidSphere(10.0, 20, 20);
    glPopMatrix();

    //clavicula esquerdo
    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(10, 33.0, 0.0); // Ajuste a posição para que o cubo rosa fique acima do cubo vermelho
    glScalef(30.0, 5.0, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    //Articulação cima braco esquerdo
    glPushMatrix();
    glColor3f(0.0,1.0,0.0);
    glTranslatef(0, 25.0, 0.0);
    glutSolidSphere(5.0, 20, 20);
    glPopMatrix();


   //braco esquerdo superior
    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(0, 15.0, 0.0); // Ajuste a posição para que o cubo rosa fique acima do cubo vermelho
    glScalef(5.0, 10.0, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();


    //Articulação baixo braco esquerdo
    glPushMatrix();
    glColor3f(0.0,1.0,0.0);
    glTranslatef(0, 10.0, 0.0);
    glutSolidSphere(5.0, 20, 20);
    glPopMatrix();

     //braco esquerdo inferior
    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(0, 3.0, 0.0); // Ajuste a posição para que o cubo rosa fique acima do cubo vermelho
    glScalef(5.0, 5.0, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();


    //clavicula direito
    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(30, 33.0, 0.0); // Ajuste a posição para que o cubo rosa fique acima do cubo vermelho
    glScalef(30.0, 5.0, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    //Articulação cima direito
    glPushMatrix();
    glColor3f(0.0,1.0,0.0);
    glTranslatef(40, 25.0, 0.0);
    glutSolidSphere(5.0, 20, 20);
    glPopMatrix();

    //braco direito superior
    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(40, 15.0, 0.0); // Ajuste a posição para que o cubo rosa fique acima do cubo vermelho
    glScalef(5.0, 10.0, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    //Articulação baixo braco direito
    glPushMatrix();
    glColor3f(0.0,1.0,0.0);
    glTranslatef(40, 10.0, 0.0);
    glutSolidSphere(5.0, 20, 20);
    glPopMatrix();

     //braco direito inferior
    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(40, 3.0, 0.0); // Ajuste a posição para que o cubo rosa fique acima do cubo vermelho
    glScalef(5.0, 5.0, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();


    //cintura
    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0);
    glTranslatef(20.0, 5.0, 0.0);
    glScalef(30.0, 5.0,1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    //Articulação perna esquerda superior
    glPushMatrix();
    glColor3f(0.0,1.0,0.0);
    glTranslatef(10.0, -2.5, 0.0);
    glutSolidSphere(5.0, 20, 20);
    glPopMatrix();

    //perna esquerda superior
    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(10, -15.0, 0.0); // Ajuste a posição para que o cubo rosa fique acima do cubo vermelho
    glScalef(5.0, 25.0, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    //Articulação perna esquerda inferior
    glPushMatrix();
    glColor3f(0.0,1.0,0.0);
    glTranslatef(10.0, -25.0, 0.0);
    glutSolidSphere(5.0, 20, 20);
    glPopMatrix();

    //perna esquerda inferior
    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(10, -30.0, 0.0); // Ajuste a posição para que o cubo rosa fique acima do cubo vermelho
    glScalef(5.0, 25.0, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    //Articulação perna direita superior
    glPushMatrix();
    glColor3f(0.0,1.0,0.0);
    glTranslatef(31.0, -2.5, 0.0);
    glutSolidSphere(5.0, 20, 20);
    glPopMatrix();

     //perna direita superior
    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(31, -15.0, 0.0); // Ajuste a posição para que o cubo rosa fique acima do cubo vermelho
    glScalef(5.0, 25.0, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    //Articulação perna direita inferior
    glPushMatrix();
    glColor3f(0.0,1.0,0.0);
    glTranslatef(31.0, -25.0, 0.0);
    glutSolidSphere(5.0, 20, 20);
    glPopMatrix();

    //perna esquerda inferior
    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(31.0, -30.0, 0.0); // Ajuste a posição para que o cubo rosa fique acima do cubo vermelho
    glScalef(5.0, 25.0, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    glutSwapBuffers();
}

void resize(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(120.0, (GLdouble)w / h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(-2.80, 10.0, 60.0,
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
