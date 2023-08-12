#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define troncoX 10.0
#define troncoY 30.0
#define tamanhoZ 5.0

#define cabecaX 20.0
#define cabecaY 20.0
#define cabecaZ 10.0

#define raioEsfera 5.0

#define pescocoX 10.0
#define pescocoY 10.0

#define claviculaX 20.0
#define claviculaY 5.0

#define bracoSuperiorX 5.0
#define bracoSuperiorY 10.0

#define bracoInferiorX 5.0
#define bracoInferiorY 10.0

#define cinturaX 20.0
#define cinturaY 5.0

#define pernaSuperiorX 5.0
#define pernaSuperiorY 20.0

#define pernaInferiorX 5.0
#define pernaInferiorY 15.0

bool girandoCabecaEsquerda = false;
bool girandoCabecaDireita = false;
bool girandoPescocoFrente = false;
bool girandoPescocoTras = false;
bool verificaLateralBraco=false;
bool controleBraco=true;
bool caminhando = false;
float anguloMovCabecaPescocoY = 0.0f;
float anguloMovCabecaPescocoX = 0.0f;
float anguloPernaEsquerda = 0.0f;
float anguloPernaDireita = 0.0f;
float anguloBracoX =0.0f;
float anguloBracoY=0.0f;
float anguloBracoZ=0.0f;
float posicaoRoboX = 0.0; // Posição do robô no eixo X
int passo = 0; // Contador de passos



//--------Declaração de Funções--------
void GirarBraco(int value);
void GirarCabeca(int value);
void GirarPescoco(int value);
void desenharArticulacao();

