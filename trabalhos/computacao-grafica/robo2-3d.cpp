#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

#define troncoX 10.0
#define troncoY 30.0
#define troncoZ 5.0

#define cabecaX 20.0
#define cabecaY 20.0
#define cabecaZ 10.0

#define raioEsfera 5.0

#define pescocoX 10.0
#define pescocoY 10.0
#define pescocoZ 5.0

#define claviculaX 20.0
#define claviculaY 5.0
#define claviculaZ 5.0

#define bracoSuperiorX 5.0
#define bracoSuperiorY 10.0
#define bracoSuperiorZ 5.0

#define bracoInferiorX 5.0
#define bracoInferiorY 10.0
#define bracoInferiorZ 5.0

#define cinturaX 20.0
#define cinturaY 5.0
#define cinturaZ 5.0

#define pernaSuperiorX 5.0
#define pernaSuperiorY 20.0
#define pernaSuperiorZ 5.0

#define pernaInferiorX 5.0
#define pernaInferiorY 15.0
#define pernaInferiorZ 5.0

float anguloCabeca = 0.0f;
bool girarCabecaEsquerda = false;
bool girarCabecaDireita = false;

float anguloPescoco = 0.0f;
bool girarPescocoEsquerda = false;
bool girarPescocoDireita = false;

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
        glRotatef(anguloPescoco,1.0,0.0,0.0);
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
void desenharClavicula()
{
    glColor3f(0.0, 0.0, 1.0);
    glPushMatrix();
        glScalef(claviculaX, claviculaY, claviculaZ);
        glutSolidCube(1.0);
    glPopMatrix();
}
void desenharBracoSuperior()
{
    glColor3f(0.0, 1.0, 1.0);
    glPushMatrix();
        glScalef(bracoSuperiorX, bracoSuperiorY, bracoSuperiorZ);
        glutSolidCube(1.0);
    glPopMatrix();
}
void desenharBracoInferior()
{
    glColor3f(0.0, 1.0, 1.0);
    glPushMatrix();
        glScalef(bracoInferiorX, bracoInferiorY, bracoInferiorZ);
        glutSolidCube(1.0);
    glPopMatrix();
}
void desenharCintura()
{
    glColor3f(1.0, 0.0, 0.0);
    glPushMatrix();
        glScalef(cinturaX,cinturaY,cinturaZ);
        glutSolidCube(1.0);
    glPopMatrix();
}
void desenharCinturaDireita()
{
    glColor3f(1.0, 0.0, 1.0);
    glPushMatrix();
        glScalef(cinturaX,cinturaY,cinturaZ);
        glutSolidCube(1.0);
    glPopMatrix();
}
void desenharPernaSuperior()
{
    glColor3f(1.0, 0.0, 1.0);
    glPushMatrix();
        glScalef(pernaSuperiorX,pernaSuperiorY,pernaSuperiorZ);
        glutSolidCube(1.0);
    glPopMatrix();

}
void desenharPernaInferior()
{
    glColor3f(1.0, 0.0, 1.0);
    glPushMatrix();
        glScalef(pernaInferiorX,pernaInferiorY, pernaInferiorZ);
        glutSolidCube(1.0);
    glPopMatrix();

}


void desenharCabeca()
{
    glColor3f(1.0, 0.0, 1.0);
    glPushMatrix();
        glRotatef(anguloCabeca,0.0,1.0,0.0);
        glScalef(cabecaX,cabecaY, cabecaZ);
        glutSolidCube(1.0);
    glPopMatrix();
}

