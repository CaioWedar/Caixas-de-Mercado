/*  Nome: Caio Alves Fagudes RA:19668771
    Nome: Gabriel de Rezende Gonçalves RA: 19289420

    - Projeto Base
    - Opcional 1
    - Opcional 5 (não conseguimos emitir relatório, optamos
                  por inserir a pessoa especial na Lista mais vazia)

    */






#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <locale.h>
#include "tela.h"

int qtFilas = 3;

char leitura()
{
	if (kbhit())
	{
		return getch();
	}

	return '\e';
}

struct fila
{
    int num;
	time_t tempo;
	struct fila * prox;

};

typedef struct fila fila;

void inserirFila(fila **inicio, fila **fim){


	fila *novo = (fila*) malloc(sizeof(fila*));

	if (novo == NULL){

		printf("Heap Overflow\n");
		system("pause");
		return;
	}

	time_t atual;
	time(&atual);
	novo->data_hora_atual = localtime(&atual);

	novo->prox = NULL;
	novo->num = 164;
	novo->tempo = atual;

	if ((*inicio) == NULL){

		(*inicio) = novo;
		(*fim) = novo;

		return;
	}

	(*fim)->prox = novo;
	(*fim) = (*fim)->prox;

}

void removerFila(fila **inicio, fila **fim){

    int tempo;

	fila * aux;
	aux = (*inicio);

	if (aux == NULL) return;

	if (aux->prox == NULL){

		(*inicio) = NULL;
		(*fim) = NULL;

		return;
	}

	(*inicio) = (*inicio)->prox;
	free(aux);

}

void inserirEspecial(fila **inicioEspecial, fila **fimEspecial){


	fila *novoEspecial = (fila*) malloc(sizeof(fila*));

	if (novoEspecial == NULL){

		printf("Heap Overflow\n");
		system("pause");
		return;
	}

	time_t atual;
	time(&atual);

	novoEspecial->prox = NULL;
	novoEspecial->num = 144;
	novoEspecial->tempo = atual;

	if ((*inicioEspecial) == NULL){

		(*inicioEspecial) = novoEspecial;
		(*fimEspecial) = novoEspecial;

		return;
	}

	(*fimEspecial)->prox = novoEspecial;
	(*fimEspecial) = (*fimEspecial)->prox;

}

void removerEspecial(fila **inicioEspecial, fila **fimEspecial){

    int tempo;

	fila * aux;
	aux = (*inicioEspecial);

	if (aux == NULL) return;

	if (aux->prox == NULL){

		(*inicioEspecial) = NULL;
		(*fimEspecial) = NULL;

		return;
	}

	(*inicioEspecial) = (*inicioEspecial)->prox;
	free(aux);

}

void tamanho(fila *inicio[], int diff, fila *inicioEspecial, int flag){

	system("cls");

	printf("O tempo é de %d segundos\n", diff);
	gotoxy(1, 10);

	fila * aux;
	int i;

	time_t atual;
	time(&atual);

	for (i = 0; i < qtFilas; i++){

		aux = inicio[i];

            printf("\nFila[%d] : ", i);

            while (aux != NULL){

                printf(" | %c ", aux->num);
                printf("%d segundos | ", (int) difftime(atual, aux->tempo));

                aux = aux->prox;
            }
        }

    if(flag == 1){



        fila *auxEspecial;
        auxEspecial = inicioEspecial;

        printf("\nFila Especial : ");

        while (auxEspecial != NULL){

            printf(" | %c ", auxEspecial->num);
            printf("%d segundos | ", (int) difftime(atual, auxEspecial->tempo));

            printf("\n");

            auxEspecial = auxEspecial->prox;
        }
    }
		printf("\n");

}


