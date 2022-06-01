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
#include <sstream>

using namespace std;

int main()
{
    int n_rodadas, dinheiro_inicial;
    int n_jogadores, pingo, aposta, n_total_jogadores = 0;
    Jogador jogadores[5];
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
            fscanf(fp, "%[^0-9] ", nome_tmp);
            nome_jogador = nome_tmp;
            printf("Jogador na leitura: %s\n", nome_tmp);
            fscanf(fp, "%d ", &aposta);
            printf("Aposta: %d\n", aposta);
            montante += aposta;
            int jogEncontradoIndex = 0;

            Jogador jogador_encontrado;
            if (i == 0)
            {
                Jogador jog(nome_jogador, dinheiro_inicial);
                n_total_jogadores = n_jogadores;
                jogadores[j] = jog;
                jogador_encontrado = jog;
            }
            else
            {
                while (jogEncontradoIndex < n_total_jogadores)
                {
                    if (jogadores[jogEncontradoIndex].mesmoJogador(nome_jogador))
                    {
                        jogador_encontrado = jogadores[jogEncontradoIndex];
                        break;
                    }
                    jogEncontradoIndex++;
                }

                //  for (int u = 0; u < n_total_jogadores; u++)
                // {
                //     if (jogadores[u].mesmoJogador(nome_jogador))
                //     {
                //         jogador_encontrado = jogadores[u];
                //         cout << "Jogador encontrado: " << jogadores[u].getNome() << endl;
                //         break;
                //     }
                // }
            }

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
            Carta carta(atoi(numeroCarta), naipeCarta);
            cout << carta.getNumero() << endl;
            printf("%c\n", carta.getNaipe());
            cartas[5] = carta;

            for (int k = 0; k < 5; k++)
            {
                cout << "CARTAS NA PORRA DO VETOR: " << cartas[k].getNumero() << " " << cartas[k].getNaipe() << endl;
            }

            Mao maoJogador(cartas);


            jogadores[jogEncontradoIndex].setMao(maoJogador);

            jogadores[jogEncontradoIndex].setValor(jogador_encontrado.getValor() - aposta);
        }

       // retirando pingo
       for (int p = 0; p < n_total_jogadores; p++)
       {   
           jogadores[p].setValor(jogadores[p].getValor() - pingo);
           montante+=pingo;
       }
    }

    for (int r = 0; r < n_total_jogadores; r++) 
    {
        printf("Jogador no vetor %d: %s\n", r, jogadores[r].getNome().c_str());
    }

    fclose(fp); 
    
    return 0;
}