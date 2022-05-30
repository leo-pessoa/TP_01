#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
#include <cstdlib>
#include "Jogador.h"

using namespace std;

int main()
{
    int n_rodadas, dinheiro_inicial;
    int n_jogadores, pingo, aposta, n_total_jogadores;
    Jogador jogadores[5];
    FILE * fp;
    fp = fopen("../entrada.txt", "r+");
    
    fscanf(fp, "%d %d\n", &n_rodadas, &dinheiro_inicial);
    printf("Rodadas: %d\n", n_rodadas);
    printf("Dinheiro inicial: %d\n", dinheiro_inicial);


    // cada rodada
    for (int i = 0; i < n_rodadas; i++) {


        fscanf(fp, "%d %d\n", &n_jogadores, &pingo); 
        printf("Numero Jogadores: %d\n", n_jogadores );
        printf("Pingo: %d\n", pingo);

        int montante = 0;

        // cada aposta
        for (int j = 0; j < n_jogadores; j++) {
            char jogador_nome[256];
            fscanf(fp, "%[^0-9]", jogador_nome);
            printf("Jogador: %s\n", jogador_nome);
            fscanf(fp, "%d ", &aposta);
            printf("Aposta: %d\n", aposta);
            montante += aposta;

            
            // cada carta
            Carta cartas[5];
            char numeroCarta[2];
            char naipeCarta;
            for (int k = 0; k < 4; k++)
            {
                fscanf(fp, "%[0-9]+", numeroCarta);
                fscanf(fp, "%c ", &naipeCarta);
                printf("Carta: %s %c\n", numeroCarta, naipeCarta);
                Carta carta(atoi(numeroCarta), naipeCarta);
                cartas[i] = carta;
            }

            fscanf(fp, "%[0-9]+", numeroCarta);
            fscanf(fp, "%c\n", &naipeCarta);
            printf("Carta: %s %c\n", numeroCarta, naipeCarta);

            Mao maoJogador;
            maoJogador.hand = cartas;

            if (i == 0)
            {
                n_total_jogadores = n_jogadores;
                Jogador jog(jogador_nome, dinheiro_inicial, maoJogador);
                jogadores[j]  = jog; 
            }



            Jogador jogador_encontrado;

            for (int k = 0; k < n_total_jogadores; k++)
            {
                if (jogadores[i].mesmoJogador(jogador_nome))
                {
                    jogador_encontrado = jogadores[i];
                    break;
                }
            }

            printf("Jogador encontrado: %s %f\n", jogador_encontrado.getNome().c_str(), jogador_encontrado.getValor());

            jogador_encontrado.setValor(jogador_encontrado.getValor() - aposta);
        
       }

       // retirando pingo
       for (int p = 0; p < n_total_jogadores; p++)
       {   
           jogadores[p].setValor(jogadores[p].getValor() - pingo);
           montante+=pingo;
       }
    }

    for (int l = 0; l < n_total_jogadores; l++) 
    {
        printf("Jogador no vetor %d: %s\n", l+1, jogadores[l].getNome().c_str());
    }

    fclose(fp); 
    
    return 0;
}