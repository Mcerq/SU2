#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>
#include "funcoes_SU(2).h"
#include <time.h>
#include <stdlib.h>


	

int main(int argc, char* argv[]) {

	clock_t Total[2];
	Total[0] = clock();


	double A;
	int i, j, k;
	double tabela;

	//As partes do loop de polyakov est�o destacadas em uma tabela no excel. 

//	arquivoU = fopen("plaq_N16_NT8_parte.txt", "w+");             			// abrindo arquivo para guardar valores de plaquetas;
	arquivoU2 = fopen("poly_NT8_ponto21_parte5.txt", "w+");				// abrindo arquivo para guardar valores de loop de polyakov;

//	arquivoU3 = fopen("config_link_for_gaugefixingN16_NT8_ponto21.txt", "w+");	// abrindo arquivo para guardar valores das configura��es de link,
											//com objetivo de utiliz�-las na fixa��o de gauge. 
/*
	if (arquivoU == NULL) {							// Aqui serve para ter a certeza que o arquivo aberto n�o dar� erro!
		printf("Erro na abertura do arquivo");
		exit(1);
	}
*/
	 if (arquivoU2 == NULL) {                                                        // Aqui serve para ter a certeza que o arquivo aberto n�o dar� erro!
                printf("Erro na abertura do arquivo");
                exit(1);
        }
	


	
	//===========================================================================================
	// Iniciando o gerador de numeros aleatorios 
	//===========================================================================================

	srand(time(NULL)); // Inicia semente  
	rmarin((int)rand() % 31328, (int)rand() % 30081); // inicia o ranmar 



	//============================================================================================
	// fun��es do programa
	//=============================================================================================

	coldStart();              // Faz a inicializa��o das matrizes de links;
	vizinhoPeriDir();	  // Faz a inicializa��o dos vizinhos da direita;
	vizinhoPeriEsq();	  // Faz a inicializa��o dos vizinhos da esquerda;
//	  load_lattice(&U[0][0][0][0][0][0],"./lattice/beta225N8.bin");
//      metropolis();

	acao();			  // Chama o primeiro valor para a a��o de gauge;
//metropolis();
//	termalizacaoHeatBath();   // Faz a termaliza��o atrav�s do HeatBath;
//	termalizacaoOver();	  // Faz a termaliza��o atrav�s do Overrelaxation;
	printf("ok\n\n");
      //  save_lattice(&U[0][0][0][0][0][0],"./lattice/beta225N8.bin");

 	//============================================================================================
        //Calculo para Rede N^4 com base em paper de Teper
	//============================================================================================


	for (i = 0; i < 1000; i++) {
              		for(j = 0; j < 512; j++){
	      	        	heatSweep();
				overSweep();
	      		}			                
			mediapolyakovloop();
                	tabela = (6.0*NR*NR*NR*NTR - 2.0*S / beta)/(6.0*NR*NR*NR*NTR);
//                	fprintf(arquivoU, "%d, %f\n", (i + 2201), tabela);
//			printf("%d, %f\n", i+i, tabela);
			fprintf(arquivoU2,"%d, %f\n", (i + 4001), mlp);
//	                printf("foram calculados %d com acao %lf e plaqueta de %lf\n", i + 1, S, tabela);
       		 	
		}
	



//	fclose(arquivoU);
	fclose(arquivoU2);
//	fclose(arquivoU3);




	Total[1] = clock();
	double TotalTime = (Total[1] - Total[0])*1.0 / CLOCKS_PER_SEC;
	printf("Tempo gasto: %g segundos.\n", TotalTime);
	printf("Tempo gasto: %g minutos.\n", TotalTime/60.0);
	printf("Tempo gasto: %g horas. \n\n", TotalTime/3600.0);

	system("pause");
	return 0;
}
