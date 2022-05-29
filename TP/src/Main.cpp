#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
#include <cstdlib>

using namespace std;
int main(int argc, char *argv[], char *envp[])
{
    int n_rodadas, dinheiro_inicial, n_jogadores, pingo, aposta;
    char mao[4][3];
    FILE * fp;
    fp = fopen ("entrada.txt", "r+");
    
    fscanf(fp, "%d %d\n", &n_rodadas, &dinheiro_inicial);
    printf("Rodadas: %d\n", n_rodadas);
    printf("Dinheiro inicial: %d\n", dinheiro_inicial);

    for (int i = 0; i < n_rodadas; i++) {
        fscanf(fp, "%d %d\n", &n_jogadores, &pingo); 
        printf("Numero Jogadores: %d\n", n_jogadores );
        printf("Pingo: %d\n", pingo);

       for (int j = 0; j < n_jogadores; j++) {
        char jogador[256];
        fscanf(fp, "%[^0-9]", jogador);
        printf("Jogador: %s\n", jogador);
        fscanf(fp, "%d ", &aposta);
        printf("Aposta: %d\n", aposta);
            for (int k = 0; k < 4; k++) {
                fscanf(fp, "%s ", mao[k]);
                printf("Carta: %s\n", mao[k]);
            }
            fscanf(fp, "%s\n", mao[5]);
            printf("Carta: %s\n", mao[5]);
       }
    }

    fclose(fp); 
    return 0;
}