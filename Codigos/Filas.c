/**************************************
* Trabalho 1-AV2 de Estrutura de Dados I
* Curso de Sistemas da informacao
* Aluno: Ian Saud Soares - matricula: 0050011104
* Filas
***************************************/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Filas.h"
/* Perguntas */
/*Que cor é azul? R:Azul*/
/*Quanto é 2*2 R:4*/
/*Quem descobriu o brasil? R:Cabral*/
/*Quanto é 4+4 R:8*/
/*Se vc fosse um passaro qual seria R:Pombo*/

int main()
{
	Fila *a;
	a=fila_cria();
	int jogadores=0;
	int i;
	int random;
	int user;
	char quiz[4][100]=
	{
	{"Que cor eh azul?\n1. Verde\n2. Azul\n3. Roxo"},
	{"Quanto eh 2+2\n1. 4\n2. 5\n3. 6"},
	{"Se vc fosse um passaro, qual seria?\n1. Pombo\n2. Cachorro\n3. Baleia"},
	{"Quem descobriu o brasil?\n1.Gabriel\n2. EUM\n3. Pedro Alvares Cabral"}
	};
	char respostas[4][1]={{"2"}, {"1"}, {"1"}, {"3"}};
	char nome[20];
	int op=1;
	while (op==1)
	{
		puts("Entre com o nome do jogador para o Quiz");
		scanf("%s", &nome);
		system("cls");
		fflush(stdin);
		fila_insere(a, nome);
		jogadores++;
		printf("%s foi inserido\n\n", nome);
		puts("O que deseja fazer?");
		puts("1. Para continuar a registrar jogadores");
		puts("2. Para comecar o jogo");
		scanf("%d", &op);
	}
	if (fila_vazia(a))
	{
		puts("Nao ha jogadores");
		exit(1);
	}
	else
	{
		while(jogadores>1)
		{
			system("cls");
			fila_retira(a,nome);
			jogadores--;
			printf("%s, sua vez!!\n", nome);
			//random=rand()%3;
			random = 0 + ( rand() % 4 );
			for (i=0;quiz[random][i]!='\0';i++)
				printf("%c",quiz[random][i]);
				puts("");
			printf("Resposta: ");scanf("%s", &user);
			fflush(stdin);
			if (respostas[random][0]==user)
			{
				puts("Certa resposta");
				Sleep(1000);
				system("cls");
				fila_insere(a, nome);
				jogadores++;
			}
			else
			{
				puts("Eliminado");
				Sleep(1000);
				system("cls");
			} 
				
			
			
		}
		if (jogadores==1);
		{
			fila_retira(a,nome);
			printf("Parabéns %s vc foi o vencedor e ganhou 100 reais!!\n", nome);	
			
		}	
	}
	
	
	
	//Pergunta 1
	//Checar Resposta 1
	// se errar exclui do jogo
	// acertar volta pro fim da fila
	
	
}

