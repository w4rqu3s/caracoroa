#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define CARA 1
#define COROA 2

long long int  inicializacao();
long long int  menu();

void resultado(long long int  qtd, long long int  caras, long long int  coroas);
double calculo(long long int  a, long long int  qtd);

long long int  rodaJogos(long long int  qtd);

long long int  main() {
    inicializacao();
    
    long long int  qtd, caras, coroas, res;

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

long long int  inicializacao() {
    srand(time(NULL));
}

long long int  menu() {
    long long int  qtd;

    printf("###################################################\n");
    printf("BEM VINDO AO SIMULADOR DE CARA OU COROA\n");
    printf("---------------------------------------------------\n");
    printf("Digite a quantidade de jogos (-1 para sair) -> ");

    scanf("%lld", &qtd);

    return qtd;
}

void resultado(long long int  qtd, long long int  caras, long long int  coroas) {

    printf("---------------------------------------------------\n");
    printf("N DE JOGOS: %lld\n", qtd);
    printf("CARAS: %lld - (%lf%%)\n", caras, calculo(caras, qtd));
    printf("COROAS: %lld - (%lf%%)\n)", coroas, calculo(coroas, qtd));
    printf("---------------------------------------------------\n\n");
    // printf("Pressione qualquer tecla para continuar...");
    system("PAUSE");
}

double calculo(long long int  a, long long int  qtd) {
    return ((double) a / qtd) * 100;
}

long long int  rodaJogos(long long int  qtd) {
    long long int  caras = 0;

    for(long long int  i = 0; i < qtd; i++) {
        caras += (rand() & 1);
    }
    return caras;
}

