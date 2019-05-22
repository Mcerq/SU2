#include <stdio.h>
#include "funcoes_SU(2).h"

double polyakovloop(int n1, int n2, int n3) {

	

	int n4;
	double traco;
		
	

	prodMatriz(U[n1][n2][n3][0][3][0], U[n1][n2][n3][0][3][1], U[n1][n2][n3][0][3][2], U[n1][n2][n3][0][3][3],
	 	   U[n1][n2][n3][1][3][0], U[n1][n2][n3][1][3][1], U[n1][n2][n3][1][3][2], U[n1][n2][n3][1][3][3],
	           &Up[n1][n2][n3][0][0], &Up[n1][n3][n3][0][1], &Up[n1][n2][n3][0][2], &Up[n1][n2][n3][0][3]);

	
	for (n4 = 0; n4 < NT - 2; n4++) {

			prodMatriz(Up[n1][n2][n3][n4][0], Up[n1][n3][n3][n4][1], Up[n1][n2][n3][n4][2], Up[n1][n2][n3][n4][3],
			U[n1][n2][n3][n4 + 2][3][0], U[n1][n3][n3][n4 + 2][3][1], U[n1][n2][n3][n4 + 2][3][2], U[n1][n2][n3][n4 + 2][3][3],
			&Up[n1][n2][n3][n4 + 1][0], &Up[n1][n3][n3][n4 + 1][1], &Up[n1][n2][n3][n4 + 1][2], &Up[n1][n2][n3][n4 + 1][3]);

	}

	
	
	traco = 2.0*Up[n1][n2][n3][NT-2][0];
	return traco;
}





void mediapolyakovloop() {

	int n1, n2, n3;
	double resultado;

	resultado = 0.0;



	for (n1 = 0; n1 < N; n1++) {
		for (n2 = 0; n2 < N; n2++) {
			for (n3 = 0; n3 < N; n3++) {



				resultado = resultado + polyakovloop(n1, n2, n3);

			}
		}
	}


	mlp = resultado / (NR*NR*NR);

}
