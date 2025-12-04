#include <stdio.h>
#include <string.h>


// DEFINI플O DAS ESTRUTURAS

struct Caixa
{
	int prioridade;
	char Arquivo[100];
	int tempo;
	Caixa *prox;
	Caixa *ant;
};

struct Processador
{
	int qtde;
	int NumeroProcessador;
	Processador *prox;
	Caixa *inicio, *fim;
};

struct DescProc
{
	Processador *inicio;
	Processador *fim;
};

struct ExecucoesEPrioridades
{
	int GDI;
	int GDE;
	int DEL;
	int LER;
	int IMP;
	int P1,P2,P3,P4;	
};




// DEFINI플O DE FUN합ES

void InicializarProcessador (DescProc &P);
Processador* CriarProcessador (int NumeroProcessador);
Caixa* CriarCaixa (char Arquivo[], int prioridade, int tempo);
int Vazia (Processador *P);
Processador* KillProcessador (Processador *P);
Caixa* KillCaixa (Caixa *C);



// CRIAR PROCESSADOR E CAIXAS / INICIALIAZA플O

void InicializarProcessador (DescProc &P)
{
	Processador *Aux = P.inicio;
	while (Aux != NULL)
	{
		Aux->inicio = KillCaixa(Aux->inicio);
		Aux = Aux->prox;
	}
	if (P.inicio != NULL)
		P.inicio = P.fim = KillProcessador(P.inicio);
}

Processador* CriarProcessador (int NumeroProcessador)
{
	Processador *NovaCaixa = new Processador;
	NovaCaixa->NumeroProcessador = NumeroProcessador;
	NovaCaixa->prox = NULL;
	NovaCaixa->inicio = NULL;
	NovaCaixa->fim = NULL;
	NovaCaixa->qtde = 0;
	return NovaCaixa;
}

Caixa* CriarCaixa (char Arquivo[], int prioridade, int tempo)
{
	Caixa *NovaCaixa = new Caixa;
	strcpy(NovaCaixa->Arquivo,Arquivo);
	NovaCaixa->prioridade = prioridade;
	NovaCaixa->tempo = tempo;
	NovaCaixa->ant = NULL;
	NovaCaixa->prox = NULL;
	return NovaCaixa;
}




// OUTRAS FUN합ES





int Vazia (Processador *P) // PERGUNTA SE A LISTA DE CAIXAS EST� VAZIA
{
	if (P->inicio == NULL)
		return 1;
	else
		return 0;
}



Processador* Inserir (Processador *P, char Arquivo[], int prioridade, int tempo)
{
	if (P->inicio == NULL)
	{
		P->inicio = P->fim = CriarCaixa(Arquivo,prioridade,tempo);
	}
	else
	{
		P->fim->prox = CriarCaixa(Arquivo,prioridade,tempo);
		P->fim->prox->ant = P->fim;
		P->fim = P->fim->prox;
		
		// INSER플O DIRETA
		
		Caixa Troca;
		Caixa *Aux = P->fim;
		while (Aux->ant != P->inicio && Aux->ant->prioridade > Aux->prioridade)
		{
			strcpy(Troca.Arquivo,Aux->Arquivo);
			Troca.prioridade = Aux->prioridade;
			Troca.tempo = Aux->tempo;
			
			strcpy(Aux->Arquivo,Aux->ant->Arquivo);
			Aux->prioridade = Aux->ant->prioridade;
			Aux->tempo = Aux->ant->tempo;
			
			strcpy(Aux->ant->Arquivo,Troca.Arquivo);
			Aux->ant->prioridade = Troca.prioridade;
			Aux->ant->tempo = Troca.tempo;
			
			Aux = Aux->ant;
		}
	}
	P->qtde++;
	return P;
}



void Retirar (Processador *P)
{
	Caixa *Aux;
	Aux = P->inicio;
	if (P->inicio->prox == NULL)
	{
		P->inicio = P->inicio->prox;
		P->fim = NULL;
	}
	else
	{
		P->inicio = P->inicio->prox;
		P->inicio->ant = NULL;
	}
	P->qtde--;
	delete(Aux);
}



Processador* KillProcessador (Processador *P)
{
	if (P == NULL)
		return NULL;
	if (P->prox != NULL)
	{
		KillProcessador(P->prox);
		delete(P);
	}
	return NULL;
}


Caixa* KillCaixa (Caixa *C)
{
	if (C == NULL)
		return NULL;
	if (C->prox != NULL)
	{
		KillCaixa(C->prox);
		delete(C);
	}
	return NULL;
}



Caixa* ElementoInicio (Processador *P)
{
	return P->inicio;
}

Caixa* ElementoFim (Processador *P)
{
	return P->fim;
}

