#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<conio2.h>

#include "TADLISTAPRIORIDADE.h"	


// FUNÇÕES ESTÉTICAS 


void moldura (int CI, int LI, int CF, int LF, int corFr, int corFu)
{
	int i;
	textcolor(RED);  //0 a 15
	textbackground(0);   //0 a 7
	gotoxy(CI,LI);
	printf ("%c",201);
	gotoxy(CI,LF);
	printf ("%c",200);
	gotoxy(CF,LI);
	printf ("%c",187);
	gotoxy(CF,LF);
	printf ("%c",188);
	
	//Verticais
	for (i=CI+1;i < CF;i++)
	{
		gotoxy(i,LI);
		printf ("%c",205);
		gotoxy(i,LF);
		printf ("%c",205);
	}
	
	//Horizontais
	for (i=LI+1;i < LF;i++)
	{
		gotoxy(CI,i);
		printf ("%c",186);
		gotoxy(CF,i);
		printf ("%c",186);
	}
	textcolor(RED);
	textbackground(0);
}

//CARREGAMENTO

void telacarregamento (void)
{
	clrscr();
	textcolor(RED);
	gotoxy (43,17);
	printf ("Threadripper 5995WX");
	textcolor(WHITE);
	gotoxy(43,18);
	printf ("Carregando Aguarde");
	
	gotoxy(61,18); printf ("..."); 
	
	moldura(20,20,84,22,7,0);
	textbackground(LIGHTGRAY);
	gotoxy(21,21);
	printf ("          "); Sleep(50);
	printf ("        "); Sleep(50);
	printf ("           "); Sleep(70);
	printf ("          "); Sleep(50);
	printf ("          "); Sleep(100);
	printf ("         "); Sleep(100);
	printf ("     "); Sleep(100);
	
	textbackground(BLACK);
	gotoxy(1,1);
}
//LIMPA TELA DA DIREITA (VISUALIZAÇÃO)
void limpavisu (void)
{
	for (int i=8; i < 29;i++)
	{
		gotoxy(58,i);
		printf ("                                         ");
	}
}
//LIMPA TELA DA ESQUERDA (MENU)
void limpamenu (void)
{
	for (int i=7; i < 29;i++)
	{
		gotoxy(4,i);
		printf ("                                             ");
	}
}

void FormPrincipal (void)
{
	moldura(1,1,102,34,0,2);
	moldura(5,3,98,5,7,0);
	textcolor(WHITE);
	gotoxy(37,4);
	printf ("### Threadripper 5995WX ###");
	moldura(5,30,98,32,7,0);
	textcolor(WHITE);
	gotoxy(6,31);
	printf ("MENSAGEM: ");
	textcolor(WHITE);
	gotoxy(45,7);
	printf ("** MENU **");
	textbackground(RED);
	gotoxy(43,7);
	printf (" ");
	gotoxy(56,7);
	printf (" ");
	textbackground(BLACK);
	moldura(3,6,100,29,7,0);
}

void MENU(void)
{
	clrscr();
	FormPrincipal();
	textcolor(WHITE);
	gotoxy(48,10);
	printf("[A] ");
	gotoxy(42,12);
	printf("### EXECUTAR ###");
	gotoxy(48,15);
	printf("[B] ");
	gotoxy(38,17);
	printf("### RETOMAR EXECUCAO ###");
	gotoxy(48,20);
	printf("[C] ");
	gotoxy(43,22);
	printf("### SOBRE ###");
	gotoxy(44,23);
	printf("(INSTRUCOES)");
	gotoxy(45,26);
	printf ("[0] SAIR");
	gotoxy(90,28);
	printf("OPCAO: ");
}

void Legenda(void);

void DesenhoExecucao (void)
{
	clrscr();
	// TELA
	moldura(1,1,102,34,0,2);
	Legenda();
	textcolor(WHITE);
	gotoxy(45,4);
	printf("** EXECUCAO **");
	textbackground(RED);
	textcolor(RED);
	gotoxy(43,4);
	printf (" ");
	gotoxy(60,4);
	printf (" ");
	textbackground(BLACK);
	// PROCESSADORES
	moldura(4,12,24,20,7,0);
	moldura(29,12,49,20,7,0);
	moldura(54,12,74,20,7,0);
	moldura(79,12,99,20,7,0);
	// P1,P2,P3,P4
	textcolor(WHITE);
	gotoxy(12,10);
	printf("NUCLEO");
	gotoxy(37,10);
	printf("NUCLEO");
	gotoxy(62,10);
	printf("NUCLEO");
	gotoxy(87,10);
	printf("NUCLEO");
	textcolor(RED);
	gotoxy(14,8);
	printf("1");
	gotoxy(39,8);
	printf("2");
	gotoxy(64,8);
	printf("3");
	gotoxy(89,8);
	printf("4");
	
	// TEXTO "INSTRUÇÕES NA FILA" EM CADA NUCLEO
	
	gotoxy(10,24);
	printf("INSTRUCOES");
	gotoxy(11,25);
	printf("NA FILA");
	
	gotoxy(35,24);
	printf("INSTRUCOES");
	gotoxy(36,25);
	printf("NA FILA");
	
	gotoxy(60,24);
	printf("INSTRUCOES");
	gotoxy(61,25);
	printf("NA FILA");
	
	gotoxy(85,24);
	printf("INSTRUCOES");
	gotoxy(86,25);
	printf("NA FILA");
	
	// TEMPO DE EXECUÇÃO
	textcolor(WHITE);
	gotoxy(4,31);
	printf("TEMPO DE EXECUCAO: ");
	textcolor(RED);
}

