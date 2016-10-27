#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h>

int x, opcao, vazio;
char pergunta[6], temp[50];

//O sistema está bem organizado.
//Mas, bugou o pesquisar, listar e mostrar espaços vazios.
//NOTA= 5,0


long long cod;

struct _cadastro {
	long long codigo;     	//código
	long long telefone;		//11 digitos
	long long cep;			//8 digitos
	char nome[50];	    	//meh
	char endereco[50];
			
};

struct _cadastro pessoa[5];

int cadastrar() {
	for (x=0; x<5; x++) printf("\nDEBUG: pessoa[%d].codigo = %d\n", x, pessoa[x].codigo);
	
	printf("\nInforme o código --> ");
	scanf("%d", &cod);
	fflush(stdin);	
	
	for (x=0; x<5; x++) {
		if ( cod == pessoa[x].codigo ) {
			printf("\nDEBUG: cod = %d\n", cod);
			printf("\nDEBUG: INDICE %d CONTEM COD IGUAL AO CÓDIGO INFORMADO\n", x);
			break;
			
		
		} else {
			if (pessoa[x].codigo == 0) { //registrar so em campo vazio!
			
				printf("\nDEBUG: REGISTRANDO NO INDICE %d\n", x);
				printf("\nDEBUG: cod = %d\n", cod);
				//checagem pra não deixar registrar igual
				//if() ...
				
				pessoa[x].codigo = cod;
				printf("\nDEBUG: pessoa[%d].codigo = %d\n", x, pessoa[x].codigo);
	
				printf("\nInforme o nome --> ");
				scanf("%[A-Z a-z]", &pessoa[x].nome);
				//pessoa[x].nome = strupr (pessoa[x].nome);
				fflush(stdin);	
				
				printf("\nInforme o endereco --> ");
				scanf("%[A-Z a-z]", &pessoa[x].endereco);
				fflush(stdin);
				
				printf("\nInforme o cep --> ");
				scanf("%d", &pessoa[x].cep);
				fflush(stdin);
				
				printf("\nInforme o telefone --> ");
				scanf("%d", &pessoa[x].telefone);
				fflush(stdin);
				
				
				break;
			}
			
				
		}
	}
	
	fim();
		
}

int listar() {
	
	printf("\nListar por CODIGO ou NOME ? --> ");
	scanf("%s", &pergunta);
	fflush(stdin);

	
	if ( strcmp (pergunta , "CODIGO") == 0 ) {
		printf("\nDEBUG: por CODIGO!\n");
		
		printf("\nInforme o código --> ");
		scanf("%d", &cod);
		fflush(stdin);
		
		printf("\nDEBUG: buscando pelo código: %d\n", cod);
		
			for (x=0; x<5; x++) {
				if ( cod == pessoa[x].codigo) {
					printf("\n--> CODIGO %d encontrado no indice %d !\n", pessoa[x].codigo , x);
					printf("\n  == INDICE %d == \n", x);
					printf("\n      - nome:         %s", pessoa[x].nome);
					printf("\n      - endereco:     %s", pessoa[x].endereco);
					printf("\n      - cep:          %d", pessoa[x].cep);
					printf("\n      - telefone:     %d", pessoa[x].telefone);
					printf("\n\n");				
				}
		
			}
	
	} 
	
	if ( strcmp (pergunta , "NOME") == 0 ) {
		printf("\nDEBUG: por NOME!\n");
		
			
		printf("\nInforme o nome --> ");
		scanf("%[A-Z a-z]", &temp);
		fflush(stdin);
		
		//temp = strupr (temp);
		
		printf("\nDEBUG: buscando pelo nome: %s\n", temp);
		
			for (x=0; x<5; x++) {
				if ( strcmp (temp , pessoa[x].nome) == 0 ) {
					printf("\n--> NOME %s encontrado no indice %d !\n", pessoa[x].nome , x);
					printf("\n  == INDICE %d == \n", x);
					printf("\n      - codigo:       %d", pessoa[x].codigo);
					printf("\n      - endereco:     %s", pessoa[x].endereco);
					printf("\n      - cep:          %d", pessoa[x].cep);
					printf("\n      - telefone:     %d", pessoa[x].telefone);
					printf("\n\n");				
				}
		
			}
	
	} 
	
	if ( strcmp (pergunta , " ") < 0 ) {
		printf("\n*** Não entendi ***\n");
	}
	

	
	fim();
	
}

int imprimir() {
	for (x=0; x<5; x++) {
		printf("\n  == INDICE %d == \n", x);
		printf("\n      - codigo:       %d", pessoa[x].codigo);
		printf("\n      - nome:         %s", pessoa[x].nome);
		printf("\n      - endereco:     %s", pessoa[x].endereco);
		printf("\n      - cep:          %d", pessoa[x].cep);
		printf("\n      - telefone:     %d", pessoa[x].telefone);
		printf("\n\n");			
	}
}

int vazios() {

	for (x=0 ; x<5 ; x++) {
		if ( (strcmp (pessoa[x].nome, "") == 0)) {
			printf("\nDEBUG: indice %d vazio!\n", x);
			vazio++;
		}
	}
	
	printf("\n   --> Existem %d indices vazios!\n", vazio);
	vazio=0;
}

int fim () {
	printf("\n\n\nDEBUG: FIM DA FUNCAO...\n\n\n==============\n");
}

int main() 
{
	/*ESCOLHER O TEMA E APLICAR:
		STRUCT
		FUNCAO OU PROCED.
		VETOR OU MATRIZ
		TODO ASSUNTO
	
	PROVA EM DUPLA
		O SISTEMA DEVE CONTER:
			1 - CADASTRO 	- NÃO PERMITIR CADASTROS IGUAIS
							- MO MÍNIMO: 5 CARACTERES
							
			2 - LISTAR 		- POR CÓDIGO
							- POR NOME
							
			3 - IMPRIMIR TODOS OS CADASTRADOS
			
			4 - MOSTRAR QUANTOS CADASTROS ESTÃO VAZIOS
		
	*/
	printf("\n===========================\nPrograma da prova - 1 sem\n===========================\nAlunos: Rafael R. e Victor Hugo\n");
	
	while (1) {
	
	printf("---+---+---+---+---+---+---+---+---+---+---+---+\nBEM-VINDO AO SISTEMA DA ESCOLINHA BRISA DA MANHA\n---+---+---+---+---+---+---+---+---+---+---+---+");
	
	printf("\nEntre com a opção desejada:\n");
	printf("\n   --> 1 = cadastrar\n");
	printf("\n   --> 2 = listar\n");
	printf("\n   --> 3 = imprimir todos\n");
	printf("\n   --> 4 = quantos estão vazios?\n");
	printf("\n      == opção: ");
	scanf("%i", &opcao);
	
	switch(opcao) {
		case 1 : {
			printf("\nDEBUG: CADASTRAR\n\n");
			cadastrar();
			break;
		}
		
		case 2 : {
			printf("\nDEBUG: LISTAR\n\n");
			listar();
			break;
		}
		
		case 3 : {
			printf("\nDEBUG: IMPRIMIR TODOS\n\n");
			imprimir();
			break;
		}
		
		case 4 : {
			printf("\nDEBUG: VAZIOS\n\n");
			vazios();
			break;
		}
		
	}
	
	if ((opcao < 1) || (opcao > 4)) printf("\n\n *** OPÇÃO NÃO ENCONTRADA!!! ***\n\n"); 
	

	}
}
