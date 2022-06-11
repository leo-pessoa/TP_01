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
#include <math.h>

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

int getNWinners(std::string str, std::string * vencedores)
{
    // word variable to store word
    std::string word;

    // making a string stream
    std::stringstream iss(str);
    int count = 0;

    // Read and print each word.
    while (iss >> word) {
        vencedores[count] = word;
        count++;
    }

    return count;

}

using namespace std;

int main()
{
    int n_rodadas, dinheiro_inicial;
    int n_jogadores, pingo, aposta, n_total_jogadores = 0;
    Jogador jogadores[8];
    int apostas[8]; 
    bool sanidade = false;
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
        sanidade = false;

        fscanf(fp, "%d %d\n", &n_jogadores, &pingo);
        montante = 0;


        // leitura de cada aposta
        char nome_tmp[256];
        for (int j = 0; j < n_jogadores; j++) {
            fscanf(fp, "%s", nome_tmp);
            nome_jogador = nome_tmp;

            erroAssert(nome_jogador != "" && nome_jogador != "", "Erro ao ler nome do jogador");
            fscanf(fp, "%d ", &aposta);
            apostas[j] = aposta;

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

                if (jogadores[j].getValor() >= aposta) {
                    jogadores[j].setValor(jogadores[j].getValor() - aposta);
                    montante += aposta;
                } else {
                    sanidade = true;
                    break;
                }
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
                    montante += aposta;
                }
                else {
                    sanidade = true;
                    break;
                }
            }
        }

        if (!sanidade) {
            int sanidade_pingo = 0;

            // chechando sanidade do pingo
            for (int p = 0; p < n_total_jogadores; p++)
            {
                if (jogadores[p].getValor() < pingo) {
                    sanidade_pingo++;
                }
            }

            if (sanidade_pingo > 0 ) {
                sanidade = true;

                // devolvendo apostas
                for (int p = 0; p < n_jogadores; p++)
                {
                    int count3 = 0;
                    while (count3 < n_total_jogadores)
                    {
                        if (jogadores[count3].mesmoJogador(jogadores_apostadores[p].getNome()))
                        {
                            jogadores[count3].setValor(jogadores_apostadores[p].getValor() + apostas[p]);
                            break;
                        }
                        count3++;
                    }

                }
                
            } else {
                // retirando pingo
                for (int p = 0; p < n_total_jogadores; p++) {
                    jogadores[p].setValor(jogadores[p].getValor() - pingo);
                    montante += pingo;
                }

            }

        }

        if (sanidade) {
            fprintf(fs, "0 0 I\n");
        } 
        
        else {

            Rodada rod;
            rod.setRodada(jogadores_apostadores, n_jogadores);

            std::string winners;

            winners = rod.getWinners(n_jogadores);

            std::string vencedores[8];

            int n_winners = getNWinners(winners, vencedores);

            for (int i2 = 0; i2 < n_winners - 1; i2++)
            {
                for (int j2 = 0; j2 < n_winners - i2 - 1; j2++)
                {
                    if (vencedores[j2]> vencedores[j2 + 1])
                    {
                        swap(vencedores[j2], vencedores[j2 + 1]);
                    }
                }
            }

            for (int i = 0; i < n_winners; i++) {
                int count = 0;
                while (count < n_total_jogadores)
                {
                    if (jogadores[count].mesmoJogador(vencedores[i]))
                    {   
                        if (i == 0)
                            fprintf(fs, "%d %d %s\n", n_winners, (int)(montante / n_winners), getTipoJogada(jogadores[count].getMao().tipoJogada()).c_str());
                        jogadores[count].setValor(jogadores[count].getValor() +  floor(montante/n_winners));

                        fprintf(fs, "%s ", jogadores[count].getNome().c_str());
                    }
                    count++;
                }
            }
                fprintf(fs, "\n");
        }
    }

    int i, j;
    int n = 5;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (jogadores[j].getValor() < jogadores[j + 1].getValor())
                swap(jogadores[j], jogadores[j + 1]);

    fprintf(fs, "####\n");

    for (int count = 0; count < n_total_jogadores; count++) {
        fprintf(fs, "%s %d\n", jogadores[count].getNome().c_str(), jogadores[count].getValor());
    }

    fclose(fp); 
    
    return 0;
}