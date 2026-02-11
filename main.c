#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define CARA 1
#define COROA 2

int inicializacao();
int menu();

void resultado(int qtd, int caras, int coroas);
float calculo(int a, int qtd);

int rodaJogos(int qtd);
int simulaJogo();

int main() {
    inicializacao();
    
    int qtd, caras, coroas, res;

    while(true) {
        system("cls");
        qtd = menu();

        if (qtd < 0) {
            printf("Tchau!!");
            break;
        }

        system("cls");

        caras = rodaJogos(qtd);
        coroas = qtd - caras;

        resultado(qtd, caras, coroas);

    }

    return 0;
}

int inicializacao() {
    srand(time(NULL));
}

int menu() {
    int qtd;

    printf("###################################################\n");
    printf("BEM VINDO AO SIMULADOR DE CARA OU COROA\n");
    printf("---------------------------------------------------\n");
    printf("Digite a quantidade de jogos (-1 para sair) -> ");

    scanf("%i", &qtd);

    return qtd;
}

void resultado(int qtd, int caras, int coroas) {

    printf("---------------------------------------------------\n");
    printf("N DE JOGOS: %i\n", qtd);
    printf("CARAS: %i - (%f%%)\n", caras, calculo(caras, qtd));
    printf("COROAS: %i - (%f%%)\n)", coroas, calculo(coroas, qtd));
    printf("---------------------------------------------------\n\n");
    // printf("Pressione qualquer tecla para continuar...");
    system("PAUSE");
}

float calculo(int a, int qtd) {
    return ((float) a / qtd) * 100;
}

int rodaJogos(int qtd) {
    int caras = 0;

    for(int i = 0; i < qtd; i++) {
        if(simulaJogo() == CARA) {
            caras++;
        }
    }
    return caras;
}

int simulaJogo() {
    int face;

    face = (rand() % 2) + 1;

    return face;
}