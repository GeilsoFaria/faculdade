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
#include <GL/glut.h>//Biblioteca Grafica
#endif
#include <stdlib.h>
#include <stdio.h>
#include <math.h>//Usado para o calculo de seno e cosseno

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


void pular(int value)
{
    if(pulou == true)//Se a variavel pulou eh setada como true comeca a animacao
    {
        anguloPular -= 0.5;//Decrementa pois para o pulo o eixo Y ja sofre uma translacao positiva
        if (anguloPular <= -2.0)
        {
            anguloPular = 0.0;
            pulou=false;//Verifica se ja atingiu o valor -2.0 e seta a variavel pulou como falsa
        }
    }
     glutPostRedisplay();
    glutTimerFunc(15, pular, 0);//Funcao espera 15 milissegundos antes de usar uma recursao com ela mesmo
}
void GirarBraco(int value)
{
    if(controleBraco==true)//Se a variavel controleBraco eh setada como true comeca a animacao
    {
        anguloBracoY +=10.0;//Atualiza a movimentacao em no eixo Y de 10 em 10
        anguloBracoZ = raioEsfera;//Mantem o valor padrao em Z, para simular o movimento em torno da esfera
        if(anguloBracoY >= bracoInferiorY+raioEsfera*2+bracoSuperiorY+raioEsfera*2)//Verifica se o braco em Y ja nao atingiu a posicao deseja com a movimentacao
        {
            anguloBracoY=bracoInferiorY+raioEsfera*2+bracoSuperiorY+raioEsfera*2;//Se atingiu seta essa posicao desejada
            anguloBracoZ=0;//Seta o movimento em Z=0, pois nao tem mais movimento em torna da esfera
            if(verificaLateralBraco== false)//Se a lateral do braco eh false comeca a animacao de mover para os lados
            {
                anguloBracoX+=0.5;
                if (anguloBracoX >= 4.0)//Se atingiu o movimento em um lado muda a variavel verificaLateralBraco
                {
                    anguloBracoX=4.0;
                    verificaLateralBraco=true;;
                }
            }
            else if(verificaLateralBraco ==true)//Se a variavel verificaLateralBraco foi mudada comeca o movimento para o outro lado
            {
                anguloBracoX-=0.5;
                if (anguloBracoX == -4.0)
                {
                    anguloBracoX=0.0;
                    verificaLateralBraco=false;//terminando o movimento nos dois lados seta como false ambas as variaveis de controle
                    controleBraco=false;//terminando o movimento nos dois lados seta como false ambas as variaveis de controle
                }
            }
        }
    }
    glutPostRedisplay();
    glutTimerFunc(100, GirarBraco, 0);//Funcao espera 100 milissegundos antes de usar uma recursao com ela mesmo
}
//Simulacao de Tchau braco esquerdo
void darTchau(int value)
{
    if(controleBracoTchau==true)
    {
        anguloBracoYTchau +=10.0;//Atualiza a movimentacao em no eixo Y de 10 em 10
        anguloBracoZTchau= raioEsfera;//Mantem o valor padrao em Z, para simular o movimento em torno da esfera
        if(anguloBracoYTchau >= bracoInferiorY+raioEsfera*2+bracoSuperiorY+raioEsfera*2)//Verifica se o braco em Y ja nao atingiu a posicao deseja com a movimentacao
        {
            anguloBracoYTchau=bracoInferiorY+raioEsfera*2+bracoSuperiorY+raioEsfera*2;//Se atingiu seta essa posicao desejada
            anguloBracoZTchau=0;//Seta o movimento em Z=0, pois nao tem mais movimento em torna da esfera
            if(verificaLateralBraco== false)//Se a lateral do braco eh false comeca a animacao de mover para os lados do braco esquerdo
            {
                anguloBracoXTchau+=0.5;
                if (anguloBracoXTchau >= 4.0)//Se atingiu o movimento em um lado muda a variavel verificaLateralBraco
                {
                    anguloBracoXTchau=4.0;
                    verificaLateralBraco=true;;
                }
            }
            else if(verificaLateralBraco ==true)//Se a variavel verificaLateralBraco foi mudada comeca o movimento para o outro lado
            {
                anguloBracoXTchau-=0.5;
                if (anguloBracoXTchau == -4.0)
                {
                    anguloBracoXTchau=0.0;
                    verificaLateralBraco=false;//terminando o movimento nos dois lados seta como false ambas as variaveis de controle
                    controleBracoTchau=false;//terminando o movimento nos dois lados seta como false ambas as variaveis de controle
                }
            }
        }
    }
    glutPostRedisplay();
    glutTimerFunc(100, darTchau, 0);//Funcao espera 100 milissegundos antes de usar uma recursao com ela mesmo
}
void GirarCabeca(int value)
{
    if (girandoCabecaEsquerda)//Verifica se a cabeca esta apta a girar pra esquerda
    {
        anguloMovCabecaPescocoY += 3.0;//Atualiza o movimento de girar a cabeca de 3 em 3
        if (anguloMovCabecaPescocoY >= 50.0)//Se atingiu o valor desejado para um lado, seta ele e gira pro outro
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
    glutTimerFunc(33, GirarCabeca, 0);//Funcao espera 33 milissegundos antes de usar uma recursao com ela mesmo
}
void GirarPescoco(int value)
{
    if (girandoPescocoTras)//Verifica se o pescoco esta apto a girar pra tras
    {
        anguloMovCabecaPescocoX += 3.0;//Atualiza o movimento de girar a cabeca de 3 em 3
        if (anguloMovCabecaPescocoX >= 35.0)//Se atingiu o valor desejado para um lado, seta ele e gira pro outro
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
    glutTimerFunc(33, GirarPescoco, 0);//Funcao espera 33 milissegundos antes de usar uma recursao com ela mesmo
}
//Funcao que sera chamada quando o usuario iniciar uma caminhada manual, passo a passo do boneco

void caminhadaManual(int valor)//valor que será incrementando conforme os passos para o movimento no eixo Z das pernas e do boneco
{
    //Perna Esquerda usando seno e direita usando para simular a caminhada em diferentes fases, enquanto uma esta realizando um
    //movimento na posicao da onda senoidal a outra esta realizando o inverso devido ao cosseno

    //(valor *0.1) ou (valor*0.1+ 3.14) para que o movimento seja atualizado aos poucos
    anguloPernaSuperior = sin(valor * 0.1) * 3.5;  // Simula o movimento da perna superior esquerda
    anguloPernaInferior = sin(valor * 0.1 + 3.14) * 40.0;  // Simula o movimento da perna inferior esquerda
    anguloPernaSuperiorDireita = cos(valor * 0.1) * 3.5; // Simula o movimento da perna superior direita
    anguloPernaInferiorDireita = cos(valor * 0.1 + 3.14) * 40.0;  // Simula o movimento da perna inferior direita
    posicaoAnimacaoZ += 5.0; // Ajuste do deslocamento do boneco no eixo Z
    glutPostRedisplay();//Atualiza a animacao
}
//Atualiza a animacao da perna esquerda
void AtualizarAnimacao(int value)
{
    if (caminhando)//Se caminhando eh setado como true comeca a simulacao de caminhada
    {
        anguloPernaSuperior = sin(value * 0.1) * 0.5;  // Simula o movimento da perna superior esquerda, com o uso de seno
        anguloPernaInferior = sin(value * 0.1 + 3.14) * 10.0;  // Simula o movimento da perna inferior esquerda, com o uso de seno
        float t = 0.2 + 0.3 * sin(value * 0.03);//Uso de seno
        MovimentoPeZ = t;//Variavel para a movimentacao do pe esquerdo
        posicaoAnimacaoZ += 0.05;  // Ajuste do deslocamento do boneco no eixo Z
    }
    glutPostRedisplay();
    glutTimerFunc(15, AtualizarAnimacao, value + 1);//Funcao espera 15 milissegundos incrementa mais 1
                                                    // antes de usar uma recursao com ela mesmo para que ocorra a atualizacao da animacao
}
//Atualiza a animacao da perna direita
void AtualizarAnimacaoDireita(int value)
{
    if (caminhando)//Caminhando setado como true em ambas as funcoes de atualizar animacao comeca a simulacao da perna direita tambem
    {
        anguloPernaSuperiorDireita = cos(value * 0.1) * 0.5;  // Simula o movimento da perna superior direita, com o uso
                                                            //de cosseno faz com que ambas as pernas fiquem em fase diferentes
        anguloPernaInferiorDireita = cos(value * 0.1 + 3.14) * 10.0;  // Simula o movimento da perna inferior esquerda, com o uso de cosseno
        float t = 0.2 + 0.3 * cos(value * 0.03);//Uso de cosseno
        MovimentoPeDireitaZ = t;//Variavel para a movimentacao do pe direito
    }
    glutPostRedisplay();
    glutTimerFunc(15, AtualizarAnimacaoDireita, value + 1);//Funcao espera 15 milissegundos incrementa mais 1
                                                    // antes de usar uma recursao com ela mesmo para que ocorra a atualizacao da animacao
}
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
        glTranslatef(0.0,0.0,MovimentoPeZ);//Simular o movimento da perna Superior esquerda em Z
         glRotatef(anguloPernaSuperior, 1.0, 0.0, 0.0);
        glutSolidCube(1.0);
    glPopMatrix();
}
void desenharPernaInferior()
{
    glColor3f(1.0, 0.0, 1.0);
    glPushMatrix();
        glScalef(pernaInferiorX,pernaInferiorY, tamanhoZ);
        glRotatef(anguloPernaInferior, 1.0, 0.0, 0.0);  // Aplica rotação em X a parte inferior da perna
        glTranslatef(0.0,0.0,MovimentoPeZ);//Simular o movimento do pe esquerdo em Z
        glutSolidCube(1.0);
    glPopMatrix();
}
void desenharPernaSuperiorDireita()
{
     glColor3f(1.0, 0.0, 1.0);
    glPushMatrix();
        glScalef(pernaSuperiorX,pernaSuperiorY,tamanhoZ);
        glRotatef( anguloPernaSuperiorDireita , 1.0, 0.0, 0.0);// Aplica rotação em X a parte inferior da perna
        glTranslatef(0.0,0.0,MovimentoPeDireitaZ);//Simular o movimento da perna Superior direita em Z
        glutSolidCube(1.0);
    glPopMatrix();
}
void desenharPernaInferiorDireita()
{
     glColor3f(1.0, 0.0, 1.0);
    glPushMatrix();
        glScalef(pernaInferiorX,pernaInferiorY, tamanhoZ);
        glRotatef(anguloPernaInferiorDireita, 1.0, 0.0, 0.0); // Aplica rotação em X a parte inferior da perna
        glTranslatef(0.0,0.0,MovimentoPeDireitaZ);//Simular o movimento do pe direito em Z
        glutSolidCube(1.0);
    glPopMatrix();
}
void desenharInferiores()
{
    //Perna Esquerda
    glTranslatef(0.0,(bracoInferiorY/2+raioEsfera*2+bracoSuperiorY+raioEsfera),0.0);//Volta o eixo y (antigamente no braco inferior direita para o centro da clavicula
    glTranslatef(-(bracoInferiorX+claviculaX+troncoX/2),-(troncoY+cinturaY),0.0);//Posiciona a partir da clavicula em X para desenhar a cintura
    glTranslatef(-cinturaX/2,0.0,0.0);//Aqui arrasta o eixo do meio exato da cintura para a metade esquerda
    desenharCintura();
    glTranslatef(-(cinturaX/2-raioEsfera),-(cinturaY+raioEsfera/2),0.0);//Translada para o centro da articulacao da perna esquerda
    desenharArticulacao();
    glTranslatef(0.0,-(raioEsfera+pernaSuperiorY/2),0.0);//Translada para o meio da perna superior esquerda
    desenharPernaSuperior();
    glTranslatef(0.0,-(raioEsfera+pernaSuperiorY/2),0.0);//Translada para o centro da articulacao inferior da perna esquerda
    desenharArticulacao();
    glTranslatef(0.0,-(raioEsfera+pernaInferiorY/2),0.0);//Translada para o meio da perna inferior esquerda
    desenharPernaInferior();

    //Perna Direita
    glTranslatef(raioEsfera,(pernaInferiorY+raioEsfera*2+pernaSuperiorY+cinturaY),0.0);//Translada em X o raio da esfera e em Y volta para a
                                                                                        //base da cintura
    glTranslatef(cinturaX,0.0,0.0);//Translada para meio da cintura direita
    desenharCintura();
    glTranslatef((cinturaX/2-raioEsfera),-(cinturaY+raioEsfera/2),0.0);//Translada para o centro da articulacao da perna direita
    desenharArticulacao();
    glTranslatef(0.0,-(raioEsfera+pernaSuperiorY/2),0.0);//Translada para o meio da perna superior direita
    desenharPernaSuperiorDireita();
    glTranslatef(0.0,-(raioEsfera+pernaSuperiorY/2),0.0);//Translada para o centro da articulacao inferior da perna direita
    desenharArticulacao();
    glTranslatef(0.0,-(raioEsfera+pernaInferiorY/2),0.0);//Translada para o meio da perna inferior direita
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
        glRotatef(anguloMovCabecaPescocoY,0.0,1.0,0.0);//Rotacao do pescoco em Y, sendo incrementa ao chamar a funcao para girar o pescoco
        glRotatef(anguloMovCabecaPescocoX,1.0,0.0,0.0);//Rotacao do pescoco em X, sendo incrementa ao chamar a funcao para girar o pescoco
        glScalef(pescocoX, pescocoY, tamanhoZ);
        glutSolidCube(1.0);
    glPopMatrix();
}

void desenharArticulacaoSuperiores()
{
    glPushMatrix();
        glColor3f(0.0,1.0,0.0);
        glTranslatef(anguloBracoX,anguloBracoY,anguloBracoZ);//Translacao das articulacoes do ombro,
                                                            //sendo incrementa ao chamar a funcao para movimentar os bracos
        glTranslatef(anguloBracoXTchau,anguloBracoYTchau,anguloBracoZTchau);//Translacao das articulacoes do ombro,
                                                            //sendo incrementa ao chamar a funcao para movimentar os bracos para 'dar Tchau'
        glutSolidSphere(raioEsfera, 20, 20);
    glPopMatrix();
}
void desenharArticulacaoSuperioresDireito()
{
    glPushMatrix();
        glColor3f(0.0,1.0,0.0);
        glTranslatef(anguloBracoX,anguloBracoY,anguloBracoZ);//Translacao das articulacoes do ombro,
                                                            //sendo incrementa ao chamar a funcao para movimentar os bracos
        glutSolidSphere(raioEsfera, 20, 20);
    glPopMatrix();
}
void desenharArticulacao()
{
    glPushMatrix();
        glColor3f(0.0,1.0,0.0);
        glTranslatef(0.0,0.0,MovimentoPeDireitaZ);//Simula a movimentacao do joelho do boneco, sendo incrementa ao chamar funcoes de caminhar
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
       glTranslatef(anguloBracoX,anguloBracoY,anguloBracoZ);//Translacao das articulacoes do ombro,
                                                            //sendo incrementa ao chamar a funcao para movimentar os bracos
        glRotatef(anguloPernaSuperior, 1.0, 0.0, 0.0);//Usa o mesmo angulo da perna para simular o movimento dos bracos enquanto caminha
        glScalef(bracoSuperiorX, bracoSuperiorY, tamanhoZ);
        glutSolidCube(1.0);
    glPopMatrix();
}
void desenharBracoSuperiorEsquerdo()
{
    glColor3f(0.0, 1.0, 1.0);
    glPushMatrix();
       glTranslatef(anguloBracoX,anguloBracoY,anguloBracoZ);//Translacao das articulacoes do ombro,
                                                            //sendo incrementa ao chamar a funcao para movimentar os bracos
       glTranslatef(anguloBracoXTchau,anguloBracoYTchau,anguloBracoZTchau);//Tranlacoes para atualizacao ao 'dar Tchau'
        glRotatef(anguloPernaSuperior, 1.0, 0.0, 0.0);//Usa o mesmo angulo da perna para simular o movimento dos bracos enquanto caminha
        glScalef(bracoSuperiorX, bracoSuperiorY, tamanhoZ);
        glutSolidCube(1.0);
    glPopMatrix();
}
void desenharBracoInferior()
{
    glColor3f(0.0, 1.0, 1.0);
    glPushMatrix();
        glTranslatef(anguloBracoX,anguloBracoY,anguloBracoZ);
        glScalef(bracoInferiorX, bracoInferiorY, tamanhoZ);
         glRotatef(anguloPernaInferior, 1.0, 0.0, 0.0);//Usa o mesmo angulo da perna para simular o movimento dos bracos enquanto caminha
        glutSolidCube(1.0);
    glPopMatrix();
}

void desenharBracoInferiorEsquerdo()
{
    glColor3f(0.0, 1.0, 1.0);
    glPushMatrix();
        glTranslatef(anguloBracoX,anguloBracoY,anguloBracoZ);//Translacao das articulacoes do ombro,
                                                            //sendo incrementa ao chamar a funcao para movimentar os bracos
        glTranslatef(anguloBracoXTchau,anguloBracoYTchau,anguloBracoZTchau);//Tranlacoes para atualizacao ao 'dar Tchau'
        glRotatef(anguloPernaInferior, 1.0, 0.0, 0.0);//Usa o mesmo angulo da perna para simular o movimento dos bracos enquanto caminha
        glScalef(bracoInferiorX, bracoInferiorY, tamanhoZ);
        glutSolidCube(1.0);
    glPopMatrix();
}
void desenharCabeca()
{
    glColor3f(1.0, 0.0, 1.0);
    glPushMatrix();
        glRotatef(anguloMovCabecaPescocoY,0.0,1.0,0.0);//Rotacao incrementada em Y ao chamar funcao de movimentar cabeca
        glRotatef(anguloMovCabecaPescocoX,1.0,0.0,0.0);//Rotacao incrementada em X ao chamar funcao de movimentar cabeca
        glScalef(cabecaX,cabecaY, cabecaZ);
        glutSolidCube(1.0);
    glPopMatrix();
}
void desenharSuperiores()
{
    glTranslatef(0,anguloPular,0);//Caso ocorra o gesto de pular altera toda a posicao do boneco em Y

    desenharTronco();
    glTranslatef(0.0, (troncoY/2+raioEsfera), 0.0);//Tranlacao para o centro da esfera do pesco
    desenharArticulacao();
    glTranslatef(0.0, (raioEsfera+pescocoY/2), 0.0);//Translacao para a metade do pescoco
    desenharPescoco();
    glTranslatef(0.0,(pescocoY/2+cabecaY/2),0.0);//Translacao para a metade da cabeca
    desenharCabeca();
    //---------BRACO ESQUERDO---------
    glTranslatef( -(claviculaX/2+troncoX/2),-((raioEsfera*2+pescocoY+raioEsfera)+claviculaY/2) ,0.0);//Translacao que move da cabeca para a clavicula em y
                                                                                                    // e depois para o centro da clavicula em X
    desenharClavicula();
    glTranslatef(-(claviculaX/2+raioEsfera),0.0,0.0);//Translacao para o centro do ombro esquerdo
    desenharArticulacao();
    glTranslatef(0.0,-(raioEsfera+bracoSuperiorY/2),0.0);//Tranlacao para a metade do braco superior esquerdo
    desenharBracoSuperiorEsquerdo();
    glTranslatef(0.0,-(raioEsfera+bracoSuperiorY/2),0.0);//Translacao para o centro da articulacao inferior do braco esquerdo
    desenharArticulacaoSuperiores();
    glTranslatef(0.0,-(raioEsfera+bracoInferiorY/2),0.0);//Translacao para o centro do braco inferior esquerdo
    desenharBracoInferiorEsquerdo();
    //---BRACO DIREITO ---
    glTranslatef((bracoInferiorX+claviculaX+troncoX+claviculaX/2),(bracoInferiorY+raioEsfera*2+bracoSuperiorX+claviculaY),0.0);
    //Translacao do centro do braco inferior esquerdo para o centro da clavicula em X e Y
    desenharClavicula();
    glTranslatef((claviculaX/2+raioEsfera),0.0,0.0);//Translacao para o centro do ombro direito
    desenharArticulacao();
    glTranslatef(0.0,-(raioEsfera+bracoSuperiorY/2),0.0);//Tranlacao para a metade do braco superior direito
    desenharBracoSuperior();
    glTranslatef(0.0,-(raioEsfera+bracoSuperiorY/2),0.0);//Translacao para o centro da articulacao inferior do braco direito
    desenharArticulacaoSuperioresDireito();
    glTranslatef(0.0,-(raioEsfera+bracoInferiorY/2),0.0);//Translacao para o centro do braco inferior direito
    desenharBracoInferior();
}
void desenharRobo()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix(); //PushMatriz() e PopMatriz() para que conforme ele seja redesenhado, ser redesenhado conforme a posição original
        glTranslatef(0.0, 0.0, posicaoAnimacaoZ);//Atualizacao do caminhar do boneco
        desenharSuperiores();
        desenharInferiores();
    glPopMatrix();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);//Definacao de um plano para simular um chao
        glVertex3f(40.0,-66.5,50.0);
        glVertex3f(40.0,-66.5,-50.0);
        glVertex3f(-40.0,-66.5,-50.0);
        glVertex3f(-40.0,-66.5,50.0);
    glEnd();
    glutSwapBuffers();
}
//Funcao para resetar todos os valores de variaveis globais
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
            controleBraco=true;//Ativa o controle do braco
            glutTimerFunc(33, GirarBraco, 0);//Chama funcao de animacao para Girar o braco
            break;
        case 1:
            Resetar();
            if (!girandoCabecaEsquerda && !girandoCabecaDireita)//Verifica se a cabeca esta girando
            {
                girandoCabecaEsquerda = true;
                glutTimerFunc(33, GirarCabeca, 0);//Chama funcao de girar cabeca
            }
            break;
        case 2:
            Resetar();
            if (!girandoPescocoTras && !girandoPescocoFrente)//Verifica se o pescoco esta girando
            {
                girandoPescocoTras = true;
                glutTimerFunc(33, GirarPescoco, 0);//Chama funcao de girar pescoco
            }
            break;
        case 3:
            Resetar();
            pulou=true;//Ativa o pulo
            anguloPular=40;//Da um pulo de 40 em Y
            break;
        case 4:
            Resetar();
            controleBracoTchau=true;//Ativa o braco para 'dar tchau'
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
            caminhadaManual(valor);//Repassa o valor para caminhada manual
            valor+=10;//Incrementa de 10 em 10 a caminhada em Z somados com os 30 iniciais
            break;
        case 1:
            caminhando = true;//Ativa caminhada automatica e como a funcao de caminhada e chamada na funcao main ela eh executada
            posicaoAnimacaoZ = 0.0;//Define a posicao inicial da animacao
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
    gluPerspective(120.0, (GLdouble)w / h, 1.0, 100.0);//Fovy=120, Aspecto=1, Znear=1, ZFar=100
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //Camera em X=-40, Y=0, Z=60
    //Olhando para X=0,Y=0,Z=0
    //Direita vertical da camera em Y
    gluLookAt(-40.0, 0.0, 60.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Robô 3D - Geilso Faria R.S.");
    glutReshapeFunc(resize);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);//Define a profundidade da animacao como ativa
    glutDisplayFunc(desenharRobo);//Desenha o boneco
    glutKeyboardFunc(Teclado);//Verifica o teclado
    glutTimerFunc(33, AtualizarAnimacao, 0);//Caminhada automatica perna esquerda
    glutTimerFunc(33, AtualizarAnimacaoDireita, 0);//Caminhada automatica perna direita
    glutTimerFunc(15, pular, 0);//Gesto de 'Pular'
    glutMouseFunc(GerenciaMouse);//Verifica o mouse
    glutMainLoop();
    return 0;
}