void Sobre (void)
{
	clrscr();
	moldura(1,1,102,34,0,2);
	gotoxy(30,4);
	printf("TRABALHO 2 BIMESTRE / ESTRUTURAS DE DADOS I");
	gotoxy(8,7);
	textcolor(WHITE);
	printf("O PRESENTE TRABALHO DEMONSTRA A EXECUCAO DE UM PROCESSADOR COM 4 NUCLEOS DIFERENTES");
	gotoxy(8,8);
	printf("EM QUE O MESMO EXECUTA INSTRUCOES VINDAS DE UM ARQUIVO TEXTO, ONDE CADA EXECUCAO");
	gotoxy(8,9);
	printf("CHAMA SEU RESPECTIVO NUCLEO E ENTRA EM UMA FILA DE INSTRUCOES PARA SER PROCESSADO.");
	gotoxy(8,10);
	printf("ATE MESMO PODENDO SER INTERROMPIDO AO MENOR APERTO DE UMA TECLA, ONDE SERA ARMAZENADO");
	gotoxy(8,11);
	printf("O RESTO DAS INSTRUCOES A SEREM EXECUTADAS POSTERIOMENTE, JUNTO DE UM PEQUENO RELATORIO");
	gotoxy(8,12);
	printf("AO FINAL DA SIMULACAO.");
	gotoxy(42,15);
	textcolor(RED);
	printf("FUNCIONALIDADES:");
	//FUNCIONALIDADE 1
	gotoxy(9,18);
	printf("RETOMADA DA EXECUCAO (DENTRO E FORA)");
	//FUNCIONALIDADE 2
	gotoxy(57,18);
	printf("TERMINAR INSTRUCOES JA EXISTENTES");
	// FUNCIONALIDADE 3
	gotoxy(34,25);
	printf("ESTRUTURA 100 POR CENTO DINAMICA");
	textcolor(WHITE);
	// 1
	gotoxy(9,20);
	printf("POSSIBILIDADE DE RETOMAR TANTO");
	gotoxy(9,21);
	printf("COM O PROGRAMA ATIVO, QUANTO APOS");
	gotoxy(9,22);
	printf("RECOMPILAR O MESMO NOVAMENTE");
	// 2
	gotoxy(57,20);
	printf("POSSIBILIDADE DE SALVAR AS FILAS DE");
	gotoxy(57,21);
	printf("INSTRUCOES, SEM PERDE-LAS, PARA UMA");
	gotoxy(57,22);
	printf("POSSIVEL RETOMADA FUTURA, OU NAO");
	//3
	gotoxy(29,27);
	printf("OS PROCESSADORES E SUAS FILAS DE INSTRUCOES");
	gotoxy(26,28);
	printf("SAO CRIADOS E DELETADOS DE FORMA DINAMICA, OU SEJA");
	gotoxy(29,29);
	printf("O PROGRAMA PODE FUNCIONAR COM X PROCESSADORES,");
	gotoxy(39,30);
	printf("COM EXCECAO DO DESENHO");
	// INTEGRANTES
	textcolor(RED);
	gotoxy(43,33);
	printf("PARTICIPANTES");
	textcolor(WHITE);
	gotoxy(7,33);
	printf("LUIS FERNANDO OLIVEIRA BELATO");
	gotoxy(63,33);
	printf("NICOLAS AUGUSTO SILVA OLIVEIRA");
	getch();
}


void Legenda (void)
{
	gotoxy(68,28);
	printf("GDI - Gravar Dispositivo Interno");
	gotoxy(68,29);
	printf("GDE - Gravar Dispositivo Externo");
	gotoxy(68,30);
	printf("DEL - Deletar");
	gotoxy(68,31);
	printf("LER - Ler");
	gotoxy(68,32);
	printf("IMP - Imprimir");
	
	textcolor(WHITE);
	gotoxy(42,30);
	printf("PRIORIDADES ->");
	gotoxy(60,28);
	printf("MAIOR");
	gotoxy(60,32);
	printf("MENOR");
	textcolor(RED);
}

