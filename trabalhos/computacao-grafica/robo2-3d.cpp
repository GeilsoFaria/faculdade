/* Aluno: Geilso Faria Rodrigues da Silva

Projeto desenvolvido na disciplina de Computação Grafica, que
simula a movimentacao e gesticulacao de um boneco 3D.

Para o usar a movimentacao e gesticulacao eh possivel usando
teclas sendo que:

    Tecla 'f'= Festejar simula o movimento dos bracos
    Tecla 'h'= movimentar cabeca(horizontalmente)
    Tecla 'm'= caminhada manual
    Tecla 'n'= movimentar pescoco(verticalmente)
    Tecla 't'= Dar tchau
    Tecla 'r'= Reseta os valores da animacao
    Tecla 'q'= encerra a animacao
    Tecla 'w'= caminhar automaticamente
    Tecla 'p'= Pular

Como também usando o menu criado, para isso clique com o
botão direito do mouse duas vezes sobre a animacao:
    No menu 'Gestos' voce poderá selecionar clicando nos seguintes campos:
        1.Festejar (maos)
        2.Mover Cabeca
        3.Mover Pescoco
        4.Pular
        5.Dar Tchau
    No menu 'Caminhar' voce podera selecionar clicando nos seguintes campos:
        1.Manualmente (Cada clique sobre esse icone equivale a um passo)
        2.Automatico (O boneco caminhara sozinho)
*/

//Inclusao de Bibliotecas necessárias
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//Definição de constantes para escalas no eixo (X,Y,Z) dos cubos e para o valor das articulações
#define raioEsfera 5.0

#define troncoX 10.0
#define troncoY 30.0
#define tamanhoZ 5.0 // Mesmo valor de Z para escala Z dos cubos, exceto para cabeca

#define cabecaX 20.0
#define cabecaY 20.0
#define cabecaZ 10.0

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

//Variaveis globais para o controle do movimentos, caminhada e gesticulacao

//Controle para giro da cabeca
bool girandoCabecaEsquerda = false;//Verificar se a cabeca ja girou para esquerda
bool girandoCabecaDireita = false;//Verificar se a cabeca ja girou para direita

//Controle para giro do pescoco
bool girandoPescocoFrente = false;//Verificar se o pescoco ja girou para Frente
bool girandoPescocoTras = false;//Verificar se o pescoco ja girou para Tras
float anguloMovCabecaPescocoY = 0.0f;//Atualiza o angulo de movimentacao do pescoco
float anguloMovCabecaPescocoX = 0.0f;//Atualiza o angulo de movimentacao do pescoco

//Controle de gestos com os bracos

bool verificaLateralBraco=false;//Verificar se o braco ja girou lateralmente
bool controleBraco=true;//Verificar se tem movimentacao no braco
bool controleBracoTchau=true;//Verificar se tem movimentacao no braco para acenar 'Dar Tchau'
float anguloBracoX =0.0f;//Angulo para atualizar o braco em X
float anguloBracoY=0.0f;//Angulo para atualizar o braco em Y
float anguloBracoZ=0.0f;//Angulo para atualizar o braco em Z
float anguloBracoXTchau =0.0f;//Angulo para atualizar o braco para acenar 'Dar Tchau'em X
float anguloBracoYTchau=0.0f;//Angulo para atualizar o braco para acenar 'Dar Tchau'em Y
float anguloBracoZTchau=0.0f;//Angulo para atualizar o braco para acenar 'Dar Tchau'em Z

//Controle de caminhada
bool caminhando = false;//Verificar se o boneco ja esta caminhando
float MovimentoPeZ=0.0;//Simula o movimento de um pe diferente no eixo Z
float MovimentoPeDireitaZ=0.0;//Simula o movimento de um pe diferente no eixo Z
float posicaoAnimacaoZ = 0.0; //Atualiza Posição do boneco no Eixo Z
float anguloPernaSuperior = 0.0f;//Atualiza o angulo da perna na parte superior
float anguloPernaInferior = 0.0f;//Atualiza o angulo da perna na parte inferior
float anguloPernaSuperiorDireita = 0.0f;//Atualiza o angulo da perna na parte superior direita
float anguloPernaInferiorDireita = 0.0f;//Atualiza o angulo da perna na parte inferior direita
int valor=30;//Valor para incrementar caminhada manual

