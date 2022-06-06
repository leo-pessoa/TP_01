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
#include "msgassert.h"
#include <sstream>
#include <iomanip>
#include <locale>

#define SIZEOF(a) sizeof(a) / sizeof(*a)


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
    erroAssert(fp != NULL, "Erro ao abrir arquivo de entrada");

    fscanf(fp, "%d %d\n", &n_rodadas, &dinheiro_inicial);
    erroAssert(n_rodadas > 0 && dinheiro_inicial > 0, "Erro ao ");
    // scan 3 1000
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
        for (int j = 0; j < n_jogadores; j++) {
            fscanf(fp, "%[^0-9]", nome_tmp);
            nome_jogador = nome_tmp;

            erroAssert(nome_jogador != "" && nome_jogador != "", "Erro ao ler nome do jogador");
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

            for (int k = 0; k < 5; k++) {
                fscanf(fp, "%d", &numeroCarta);
                fscanf(fp, "%c ", &naipeCarta);
                printf("Carta: %d %c\n", numeroCarta, naipeCarta);
                Carta carta(numeroCarta, naipeCarta);
                cartas[k] = carta;
            }

            Mao mao_jogador(cartas);

            if (i == 0) {
                Jogador jog(nome_jogador, dinheiro_inicial, mao_jogador);
                n_total_jogadores = n_jogadores;
                jogadores[j] = jog;
                jogadores_apostadores[j] = jog;
            } else {
                while (jogEncontradoIndex < n_total_jogadores) {
                    if (jogadores[jogEncontradoIndex].mesmoJogador(nome_jogador)) {
                        jogadores[jogEncontradoIndex].setMao(mao_jogador);
                        jogadores_apostadores[j] = jogadores[jogEncontradoIndex];
                        break;
                    }
                    jogEncontradoIndex++;
                }
            }

            // retirando pingo
            for (int p = 0; p < n_total_jogadores; p++) {
                jogadores[p].setValor(jogadores[p].getValor() - pingo);
                montante += pingo;
            }

            //retirando aposta
            jogadores[jogEncontradoIndex].setValor(jogadores[jogEncontradoIndex].getValor() - aposta);

        }

        for (int i = 0; i < n_jogadores; i++)
        {
            printf("Jogador cartomante: %s\n", jogadores_apostadores[i].getNome().c_str());
            for (int k = 0; k < 5; k++)
            {
                printf("Carta ordenada: %d %c\n", jogadores_apostadores[i].getMao().hand[k].getNumero(), jogadores_apostadores[i].getMao().hand[k].getNaipe());
            }
        }

        Rodada rod;
        rod.setRodada(jogadores_apostadores, n_jogadores);
        for (int count = 0; count < n_jogadores; count++) {
           int jogada = jogadores_apostadores[count].getMao().tipoJogada();
           cout << "Jogadaça: " << jogada << endl;
        }

        std::string winners;
        
        
        winners = rod.getWinners(n_jogadores);

        int n = winners.length();

        char winners_array[n + 1];

        strcpy(winners_array, winners.c_str());

        char *token = strtok(winners_array, "\n");

        printf("Winners:\n");

        int n_winners = 0;
        while (token != NULL)
        {
            n_winners++;
            int count = 0;
            while (count < n_total_jogadores)
            {
                if (jogadores[count].mesmoJogador(nome_jogador))
                {
                    printf("%d\n", montante);
                    printf("%s\n", jogadores[count].getNome().c_str());
                    printf("%d\n", jogadores[count].getMao().tipoJogada());
                    jogadores[count].setValor(jogadores[count].getValor()+montante);
                }
                count++;
            }

            token = strtok(NULL, "\n");
        }

        // for (int i = 0; i < n_winners; i++)
        // {
        //     string tmp_string(token[i]);
        //     if (jogadores[i].mesmoJogador(token[i]))
        //     {
        //         std::string nome_aux =  token[i]
        //         printf("%s\n", jogadores[count].getNome());
        //         printf("%s\n", jogadores[count].getNome())
        //     }
        // }
    }

    int i, j;
    int n = 5;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (jogadores[j].getValor() > jogadores[j + 1].getValor())
                swap(jogadores[j], jogadores[j + 1]);

    for (int count = 0; count < n_total_jogadores; count++){
        printf("%s %d\n", jogadores[count].getNome().c_str(), jogadores[count].getValor());
    }

    fclose(fp); 
    
    return 0;
}