int main(){

	setlocale(LC_ALL, "portuguese");

	int countEntrada[qtFilas];
	int countSaida[qtFilas];
	int countEntradaEspecial = 0;
	int countSaidaEspecial = 0;
	int segundo = 0;
    int i;
	int media;
	int maior[qtFilas];
    int menor[qtFilas];
    int maiorEspecial = -9999;
    int menorEspecial = 9999;
    int somaTempoFilas[qtFilas];
    int somaTempoFilasEspecial = 0;
    int flag = 0;

	char especial;
	char op;
	time_t inicial;
	time_t atual;
	time_t tempo;
	time_t tempoEspecial;



	fila *inicio[qtFilas];
	fila *fim[qtFilas];
	fila *inicioEspecial = NULL;
	fila *fimEspecial = NULL;

	int opcoes;
	int qtTempoEntrada = 2;
	int qtTempoSaida = 4;
	int qtTempoExecucao = 10;

	do{
            textcolor(VERDE);

	    printf("\tTempo de Inserção = %d s, Tempo de Remoção = %d s, Numero de Filas = %d e Tempo de Execução = %d s\n\n", qtTempoEntrada, qtTempoSaida, qtFilas, qtTempoExecucao);

        printf("1. Alterar quantidade de fila [0-100]\n");
        printf("2. Alterar tempo de entrada dos clientes\n");
        printf("3. Alterar tempo de saida\n");
        printf("4. Alterar tempo de execução do programa\n");
        printf("5. Começar programa\n");
        printf("0. Sair.\n");
        printf("\n->:  ");
        scanf("%d", &opcoes);
        system("cls");
        switch(opcoes){

            case 1:
                printf("Digite a quantidade de filas: ");
                scanf("%d", &qtFilas);
                if(qtFilas < 0 || qtFilas > 100){
                    printf ("Valor inválido!\n");
                    system("pause");
                    system("cls");
                    qtFilas = 0;
                }
                system("cls");
            break;

            case 2:
                printf("Digite, em segundos, o tempo em que cada cliente entrará na fila: ");
                scanf("%d", &qtTempoEntrada);
                system("cls");
            break;

            case 3:
                printf("Digite, em segundos, o tempo em que cada cliente será atendido: ");
                scanf("%d", &qtTempoSaida);
                system("cls");
            break;

            case 4:
                printf("Digite, em segundos, o tempo de execução do programa: ");
                scanf("%d", &qtTempoExecucao);
                system("cls");
            break;

            case 5:
            textcolor(CIANO);
                for (i = 0; i < qtFilas; i++){

                inicio[i] = NULL;
                fim[i] = NULL;
                }

                for (i = 0; i < qtFilas; i++){

                    maior[i] = -9999;
                    menor[i] = 9999;
                }
                for (i = 0; i < qtFilas; i++){

                	countEntrada[i] = 0;
                    countSaida[i] = 0;
                    somaTempoFilas[i] = 0;
                }

                time(&inicial);

                do {

                    time(&atual);

                    for (i = 0; i < qtFilas; i++){

                        if ((int) difftime(atual, inicial) % qtTempoEntrada == 0 && (int) difftime(atual, inicial) > 1){

                            inserirFila(&inicio[i], &fim[i]);
                            countEntrada[i]++;
                        }

                        if ((int) difftime(atual, inicial) % qtTempoSaida == 0 && (int) difftime(atual, inicial) > 1){

                            tempo = (int) difftime(atual, inicio[i]->tempo);

                            somaTempoFilas[i] =  somaTempoFilas[i] + tempo;


                            if(tempo < menor[i]){

                                menor[i] = tempo;
                            }
                            if(tempo > maior[i]){

                                maior[i] = tempo;
                            }
                            removerFila(&inicio[i], &fim[i]);
                            countSaida[i]++;


                        }

                        op = leitura();
                        if(op == 'e')
                        {
                            inserirEspecial(&inicio, &fim);
                            countEntradaEspecial++;
                            flag = 1;

                            if ((int) difftime(atual, inicial) % qtTempoSaida == 0 && (int) difftime(atual, inicial) > 1){

                                tempoEspecial = (int) difftime(atual, inicioEspecial->tempo);

                                somaTempoFilasEspecial =  somaTempoFilasEspecial + tempoEspecial;

                                if(tempo < menorEspecial){

                                    menorEspecial = tempoEspecial;
                                }
                                if(tempo > maiorEspecial){

                                    maiorEspecial = tempoEspecial;
                                }

                                removerEspecial(&inicioEspecial, &fimEspecial);
                                countSaidaEspecial++;

                            }
                        }

                    }

                    tamanho(inicio, (int) difftime(atual, inicial), inicioEspecial, flag);


                } while ((int) difftime(atual, inicial) < qtTempoExecucao);

                textcolor(ROSA);

                printf("\n\n ---------- \\ RELATÓRIO // ----------");

                for(i=0; i< qtFilas; i++){

                    int total = countEntrada[i] - countSaida[i];
                    int media = somaTempoFilas[i] / countSaida[i];


                    printf("\n\nO maior da fila[%d] tempo de espera foi %d \n", i, maior[i]);
                    printf("O menor tempo[%d] de espera foi %d \n", i, menor[i]);
                    printf("O tamanho da fila é de %d\n", total);
                    printf("A quantidade de pessoas atendidas é de %d\n", countSaida[i]);
                    printf("A média de tempo esperando é de %d s\n\n", media);


                }

                system("pause");
                system("cls");
                break;

            case 0:

                exit(0);
            break;

            default :

                printf ("Valor inválido!\n");
                system("pause");
                system("cls");
        }
	}while(opcoes != 0);
}
