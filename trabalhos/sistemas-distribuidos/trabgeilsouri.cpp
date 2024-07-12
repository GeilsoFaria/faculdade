/* DESCRIÇÂO:
   Disciplina: Sistemas Distribuidos
   Docente: Rodrigo Porfirio Sacchi
   Discentes: Geilso Faria Rodrigues Da Silva 
              Uri Raymison Ferreira Portiolli Ferraz
   Modo de Uso: 
        Digite 1 para adicionar voos, colocando as informacoes pedidas. 
        Digite 2 para mostrar as atividades do aeroporto selecionado.
        Digite 0 para fechar o programa.

   Como Funciona:
         O programa permite aos usuários adicionar voos, visualizar informações detalhadas dos aeroportos, e manipular dados de voos em tempo real entre diferentes processos.
         Cada processo é um aeroporto que tem o seu relógio lógico, sendo atualizado conforme tem decolagens e pousosos, relógios lógicos são sincronizados,
         fazendo com que não haja conflitos de pousos e decolagens.
*/
#include "mpi.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Adicionado para std::sort, std::max

struct Voo {
    int codigo;
    int origem;//Aeroporto Origem do Voo
    int destino;//Aeroporto Destino do Voo
    int horarioChegada; //Horário do pouso
    int horarioPartida; //Horário da decolagem
    int tempoVoo;
    char tipo; // 'd' = decolagem
    
};

struct Aeroporto {
    int codigoA;
    int numPousos;
    int numDecolagens;
    int relogioLogico;
    std::vector<Voo> aeroptDecolagens;
    std::vector<Voo> aeroptPousos;
};

bool verificarCodigoAeroporto(int aeroportoSelecionado, std::vector<Aeroporto>& aeroportos);


std::string toString(const Voo& voo, bool isDecolagem) {//Para gerar os dados do Voo e colocar no formato 
    std::string dados;
    if (isDecolagem) {
        dados = std::to_string(voo.destino+1) + "         " +  
                std::to_string(voo.horarioPartida) + "         " +
                std::to_string(voo.tempoVoo);
    } else {
        dados = std::to_string(voo.origem+1) + "        " +
                std::to_string(voo.horarioChegada) + "        " +
                std::to_string(voo.tempoVoo);
    }
    return dados;
}


std::string toString(const Aeroporto& aeroporto) {//Gera o cabeçalho do aeroporto
    std::string dados = "Pousos:    " + std::to_string(aeroporto.numPousos) +
                        "    Decolagens:    " + std::to_string(aeroporto.numDecolagens) + "\n" +
                        "Pousos | Origem | Chegada | Tempo Voo\n";
    for (const Voo& voo : aeroporto.aeroptPousos) {
        dados += std::to_string(voo.codigo) + "           " + toString(voo, false) + "\n";
    }
    dados += "Decolagens | Destino | Partida | Tempo de Voo\n";
    for (const Voo& voo : aeroporto.aeroptDecolagens) {
        dados += std::to_string(voo.codigo) + "            " + toString(voo, true) + "\n";
    }
    return dados;
}


