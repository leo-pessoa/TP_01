#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
#include <cstdlib>
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
    FILE * fp;
    fp = fopen("../entrada.txt", "r+");
    
    fscanf(fp, "%d %d", &n_rodadas, &dinheiro_inicial);
    printf("Rodadas: %d\n", n_rodadas);
    printf("Dinheiro inicial: %d\n", dinheiro_inicial);

    // cada rodada
    for (int i = 0; i < n_rodadas; i++) {

        fscanf(fp, "\n%d %d\n", &n_jogadores, &pingo);
        printf("Numero Jogadores: %d\n", n_jogadores );
        printf("Pingo: %d\n", pingo);

        int montante = 0;

        // cada aposta
        char nome_tmp[256];
        for (int j = 0; j < n_jogadores; j++) {
            fscanf(fp, "%[^0-9]", nome_tmp);
            std::string nome_jogador = nome_tmp;
            printf("Jogador na leitura: %s\n", nome_tmp);
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
            Carta carta(atoi(numeroCarta), naipeCarta);
            cartas[5] = carta;

            Jogador jogador_encontrado;
            if (i == 0)
            {
                n_total_jogadores = n_jogadores;
                Jogador jog(nome_jogador, dinheiro_inicial);
                jogadores[j] = jog;
                jogador_encontrado = jog;
                cout << jogador_encontrado.getNome() << "JOGADOR ENCONTRADOOO";
            }
            else {
                for (int l = 0; l < n_total_jogadores; l++)
                {
                    if (jogadores[l].mesmoJogador(nome_jogador))
                    {
                        jogador_encontrado = jogadores[l];
                        break;
                    }
                }
            }

            printf("Jogador encontrado: %s %f\n", jogador_encontrado.getNome().c_str(), jogador_encontrado.getValor());


            Mao maoJogador;
            maoJogador.hand = cartas;


            jogador_encontrado.setValor(jogador_encontrado.getValor() - aposta);        
       }

       // retirando pingo
       for (int p = 0; p < n_total_jogadores; p++)
       {   
           jogadores[p].setValor(jogadores[p].getValor() - pingo);
           montante+=pingo;
       }
    }

    cout << "CONTADOOOOR EI NAO TO MALUCO: " << n_total_jogadores << "\n";

    for (int r = 0; r < n_total_jogadores; r++) 
    {
        printf("Jogador no vetor %d: %s\n", r, jogadores[r].getNome().c_str());
    }

    fclose(fp); 
    
    return 0;
}