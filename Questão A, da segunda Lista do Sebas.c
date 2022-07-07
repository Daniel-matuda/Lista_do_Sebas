/*
A - Escreva um programa que solicita o nome e a data de nascimento do usuário,
calcule a sua idade atual e grave os dados em um um arquivo chamado
“arq01.txt”. O programa deve imprimir na tela o conteúdo atual do arquivo, a
cada nova entrada.
*/

//          AGENDA DE ANIVERSÁRIOS

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <time.h>

int hdia, ndia;
int hmes, nmes;
int hano, nano;
int dia, mes, ano;
int diferenca;


typedef struct{
    char nome[50];
    int dia, mes, ano;
}Contato;

void imprimir(Contato **c, int quant){
    int i;

    printf("\n\t\tLista de Contatos:\n");
    printf("\t--------------------------------\n");
    for(i = 0; i < quant; i++){
        printf("\t%d = %2d/%2d/%4d\t%s\n", i+1, c[i]->dia, c[i]->mes, c[i]->ano, c[i]->nome);
    }
    printf("\t--------------------------------\n");
}

int cadastrar_contato(Contato **c, int quant, int tam){

    if(quant < tam){
        Contato *novo = malloc(sizeof(Contato));

        printf("\nDigite o nome do contato: ");
        scanf("%50[^\n]", novo->nome);
        printf("\nDigite a data de aniversario dd mm aaaa: ");
        scanf("%d%d%d", &novo->dia, &novo->mes, &novo->ano);
        getchar();
        c[quant] = novo;
        return 1;
    }
    else{
        printf("\n\tImpossivel novo cadastro. Vetor cheio!\n");
        return 0;
    }
}

void alterar_contato(Contato **c, int quant){
    int id;

    imprimir(c, quant);

    printf("\n\tDigite o codigo do contato que deseja alterar: \n");
    scanf("%d", &id);
    getchar();
    id--;

    if(id >= 0 && id < quant){
        Contato *novo = malloc(sizeof(Contato));
        printf("\nDigite o nome do contato: ");
        scanf("%50[^\n]", novo->nome);
        printf("\nDigite a data de aniversario dd mm aaaa: ");
        scanf("%d%d%d", &novo->dia, &novo->mes, &novo->ano);
        getchar();
        c[id] = novo;
    }
    else
        printf("\n\tCodigo invalido!\n");
}

void salvar(Contato **c, int quant, char arq[]){
    FILE *file = fopen(arq, "w");
    int i;

    if(file){
        fprintf(file, "%d\n", quant);
        for(i = 0; i < quant; i++){
            fputs(c[i]->nome, file);
            fputc('\n', file);
            fprintf(file, "%d %d %d\n", c[i]->dia, c[i]->mes, c[i]->ano);
        }
        fclose(file);
    }
    else
        printf("\n\tNAO FOI POSSIVEL ABRIR/CRIAR O ARQUIVO!\n");
}

int main(){

    Contato *agenda[50];
    char arquivo[] = {"arq01.txt"};
    int opcao, tam = 50, quant = 0;

    do{
        printf("\n\t0 - Sair\n\t1 - Cadastrar\n\t2 - Alterar\n\t3 - Imprimir\n\t4 - Salvar\n\t5 - Ler arquivo\n\t6 - Calcular idade\n");
        scanf("%d", &opcao);
        getchar();

        switch(opcao){
        case 1:
            quant += cadastrar_contato(agenda, quant, tam);
            break;
        case 2:
            alterar_contato(agenda, quant);
            break;
        case 3:
            imprimir(agenda, quant);
            break;
        case 4:
            salvar(agenda, quant, arquivo);
            break;
        case 5:
            
            break;
        case 6:
  
              hdia = 0;  /* dia de hoje                                               */ 
              ndia = 0;  /* dia de nascimento                                         */
              hmes = 0;  /* mes de hoje                                               */ 
              nmes = 0;  /* mes de nascimento                                         */
              hano = 0;  /* ano de hoje                                               */
              nano = 0;  /* ano de nascimento                                         */

  
            /*  ENTRADA DE DADOS                                                      */ 
              printf("%s","*** Calculadora de Tempo de Vida ANSI C\n");
              printf("%s","Por favor informe a data de ""hoje?\n");
              printf("%s","[dd mm aaaa]: ");
              scanf(" %d%d%d", &hdia, &hmes, &hano);
              printf("              %2d/%2d/%3d\n\n", hdia, hmes, hano);
              
              printf("%s","Por favor informe a data de ""nascimento?\n");
              printf("%s","[dd mm aaaa]: ");
              scanf(" %d%d%d", &ndia, &nmes, &nano);
              printf("              %2d/%2d/%3d\n\n", ndia, nmes, nano);
            
            /* PROCESSAMENTO DE  DADOS                                                */
              diferenca =   365*hano + 30*hmes + hdia
                          - 365*nano - 30*nmes - ndia;
  
              ano = diferenca/365;
              diferenca = diferenca%365;
              
              mes = diferenca/30;
              diferenca = diferenca%30;
              
              dia = diferenca;
  
            /* RESULTADO                                                              */
              printf("%s %d %s %d %s %d %s", /* ---são as máscaras de saída do printf */
                "Tem de vida:", ano, "ano(s)", mes, "mes(es)", dia, "dia(s).\n");
                        
                        
              break;
        default:
            if(opcao != 0)
                printf("\n\tOpcao invalida!!!\n");
        }
    }while(opcao != 0);
    return 0;
}