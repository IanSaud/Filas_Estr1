/**************************************
* Trabalho 1-AV2 de Estrutura de Dados I
* Curso de Sistemas da informacao
* Aluno: Ian Saud Soares - matricula: 0050011104
* Filas
***************************************/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

struct lista {
    char info[20];
    struct lista * prox;
};

typedef struct lista Lista;

struct fila{
    Lista* ini;
    Lista* fim;
};
typedef struct fila Fila;

int fila_vazia(Fila* f)
{
    if(f->ini==NULL)
        return 1;
    return 0;
}
Fila* fila_cria (void)
{
    Fila* f = (Fila*) malloc(sizeof(Fila));
	f->ini = f->fim = NULL;
	return f;
}
void fila_insere(Fila*f, char v[])
{
	Lista* T = (Lista*) malloc(sizeof(Lista));
	strcpy(T->info,v);
	T->prox = NULL;
	if (f->fim != NULL)
		f->fim->prox = T;
	else 
		f->ini = T;
		f->fim = T; 
}
char fila_retira (Fila* f, char*a)
{ 
	Lista* T;
	if (fila_vazia(f))
	{ 
		printf("Fila vazia.\n");
		exit(1);
	}
	T = f->ini;
	strcpy(a,T->info);
	f->ini = T->prox;
	if (f->ini == NULL) /* verifica se fila ficou vazia */
	f->fim = NULL;
	free(T);
}
void fila_libera (Fila* f)
{
	Lista* q = f->ini;
	while (q!=NULL) 
	{
		Lista* t = q->prox;
		free(q);
		q = t;
	}
	free(f);
}