//Controle de pulo
float anguloPular=0.0f;//Atualiza o gesto 'pular' no eixo Y
bool pulou=false;//Verificar se o boneco ja pulou

//--------Declaração de Funções--------
void GirarBraco(int value);
void GirarCabeca(int value);
void GirarPescoco(int value);
void desenharArticulacao();
void Resetar();


//-------------MOVIMENTACAO--------------
void pular(int value)
{
    if(pulou == true)
    {
        anguloPular -= 0.5;
        if (anguloPular <= -2.0)
        {
            anguloPular = 0.0;
            pulou=false;
        }
    }
     glutPostRedisplay();
    glutTimerFunc(15, pular, 0);
}
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
void darTchau(int value)
{
    if(controleBracoTchau==true)
    {
        anguloBracoYTchau +=10.0;
        anguloBracoZTchau= 5.0;
        if(anguloBracoYTchau >= bracoInferiorY+raioEsfera*2+bracoSuperiorY+raioEsfera*2)
        {
            anguloBracoYTchau=bracoInferiorY+raioEsfera*2+bracoSuperiorY+raioEsfera*2;
            anguloBracoZTchau=0;
            if(verificaLateralBraco== false)
            {
                anguloBracoXTchau+=0.5;
                if (anguloBracoXTchau >= 4.0)
                {
                    anguloBracoXTchau=4.0;
                    verificaLateralBraco=true;;
                }
            }
            else if(verificaLateralBraco ==true)
            {
                anguloBracoXTchau-=0.5;
                if (anguloBracoXTchau == -4.0)
                {
                    anguloBracoXTchau=0.0;
                    verificaLateralBraco=false;
                    controleBracoTchau=false;
                }
            }
        }
    }
    glutPostRedisplay();
    glutTimerFunc(100, darTchau, 0);
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
void caminhadaManual(int valor)
{
    anguloPernaSuperior = sin(valor * 0.1) * 3.5;  // Simula o movimento da perna esquerda
    anguloPernaInferior = sin(valor * 0.1 + 3.14) * 40.0;  // Mantém a perna direita reta
    anguloPernaSuperiorDireita = cos(valor * 0.1) * 3.5;  // Simula o movimento da perna esquerda
    anguloPernaInferiorDireita = cos(valor * 0.1 + 3.14) * 40.0;  // Mantém a perna direita reta
    posicaoAnimacaoZ += 5.0; // Ajuste a velocidade de movimento conforme necessário
    glutPostRedisplay();
}
void AtualizarAnimacao(int value)
{
    // Atualiza o ângulo das pernas de acordo com o passo atual
    if (caminhando)
    {
        anguloPernaSuperior = sin(value * 0.1) * 0.5;  // Simula o movimento da perna esquerda
        anguloPernaInferior = sin(value * 0.1 + 3.14) * 10.0;  // Mantém a perna direita reta
        float t = 0.2 + 0.3 * sin(value * 0.03);
        MovimentoPeZ = t;
        posicaoAnimacaoZ += 0.05; // Ajuste a velocidade de movimento conforme necessário
    }
    glutPostRedisplay();
    glutTimerFunc(15, AtualizarAnimacao, value + 1);
}
void AtualizarAnimacaoDireita(int value)
{
    if (caminhando)
    {
        anguloPernaSuperiorDireita = cos(value * 0.1) * 0.5;  // Simula o movimento da perna esquerda
        anguloPernaInferiorDireita = cos(value * 0.1 + 3.14) * 10.0;  // Mantém a perna direita reta
        float t = 0.2 + 0.3 * cos(value * 0.03);
        MovimentoPeDireitaZ = t;
    }
    glutPostRedisplay();
    glutTimerFunc(15, AtualizarAnimacaoDireita, value + 1);
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
        glTranslatef(0.0,0.0,MovimentoPeZ);
         glRotatef(anguloPernaSuperior, 1.0, 0.0, 0.0);
        glutSolidCube(1.0);
    glPopMatrix();
}
void desenharPernaInferior()
{
    glColor3f(1.0, 0.0, 1.0);
    glPushMatrix();
        glScalef(pernaInferiorX,pernaInferiorY, tamanhoZ);
        glRotatef(anguloPernaInferior, 1.0, 0.0, 0.0);  // Aplica a rotação da perna
        glTranslatef(0.0,0.0,MovimentoPeZ);
        glutSolidCube(1.0);
    glPopMatrix();
}
void desenharPernaSuperiorDireita()
{
    glColor3f(0.5, 0.5, 1.0);
    glPushMatrix();
        glScalef(pernaSuperiorX,pernaSuperiorY,tamanhoZ);
        glRotatef( anguloPernaSuperiorDireita , 1.0, 0.0, 0.0);
        glTranslatef(0.0,0.0,MovimentoPeDireitaZ);
        glutSolidCube(1.0);
    glPopMatrix();
}
void desenharPernaInferiorDireita()
{
    glColor3f(0.5, 0.5, 1.0);
    glPushMatrix();
        glScalef(pernaInferiorX,pernaInferiorY, tamanhoZ);
        glRotatef(anguloPernaInferiorDireita, 1.0, 0.0, 0.0);  // Aplica a rotação da perna
        glTranslatef(0.0,0.0,MovimentoPeDireitaZ);
        glutSolidCube(1.0);
    glPopMatrix();
}
void desenharInferiores()
{
    //----INFERIORES----
    //Perna Esquerda
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
    desenharPernaSuperiorDireita();
    glTranslatef(0.0,-(raioEsfera+pernaSuperiorY/2),0.0);
    desenharArticulacao();
    glTranslatef(0.0,-(raioEsfera+pernaInferiorY/2),0.0);
    desenharPernaInferiorDireita();
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
        glScalef(pescocoX, pescocoY, tamanhoZ);
        glutSolidCube(1.0);
    glPopMatrix();
}

void desenharArticulacaoSuperiores()
{
    glPushMatrix();
        glColor3f(0.0,1.0,0.0);
        glTranslatef(anguloBracoX,anguloBracoY,anguloBracoZ);
         glTranslatef(anguloBracoXTchau,anguloBracoYTchau,anguloBracoZTchau);
        glutSolidSphere(raioEsfera, 20, 20);
    glPopMatrix();
}
void desenharArticulacaoSuperioresDireito()
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
        glTranslatef(0.0,0.0,MovimentoPeDireitaZ);
        glutSolidSphere(raioEsfera, 20, 20);
    glPopMatrix();
}
void desenharClavicula()
{
    glColor3f(0.0, 0.0, 1.0);
    glPushMatrix();
        glScalef(claviculaX, claviculaY, tamanhoZ);
        glutSolidCube(1.0);
    glPopMatrix();
}
void desenharBracoSuperior()
{
    glColor3f(0.0, 1.0, 1.0);
    glPushMatrix();
       glTranslatef(anguloBracoX,anguloBracoY,anguloBracoZ);
        glScalef(bracoSuperiorX, bracoSuperiorY, tamanhoZ);
        glRotatef(anguloPernaSuperior, 1.0, 0.0, 0.0);
        glutSolidCube(1.0);
    glPopMatrix();
}
void desenharBracoSuperiorEsquerdo()
{
    glColor3f(0.0, 1.0, 1.0);
    glPushMatrix();
       glTranslatef(anguloBracoX,anguloBracoY,anguloBracoZ);
       glTranslatef(anguloBracoXTchau,anguloBracoYTchau,anguloBracoZTchau);
        glScalef(bracoSuperiorX, bracoSuperiorY, tamanhoZ);
        glRotatef(anguloPernaSuperior, 1.0, 0.0, 0.0);
        glutSolidCube(1.0);
    glPopMatrix();
}
void desenharBracoInferior()
{
    glColor3f(0.0, 1.0, 1.0);
    glPushMatrix();
        glTranslatef(anguloBracoX,anguloBracoY,anguloBracoZ);
        glScalef(bracoInferiorX, bracoInferiorY, tamanhoZ);
         glRotatef(anguloPernaInferior, 1.0, 0.0, 0.0);  // Aplica a rotação da perna
        glutSolidCube(1.0);
    glPopMatrix();
}

