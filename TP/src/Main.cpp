#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
#include <cstdlib>
#include <string.h>
#include "Jogador.h"
#include "Mao.h"
#include "Carta.h"
#include "Rodada.h"
#include <sstream>

using namespace std;

int main()
{
    int n_rodadas, dinheiro_inicial;
    int n_jogadores, pingo, aposta, n_total_jogadores = 0;
    Jogador jogadores[5];
    Jogador jogadores_apostadores[5];
    std::string nome_jogador;
    FILE * fp;
    fp = fopen("../entrada.txt", "r+");

    fscanf(fp, "%d %d\n", &n_rodadas, &dinheiro_inicial); // scan 3 1000
    printf("Rodadas: %d\n", n_rodadas);
    printf("Dinheiro inicial: %d\n", dinheiro_inicial);

    // cada rodada
    for (int i = 0; i < n_rodadas; i++) {

        fscanf(fp, "%d %d\n", &n_jogadores, &pingo); // scan 5 50
        printf("Numero Jogadores: %d\n", n_jogadores );
        printf("Pingo: %d\n", pingo);

        int montante = 0;

        // cada aposta

        char nome_tmp[256];
        for (int j = 0; j < n_jogadores; j++)
        {
            fscanf(fp, "%[^0-9]", nome_tmp);
            nome_jogador = nome_tmp;
            printf("Jogador na leitura: %s\n", nome_tmp);
            fscanf(fp, "%d ", &aposta);
            printf("Aposta: %d\n", aposta);
            montante += aposta;
            int jogEncontradoIndex = 0;

            // leitura das cartas
            //  cada carta
            Carta cartas[5];
            int numeroCarta;
            char naipeCarta;

            for (int k = 0; k < 5; k++)
            {
                fscanf(fp, "%d", &numeroCarta);
                fscanf(fp, "%c ", &naipeCarta);
                printf("Carta: %d %c\n", numeroCarta, naipeCarta);
                Carta carta(numeroCarta, naipeCarta);
                cartas[k] = carta;
            }

            Mao mao_jogador(cartas);


            if (i == 0)
            {
                
                Jogador jog(nome_jogador, dinheiro_inicial, mao_jogador);
                n_total_jogadores = n_jogadores;
                jogadores[j] = jog;
                jogadores_apostadores[j] = jog;
            }
            else
            {
                while (jogEncontradoIndex < n_total_jogadores)
                {
                    if (jogadores[jogEncontradoIndex].mesmoJogador(nome_jogador))
                    {
                        jogadores[jogEncontradoIndex].setMao(mao_jogador);
                        jogadores_apostadores[j] = jogadores[jogEncontradoIndex];
                        break;
                    }
                    jogEncontradoIndex++;
                }
            }

            jogadores[jogEncontradoIndex].setValor(jogadores[jogEncontradoIndex].getValor() - aposta);
        }

       Rodada rod(jogadores_apostadores);
       // retirando pingo
       for (int p = 0; p < n_total_jogadores; p++)
       {   
           jogadores[p].setValor(jogadores[p].getValor() - pingo);
           montante+=pingo;
       }

       for (int count = 0; count < n_jogadores; count++)
       {
           int jogada = jogadores_apostadores[count].getMao().tipoJogada();
           cout << "Jogadaça: " << jogada << endl;
       }
       
       Jogador winner = rod.getWinner(n_jogadores);

       cout << "Winner: " << winner.getNome() << winner.getMao().tipoJogada() << endl;
    }


    for (int count = 0; count < n_jogadores; count++)
    {
        printf("Jogador %d: %s\n", count+1, jogadores_apostadores[count].getNome().c_str());
        for (int count2 = 0; count2 < 5; count2++)
        {
            printf("Carta %d: %d%c\n", count2+1, jogadores_apostadores[count].getMao().hand[count2].getNumero(), jogadores_apostadores[count].getMao().hand[count2].getNaipe());
        }
    }

    fclose(fp); 
    
    return 0;
}