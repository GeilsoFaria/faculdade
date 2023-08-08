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
        glTranslatef(20.0, 40.0, 0.0);
        glPushMatrix();
            glScalef(10.0, 30.0, 10.0);
            glutSolidCube(1.0);
        glPopMatrix();
    //Articulação pescoço
        glPushMatrix();
            glColor3f(0.0,1.0,0.0);
            glTranslatef(0.0, 20.0, 0.0);
            glutSolidSphere(5.0, 20, 20);
        glPopMatrix();
    //pescoco
        glPushMatrix();
            glColor3f(1.0, 0.0, 0.0);
            glTranslatef(0, 25.0, 0.0);
            glPushMatrix();
                glScalef(4.0, 5.0, 10.0);
                glutSolidCube(1.0);
            glPopMatrix();
        //cabeca
            glPushMatrix();
                glColor3f(0.0,0.0,0.0);
                glTranslatef(0.0, 7.5, 0.0);
                glutSolidSphere(10.0, 20, 20);
            glPopMatrix();
        glPopMatrix();


    //clavicula esquerdo
    glPushMatrix();
        glColor3f(1.0, 1.0, 0.0);
        glTranslatef(-12.5, 12.5, 0.0);
        glPushMatrix();
            glScalef(15.0, 5.0, 10.0);
            glutSolidCube(1.0);
        glPopMatrix();
        //Articulação cima braco esquerdo
        glPushMatrix();
            glColor3f(0.0,1.0,0.0);
            glTranslatef(-12.5, -2.0, 0.0);
            glutSolidSphere(5.0, 20, 20);
        glPopMatrix();
        //braco esquerdo cima
        glPushMatrix();
            glColor3f(1.0, 1.0, 0.0);
            glTranslatef(-12.5, -15.0, 0.0);
            glPushMatrix();
            glScalef(5.0, 15.0, 10.0);
            glutSolidCube(1.0);
            glPopMatrix();
        glPopMatrix();
        //articulacao de baixo esquerda
        glPushMatrix();
            glColor3f(0.0,1.0,0.0);
            glTranslatef(-12.5, -28.5, 0.0);
            glutSolidSphere(5.0, 20, 20);
        glPopMatrix();
        //inferior braco esquerdo
        glPushMatrix();
            glColor3f(1.0, 1.0, 0.0);
            glTranslatef(-12.5, -37.5, 0.0);
            glScalef(7.5, 5.0, 10.0);
            glutSolidCube(1.0);
            glPopMatrix();
    glPopMatrix();


    //clavicula direito
    glPushMatrix();
        glColor3f(1.0, 1.0, 0.0);
        glTranslatef(12.5, 12.5, 0.0);
        glPushMatrix();
            glScalef(15.0, 5.0, 10.0);
            glutSolidCube(1.0);
        glPopMatrix();
        //Articulação cima braco direito
        glPushMatrix();
            glColor3f(0.0,1.0,0.0);
            glTranslatef(12.5, -2.0, 0.0);
            glutSolidSphere(5.0, 20, 20);
        glPopMatrix();
        //braco direito cima
        glPushMatrix();
            glColor3f(1.0, 1.0, 0.0);
            glTranslatef(12.5, -15.0, 0.0);
            glPushMatrix();
            glScalef(5.0, 15.0, 10.0);
            glutSolidCube(1.0);
            glPopMatrix();
        glPopMatrix();
        //articulacao de baixo direito
        glPushMatrix();
            glColor3f(0.0,1.0,0.0);
            glTranslatef(12.5, -28.5, 0.0);
            glutSolidSphere(5.0, 20, 20);
        glPopMatrix();
        //inferior braco direito
        glPushMatrix();
            glColor3f(1.0, 1.0, 0.0);
            glTranslatef(12.5, -37.5, 0.0);
            glScalef(7.5, 5.0, 10.0);
            glutSolidCube(1.0);
            glPopMatrix();
    glPopMatrix();

     //cintura
    glPushMatrix();
        glColor3f(1.0, 0.0, 0.0);
        glTranslatef(0.0, -15.0, 0.0);
        glPushMatrix();
        glScalef(30.0, 5.0,10.0);
        glutSolidCube(1.0);
        glPopMatrix();
        //Articulação perna esquerda superior
        glPushMatrix();
            glColor3f(0.0,0.0,0.0);
            glTranslatef(-7.5, -7.5, 0.0);
            glutSolidSphere(5.0, 20, 20);
        glPopMatrix();
         //perna esquerda superior
        glPushMatrix();
            glColor3f(1.0, 1.0, 0.0);
            glTranslatef(-7.5, -25.0, 0.0);
            glPushMatrix();
            glScalef(5.0, 25.0, 10.0);
            glutSolidCube(1.0);
            glPopMatrix();
        glPopMatrix();
        //Articulação perna esquerda inferior
        glPushMatrix();
            glColor3f(0.0,1.0,0.0);
            glTranslatef(-7.5, -45.0, 0.0);
            glutSolidSphere(5.0, 20, 20);
        glPopMatrix();
        //perna esquerda inferior
        glPushMatrix();
            glColor3f(1.0, 1.0, 0.0);
            glTranslatef(-7.5, -65.0, 0.0);
            glPushMatrix();
            glScalef(5.0, 25.0, 10.0);
            glutSolidCube(1.0);
            glPopMatrix();
        glPopMatrix();

        //--------------perna direita
        //Articulação perna esquerda superior
        glPushMatrix();
            glColor3f(0.0,0.0,0.0);
            glTranslatef(7.5, -7.5, 0.0);
            glutSolidSphere(5.0, 20, 20);
        glPopMatrix();
         //perna esquerda superior
        glPushMatrix();
            glColor3f(1.0, 1.0, 0.0);
            glTranslatef(7.5, -25.0, 0.0);
            glPushMatrix();
            glScalef(5.0, 25.0, 10.0);
            glutSolidCube(1.0);
            glPopMatrix();
        glPopMatrix();
        //Articulação perna esquerda inferior
        glPushMatrix();
            glColor3f(0.0,1.0,0.0);
            glTranslatef(7.5, -45.0, 0.0);
            glutSolidSphere(5.0, 20, 20);
        glPopMatrix();
        //perna esquerda inferior
        glPushMatrix();
            glColor3f(1.0, 1.0, 0.0);
            glTranslatef(7.5, -65.0, 0.0);
            glPushMatrix();
            glScalef(5.0, 25.0, 10.0);
            glutSolidCube(1.0);
            glPopMatrix();
        glPopMatrix();

    glPopMatrix();//matriz cintura

    glPopMatrix();//matriz tronco

     glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(60.0,-28.5,30.0);
        glVertex3f(60.0,-28.5,-30.0);
        glVertex3f(-20.0,-28.5,-30.0);
        glVertex3f(-20.0,-28.5,30.0);
    glEnd();

    /* glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(60.0,0.0,30.0);
        glVertex3f(60.0,0.0,-30.0);
        glVertex3f(-20.0,0.0,-30.0);
        glVertex3f(-20.0,0.0,30.0);
    glEnd();*/

    glutSwapBuffers();
}

void resize(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(120.0, (GLdouble)w / h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.00, 40.0, 60.0,
              20.0, 20.0, 0.0,
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
