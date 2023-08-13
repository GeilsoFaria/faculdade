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
float anguloPernaSuperior = 0.0f;
float anguloPernaInferior = 0.0f;
float anguloPernaSuperiorDireita = 0.0f;
float anguloPernaInferiorDireita = 0.0f;
float anguloBracoX =0.0f;
float anguloBracoY=0.0f;
float anguloBracoZ=0.0f;
float posicaoAnimacaoZ = 0.0; // Posição do robô no eixo X
float anguloAgachar=0.0f;
float anguloPular=0.0f;
//int passo = 0; // Contador de passos
float MovimentoPeZ=0.0;
float MovimentoPeDireitaZ=0.0;
//--------Declaração de Funções--------
void GirarBraco(int value);
void GirarCabeca(int value);
void GirarPescoco(int value);
void desenharArticulacao();
void agachar();
bool desceu=false;
int valor=30;
int cont=0;
bool agachou= false;
bool pulou=false;

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
            //desceu=true;
        }
    }
     glutPostRedisplay();
    glutTimerFunc(15, pular, 0);
}
void agachar(int value)
{

    if(agachou == true)
    {
        anguloAgachar += 0.5;
        if (anguloAgachar >= 2.0)
        {
            anguloAgachar = 0.0;
            agachou=false;
            desceu=true;
        }
    }
    /*if (desceu==true && anguloAgachar <=1.0)
    {
        anguloAgachar += 0.1;
        if (anguloAgachar == 1.0)
        {
            anguloAgachar = 1.0;
            //return true;
            agachou= false;
            cont=1;
        }
    }*/
    glutPostRedisplay();
    glutTimerFunc(15, agachar, 0);

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
    float t = 0.2 + 0.3 * sin(valor * 0.03);
    //MovimentoPeZ = t;
    anguloPernaSuperiorDireita = cos(valor * 0.1) * 3.5;  // Simula o movimento da perna esquerda
    anguloPernaInferiorDireita = cos(valor * 0.1 + 3.14) * 40.0;  // Mantém a perna direita reta
    float te = 0.2 + 0.3 * cos(valor * 0.03);
   // MovimentoPeDireitaZ += te;

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
         //glTranslatef(0.0,anguloAgachar,0.0);
       // glRotatef(anguloAgachar,1.0,0.0,0.0);
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
        // glRotatef(-anguloAgachar,0.0,1.0,0.0);
         //glTranslatef(0.0,anguloAgachar,0.0);
          // glRotatef(anguloAgachar, 1.0, 0.0, 0.0);
        glutSolidCube(1.0);
    glPopMatrix();

}
void desenharPernaInferior()
{
    glColor3f(1.0, 0.0, 1.0);
    glPushMatrix();
        glScalef(pernaInferiorX,pernaInferiorY, tamanhoZ);
        //glTranslatef(0.0, 0.0, posicaoRoboZ);
        glRotatef(anguloPernaInferior, 1.0, 0.0, 0.0);  // Aplica a rotação da perna
        glTranslatef(0.0,0.0,MovimentoPeZ);
         // glRotatef(anguloAgachar, 1.0, 0.0, 0.0);
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
          //glTranslatef(0.0,anguloAgachar,0.0);
       // glRotatef(anguloAgachar,1.0,0.0,0.0);
        // glRotatef(anguloAgachar, 1.0, 0.0, 0.0);

        glutSolidCube(1.0);
    glPopMatrix();

}
void desenharPernaInferiorDireita()
{
    glColor3f(0.5, 0.5, 1.0);
    glPushMatrix();
        glScalef(pernaInferiorX,pernaInferiorY, tamanhoZ);
        //glTranslatef(0.0, 0.0, posicaoRoboZ);
        glRotatef(anguloPernaInferiorDireita, 1.0, 0.0, 0.0);  // Aplica a rotação da perna
        glTranslatef(0.0,0.0,MovimentoPeDireitaZ);
         // glRotatef(anguloAgachar, 1.0, 0.0, 0.0);
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
           // glTranslatef(0.0,anguloAgachar,0.0);
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
        //glTranslatef(0.0,anguloAgachar,0.0);
        glutSolidCube(1.0);
    glPopMatrix();
}