void desenharBracoInferiorEsquerdo()
{
    glColor3f(0.0, 1.0, 1.0);
    glPushMatrix();
        glTranslatef(anguloBracoX,anguloBracoY,anguloBracoZ);
        glTranslatef(anguloBracoXTchau,anguloBracoYTchau,anguloBracoZTchau);
        glScalef(bracoInferiorX, bracoInferiorY, tamanhoZ);
        glRotatef(anguloPernaInferior, 1.0, 0.0, 0.0);  // Aplica a rotação da perna
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
    glTranslatef(0,anguloPular,0);
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
    desenharBracoSuperiorEsquerdo();
    glTranslatef(0.0,-(raioEsfera+bracoSuperiorY/2),0.0);
    desenharArticulacaoSuperiores();
    //Braco Inferior Esquerdo
    glTranslatef(0.0,-(raioEsfera+bracoInferiorY/2),0.0);
    desenharBracoInferiorEsquerdo();
    //---BRACO DIREITO ---
    glTranslatef((bracoInferiorX+claviculaX+troncoX+claviculaX/2),(bracoInferiorY+raioEsfera*2+bracoSuperiorX+claviculaY),0.0);
    //Clavicula Direita
    desenharClavicula();
    glTranslatef((claviculaX/2+raioEsfera),0.0,0.0);
    desenharArticulacao();
    glTranslatef(0.0,-(raioEsfera+bracoSuperiorY/2),0.0);
    desenharBracoSuperior();
    glTranslatef(0.0,-(raioEsfera+bracoSuperiorY/2),0.0);
    desenharArticulacaoSuperioresDireito();
    glTranslatef(0.0,-(raioEsfera+bracoInferiorY/2),0.0);
    desenharBracoInferior();
}
void desenharRobo()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix(); //Usar PushMatriz() e PopMatriz() para que conforme ele seja redesenhado, ele ser redesenhado conforme a posição original
        glTranslatef(0.0, 0.0, posicaoAnimacaoZ);
        desenharSuperiores();
        desenharInferiores();
    glPopMatrix();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(40.0,-66.5,50.0);
        glVertex3f(40.0,-66.5,-50.0);
        glVertex3f(-40.0,-66.5,-50.0);
        glVertex3f(-40.0,-66.5,50.0);
    glEnd();
    glutSwapBuffers();
}
void Resetar()
{
    anguloBracoXTchau=0;
    anguloBracoYTchau=0;
    anguloBracoZTchau=0;
    anguloBracoX=0;
    anguloBracoY=0;
    anguloBracoZ=0;
    controleBracoTchau=false;
    posicaoAnimacaoZ = 0.0;
    caminhando=false;
    valor=30;
    MovimentoPeZ=0.0;
    MovimentoPeDireitaZ=0.0;
    posicaoAnimacaoZ = 0.0;
    anguloPernaSuperior = 0.0f;
    anguloPernaInferior = 0.0f;
    anguloPernaSuperiorDireita = 0.0f;
    anguloPernaInferiorDireita = 0.0f;

}
void MenuGestos(int op)
{
    switch(op)
    {
        case 0:
            Resetar();
            controleBraco=true;
            glutTimerFunc(33, GirarBraco, 0);
            break;
        case 1:
            Resetar();
            if (!girandoCabecaEsquerda && !girandoCabecaDireita)
            {
                girandoCabecaEsquerda = true;
                glutTimerFunc(33, GirarCabeca, 0);
            }
            break;
        case 2:
            Resetar();
            if (!girandoPescocoTras && !girandoPescocoFrente)
            {
                girandoPescocoTras = true;
                glutTimerFunc(33, GirarPescoco, 0);
            }
            break;
        case 3:
            Resetar();
           pulou=true;
            anguloPular=40;
            break;
        case 4:
            //anguloBracoXTchau=0;
            //anguloBracoYTchau=0;
            //anguloBracoZTchau=0;
           // anguloBracoX=0;
            //anguloBracoY=0;
            //anguloBracoZ=0;
            Resetar();
            controleBracoTchau=true;
            glutTimerFunc(33, darTchau, 0);
            break;
    }

    glutPostRedisplay();
}