void LimparInstrucoesFila (int qtde)
{
	if (qtde <= 10)
	{
		gotoxy(90,22);
		printf(" ");
	}
}






// FUNÇÕES CONCRETAS






Processador* Busca (DescProc P, int NumeroProcessador)
{
	Processador *Aux = P.inicio;
	while (Aux != NULL && Aux->NumeroProcessador != NumeroProcessador)
		Aux = Aux->prox;
	return Aux;
}


int ConverterPrioridade (char comando[])
{
	int prioridade;
	if (stricmp(comando,"Gravar Dispositivo Interno") == 0)
		prioridade = 1;

	if (stricmp(comando,"Gravar Dispositivo Externo") == 0)
		prioridade = 2;
		
	if (stricmp(comando,"Deletar") == 0)
		prioridade = 3;
		
	if (stricmp(comando,"Ler") == 0)
		prioridade = 4;	
		
	if (stricmp(comando,"Imprimir") == 0)
		prioridade = 5;	
	
	return prioridade;
}

void ConverterPrioridadeReverso (int a,char c[])
{	
	if (a == 1)
		strcat(c,"Gravar Dispositivo Interno");

	if (a == 2)
		strcat(c,"Gravar Dispositivo Externo");
		
	if (a == 3)
		strcat(c,"Deletar");
		
	if (a == 4)
		strcat(c,"Ler");
		
	if (a == 5)
		strcat(c,"Imprimir");
	strcat(c,'\0');	
	
}


void ConverterComando (char comando[], int Nucleo)
{
	int i,a;
	if (Nucleo == 1)
	{
		gotoxy(22,15);
		printf(" ");
		for (i=0; i < strlen(comando) && comando[i] != '.';i++);
		for (a=18;i < strlen(comando);i++,a++)
		{
			gotoxy(a,15);
			printf("%c",comando[i]);
		}
		gotoxy(7,15);
		printf("TP de Arq:");
	}
	if (Nucleo == 2)
	{
		gotoxy(47,15);
		printf(" ");
		for (i=0; i < strlen(comando) && comando[i] != '.';i++);
		for (a=43;i < strlen(comando);i++,a++)
		{
			gotoxy(a,15);
			printf("%c",comando[i]);
		}
		gotoxy(32,15);
		printf("TP de Arq:");
	}
	if (Nucleo == 3)
	{
		gotoxy(72,15);
		printf(" ");
		for (i=0; i < strlen(comando) && comando[i] != '.';i++);
		for (a=68;i < strlen(comando);i++,a++)
		{
			gotoxy(a,15);
			printf("%c",comando[i]);
		}
		gotoxy(57,15);
		printf("TP de Arq:");
	}
	if (Nucleo == 4)
	{
		gotoxy(97,15);
		printf(" ");
		for (i=0; i < strlen(comando) && comando[i] != '.';i++);
		for (a=93;i < strlen(comando);i++,a++)
		{
			gotoxy(a,15);
			printf("%c",comando[i]);
		}
		gotoxy(82,15);
		printf("TP de Arq:");
	}
}


void EsvaziarFilas (FILE *ptr,DescProc P, ExecucoesEPrioridades &EP, int &tempo)
{
	int cont=tempo;
	Processador *Aux = P.inicio;
	while(Aux != NULL)
	{
		if(!Vazia(Aux))
			Retirar(Aux);
		
		char O[60];
		
		Caixa *C = Aux->inicio;
		while(C != NULL)
		{
			cont++;
			
			if (Aux->NumeroProcessador == 1) EP.P1--;
			if (Aux->NumeroProcessador == 2) EP.P2--;
			if (Aux->NumeroProcessador == 3) EP.P3--;
			if (Aux->NumeroProcessador == 4) EP.P4--;
			
			if (C->prioridade == 1) EP.GDI--;
			if (C->prioridade == 2) EP.GDE--;
			if (C->prioridade == 3) EP.DEL--;
			if (C->prioridade == 4) EP.LER--;
			if (C->prioridade == 5) EP.IMP--;
			
			if(C->prioridade == 1)
			strcpy(O,"Gravar Dispositivo Interno\0");
			if(C->prioridade == 2)
			strcpy(O,"Gravar Dispositivo Externo\0");
			if(C->prioridade == 3)
			strcpy(O,"Deletar\0");
			if(C->prioridade == 4)
			strcpy(O,"Ler\0");
			if(C->prioridade == 5)
			strcpy(O,"Imprimir\0");
		
			fprintf(ptr,"%d,%s,%s,%d\n",Aux->NumeroProcessador,C->Arquivo,O,C->tempo);
			C= C->prox;		
		}
		Aux = Aux->prox;
	}
	tempo = cont;
}