//-------------MOVIMENTACAO--------------
void GirarBraco(int value)
{
    if(controleBraco==true)
    {
        anguloBracoY +=10.0;
        anguloBracoZ = 5.0;
        if(anguloBracoY >= bracoInferiorY+raioEsfera*2+bracoSuperiorY+raioEsfera*2)
        {
            anguloBracoY=bracoInferiorY+raioEsfera*2+bracoSuperiorY+raioEsfera*2;
            anguloBracoZ=0;
            if(verificaLateralBraco== false)
            {
                anguloBracoX+=0.5;
                if (anguloBracoX >= 4.0)
                {
                    anguloBracoX=4.0;
                    verificaLateralBraco=true;;
                }
            }
            else if(verificaLateralBraco ==true)
            {
                anguloBracoX-=0.5;
                if (anguloBracoX == -4.0)
                {
                    anguloBracoX=0.0;
                    verificaLateralBraco=false;
                    controleBraco=false;
                }
            }
        }
    }
    glutPostRedisplay();
    glutTimerFunc(100, GirarBraco, 0);
}
void GirarCabeca(int value)
{
    if (girandoCabecaEsquerda)
    {
        anguloMovCabecaPescocoY += 3.0;
        if (anguloMovCabecaPescocoY >= 50.0)
        {
            anguloMovCabecaPescocoY = 50.0;
            girandoCabecaEsquerda = false;
            girandoCabecaDireita = true;
        }
    }
    else if (girandoCabecaDireita)
    {
        anguloMovCabecaPescocoY -= 3.0;
        if (anguloMovCabecaPescocoY <= -50.0)
        {
            anguloMovCabecaPescocoY = 0.0;
            girandoCabecaDireita = false;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(33, GirarCabeca, 0);
}
void GirarPescoco(int value)
{
    if (girandoPescocoTras)
    {
        anguloMovCabecaPescocoX += 3.0;
        if (anguloMovCabecaPescocoX >= 35.0)
        {
            anguloMovCabecaPescocoX = 35.0;
            girandoPescocoTras = false;
            girandoPescocoFrente = true;
        }
    }
    else if (girandoPescocoFrente)
    {
        anguloMovCabecaPescocoX -= 3.0;
        if (anguloMovCabecaPescocoX <= -35.0)
        {
            anguloMovCabecaPescocoX = 0.0;
            girandoPescocoFrente = false;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(33, GirarPescoco, 0);
}
//-------------------$ CAMINHADA $ -------------------
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
void ConcluirPasso(int value)
{
    passo++;
    if (passo < 2) {
        glutTimerFunc(1000, ConcluirPasso, 0);  // Espera 1 segundo antes de dar o próximo passo
    } else {
        PararCaminhada(); // Para a animação após dois passos
    }
}
//-------------------^MOVIMENTACAO^-------------------
void desenharCintura()
{
    glColor3f(1.0, 1.0, 0.0);
    glPushMatrix();
        glScalef(cinturaX,cinturaY,tamanhoZ);
        glutSolidCube(1.0);
    glPopMatrix();
}
void desenharPernaSuperior()
{
    glColor3f(1.0, 0.0, 1.0);
    glPushMatrix();
        glScalef(pernaSuperiorX,pernaSuperiorY,tamanhoZ);
         glRotatef(anguloPernaEsquerda, 1.0, 0.0, 0.0);
        glutSolidCube(1.0);
    glPopMatrix();

}

void desenharPernaInferior()
{
    glColor3f(1.0, 0.0, 1.0);
    glPushMatrix();
        glScalef(pernaInferiorX,pernaInferiorY, tamanhoZ);
        glRotatef(anguloPernaDireita, 1.0, 0.0, 0.0);  // Aplica a rotação da perna
        glutSolidCube(1.0);
    glPopMatrix();

}
void desenharInferiores()
{
    //----INFERIORES----
    //Perna Esquerda
    //glTranslatef(0.0,-troncoY,0.0);

    glTranslatef(0.0,(bracoInferiorY/2+raioEsfera*2+bracoSuperiorY+raioEsfera),0.0);//Volta o eixo para o centro de massa da esfera ao lado da clavívula
    glTranslatef(-(bracoInferiorX+claviculaX+troncoX/2),-(troncoY+cinturaY),0.0);//Posiciona para desenhar a cintura
    glTranslatef(-cinturaX/2,0.0,0.0);//Aqui arrasta o eixo do meio exato da cintura para a metade esquerda

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
void desenharTronco()
{
    glColor3f(1.0, 0.0, 0.0);
    glPushMatrix();
            glScalef(troncoX, troncoY, tamanhoZ);
            glutSolidCube(1.0);
    glPopMatrix();
}
void desenharPescoco()
{
    glColor3f(1.0, 0.0, 0.0);
    glPushMatrix();
        glRotatef(anguloMovCabecaPescocoY,0.0,1.0,0.0);
        glRotatef(anguloMovCabecaPescocoX,1.0,0.0,0.0);
        //glRotatef(anguloPescoco,1.0,0.0,0.0);
        glScalef(pescocoX, pescocoY, tamanhoZ);
        glutSolidCube(1.0);
    glPopMatrix();
}

void desenharArticulacaoSuperiores()
{
    glPushMatrix();
        glColor3f(0.0,1.0,0.0);
        glTranslatef(anguloBracoX,anguloBracoY,anguloBracoZ);
        glutSolidSphere(raioEsfera, 20, 20);
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
        //glTranslatef(anguloBracoLateral,anguloBracoY,angulobracoZ);
        glScalef(claviculaX, claviculaY, tamanhoZ);
        glutSolidCube(1.0);
    glPopMatrix();
}
void desenharBracoSuperior()
{
    glColor3f(0.0, 1.0, 1.0);
    glPushMatrix();
       // glTranslatef(0.0,anguloBracoY,angulobracoZ);
       glTranslatef(anguloBracoX,anguloBracoY,anguloBracoZ);
        glScalef(bracoSuperiorX, bracoSuperiorY, tamanhoZ);
       // glRotatef(anguloPernaDireita, 1.0, 0.0, 0.0);  // Aplica a rotação da perna ao braco

        glutSolidCube(1.0);
    glPopMatrix();
}
void desenharBracoInferior()
{
    glColor3f(0.0, 1.0, 1.0);
    glPushMatrix();
        glTranslatef(anguloBracoX,anguloBracoY,anguloBracoZ);
        glScalef(bracoInferiorX, bracoInferiorY, tamanhoZ);
        //glRotatef(anguloPernaEsquerda, 1.0, 0.0, 0.0);
        glutSolidCube(1.0);
    glPopMatrix();
}

void desenharCabeca()
{
    glColor3f(1.0, 0.0, 1.0);
    glPushMatrix();
        glScalef(cabecaX,cabecaY, cabecaZ);
        glRotatef(anguloMovCabecaPescocoY,0.0,1.0,0.0);
        glRotatef(anguloMovCabecaPescocoX,1.0,0.0,0.0);
        glutSolidCube(1.0);
    glPopMatrix();
}

void desenharSuperiores()
{
    //---TRONCO---
    desenharTronco();
    glTranslatef(0.0, (troncoY/2+raioEsfera), 0.0);
    //---ARTICULAÇÃO PESCOCO---
    desenharArticulacao();
    //---PESCOCO---
    glTranslatef(0.0, (raioEsfera+pescocoY/2), 0.0);
    desenharPescoco();
    //---CABECA---
    glTranslatef(0.0,(pescocoY/2+cabecaY/2),0.0);
    desenharCabeca();

    //---------BRACO ESQUERDO---------
    //---Clavícula Esquerda---
    glTranslatef( -(claviculaX/2+troncoX/2),-((raioEsfera*2+pescocoY+raioEsfera)+claviculaY/2) ,0.0);
    desenharClavicula();
    //---OMBRO ESQUERDO---
    glTranslatef(-(claviculaX/2+raioEsfera),0.0,0.0);
    desenharArticulacao();
    //Braco Superior Esquerdo
    glTranslatef(0.0,-(raioEsfera+bracoSuperiorY/2),0.0);
    //glPushMatrix();
   // glTranslatef(anguloBracoLateral,anguloBraco,angulobracoZ);
    desenharBracoSuperior();
    //glPopMatrix();
    glTranslatef(0.0,-(raioEsfera+bracoSuperiorY/2),0.0);
    //glTranslatef(anguloBracoLateral,anguloBraco,angulobracoZ);
    desenharArticulacaoSuperiores();
    //Braco Inferior Esquerdo
    glTranslatef(0.0,-(raioEsfera+bracoInferiorY/2),0.0);
    //glTranslatef(anguloBracoLateral,anguloBraco,angulobracoZ);
    desenharBracoInferior();
    //glPopMatrix();
    //glTranslatef(0.0,-bracoSuperiorY*2,0);



    //---BRACO DIREITO ---
    glTranslatef((bracoInferiorX+claviculaX+troncoX+claviculaX/2),(bracoInferiorY+raioEsfera*2+bracoSuperiorX+claviculaY),0.0);
    //Clavicula Direita
    desenharClavicula();
    glTranslatef((claviculaX/2+raioEsfera),0.0,0.0);
    desenharArticulacao();
   // glPushMatrix();
    //glTranslatef(0.0,anguloBraco,angulobracoZ);
    glTranslatef(0.0,-(raioEsfera+bracoSuperiorY/2),0.0);
    desenharBracoSuperior();
    glTranslatef(0.0,-(raioEsfera+bracoSuperiorY/2),0.0);
    //glTranslatef(0.0,anguloBraco,angulobracoZ);
    desenharArticulacaoSuperiores();
    glTranslatef(0.0,-(raioEsfera+bracoInferiorY/2),0.0);
     //glTranslatef(0.0,anguloBraco,angulobracoZ);
    desenharBracoInferior();
    //glPopMatrix();
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
void Teclado(unsigned char tecla, int x, int y)
{
    switch (tecla)
    {
        case 27:
        case 'q':
            exit(0);
            break;
         //Girar Cabeca(HEAD - h)
        case 'h':
            if (!girandoCabecaEsquerda && !girandoCabecaDireita)
            {
                girandoCabecaEsquerda = true;
                glutTimerFunc(33, GirarCabeca, 0);
            }
            break;
        //Girar Pescoco(NECK - n)
        case 'n':
            if (!girandoPescocoTras && !girandoPescocoFrente)
            {
                girandoPescocoTras = true;
                glutTimerFunc(33, GirarPescoco, 0);
            }
            break;
        case 'a'://Acenar - a
            //anguloBracoX=0.0;
            //anguloBracoY=0.0;
            //anguloBracoZ=0.0;
            //desenharBracoInferior();
            //desenharBracoSuperior();
            controleBraco=true;
            glutTimerFunc(33, GirarBraco, 0);
            break;
        case 'w': // Inicia Para a caminhada
            caminhando = true;
            passo = 0;
            posicaoRoboX = 0.0;
            break;
        case 'p':
            caminhando=false;
            break;
    }
}
void resize(int w, int h)
{
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
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Robô 3D com 9 articulações");
    glutReshapeFunc(resize);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(desenharRobo);
    glutKeyboardFunc (Teclado);
    glutTimerFunc(33, AtualizarAnimacao, 0);

    glutMainLoop();
    return 0;
}
