//Aluno: Geilso Faria Rodrigues da Silva
#include <process.h>
#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <thread>
using namespace std;

int** matriz;
int contaPrimos = 0;
HANDLE hMutex;
int posicaoAtual = 0; // variável usada para posicionar para threads executarem de acordo com a posicao no vetor

typedef struct {
    int linhaInicial;
    int linhaFinal;
    int colunaInicial;
    int colunaFinal;
} PARAM;

vector<HANDLE> hThread;
PARAM adicionaVetor;
vector<PARAM> vetorParametro;

void criarMatriz(int, int);
void preencherMatriz(int, int, int);
void contarPrimos(int, int);
bool ehPrimo(int);
void contarPrimosParalelo(int, int, int, int);
void testeParametro(void* parametroFunc);
bool verificaPreenchimento(int, int);
void destroiMatriz(int, int);

int main()
{
    time_t tinicialserial, tfinalserial, tinicialparalelo, tfinalparalelo;
    int opcao = 0, semente = 3, linhas = 0, colunas = 0, linhasSubMatriz = 0, colunasSubMatriz = 0, quantThreads = 1, x = 0, y = 0;
    bool verifica1 = false, verifica2 = true, verifica3 = false, verifica4 = false, verifica5 = false, verifica6 = false;
    bool verificaMatriz = false;

    hMutex = CreateMutex(NULL, FALSE, NULL);
    do
    {
        cout << " ------------- Selecione uma opcao ---------------- " << endl;
        cout << " [1] Definir o tamanho da matriz" << endl;
        cout << " [2] Definir semente para o gerador de números aleatórios" << endl;
        cout << " [3] Preencher a matriz com números aleatórios" << endl;
        cout << " [4] Definir o tamanho das submatrizes" << endl;
        cout << " [5] Definir o número de Threads" << endl;
        cout << " [6] Executar" << endl;
        cout << " [7] Visualizar o tempo de execução e quantidade de números primos" << endl;
        cout << " [8] Encerrar" << endl;
        cin >> opcao;
        switch (opcao)
        {
        case 1:
            verificaMatriz = verificaPreenchimento(linhas, colunas);
            if (verificaMatriz == true) //se tem matriz destrói elas
            {
                destroiMatriz(linhas, colunas);
                linhasSubMatriz = 0;
                colunasSubMatriz = 0;
                cout << " Matriz redefinida " << endl;
                cout << "Linha e colunas da submatrizes zeradas. Defina novamente" << endl;
            }
            cout << "Digite a quantidade de linhas da matriz: " << endl;
            cin >> linhas;
            cout << "Digite a quantidade de colunas da matriz: " << endl;
            cin >> colunas;
            criarMatriz(linhas, colunas);
            verifica1 = true;
            break;
        case 2:
            cout << " Digite a semente para a geracao de numeros aleatorios" << endl;
            cin >> semente;
            cout << "Semente definida" << endl;
            break;
        case 3:
            if (verifica1 == true)
            {
                preencherMatriz(linhas, colunas, semente);
                cout << "Matriz Preenchida" << endl;
                //verifica3= true;
            }
            else if (verifica1 == false)
                cout << "Nao existem matrizes para preecher" << endl;
            break;
        case 4:
            //Se esta opcao for executado antes da opcao 1 para sair será necessário definir uma matriz 0X0
            cout << "Digite a quantidade de linhas das submatrizes: " << endl;
            cin >> linhasSubMatriz;
            cout << "Digite a quantidade de colunas das submatrizes: " << endl;
            cin >> colunasSubMatriz;
            //Verificar se linhas e/ou colunas da submatrizes não são maiores que a da matriz
            while (linhasSubMatriz > linhas || colunasSubMatriz > colunas)
            {
                cout << "Ha mais linhas e/ou colunas que a matriz original " << endl;
                cout << "Digite a quantidade de linhas das submatrizes: " << endl;
                cin >> linhasSubMatriz;
                cout << "Digite a quantidade de colunas das submatrizes: " << endl;
                cin >> colunasSubMatriz;
            }
            //Se tem elementos no vetor de parametro apaga
            if (vetorParametro.size() > 0) {
                while (!vetorParametro.empty()) {
                    vetorParametro.pop_back();
                }
            }
            //---DIVIDIR A MATRIZ EM SUBMATRIZES---
            for (int i = 0; i < linhas; i += linhasSubMatriz)
            {
                for (int j = 0; j < colunas; j += colunasSubMatriz)
                {
                    adicionaVetor.linhaInicial = i;
                    adicionaVetor.colunaInicial = j;
                    if (i + linhasSubMatriz - 1 <= linhas - 1)
                    {
                        adicionaVetor.linhaFinal = i + linhasSubMatriz - 1;//Se a quantidade de linhas da submatriz for menor que as linha da matriz
                    }
                    else
                    {
                        adicionaVetor.linhaFinal = linhas - 1;//Se a quantidade de linhas da submatriz ultrapassar a da matriz original,pega a quantidade da matriz original
                    }

                    if (j + colunasSubMatriz - 1 <= colunas - 1)
                    {
                        adicionaVetor.colunaFinal = j + colunasSubMatriz - 1;//Se a quantidade de colunas da submatriz for menor que as colunas da matriz
                    }
                    else
                    {
                        adicionaVetor.colunaFinal = colunas - 1;//Se a quantidade de colunas da submatriz ultrapassar a da matriz original,pega a quantidade da matriz original
                    }
                    vetorParametro.push_back(adicionaVetor);
                }
            }
            break;
        case 5:
            cout << "Defina a quantidade de Threads: " << endl;
            cin >> quantThreads;
            cout << "Quantidade de Threads definidas" << endl;
            break;
        case 6:
            contaPrimos = 0;//Zera a variável global de primos
            //cout << "-----------------------SERIAL----------------------------" << endl;
            tinicialserial = time(0);
            contarPrimos(linhas, colunas);
            tfinalserial = time(0);

            x = contaPrimos;//x guarda o valor de primos serial
            //cout << "-----------------------PARALELO----------------------------" << endl;
            posicaoAtual = 0;// Zera para posicionar as threads corretamente de acordo com a posicao no vetor
            contaPrimos = 0;//Zera a variável global de primos
            tinicialparalelo = time(0);
            for (int i = 0; i < quantThreads; i++)
            {
                HANDLE thread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&testeParametro, &vetorParametro[i], 0, NULL);
                hThread.push_back(thread);
            }
            WaitForMultipleObjects(hThread.size(), hThread.data(), TRUE, INFINITE);
            tfinalparalelo = time(0);
            cout << "Pressione 7 para ver a quantidade de primos e o tempo de execucao " << endl;
            y = contaPrimos;//guarda a quantidade de primos parelelo
            break;
        case 7:
            cout << "Tempo de execucao (serial): " << tfinalserial - tinicialserial << " segundos" << endl;
            cout << "Tem " << x << " primos em serial" << endl;
            cout << "Tempo de execucao (paralelo): " << tfinalparalelo - tinicialparalelo << " segundos" << endl;
            cout << "Tem " << y << " primos em parelelo" << endl;
            break;
        case 8:
            destroiMatriz(linhas, colunas);
            CloseHandle(hMutex);
            cout << " Opcao 8" << endl;
            break;
        default:
            cout << " Opcao Invalida" << endl;
            break;
        }
    } while (opcao != 8);
    return 0;
}
void testeParametro(void* parametroFunc) {
    PARAM* parametro = (PARAM*)parametroFunc;

    while (posicaoAtual < vetorParametro.size()) {
        // bloqueia o mutex não acessar a mesma posição no vetor
        WaitForSingleObject(hMutex, INFINITE);
        int posicao = posicaoAtual++;
        ReleaseMutex(hMutex);

        // verifica se a posição atual ainda está dentro do vetor
        if (posicao >= vetorParametro.size()) {
            break;
        }
        // chama função contarPrimosParalelo com os parâmetros da submatriz atual
        PARAM submatriz = vetorParametro[posicao];
        contarPrimosParalelo(submatriz.linhaInicial, submatriz.linhaFinal, submatriz.colunaInicial, submatriz.colunaFinal);
    }
    _endthread();

}
void contarPrimosParalelo(int inicioLinha, int fimLinha, int inicioColuna, int fimColuna) {
    int contadorLocal = 0;
    for (int i = inicioLinha; i <= fimLinha; i++) {
        for (int j = inicioColuna; j <= fimColuna; j++) {
            if (ehPrimo(matriz[i][j])) {
                contadorLocal++;
            }
        }
    }
    WaitForSingleObject(hMutex, INFINITE);
    contaPrimos += contadorLocal;
    ReleaseMutex(hMutex);
}
void criarMatriz(int linhas, int colunas)
{
    matriz = new int* [linhas];
    for (int i = 0; i < linhas; i++)
    {
        matriz[i] = new int[colunas];
    }
}
void preencherMatriz(int linhas, int colunas, int semente)
{
    int guardaRand;
    srand(semente);
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            guardaRand = rand() % 100000000;
            matriz[i][j] = guardaRand;
        }
    }
}
bool ehPrimo(int num)
{
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}
void contarPrimos(int linha, int coluna)
{
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++) {
            if (ehPrimo(matriz[i][j])) {
                contaPrimos++;
            }
        }
    }

}
bool verificaPreenchimento(int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (matriz[i][j] != 0)
                return true;
        }
    }
    return false;
}
void destroiMatriz(int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        delete[] matriz[i];
    }
    delete[] matriz;
}