void VisualizarFila (int Nucleo, DescProc P)
{
	int i,j=0;
	clrscr();
	moldura(1,1,102,34,0,2);
	Processador *Aux = P.inicio;
	
	while (Aux != NULL && Aux->NumeroProcessador != Nucleo)
		Aux = Aux->prox;
		
	if (Aux != NULL && !Vazia(Aux))
	{
		gotoxy(43,12);
		printf("FILA: NUCLEO %d",Nucleo);
		Caixa *Aux1 = Aux->inicio;
		i = 15;
		while(Aux1 != NULL)
		{
			gotoxy(43,i);
			if(Aux1->prioridade == 1)
				printf("PRIORIDADE: GDI");
			if(Aux1->prioridade == 2)
				printf("PRIORIDADE: GDE");
			if(Aux1->prioridade == 3)
				printf("PRIORIDADE: DEL");
			if(Aux1->prioridade == 4)
				printf("PRIORIDADE: LER");
			if(Aux1->prioridade == 5)
				printf("PRIORIDADE: IMP");
			
			gotoxy(27,i+1); i=i+2; j++;
			textcolor(WHITE);
			printf("INSTRUCAO: %d | ARQUIVO: %s - TEMPO: %d", j, Aux1->Arquivo, Aux1->tempo);
			Aux1 = Aux1->prox;
			textcolor(RED);
		}
	}
	else
	{
		textbackground(RED);
		gotoxy(39,17);
		printf(" ");
		gotoxy(61,17);
		printf(" ");
		gotoxy(41,17);
		textbackground(BLACK);
		printf("AVISO: FILA VAZIA !");
	}
	getch();
}