// Gerenciamento do menu caminhada
void MenuCaminhada(int op)
{
   switch(op)
   {
        case 0:
            caminhando=false;
            caminhadaManual(valor);
            valor+=10;
            break;
        case 1:
            caminhando = true;
            posicaoAnimacaoZ = 0.0;
            break;
    }
    glutPostRedisplay();
}

// Gerenciamento do menu principal
void MenuPrincipal(int op)
{
}

// Criacao do Menu
void CriaMenu()
{
    int menu,submenu1,submenu2,submenu3;

	submenu1 = glutCreateMenu(MenuCaminhada);
	glutAddMenuEntry("Manualmente",0);
	glutAddMenuEntry("Automatico",1);

    submenu2 = glutCreateMenu(MenuGestos);
	glutAddMenuEntry("Festejar (Maos)",0);
	glutAddMenuEntry("Mover Cabeca",1);
	glutAddMenuEntry("Mover Pescoco",2);
	glutAddMenuEntry("Pular",3);
	glutAddMenuEntry("Dar Tchau",4);



    menu = glutCreateMenu(MenuPrincipal);
	glutAddSubMenu("Caminhar",submenu1);
	glutAddSubMenu("Gestos",submenu2);


	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
//Gerenciamento do Mouse
void GerenciaMouse(int button, int state, int x, int y)
{
    if (button == GLUT_RIGHT_BUTTON)
         if (state == GLUT_DOWN)
            CriaMenu();
    if(button ==GLUT_LEFT_BUTTON)
    {
        anguloBracoX=0;
        anguloBracoY=0;
        anguloBracoZ=0;
    }
    glutPostRedisplay();
}
//Gerenciamento do Teclado
void Teclado(unsigned char tecla, int x, int y)
{
    switch (tecla)
    {
        //festejar - f
        case 'f':
            Resetar();
            controleBraco=true;
            glutTimerFunc(33, GirarBraco, 0);
            break;

         //Girar Cabeca(HEAD - h)
        case 'h':
            Resetar();
            if (!girandoCabecaEsquerda && !girandoCabecaDireita)
            {
                girandoCabecaEsquerda = true;
                glutTimerFunc(33, GirarCabeca, 0);
            }
            break;

        //Manual - m
        case 'm':
            caminhadaManual(valor);
            valor+=10;
            break;

         //Girar Pescoco(NECK - n)
        case 'n':
            Resetar();
            if (!girandoPescocoTras && !girandoPescocoFrente)
            {
                girandoPescocoTras = true;
                glutTimerFunc(33, GirarPescoco, 0);
            }
            break;
        //Tchau - t
        case 't':
            Resetar();
            controleBracoTchau=true;
            glutTimerFunc(33, darTchau, 0);
            break;

        //Reset - r
        case 'r':
            Resetar();
            break;

        //Quit - q
        case 27:
        case 'q':
            exit(0);
            break;

        // Walking (caminhando) - w
        case 'w':
            Resetar();
            caminhando = true;
            posicaoAnimacaoZ = 0.0;
            break;

        //Pular - p
        case 'p':
            Resetar();
            pulou=true;
            anguloPular=40;
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
    gluLookAt(-40.0, 0.0, 60.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Robô 3D com 9 articulações");
    glutReshapeFunc(resize);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(desenharRobo);
    glutKeyboardFunc (Teclado);
    glutTimerFunc(33, AtualizarAnimacao, 0);
    glutTimerFunc(33, AtualizarAnimacaoDireita, 0);
    glutTimerFunc(15, pular, 0);
    glutMouseFunc(GerenciaMouse);
    glutMainLoop();
    return 0;
}
