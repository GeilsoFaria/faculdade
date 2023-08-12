#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int passo = 0; // Contador de passos
bool caminhando = false;
float posicaoRoboX = 0.0; // Posição do robô no eixo X

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
float anguloCabecaX = 0.0f;
float anguloBraco = 0.0f;
float angulobracoX =0.0f;
float angulobracoZ=0.0f;
float anguloBracoLateral=0.0f;
bool girarCabecaEsquerda = false;
bool girarCabecaDireita = false;
bool girarCabecaFrente = false;
bool girarCabecaTras = false;
bool varGirabraco=false;
bool controleBraco=true;

float anguloPernaEsquerda = 0.0f;
float anguloPernaDireita = 0.0f;


void GirarBraco(int value);

void AtualizarAnimacao(int value) {
    // Atualiza o ângulo das pernas de acordo com o passo atual
    if (caminhando) {
        if (passo % 2 == 0) {
            anguloPernaEsquerda = sin(value * 0.1) * 45.0;  // Simula o movimento da perna esquerda
            anguloPernaDireita = sin(value * 0.1 + 3.14) * 45.0;  // Mantém a perna direita reta
        } else {
            anguloPernaEsquerda = sin(value * 0.1 + 3.14) * 45.0;  // Mantém a perna esquerda reta
            anguloPernaDireita = sin(value * 0.1) * 45.0;  // Simula o movimento da perna direita
        }

        // Move o robô para frente durante a caminhada
        if (passo < 2) {
            posicaoRoboX += 0.05; // Ajuste a velocidade de movimento conforme necessário
        } else {
            caminhando = false; // Termina a animação após dois passos
        }
    }

    glutPostRedisplay();
    glutTimerFunc(33, AtualizarAnimacao, value + 1);
}



// Função para iniciar a animação de caminhada
void IniciarCaminhada() {
    caminhando = true;
    passo = 0;
}

// Função para parar a animação de caminhada
void PararCaminhada() {
    caminhando = false;
}
void ConcluirPasso(int value) {
    passo++;

    if (passo < 2) {
        glutTimerFunc(1000, ConcluirPasso, 0);  // Espera 1 segundo antes de dar o próximo passo
    } else {
        PararCaminhada(); // Para a animação após dois passos
    }
}

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
        //glRotatef(anguloPescoco,1.0,0.0,0.0);
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
       // glTranslatef(0.0,anguloBraco,angulobracoZ);
        glScalef(bracoSuperiorX, bracoSuperiorY, bracoSuperiorZ);
        // glRotatef(90.0,1.0,0.0,0.0);
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