bool Leitura(DescProc &P, FILE *ponteiro, int &tempo, ExecucoesEPrioridades &EP)
{
	rewind(ponteiro);
	DesenhoExecucao();
	Processador *Aux;
	int flag;
	int prioridade;
	int controleEntrada=tempo;
	char comando[300];
	int NumP;
	int escolhe = 0;
	char nomeArq[300];
	bool Acabou;
	fscanf(ponteiro,"%d,%[^,],%[^,],%d\n",&NumP,&nomeArq,&comando,&tempo);
	while(!feof(ponteiro) && escolhe != 27)
	{
		
		if (P.inicio == NULL) // SE A LISTA DE PROCESSADORES ESTIVER VAZIA
		{
			P.inicio = P.fim = CriarProcessador(NumP);
		}
			
		Aux = Busca(P,NumP); // PROCURAR SE EXISTE O PROCESSADOR NA LISTA DE PROCESSADORES
		
		if (Aux == NULL) 
		{
			P.fim->prox = CriarProcessador(NumP);   // SE NÃO ENCONTRAR O PROCESSADOR NA LISTA DE PROCESSADORES, CRIAR UM PROCESSADOR NO FINAL
			P.fim = P.fim->prox;
			Aux = P.fim;
		}
		
		
		if (controleEntrada % 2 == 0)
		{
			// DEFINIR A PRIORIDADE
			
			prioridade = ConverterPrioridade(comando);
			
			// INSERIR NA FILA
				
			Inserir(Aux,nomeArq,prioridade,tempo);
			
			// CONTADORES
			
			if (NumP == 1) EP.P1++;
			if (NumP == 2) EP.P2++;
			if (NumP == 3) EP.P3++;
			if (NumP == 4) EP.P4++;
			
			if (stricmp(comando,"Gravar Dispositivo Interno") == 0) EP.GDI++;
			if (stricmp(comando,"Gravar Dispositivo Externo") == 0) EP.GDE++;
			if (stricmp(comando,"Deletar") == 0) EP.DEL++;
			if (stricmp(comando,"Ler") == 0) EP.LER++;	
			if (stricmp(comando,"Imprimir") == 0) EP.IMP++;	
			
			// SAI LIDO
			
			fscanf(ponteiro,"%d,%[^,],%[^,],%d\n",&NumP,&nomeArq,&comando,&tempo);	
		}
		
		// VARREDURA PARA DECREMENTAR O TEMPO DE EXECUÇÃO DA CAIXA DO INICIO DA FILA DE CADA PROCESSADOR
		
		// NA NOSSA LISTA DE PROCESSADORES, AS CAIXAS VÃO FICAR NA ORDEM (3,1,4,2) E NÃO (1,2,3,4)
		
		Aux = P.inicio;
		while (Aux != NULL)
		{
			fflush(stdin);
			
			if (Vazia(Aux) && Aux->NumeroProcessador == 1)
			{
				gotoxy(6,15);
				printf("                 ");
				gotoxy(6,16);
				printf("                 ");
				gotoxy(6,17);
				printf("                 ");
			}
			if (Vazia(Aux) && Aux->NumeroProcessador == 2)
			{
				gotoxy(31,15);
				printf("                 ");
				gotoxy(31,16);
				printf("                 ");
				gotoxy(31,17);
				printf("                 ");
			}
			if (Vazia(Aux) && Aux->NumeroProcessador == 3)
			{
				gotoxy(56,15);
				printf("                 ");
				gotoxy(56,16);
				printf("                 ");
				gotoxy(56,17);
				printf("                 ");
			}
			if (Vazia(Aux) && Aux->NumeroProcessador == 4)
			{
				gotoxy(82,15);
				printf("                 ");
				gotoxy(82,16);
				printf("                 ");
				gotoxy(82,17);
				printf("                 ");
			}			
			if (!Vazia(Aux) && Aux->NumeroProcessador == 1)
			{
				gotoxy(14,22);
				printf("%d",Aux->qtde-1);
				gotoxy(10,17);
				printf("Tempo: %d",Aux->inicio->tempo);
				if(Aux->inicio->prioridade == 1)
				{
					
					gotoxy(7,16);
					printf("Prioridade: GDI");	
				}
				if(Aux->inicio->prioridade == 2)
				{
					
					gotoxy(7,16);
					printf("Prioridade: GDE");	
				}
				if(Aux->inicio->prioridade == 3)
				{
					gotoxy(7,16);
					printf("Prioridade: DEL");	
				}
				if(Aux->inicio->prioridade == 4)
				{
					gotoxy(7,16);
					printf("Prioridade: Ler");	
				}
				if(Aux->inicio->prioridade == 5)
				{
					gotoxy(7,16);
					printf("Prioridade: IMP");	
				}
				
				ConverterComando(Aux->inicio->Arquivo,1);
				
			}
			if (!Vazia(Aux) && Aux->NumeroProcessador == 2)
			{
				gotoxy(39,22);
				printf("%d",Aux->qtde-1);
				gotoxy(35,17);
				printf("Tempo: %d",Aux->inicio->tempo);
				
				if(Aux->inicio->prioridade == 1)
				{
					gotoxy(32,16);
					printf("Prioridade: GDI");	
				}
				if(Aux->inicio->prioridade == 2)
				{
					gotoxy(32,16);
					printf("Prioridade: GDE");	
				}
				if(Aux->inicio->prioridade == 3)
				{
					gotoxy(32,16);
					printf("Prioridade: DEL");	
				}
				if(Aux->inicio->prioridade == 4)
				{
					gotoxy(32,16);
					printf("Prioridade: Ler");	
				}
				if(Aux->inicio->prioridade == 5)
				{
					gotoxy(32,16);
					printf("Prioridade: IMP");	
				}
				
				ConverterComando(Aux->inicio->Arquivo,2);
			}
			if (!Vazia(Aux) && Aux->NumeroProcessador == 3)
			{
				gotoxy(64,22);
				printf("%d",Aux->qtde-1);
				gotoxy(60,17);
				printf("Tempo: %d",Aux->inicio->tempo);
				
				if(Aux->inicio->prioridade == 1)
				{
					gotoxy(57,16);

					printf("Prioridade: GDI");	
				}
				if(Aux->inicio->prioridade == 2)
				{
					gotoxy(57,16);
					printf("Prioridade: GDE");	
				}
				if(Aux->inicio->prioridade == 3)
				{
					gotoxy(57,16);
					printf("Prioridade: DEL");	
				}
				if(Aux->inicio->prioridade == 4)
				{
					gotoxy(57,16);
					printf("Prioridade: Ler");	
				}
				if(Aux->inicio->prioridade == 5)
				{
					gotoxy(57,16);
					printf("Prioridade: IMP");	
				}
				
				ConverterComando(Aux->inicio->Arquivo,3);
			}
			if (!Vazia(Aux) && Aux->NumeroProcessador == 4)
			{
				LimparInstrucoesFila(Aux->qtde);
				gotoxy(89,22);
				printf("%d",Aux->qtde -1);
				gotoxy(85,17);
				printf("Tempo: %d",Aux->inicio->tempo);
				
				if(Aux->inicio->prioridade == 1)
				{
					gotoxy(82,16);

					printf("Prioridade: GDI");	
				}
				if(Aux->inicio->prioridade == 2)
				{
					gotoxy(82,16);
					printf("Prioridade: GDE");	
				}
				if(Aux->inicio->prioridade == 3)
				{
					gotoxy(82,16);
					printf("Prioridade: DEL");	
				}
				if(Aux->inicio->prioridade == 4)
				{
					gotoxy(82,16);
					printf("Prioridade: LER");	
				}
				if(Aux->inicio->prioridade == 5)
				{
					gotoxy(82,16);
					printf("Prioridade: IMP");	
				}
				
				ConverterComando(Aux->inicio->Arquivo,4);
			}
			if (!Vazia(Aux))
			{
				Aux->inicio->tempo--;
				if (!Vazia(Aux) && Aux->inicio->tempo == 8)
					{
						gotoxy(18,17);
						printf("  ");
						gotoxy(43,17);
						printf("  ");
						gotoxy(68,17);
						printf("  ");
						gotoxy(93,17);
						printf("  ");
					}
				if (Aux->inicio->tempo == -1) Retirar(Aux);
			}		
			Aux = Aux->prox;
		}
		
		gotoxy(23,31);
		printf("%d SEGUNDOS",controleEntrada-2);
		controleEntrada++;
		Sleep(100);
		
		escolhe = 0;
		
		if(kbhit())
			escolhe = getch();
			
		if (escolhe == 49)
		{
			VisualizarFila(1,P);
			DesenhoExecucao();
		}
		if (escolhe == 50)
		{
			VisualizarFila(2,P);
			DesenhoExecucao();
		}
		if (escolhe == 51)
		{
			VisualizarFila(3,P);
			DesenhoExecucao();
		}
		if (escolhe == 52)
		{
			VisualizarFila(4,P);
			DesenhoExecucao();
		}
	}	
	tempo = controleEntrada;
	
	if (NumP == 1) EP.P1++;
	if (NumP == 2) EP.P2++;
	if (NumP == 3) EP.P3++;
	if (NumP == 4) EP.P4++;
	
	if (stricmp(comando,"Gravar Dispositivo Interno") == 0) EP.GDI++;
	if (stricmp(comando,"Gravar Dispositivo Externo") == 0) EP.GDE++;
	if (stricmp(comando,"Deletar") == 0) EP.DEL++;
	if (stricmp(comando,"Ler") == 0) EP.LER++;	
	if (stricmp(comando,"Imprimir") == 0) EP.IMP++;	
	
	// PREPARAR O ARQUIVO PARA A RETOMADA DA EXECUÇÃO
	
	if (!feof(ponteiro)) // O IF PERGUNTA SE A REPETIÇÃO ACABOU PQ ALGUEM APERTOU ALGUMA TECLA
	{		
		// ----------------------------------------------------------------------------------------------------------------------
		
		textbackground(RED);
		gotoxy(34,4);
		printf(" ");
		gotoxy(71,4);
		printf(" ");
		textcolor(WHITE);
		textbackground(BLACK);
		gotoxy(36,4);
		printf("TERMINANDO PROCESSOS PENDENTES ...");
		textcolor(RED);
		Sleep(1500);
		flag = 1;
		while (flag == 1)
		{
			Aux = P.inicio;	
			while (Aux != NULL)
			{
				fflush(stdin);
				
				if (Vazia(Aux) && Aux->NumeroProcessador == 1)
				{
					gotoxy(6,15);
					printf("                 ");
					gotoxy(6,16);
					printf("                 ");
					gotoxy(6,17);
					printf("                 ");
				}
				if (Vazia(Aux) && Aux->NumeroProcessador == 2)
				{
					gotoxy(31,15);
					printf("                 ");
					gotoxy(31,16);
					printf("                 ");
					gotoxy(31,17);
					printf("                 ");
				}
				if (Vazia(Aux) && Aux->NumeroProcessador == 3)
				{
					gotoxy(56,15);
					printf("                 ");
					gotoxy(56,16);
					printf("                 ");
					gotoxy(56,17);
					printf("                 ");
				}
				if (Vazia(Aux) && Aux->NumeroProcessador == 4)
				{
					gotoxy(82,15);
					printf("                 ");
					gotoxy(82,16);
					printf("                 ");
					gotoxy(82,17);
					printf("                 ");
				}			
				if (!Vazia(Aux) && Aux->NumeroProcessador == 1)
				{
					gotoxy(14,22);
					printf("%d",Aux->qtde-1);
					gotoxy(10,17);
					printf("Tempo: %d",Aux->inicio->tempo);
					if(Aux->inicio->prioridade == 1)
					{
						
						gotoxy(7,16);
						printf("Prioridade: GDI");	
					}
					if(Aux->inicio->prioridade == 2)
					{
						
						gotoxy(7,16);
						printf("Prioridade: GDE");	
					}
					if(Aux->inicio->prioridade == 3)
					{
						gotoxy(7,16);
						printf("Prioridade: DEL");	
					}
					if(Aux->inicio->prioridade == 4)
					{
						gotoxy(7,16);
						printf("Prioridade: Ler");	
					}
					if(Aux->inicio->prioridade == 5)
					{
						gotoxy(7,16);
						printf("Prioridade: IMP");	
					}
					
					ConverterComando(Aux->inicio->Arquivo,1);
					
				}
				if (!Vazia(Aux) && Aux->NumeroProcessador == 2)
				{
					gotoxy(39,22);
					printf("%d",Aux->qtde-1);
					gotoxy(35,17);
					printf("Tempo: %d",Aux->inicio->tempo);
					
					if(Aux->inicio->prioridade == 1)
					{
						gotoxy(32,16);
						printf("Prioridade: GDI");	
					}
					if(Aux->inicio->prioridade == 2)
					{
						gotoxy(32,16);
						printf("Prioridade: GDE");	
					}
					if(Aux->inicio->prioridade == 3)
					{
						gotoxy(32,16);
						printf("Prioridade: DEL");	
					}
					if(Aux->inicio->prioridade == 4)
					{
						gotoxy(32,16);
						printf("Prioridade: Ler");	
					}
					if(Aux->inicio->prioridade == 5)
					{
						gotoxy(32,16);
						printf("Prioridade: IMP");	
					}
					
					ConverterComando(Aux->inicio->Arquivo,2);
				}
				if (!Vazia(Aux) && Aux->NumeroProcessador == 3)
				{
					gotoxy(64,22);
					printf("%d",Aux->qtde-1);
					gotoxy(60,17);
					printf("Tempo: %d",Aux->inicio->tempo);
					
					if(Aux->inicio->prioridade == 1)
					{
						gotoxy(57,16);
	
						printf("Prioridade: GDI");	
					}
					if(Aux->inicio->prioridade == 2)
					{
						gotoxy(57,16);
						printf("Prioridade: GDE");	
					}
					if(Aux->inicio->prioridade == 3)
					{
						gotoxy(57,16);
						printf("Prioridade: DEL");	
					}
					if(Aux->inicio->prioridade == 4)
					{
						gotoxy(57,16);
						printf("Prioridade: Ler");	
					}
					if(Aux->inicio->prioridade == 5)
					{
						gotoxy(57,16);
						printf("Prioridade: IMP");	
					}
					
					ConverterComando(Aux->inicio->Arquivo,3);
				}
				if (!Vazia(Aux) && Aux->NumeroProcessador == 4)
				{
					LimparInstrucoesFila(Aux->qtde);
					gotoxy(89,22);
					printf("%d",Aux->qtde -1);
					gotoxy(85,17);
					printf("Tempo: %d",Aux->inicio->tempo);
					
					if(Aux->inicio->prioridade == 1)
					{
						gotoxy(82,16);
	
						printf("Prioridade: GDI");	
					}
					if(Aux->inicio->prioridade == 2)
					{
						gotoxy(82,16);
						printf("Prioridade: GDE");	
					}
					if(Aux->inicio->prioridade == 3)
					{
						gotoxy(82,16);
						printf("Prioridade: DEL");	
					}
					if(Aux->inicio->prioridade == 4)
					{
						gotoxy(82,16);
						printf("Prioridade: LER");	
					}
					if(Aux->inicio->prioridade == 5)
					{
						gotoxy(82,16);
						printf("Prioridade: IMP");	
					}
					
					ConverterComando(Aux->inicio->Arquivo,4);
				}
				if (!Vazia(Aux))
				{
					if(Aux->inicio->tempo > 0)
						Aux->inicio->tempo--;
					if (!Vazia(Aux) && Aux->inicio->tempo == 8)
						{
							gotoxy(18,17);
							printf("  ");
							gotoxy(43,17);
							printf("  ");
							gotoxy(68,17);
							printf("  ");
							gotoxy(93,17);
							printf("  ");
						}
					
				}		
				Aux = Aux->prox;
			}
			Aux = P.inicio;
			flag = 0;
			while (Aux != NULL)
			{
				if (!Vazia(Aux)&& Aux->inicio->tempo != 0 )
					flag=1;
				Aux = Aux->prox;
			}
			Sleep(200);
		}
		clrscr();
		
		//PASSA DA FILA PARA O ARQUIVO NOVAMENTE
		FILE *ptr = fopen ("instrucoes_retomada.txt","w+");
		EsvaziarFilas(ptr,P,EP,tempo);
		
		
		
		// CRIAR ARQUIVO COM OS CONTADORES
		
		FILE *ptro = fopen ("processos_contadores.txt","w+");
		fprintf(ptro,"%d,%d,%d,%d\n",EP.P1,EP.P2,EP.P3,EP.P4); // PROCESSOS
		fprintf(ptro,"%d,%d,%d,%d,%d\n",EP.GDI,EP.GDE,EP.DEL,EP.LER,EP.IMP); // PRIORIDADES
		fprintf(ptro,"%d",tempo);
		fclose(ptro);


		//-----------------------------------------------------------------------------------------------------------------------------
		
		
		Acabou = false;
		char c ,temp[500];
		fgets(temp,500,ponteiro);
		while(!feof(ponteiro))
		{
			fputs(temp,ptr);
			fgets(temp,500,ponteiro);
		}
		fclose(ptr);
		fclose(ponteiro);
		remove("instrucoes_retomadaaux.txt");
		rename("instrucoes_retomada.txt","instrucoes_retomadaaux.txt");
	}
	else
	{
		Acabou = true;
		fclose(ponteiro);
		remove("processos_contadores.txt");
		remove("instrucoes_retomada.txt");
		remove("instrucoes_retomadaaux.txt");
		clrscr();
		moldura(1,1,102,34,0,2);
		textcolor(WHITE);
		gotoxy(40,4);
		printf("** EXECUCAO FINALIZADA **");
		textbackground(RED);
		textcolor(RED);
		gotoxy(38,4);
		printf (" ");
		gotoxy(66,4);
		printf (" ");
		textbackground(BLACK);
		gotoxy(30,13);
		textcolor(WHITE);
		printf("TOTAL DE INSTRUCOES EXECUTADAS/PROCESSADOR:"); 
		textcolor(RED);
		gotoxy(22,15); printf("NUCLEO 1: %d",EP.P1); gotoxy(37,15); printf("NUCLEO 2: %d",EP.P2); gotoxy(52,15); printf("NUCLEO 3: %d",EP.P3); gotoxy(67,15); printf("NUCLEO 4: %d",EP.P4);
		textcolor(WHITE);
		gotoxy(30,17);
		printf("TOTAL INDIVIDUAL DE TIPO DE TAREFA/EXECUCAO:");
		textcolor(RED);
		gotoxy(36,19);
		printf("%d - Gravar Dispositivo Interno",EP.GDE);
		gotoxy(36,20);
		printf("%d - Gravar Dispositivo Externo",EP.GDI);
		gotoxy(36,21);
		printf("%d - Deletar",EP.DEL);
		gotoxy(36,22);
		printf("%d - Ler",EP.LER);
		gotoxy(36,23);
		printf("%d - Imprimir",EP.IMP);
		getch();
	}
	return Acabou;
}








