//////////////////////////////////////////////////////
//													//	
//													//
//		PROGRAMA CONTADOR DE HORAS CURRICULARES		//
//													//
//		Gustavo Araujo e Rafael Requiao				//
//													//
//													//
//													//	
//////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
char materia[2][20] = 	{	{"MAT01","68"},
							{"MAT02","68"},
							{"MAT03","68"},
							{"MAT04","68"},
							{"MAT05","68"},

							{"MAT06","68"},
							{"MAT07","68"},
							{"MAT08","68"},
							{"MAT09","68"},
							{"MAT10","68"},

							{"MAT11","68"},
							{"MAT12","68"},
							{"MAT13","68"},
							{"MAT14","68"},
							{"MAT15","68"},

							{"MAT16","68"},
							{"MAT17","68"},
							{"MAT18","68"},
							{"MAT19","68"},
							{"MAT20","68"},

						};
*/						
						
struct _materia {
	char cod[7];   	//6 caracteres + 1 terminador nulo
	int  carga;
	int  tipo;  	//1 = exatas , 2 = artisticas , 3 = humanisticas
	  
	// gostei dos colchetes! membro de vetor flexivel precisa estar no final do struct, 
	// segundo o GCC
};

//static 
struct _materia materia[37];
						
//static 
int cargahoraria[7] = 	{136 , 136 , 816 , 476 , 476 , 360, 2400};
							
int x , pag , a , b , opcao, i;		


//provavelmente eu precise de um typedef... ou não
struct _temp{
	char cod[7];   //6 caracteres + 1 terminador nulo
	int  carga;
	int  tipo;  	//1 = exatas , 2 = artisticas , 3 = humanisticas

};

struct _temp temp[50]; //qual o numero que esgota a porra toda?

char   agoravai[7];  //scanf tá sacaneando pra ler isso...


							
							
/* 
	cargahoraria[0] --> humanisticas 					= 136h
	cargahoraria[1] --> artisticas						= 136h
	cargahoraria[2] --> exatas							= 816h
	cargahoraria[3] --> componente livre				= 476h
	cargahoraria[4]	-->	obrigatorias					= 476h
	cargahoraria[5] --> atividades complementares		= 360h
	cargahoraria[6] --> carga horaria do curso (total)	= 2400h
	
*/

int precarregar() {

//precarregar informações
//strcpy tá dando BUS ERROR logo de cara
//algo com ponteiros e memoria read-only... o animal aqui errou a ordem do strcpy()
	
	strcpy(materia[0].cod, "ENGC99") ;	//primeira materia de EXATAS
	materia[0].carga	=  102;
	
	strcpy(materia[1].cod, "MATA01") ;
	materia[1].carga	=  68;
	
	strcpy(materia[2].cod, "MATA02") ;
	materia[2].carga	=  102;
	
	strcpy(materia[3].cod, "QUI037") ;
	materia[3].carga	=  136;
	
	strcpy(materia[4].cod, "ENGD01") ;
	materia[4].carga	=  68;
	
	strcpy(materia[5].cod, "FIS121") ;
	materia[5].carga	=  102;
	
	strcpy(materia[6].cod, "MATA03") ;
	materia[6].carga	=  102;
	
	strcpy(materia[7].cod, "MATA07") ;
	materia[7].carga	=  68;
	
	strcpy(materia[8].cod, "QUIA14") ;
	materia[8].carga	=  85;
	
	strcpy(materia[9].cod, "ENGD02") ;
	materia[9].carga	=  68;
	
	//10
	
	strcpy(materia[10].cod, "FIS122") ;
	materia[10].carga	=  102;

	strcpy(materia[11].cod, "MATA04") ;
	materia[11].carga	=  102;

	strcpy(materia[12].cod, "QUIA01") ;
	materia[12].carga	=  102;

	strcpy(materia[13].cod, "QUIA15") ;
	materia[13].carga	=  68;

	strcpy(materia[14].cod, "ENG372") ;
	materia[14].carga	=  68;

	strcpy(materia[15].cod, "ENGD04") ;
	materia[15].carga	=  68;

	strcpy(materia[16].cod, "FIS123") ;
	materia[16].carga	=  102;

	strcpy(materia[17].cod, "QUI138") ;
	materia[17].carga	=  68;

	strcpy(materia[18].cod, "QUIA16") ;
	materia[18].carga	=  68;

	strcpy(materia[19].cod, "QUIA17") ;	//ultima materia de EXATAS
	materia[19].carga	=  34;

	
	//20
	
	strcpy(materia[20].cod, "HACB07") ;	//primeira materia de ARTISTICAS
	materia[20].carga	=  68;

	strcpy(materia[21].cod, "HACB23") ;	
	materia[21].carga	=  68;  //nao tinha no arquivo

	strcpy(materia[22].cod, "HACA48") ;
	materia[22].carga	=  34;

	strcpy(materia[23].cod, "HACA82") ;
	materia[23].carga	=  68;

	strcpy(materia[24].cod, "HACB11") ;
	materia[24].carga	=  68;

	strcpy(materia[25].cod, "HACA07-1") ;
	materia[25].carga	=  68;

	strcpy(materia[26].cod, "HACB24-1") ;
	materia[26].carga	=  68;

	strcpy(materia[27].cod, "HACA07-2") ;
	materia[27].carga	=  68;

	strcpy(materia[28].cod, "HACB24-2") ;	//ultima materia de ARTISTICAS
	materia[28].carga	=  34;

	strcpy(materia[29].cod, "HACA76") ;	//primeira materia de HUMANISTICAS
	materia[29].carga	=  68;

	//30
	
	strcpy(materia[30].cod, "HACA36") ;
	materia[30].carga	=  68;

	strcpy(materia[31].cod, "HACA03") ;
	materia[31].carga	=  68;

	strcpy(materia[32].cod, "HACA35") ;
	materia[32].carga	=  68;

	strcpy(materia[33].cod, "HACA77") ;
	materia[33].carga	=  68;

	strcpy(materia[34].cod, "HACB36") ;
	materia[34].carga	=  68;

	strcpy(materia[35].cod, "HACA51") ;
	materia[35].carga	=  68;

	strcpy(materia[36].cod, "HACB40") ;	//ultima materia de HUMANISTICAS
	materia[36].carga	=  34;
	
	//definir o tipo das materias
	//exatas = 1 ; artisticas = 2 ; humanisticas = 3;
	
	for (i=0  ; i<20 ; i++) materia[i].tipo = 1;
	
	for (i=20 ; i<29 ; i++) materia[i].tipo = 2;

	for (i=29 ; i<37 ; i++) materia[i].tipo = 3;

}