void menu(int size, std::vector<Aeroporto>& aeroportos, int rank) {
    int opcao = -1;
    int aeroportoSelecionado = -1;

    while (opcao != 0) 
    {
        
        std::cout << "----------------------------------" << std::endl;
        std::cout << "| [1] Cadastrar Voo              |" << std::endl;
        std::cout << "| [2] Mostrar todos os aeroportos|" << std::endl;
        std::cout << "| [0] Sair                       |" << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << "Digite aqui: ";
        std::cin >> opcao;

        switch (opcao) 
        {
            case 0:
                std::cout << "Saindo..." << std::endl;
                break;

            case 1:{
                system("clear");
                std::cout << "[------TELA DE VOOS-----]" << std::endl;
                std::cout << "Digite aeroporto origem 1 à "<< size << std::endl;
                std::cin >> aeroportoSelecionado;
            
                if (verificarCodigoAeroporto(aeroportoSelecionado, aeroportos) == false){
                    std::cout << "Codigo invalido ou origem eh igual ao destino" << std::endl;
                    break;
                }
                
                Voo novoVoo; //declara um voo
                novoVoo.origem = aeroportoSelecionado - 1;

                std::cout << "Digite aeroporto destino 1 à "<< size << std::endl;
                std::cin >> novoVoo.destino;
                novoVoo.destino--;


                if (verificarCodigoAeroporto(novoVoo.destino+1, aeroportos) == false || novoVoo.destino+1 == aeroportoSelecionado ){
                    std::cout << "Codigo invalido ou origem eh igual ao destino" << std::endl;
                    break;
                }

                std::cout << "Digite o tempo de voo" << std::endl;
                std::cin >> novoVoo.tempoVoo;
            
                novoVoo.tipo = 'd'; //Se vc já está em um aeroporto não tem como fazer outra coisas senão decolar. Pousado vc já está, pq vc tá no aeroporto e os pousos vão vir de outros aeroporto em que o destino é vc.

                int numeroVoo = (aeroportos[novoVoo.origem].numDecolagens) + 1;//Pega a soma de decolagens 

                aeroportos[novoVoo.origem].relogioLogico++;//Atualiza o relógio lógico

                
                novoVoo.codigo = aeroportoSelecionado * 10 + numeroVoo;//gera o código do voo 
                novoVoo.horarioPartida = aeroportos[novoVoo.origem].relogioLogico;//atualiza o relógio lógico
                novoVoo.horarioChegada =  novoVoo.horarioPartida + novoVoo.tempoVoo;// atualiza o horario de chegada 
                aeroportos[novoVoo.origem].numDecolagens++;//atualiza o numero de decolagens                  

                //Caso ocorra uma chegada e partida ao mesmo tempo , faça a partida receber +1 
                for(int i =0; i < aeroportos[novoVoo.origem].aeroptDecolagens.size(); i++){//roda todo o vetor de decolagens pra verificar
                    if(novoVoo.horarioPartida == aeroportos[novoVoo.origem].aeroptDecolagens[i].horarioChegada){
                        novoVoo.horarioPartida++;
                        std::cout << "Partida e decolagem ao mesmo tempo " << std::endl; 
                    }
                }
                aeroportos[novoVoo.origem].aeroptDecolagens.push_back(novoVoo);//Salva o voo no vetor de decolagens

                //SE dois voos decolam ao mesmo tempo
                std::sort(aeroportos[novoVoo.origem].aeroptDecolagens.begin(), aeroportos[novoVoo.origem].aeroptDecolagens.end(), [](const Voo& v1, const Voo& v2){
                    if (v1.horarioPartida != v2.horarioPartida) {//Se não tem conflito na hora de decolar
                        return v1.horarioPartida < v2.horarioPartida; 
                    } else if(v1.horarioPartida == v2.horarioPartida){//Se tem conflito na hora de decolar
                        return v1.tempoVoo > v2.tempoVoo; // Prioriza o voo com maior tempo de voo
                    }
                    return false; // Adicionando um retorno no final da função lambda
                });

                // Atualiza os códigos dos voos, caso ocorreu algum conflito ou não
                for (size_t i = 0; i < aeroportos[novoVoo.origem].aeroptDecolagens.size(); i++) {
                    aeroportos[novoVoo.origem].aeroptDecolagens[i].codigo = (aeroportoSelecionado * 10) + (i + 1);
                }
                

                for (int i = 0; i < size; i++) {
                    MPI_Request req;
                    
                    if(novoVoo.origem != i){//Pra não enviar pra si mesmo
                        MPI_Isend(&novoVoo, sizeof(novoVoo), MPI_BYTE, i, 1, MPI_COMM_WORLD, &req);//Envia usando um envio não bloqueante
                    }
                }
                
                for (int i = 0; i < size; i++) {
                    MPI_Request req;
                    MPI_Irecv(&novoVoo, sizeof(novoVoo), MPI_BYTE, i, MPI_ANY_TAG, MPI_COMM_WORLD, &req);//recebe através de um recebimento não bloqueante
                    
                    // faz a verificação dos relógios lógicos e atualiza 
                    if(novoVoo.destino == i)//Se for o destino faz os devidos tratamentos
                    {
                        if(aeroportos[novoVoo.destino].relogioLogico < novoVoo.horarioChegada){
                            aeroportos[novoVoo.destino].relogioLogico  = std::max(novoVoo.horarioChegada, aeroportos[novoVoo.destino].relogioLogico) + 1; //Maximo entre o relógio lógico do Voo(horarioChegada) e do aeroporto(aeroportos[novoVoo.destino].relogioLogico)
                            aeroportos[novoVoo.destino].aeroptPousos.push_back(novoVoo);//Guarda um voo no vetor de pousos do aeropt destino
                            aeroportos[novoVoo.destino].numPousos++;
                        }
                    } else {//atualiza todos os relógios lógicos não destinos
                        aeroportos[i].relogioLogico  = std::max(novoVoo.horarioChegada, aeroportos[i].relogioLogico ) + 1;
                    }
                }

                //Ordenar pousos
                std::sort(aeroportos[novoVoo.origem].aeroptPousos.begin(), aeroportos[novoVoo.origem].aeroptPousos.end(), [](const Voo& v1, const Voo& v2){
                    if (v1.horarioChegada != v2.horarioChegada) {//Se não tem conflito na hora de pousar
                        return v1.horarioChegada < v2.horarioChegada; 
                    } else if(v1.horarioChegada == v2.horarioChegada){//Se tem conflito na hora de pousar
                        return v1.tempoVoo > v2.tempoVoo; // Prioriza o voo com maior tempo de voo      
                    }
                        return false; // Adicionando um retorno no final da função lambda
                });
                    std::cout << "Voo cadastrado com sucesso!" << std::endl;
                    break;
                }
            case 2: {
                system("clear");
                int codigoAeroporto;
                std::cout << "Digite o código do aeroporto para visualizar detalhes: ";
                std::cin >> codigoAeroporto;
                codigoAeroporto--;   

                if (!verificarCodigoAeroporto(codigoAeroporto, aeroportos)) {
                    std::cout << "Código de aeroporto inválido." << std::endl;
                    break;
                }
                system("clear");
                std::cout << "RL: " << aeroportos[codigoAeroporto].relogioLogico << " AEROPT : " << codigoAeroporto + 1 << std::endl;//relogio lógico atual do aeropt
                std::cout << "Detalhes do Aeroporto:\n" << toString(aeroportos[codigoAeroporto]) << std::endl;
                break;
            }
            default:
                std::cout << "Opção inválida! Tente novamente." << std::endl;
                system("clear");
                break;     
        }    
    }
}

bool verificarCodigoAeroporto(int aeroportoSelecionado, std::vector<Aeroporto>& aeroportos){//verifica se o código é existente
    
    if (aeroportoSelecionado < 0 || aeroportoSelecionado > aeroportos.size()){
        std::cout << "Aeroporto Invalido" << std::endl;
        return false;
    }
    return true;
}

int main(int argc, char** argv) 
{
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Criação de aeroportos
    std::vector<Aeroporto> aeroportos(size);

    
    aeroportos[rank].codigoA = rank;
    aeroportos[rank].numPousos = 0;
    aeroportos[rank].numDecolagens = 0;
    aeroportos[rank].relogioLogico = 0;
    
    
    if (rank == 0) menu(size, aeroportos,rank);
    
    MPI_Finalize();
    return 0;
}