void desenharCabeca()
{
    glColor3f(1.0, 0.0, 1.0);
    glPushMatrix();
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
    glPushMatrix();
        glRotatef(anguloCabeca,0.0,1.0,0.0);
        glRotatef(anguloCabecaX,1.0,0.0,0.0);
        pescoco();
    glPopMatrix();

    glTranslatef(0.0,(pescocoY/2+cabecaY/2),0.0);

    //---CABECA---
    glPushMatrix();
        glRotatef(anguloCabeca,0.0,1.0,0.0);
        glRotatef(anguloCabecaX,1.0,0.0,0.0);
        desenharCabeca();
    glPopMatrix();

    glTranslatef( -(claviculaX/2+troncoX/2),-((raioEsfera*2+pescocoY+raioEsfera)+claviculaY/2) ,0.0);


    //----BRACO ESQUERDO---
    //Clavicula Esquerda
    desenharClavicula();
    glTranslatef(-(claviculaX/2+raioEsfera),0.0,0.0);
    desenharArticulacao();
    //Braco Superior Esquerdo
    glTranslatef(0.0,-(raioEsfera+bracoSuperiorY/2),0.0);

    glPushMatrix();
      glTranslatef(anguloBracoLateral,anguloBraco,angulobracoZ);
      desenharBracoSuperior();
    //glPopMatrix();
    glTranslatef(0.0,-(raioEsfera+bracoSuperiorY/2),0.0);
    glTranslatef(anguloBracoLateral,anguloBraco,angulobracoZ);
    desenharArticulacao();
    //Braco Inferior Esquerdo
    glTranslatef(0.0,-(raioEsfera+bracoInferiorY/2),0.0);
    glTranslatef(anguloBracoLateral,anguloBraco,angulobracoZ);
    desenharBracoInferior();
    glPopMatrix();
    glTranslatef(0.0,-bracoSuperiorY*2,0);



    //---BRACO DIREITO ---
    glTranslatef((bracoInferiorX+claviculaX+troncoX+claviculaX/2),(bracoInferiorY+raioEsfera*2+bracoSuperiorX+claviculaY),0.0);
    //Clavicula Direita
    desenharClavicula();
    glTranslatef((claviculaX/2+raioEsfera),0.0,0.0);
    desenharArticulacao();
    glPushMatrix();
    glTranslatef(0.0,anguloBraco,angulobracoZ);
    glTranslatef(0.0,-(raioEsfera+bracoSuperiorY/2),0.0);
    desenharBracoSuperior();
    glTranslatef(0.0,-(raioEsfera+bracoSuperiorY/2),0.0);
    glTranslatef(0.0,anguloBraco,angulobracoZ);
    desenharArticulacao();
    glTranslatef(0.0,-(raioEsfera+bracoInferiorY/2),0.0);
     glTranslatef(0.0,anguloBraco,angulobracoZ);
    desenharBracoInferior();
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
void desenharPernaSuperior()
{
    glColor3f(1.0, 0.0, 1.0);
    glPushMatrix();
        glScalef(pernaSuperiorX,pernaSuperiorY,pernaSuperiorZ);
         glRotatef(anguloPernaEsquerda, 1.0, 0.0, 0.0);
        glutSolidCube(1.0);
    glPopMatrix();

}

void desenharPernaInferior()
{
    glColor3f(1.0, 0.0, 1.0);
    glPushMatrix();
        glScalef(pernaInferiorX,pernaInferiorY, pernaInferiorZ);
        glRotatef(anguloPernaDireita, 1.0, 0.0, 0.0);  // Aplica a rotação da perna
        glutSolidCube(1.0);
    glPopMatrix();

}
void desenharInferiores()
{
    //----INFERIORES----
    //Perna Esquerda
    glTranslatef(0.0,-troncoY,0.0);
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
     glTranslatef(0.0, 0.0, posicaoRoboX);
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
void GirarPescoco(int value);
void GirarPescocoFrenteTras(int value);
void IniciarPararCaminhada() {
    caminhando = !caminhando;
}

void Teclado(unsigned char tecla, int x, int y) {
    switch (tecla) {
        case 27:
        case 'q':
            exit(0);
            break;
        case 'h': //Girar Head(Cabeca)
            if (!girarCabecaEsquerda && !girarCabecaDireita) {
                girarCabecaEsquerda = true;
                glutTimerFunc(33, GirarPescoco, 0);

            }
            break;
        case 'n':
            if (!girarCabecaTras && !girarCabecaFrente) {
                girarCabecaTras = true;
                glutTimerFunc(33, GirarPescocoFrenteTras, 0);
            }
            break;
        case 'b':
                //if (!varGirabraco) {
                //varGirabraco = true;
                controleBraco=true;
                glutTimerFunc(33, GirarBraco, 0);
            //}

            break;
        case 'w': // Inicia/Para a caminhada
            caminhando = true;
            passo = 0;
            posicaoRoboX = 0.0;
            break;




    }
}
 bool verificaLateral=false;
void GirarBraco(int value) {

   // if (varGirabraco && controleBraco ==false)
    //{
        //angulobracoX += 10.0;
        if(controleBraco==true)
        {
            anguloBraco +=10.0;
            angulobracoZ = 5.0;

        if(anguloBraco >= bracoSuperiorY*2)
        {
            anguloBraco=bracoSuperiorY*2;
            angulobracoZ=0;


            if(verificaLateral== false)
            {
                anguloBracoLateral+=0.5;
                if (anguloBracoLateral >= 3.0)
                {
                    anguloBracoLateral=3.0;
                    verificaLateral=true;;
                }
            }else if(verificaLateral ==true)
            {
                anguloBracoLateral-=0.5;
                if (anguloBracoLateral == -3.0)
                {
                    //anguloBracoLateral=3.0;
                    anguloBracoLateral=0.0;
                    verificaLateral=false;
                    controleBraco=false;
                }
            }
        }
        }
    glutPostRedisplay();
    glutTimerFunc(33, GirarBraco, 0);

}

void GirarPescoco(int value) {
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

    glutPostRedisplay();
    glutTimerFunc(33, GirarPescoco, 0);
}
void GirarPescocoFrenteTras(int value) {
    if (girarCabecaTras)
    {
        anguloCabecaX += 3.0;
        if (anguloCabecaX >= 90.0) {
            anguloCabecaX = 90.0;
            girarCabecaTras = false;
            girarCabecaFrente = true;
        }
    } else if (girarCabecaFrente) {
        anguloCabecaX -= 3.0;
        if (anguloCabecaX <= -40.0) {
            anguloCabecaX = 0.0;
            girarCabecaFrente = false;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(33, GirarPescocoFrenteTras, 0);
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
     glutTimerFunc(33, AtualizarAnimacao, 0);

    glutMainLoop();
    return 0;
}