bool Retomar (DescProc &P, bool Acabou, int &tempo, ExecucoesEPrioridades &EP)
{
	if (Acabou == true) // SE A EXECUÇÃO FOR FINALIZADA
		{
			gotoxy(16,31);
			printf("Execucao Finalizada Nao Pode ser Retomada");
			getch();
		}
	else
	{
		FILE *ponteiro = fopen ("instrucoes_retomadaaux.txt","r+");
		if (ponteiro == NULL) // SE O ARQUIVO NÃO EXISTIR 
			return false;
		else // SE A EXECUÇÃO NÃO FOR FINALIZADA
		{
			// ARQUIVO DOS CONTADORES
	
			FILE *ptr = fopen("processos_contadores.txt","r+");
			if (ptr == NULL) // SE ELE NÃO EXISTIR
			{
				return false;
				getch();
			}
				
			else
			{
				fscanf(ptr,"%d,%d,%d,%d\n",&EP.P1,&EP.P2,&EP.P3,&EP.P4);
				fscanf(ptr,"%d,%d,%d,%d,%d\n",&EP.GDI,&EP.GDE,&EP.DEL,&EP.LER,&EP.IMP);
				fscanf(ptr,"%d",&tempo);
				fclose(ptr);
			}
			return Leitura(P,ponteiro,tempo,EP);
		}
	}
}





void InicializarEP (ExecucoesEPrioridades &EP)
{
	EP.GDI = 0;
	EP.GDE = 0;
	EP.DEL = 0;
	EP.LER = 0;
	EP.IMP = 0;
	EP.P1 = 0;
	EP.P2 = 0;
	EP.P3 = 0;
	EP.P4 = 0;	
}

// MAIN





int main ()
{
	int tempo;
	bool Acabou = false;
	char op='*';
	DescProc P;
	P.inicio = P.fim = NULL;
	InicializarProcessador(P);
	ExecucoesEPrioridades EP;
	Acabou = Retomar(P,Acabou,tempo,EP);
	do
	{
		if (op == '*')
			telacarregamento();
		
		MENU();
		op = toupper(getche());
		if (op == 'A')
		{
			FILE *ponteiro = fopen("instrucoes_do_processador.txt","r");
			tempo = 2;
			InicializarEP(EP);
			InicializarProcessador(P);
			Acabou = Leitura(P,ponteiro,tempo,EP);
		}
		if (op == 'B')
			Acabou = Retomar(P,Acabou,tempo,EP);
		if (op == 'C')
			Sobre();
		fflush(stdin);
	}while (op != '0');
	return 0;
}