int listar() {

	//informar materias no sistema
	//dividir por telas... 10 em cada lado
	while (pag != 9) {
		
		printf("\n\nDigite a página para listagem (9 = sair): ");
		scanf("%i", &pag);  //so quero inteiros!
		fflush(stdin);
		
		switch (pag) {
	
			case 1 : {
				a = 0  ; b = 10; break;
			} 
	
			case 2 : {
				a = 10 ; b = 20; break;
			}
	
			case 3 : {
				a = 20 ; b = 30; break;
			}
	
			case 4 : {
				a = 30 ; b = 40; break;
			}
	
			case 9 : {
				printf("\nSaindo pro MENU!\n");
				break;
			}
	
		}

		if (pag != 9) {	 //ver esse if aí...		
			for (x = a; x < b; x++) {   //inicial a=0 , b=10
				printf("\n");
		
				//imprimir materia e cargahoraria ao lado - 10 e depois mais 10
				printf("  -->%s -- %d horas", materia[x].cod, materia[x].carga);  
				//formatar esse printf depois com tabulação
				printf("\n");
		
			}
		}
	}
}

int cadastrar() {
	printf("\nWIP\n");

	/*
	//pseudo-código
	* inicializar vetor que vai armazenar as materias escolhidas
	
	1 - pegar materia
	2 - computar tipo da materia
	3 - subtrair carga horaria da materia de acordo com o tipo
		* caso alguma materia estoure - comeca a subtrarir de coomponente livre
		
	4 - imprimir horas restantes
		

	*/
	
	printf("\nDigite o código da materia: ");
	fflush(stdin);
//	scanf("%[A-Z0-9]", &agoravai[7]);   //ta bugando pq???
	int aeho;
	for (aeho=0; aeho<7; aeho++) {
		agoravai[aeho] = getchar();
	}
	
	fflush(stdin);

	
	//buscar pela materia
	int y, n;
	for (y=0; y < 40; y++) {
		if (strcmp (materia[y].cod , agoravai) == 0) {
			for (n=0 ; n < 40 ; n++) {
				if (temp[n].carga != 0) {
					//copiar materia escolhida e encontrada para vetor temporario
					temp[n].carga = materia[y].carga;
					strcpy( materia[y].cod, temp[n].cod);
					
					
				} else if (temp[n].carga == 0) printf("\n*** INDICE %d VAZIO ***\n", n);
			}
		
		}
		
	
	
	}
	
	
	//armazenar informacoes num vetor temporário
	//strcpy


}



int restante() {
	printf("\n\n--> Imprimindo materias escolhidas...\n");
	int z;
	
	for (z=0 ; z<40 ; z++) {
		printf("\n   %s -- %d horas", temp[z].cod , temp[z].carga );
	}
	
	printf("\n\n--> Calculando CARGA HORARIA...\n");
	
	printf("\n humanisticas                   = %d", cargahoraria[0]);
	printf("\n artisticas                     = %d", cargahoraria[1]);
	printf("\n exatas                         = %d", cargahoraria[2]);
	printf("\n componente livre               = %d", cargahoraria[3]);
	printf("\n obrigatorias                   = %d", cargahoraria[4]);
	printf("\n atividades complementares      = %d", cargahoraria[5]);
	printf("\n carga horaria do curso (total) = %d", cargahoraria[6]);
	
}




int main() {

	
	printf("\n\n\n");
	printf("\n**************************************************"); //60 caracteres
	printf("\n      CALCULADORA DE CARGA HORARIA RESTANTE");
	printf("\n          meh 12345");
	printf("\n          aeHOOO");
	printf("\n**************************************************"); //60 caracteres
	printf("\n\n\n");
	
	precarregar();

	
	while (1) {
	
	pag=0; //desbugar listar!
	
	printf("\n\n  Entre com a opcao desejada:");
	printf("\n      1 --> listar materias");
	printf("\n      2 --> cadastrar materia");
	printf("\n      3 --> imprimir carga horaria restante");
	printf("\n\n\n");
	printf("\nOpcao: ");
	
	scanf("%i", &opcao);   //so quero numeros
	fflush(stdin);

	
	switch (opcao) {
		case 1 : { listar(); 		break;}
		case 2 : { cadastrar(); 	break;}
		case 3 : { restante(); 		break;}
	
	}
	
	

	}
	

}