void desenharSuperiores()
{
        //---TRONCO---
    tronco();
    glTranslatef(0.0, (troncoY/2+raioEsfera), 0.0);
    desenharArticulacao();
    glTranslatef(0.0, (raioEsfera+pescocoY/2), 0.0);
    //---PESCOCO---
    pescoco();
    glTranslatef(0.0,(pescocoY/2+cabecaY/2),0.0);
    //---CABECA---
    desenharCabeca();
    glTranslatef( -(claviculaX/2+troncoX/2),-((raioEsfera*2+pescocoY+raioEsfera)+claviculaY/2) ,0.0);

    //----BRACO ESQUERDO---
    //Clavicula Esquerda
    desenharClavicula();
    glTranslatef(-(claviculaX/2+raioEsfera),0.0,0.0);
    desenharArticulacao();
    //Braco Superior Esquerdo
    glTranslatef(0.0,-(raioEsfera+bracoSuperiorY/2),0.0);
    desenharBracoSuperior();
    glTranslatef(0.0,-(raioEsfera+bracoSuperiorY/2),0.0);
    desenharArticulacao();
    //Braco Inferior Esquerdo
    glTranslatef(0.0,-(raioEsfera+bracoInferiorY/2),0.0);
    desenharBracoInferior();

    //---BRACO DIREITO ---
    glTranslatef((bracoInferiorX+claviculaX+troncoX+claviculaX/2),(bracoInferiorY+raioEsfera*2+bracoSuperiorX+claviculaY),0.0);
    //Clavicula Direita
    desenharClavicula();
    glTranslatef((claviculaX/2+raioEsfera),0.0,0.0);
    desenharArticulacao();
    glTranslatef(0.0,-(raioEsfera+bracoSuperiorY/2),0.0);
    desenharBracoSuperior();
    glTranslatef(0.0,-(raioEsfera+bracoSuperiorY/2),0.0);
    desenharArticulacao();
    glTranslatef(0.0,-(raioEsfera+bracoInferiorY/2),0.0);
    desenharBracoInferior();

}
void desenharInferiores()
{
    //----INFERIORES----
    //Perna Esquerda
    glTranslatef(0.0,(bracoInferiorY+raioEsfera*2+bracoSuperiorY+claviculaY),0.0);
    glTranslatef(-(bracoInferiorX+claviculaX+troncoX/2),-(troncoY+cinturaY),0.0);
    glTranslatef(-cinturaX/2,0.0,0.0);

    desenharCintura();
    glTranslatef(-(cinturaX/2-raioEsfera),-(cinturaY+raioEsfera/2),0.0);
    desenharArticulacao();
    glTranslatef(0.0,-(raioEsfera+pernaSuperiorY/2),0.0);
    desenharPernaSuperior();
    glTranslatef(0.0,-(raioEsfera+pernaSuperiorY/2),0.0);
    desenharArticulacao();
    glTranslatef(0.0,-(raioEsfera+pernaInferiorY/2),0.0);
    desenharPernaInferior();
    //Perna Direita
    glTranslatef(raioEsfera,(pernaInferiorY+raioEsfera*2+pernaSuperiorY+cinturaY),0.0);
    glTranslatef(cinturaX,0.0,0.0);
    desenharCintura();
    glTranslatef((cinturaX/2-raioEsfera),-(cinturaY+raioEsfera/2),0.0);
    desenharArticulacao();
    glTranslatef(0.0,-(raioEsfera+pernaSuperiorY/2),0.0);
    desenharPernaSuperior();
    glTranslatef(0.0,-(raioEsfera+pernaSuperiorY/2),0.0);
    desenharArticulacao();
    glTranslatef(0.0,-(raioEsfera+pernaInferiorY/2),0.0);
    desenharPernaInferior();


}
void desenharRobo()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    desenharSuperiores();
    desenharInferiores();
    glutSwapBuffers();
    glPopMatrix();
}

void resize(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(120.0, (GLdouble)w / h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(-50.0, 0.0, 60.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
}
void Timer(int value);

void Teclado(unsigned char tecla, int x, int y) {
    switch (tecla) {
        case 27:
        case 'q':
            exit(0);
            break;
        case 'h'://Girar Head(Cabeca)
            if (!girarCabecaEsquerda && !girarCabecaDireita) {
                girarCabecaEsquerda = true;
                glutTimerFunc(33, Timer, 0);
            }
            break;
        case 'n'://Girar
            if (!girarPescocoEsquerda && !girarPescocoDireita) {
                girarPescocoEsquerda = true;
                glutTimerFunc(33, Timer, 0);
            }
            break;
    }
}

void Timer(int value) {
    if (girarCabecaEsquerda)
    {
        anguloCabeca += 3.0;
        if (anguloCabeca >= 50.0) {
            anguloCabeca = 50.0;
            girarCabecaEsquerda = false;
            girarCabecaDireita = true;
        }
    } else if (girarCabecaDireita) {
        anguloCabeca -= 3.0;
        if (anguloCabeca <= -50.0) {
            anguloCabeca = 0.0;
            girarCabecaDireita = false;
        }
    }
    if (girarPescocoEsquerda)
    {
        anguloPescoco += 3.0;
        if (anguloPescoco >= 50.0) {
            anguloPescoco = 50.0;
            girarPescocoEsquerda = false;
            girarPescocoDireita = true;
        }
    } else if (girarPescocoDireita) {
        anguloPescoco -= 3.0;
        if (anguloPescoco <= -50.0) {
            anguloPescoco = 0.0;
            girarPescocoDireita = false;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(33, Timer, 0);
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
    glutKeyboardFunc (Teclado);
    //glutTimerFunc(33, Timer, 1);

    glutMainLoop();
    return 0;
}