void desenharArticulacaoSuperiores()
{
    glPushMatrix();
        glColor3f(0.0,1.0,0.0);
        glTranslatef(anguloBracoX,anguloBracoY,anguloBracoZ);
        //glTranslatef(0.0,anguloAgachar*raioEsfera*2,0.0);
        glutSolidSphere(raioEsfera, 20, 20);
    glPopMatrix();
}
void desenharArticulacao()
{
    glPushMatrix();
        glColor3f(0.0,1.0,0.0);
        glTranslatef(0.0,0.0,MovimentoPeDireitaZ);
        //glTranslatef(0.0,anguloAgachar*raioEsfera*2,0.0);
        glutSolidSphere(raioEsfera, 20, 20);
    glPopMatrix();
}
void desenharClavicula()
{
    glColor3f(0.0, 0.0, 1.0);
    glPushMatrix();
        glScalef(claviculaX, claviculaY, tamanhoZ);
        //glTranslatef(0.0,anguloAgachar,0.0);
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
        //glTranslatef(0.0,0.0,MovimentoPeDireitaZ);
        //glTranslatef(0.0,anguloAgachar,0.0);
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
         //glTranslatef(0.0,0.0,MovimentoPeDireitaZ);
         //glTranslatef(0.0,anguloAgachar,0.0);
        //printf("%f\n", anguloAgachar);

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
        //glTranslatef(0.0,anguloAgachar,0.0);
        //glTranslatef(0,anguloAgachar,0);
        //printf("%f\n", anguloAgachar);
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
   // glPushMatrix();
    //glTranslatef(0.0,anguloAgachar*raioEsfera*2,0.0);
    desenharArticulacao();
    //glPopMatrix();
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
    //glPushMatrix();
    //glTranslatef(0.0,anguloAgachar*raioEsfera*2,0.0);
    desenharArticulacao();
    //glPopMatrix();
    //Braco Superior Esquerdo
    glTranslatef(0.0,-(raioEsfera+bracoSuperiorY/2),0.0);
    desenharBracoSuperior();
    glTranslatef(0.0,-(raioEsfera+bracoSuperiorY/2),0.0);
    desenharArticulacaoSuperiores();
    //Braco Inferior Esquerdo
    glTranslatef(0.0,-(raioEsfera+bracoInferiorY/2),0.0);
    desenharBracoInferior();
    //---BRACO DIREITO ---
    glTranslatef((bracoInferiorX+claviculaX+troncoX+claviculaX/2),(bracoInferiorY+raioEsfera*2+bracoSuperiorX+claviculaY),0.0);
    //Clavicula Direita
    desenharClavicula();
    glTranslatef((claviculaX/2+raioEsfera),0.0,0.0);
    //glPushMatrix();
    //glTranslatef(0.0,anguloAgachar*raioEsfera*2,0.0);
    desenharArticulacao();
    //glPopMatrix();
    glTranslatef(0.0,-(raioEsfera+bracoSuperiorY/2),0.0);
    desenharBracoSuperior();
    glTranslatef(0.0,-(raioEsfera+bracoSuperiorY/2),0.0);
    desenharArticulacaoSuperiores();
    glTranslatef(0.0,-(raioEsfera+bracoInferiorY/2),0.0);
    desenharBracoInferior();


}
void desenharRobo()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef(0.0, 0.0, posicaoAnimacaoZ);
        desenharSuperiores();
        desenharInferiores();
    glPopMatrix();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(40.0,-66.5,40.0);
        glVertex3f(40.0,-66.5,-40.0);
        glVertex3f(-40.0,-66.5,-40.0);
        glVertex3f(-40.0,-66.5,40.0);
    glEnd();
    glutSwapBuffers();
}
void MenuGestos(int op)
{
    switch(op)
    {
        case 0:
            controleBraco=true;
            glutTimerFunc(33, GirarBraco, 0);
            break;
        case 1:
            if (!girandoCabecaEsquerda && !girandoCabecaDireita)
            {
                girandoCabecaEsquerda = true;
                glutTimerFunc(33, GirarCabeca, 0);
            }
            break;
        case 2:
            if (!girandoPescocoTras && !girandoPescocoFrente)
            {
                girandoPescocoTras = true;
                glutTimerFunc(33, GirarPescoco, 0);
            }
            break;
        case 3:
           pulou=true;
            anguloPular=40;
    }

    glutPostRedisplay();
}

// Gerenciamento do menu com as op��es de cores
void MenuCaminhada(int op)
{
   switch(op)
   {
        case 0:
            caminhando=false;
//            passo = 0;
            //posicaoAnimacaoZ = 0.0;
            caminhadaManual(valor);
            valor+=10;
            break;
        case 1:
            caminhando = true;
//            passo = 0;
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
    int menu,submenu1,submenu2;

	submenu1 = glutCreateMenu(MenuCaminhada);
	glutAddMenuEntry("Manualmente",0);
	glutAddMenuEntry("Automatico",1);


    submenu2 = glutCreateMenu(MenuGestos);
	glutAddMenuEntry("Acenar",0);
	glutAddMenuEntry("Mover Cabeca",1);
	glutAddMenuEntry("Mover Pescoco",2);
	glutAddMenuEntry("Pular",3);

    menu = glutCreateMenu(MenuPrincipal);
	glutAddSubMenu("Gestos",submenu2);
    glutAddSubMenu("Caminhar",submenu1);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void GerenciaMouse(int button, int state, int x, int y)
{
    if (button == GLUT_RIGHT_BUTTON)
         if (state == GLUT_DOWN)
            CriaMenu();

    glutPostRedisplay();
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

            //desenharBracoInferior();
            //desenharBracoSuperior();
            controleBraco=true;
            glutTimerFunc(33, GirarBraco, 0);
            break;
        case 'w': // Inicia Para a caminhada
            caminhando = true;
//            passo = 0;
            posicaoAnimacaoZ = 0.0;
            break;
        case 'p':
            caminhando=false;
            break;
         case 'r'://Acenar - a
            anguloBracoX=0.0;
            anguloBracoY=0.0;
            anguloBracoZ=0.0;
            break;
         case 'm':
            caminhadaManual(valor);
            valor+=10;
         case 's':
             agachou=true;
            // glutTimerFunc(33, agachar, 0);
            //agachar();
//            pular();
            break;
        case 'i':
            //agachou=false;
            pulou=true;
            anguloPular=40;
            //glutTimerFunc(33, pular, 0);
            //agachar();

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
    glutTimerFunc(15, agachar, 0);
    glutTimerFunc(15, pular, 0);

    glutMouseFunc(GerenciaMouse);

    glutMainLoop();
    return 0;
}
