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

#define RSF 100000
#define SF 90000
#define FK 80000
#define FH 70000
#define F 60000
#define S 50000
#define TK 40000
#define TP 30000
#define OP 20000
#define HC 10000

std::string getTipoJogada(int n) {

    if (n >= RSF)
    {
        return "RSF";
    }
    if (n >= SF)
    {
        return "SF";
    }
    if (n >= FK)
    {
        return "FK";
    }
    if (n >= FH)
    {
        return "FH";
    }
    if (n >= F)
    {
        return "F";
    }
    if (n >= S)
    {
        return "S";
    }
    if (n >= TK)
    {
        return "TK";
    }

    if (n >= TP)
    {
        return "TP";
    }

    if (n >= OP)
    {
        return "OP";
    }

    return "HC";
}


using namespace std;

int main()
{
    int n_rodadas, dinheiro_inicial;
    int n_jogadores, pingo, aposta, n_total_jogadores = 0;
    Jogador jogadores[5];
    Jogador jogadores_apostadores[5];
    std::string nome_jogador;
    FILE * fp;
    int montante = 0;
    fp = fopen("../entrada.txt", "r+");
    erroAssert(fp != NULL, "Erro ao abrir arquivo de entrada");

    FILE *fs;
    fs = fopen("../saida.txt", "w");
    erroAssert(fp != NULL, "Erro ao abrir arquivo de saida");

    fscanf(fp, "%d %d\n", &n_rodadas, &dinheiro_inicial);
    erroAssert(n_rodadas > 0 && dinheiro_inicial > 0, "Erro ao ");

    // leitura de cada rodada
    for (int i = 0; i < n_rodadas; i++) {

        fscanf(fp, "%d %d\n", &n_jogadores, &pingo);
        montante = 0;



        // teste de sanidade
        for (int j = 0; j < n_jogadores; j++) {
            
        }

        // leitura de cada aposta
        char nome_tmp[256];
        for (int j = 0; j < n_jogadores; j++) {
            fscanf(fp, "%[^0-9]", nome_tmp);
            nome_jogador = nome_tmp;

            erroAssert(nome_jogador != "" && nome_jogador != "", "Erro ao ler nome do jogador");
            fscanf(fp, "%d ", &aposta);

            montante += aposta;
            int jogEncontradoIndex = 0;

            // leitura de cada carta
            Carta cartas[5];
            int numeroCarta;
            char naipeCarta;

            for (int k = 0; k < 5; k++) {
                fscanf(fp, "%d", &numeroCarta);
                fscanf(fp, "%c ", &naipeCarta);
                Carta carta(numeroCarta, naipeCarta);
                cartas[k] = carta;
            }

            Mao mao_jogador(cartas);

            if (i == 0) {
                Jogador jog(nome_jogador, dinheiro_inicial, mao_jogador);
                n_total_jogadores = n_jogadores;
                jogadores[j] = jog;
                jogadores_apostadores[j] = jog;
                jogadores[j].setValor(jogadores[j].getValor() - aposta);
            } else {
                while (jogEncontradoIndex < n_total_jogadores) {
                    if (jogadores[jogEncontradoIndex].mesmoJogador(nome_jogador)) {
                        jogadores[jogEncontradoIndex].setMao(mao_jogador);
                        jogadores_apostadores[j] = jogadores[jogEncontradoIndex];
                        break;
                    }
                    jogEncontradoIndex++;
                }

                // retirando aposta
                if (jogadores[jogEncontradoIndex].getValor() >= aposta) {
                    jogadores[jogEncontradoIndex].setValor(jogadores[jogEncontradoIndex].getValor() - aposta);
                }
            }
        }

        // retirando pingo
        for (int p = 0; p < n_total_jogadores; p++) {
            jogadores[p].setValor(jogadores[p].getValor() - pingo);
            montante += pingo;
        }

        Rodada rod;
        rod.setRodada(jogadores_apostadores, n_jogadores);

        std::string winners;

        winners = rod.getWinners(n_jogadores);

        int n = winners.length();

        char winners_array[n + 1];

        strcpy(winners_array, winners.c_str());

        char *token = strtok(winners_array, "\n");
        char *token_aux = strtok(winners_array, "\n");

        int n_winners = 0;

        while (token_aux != NULL)
        {
            n_winners++;
            token_aux = strtok(NULL, "\n");
        }

        //impressao da saida

        while (token != NULL)
        {
            int count = 0;
            
            while (count < n_total_jogadores)
            {
                if (jogadores[count].mesmoJogador(token))
                {
                    fprintf(fs, "%d %d %s\n",n_winners,  montante, getTipoJogada(jogadores[count].getMao().tipoJogada()).c_str());
                    jogadores[count].setValor(jogadores[count].getValor()+montante);
                    fprintf(fs, "%s\n", jogadores[count].getNome().c_str());
                }
                count++;
            }

            token = strtok(NULL, "\n");
        }
    }

    int i, j;
    int n = 5;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (jogadores[j].getValor() < jogadores[j + 1].getValor())
                swap(jogadores[j], jogadores[j + 1]);

    fprintf(fs, "####\n");

    for (int count = 0; count < n_total_jogadores; count++){
        fprintf(fs, "%s%d\n", jogadores[count].getNome().c_str(), jogadores[count].getValor());
    }

    fclose(fp); 
    
    return 0;
}