/*
C - Construa um função em C que possua a capacidade de escrever um inteiro em um
arquivo binário. Escreva um programa que se utiliza adequadamente da função
que você projetou.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <time.h>

/*
        Modos de abertura de arquivos:
        wb -> Escrita
        rb -> leitura
        ab -> anexar
        rb+ -> leitura e escrita
        wb+ -> leitura e escrita (apaga o conteúdo caso o arquivo exista)
        ab+ -> leitura e escrita (adiciona ao final do arquivo)
*/

typedef struct{
    char nome[50];
    int inteiro;
}Contato;

void escrever(char arq[]){
    Contato c;
    FILE *file = fopen(arq, "ab");

    if(file){
        printf("Digite o nome e um número inteiro qualquer: ");
        scanf("%49[^\n]%d", c.nome, &c.inteiro);
        fwrite(&c, sizeof(Contato), 1, file);
        fclose(file);
    }
    else
        printf("\nErro ao abrir arquivo!\n");
}

int main(){
    char arquivo[] = {"agenda.dat"};

    escrever(arquivo);

    return 0;
}