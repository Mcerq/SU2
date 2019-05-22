#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "funcoes_SU(2).h"

/*
void marsaglia() {

	double aux, aux1, aux2;
	double a0, a1, a2, a3;
	int n0, n1, n2, n3;
	int i;
	
	do {

	a0 = aleatorio();
	a1 = aleatorio();
	a2 = aleatorio();
	a3 = aleatorio();


	*b0 = a0;
	*b1 = a1;
	*b2 = a2 * sqrt((1 - (a0 * a0 + a1 * a1)) / a2 * a2 + a3 * a3);
	*b3 = a3 * sqrt((1 - (a0 * a0 + a1 * a1)) / a2 * a2 + a3 * a3);
	*b2 = a2;
	*b3 = a3;


	} while (a0 * a0 + a1 * a1 <= 1 && a2 * a2 + a3 * a3 <= 1);




	


		a0 = aleatorio();
	a1 = aleatorio();
	a2 = aleatorio();
	a3 = aleatorio();


	if (a0 * a0 + a1 * a1 < 1 && a2 * a2 + a3 * a3 < 1 &&  a2 * a2 + a3 * a3 != 0) {

	c0 = a0;
	c1 = a1;
	c2 = a2;
	c3 = a3;




	}
	else {
	d0 = a0;
	d1 = a1;
	d2 = a2;
	d3 = a3;

	}

	*b0 = c0;
	*b1 = c1;
	*b2 = c2 * sqrt((1 - (c0 * c0 + c1 * c1)) / c2 * c2 + c3 * c3);
	*b3 = c3 * sqrt((1 - (c0 * c0 + c1 * c1)) / c2 * c2 + c3 * c3);

	


	for (n0 = 0; n0 < N; n0++) {
		for (n1 = 0; n1 < N; n1++) {
			for (n2 = 0; n2 < N; n2++) {
				for (n3 = 0; n3 < N; n3++) {
					for (i = 0; i < 4; i++) {
						aux1 = 1.0;
						aux2 = 1.0;
						while (aux1 >= 1.0) {
							a0 = aleatorio();
							a1 = aleatorio();
							aux1 = a0 * a0 + a1 * a1;
						}
						while (aux2 >= 1.0) {
							a2 = aleatorio();
							a3 = aleatorio();
							aux2 = a2 * a2 + a3 * a3;
						}


						a2 = a2 * sqrt((1.0 - aux1) / aux2);
						a3 = a3 * sqrt((1.0 - aux1) / aux2);

						aux = a0 * a0 + a1 * a1 + a2 * a2 + a3 * a3;

						U[n0][n1][n2][n3][i][0] = a0;
						U[n0][n1][n2][n3][i][1] = a1;
						U[n0][n1][n2][n3][i][2] = a2;
						U[n0][n1][n2][n3][i][3] = a3;



						//printf("%f, %f, %f, %f, %f\n\n", U[n0][n1][n2][n3][i][0],
						//							 U[n0][n1][n2][n3][i][1],
						//						 U[n0][n1][n2][n3][i][2],
						//					 U[n0][n1][n2][n3][i][3], aux);
					}
				}
			}
		}
	}
	
	a0 = aleatorio();
	a1 = aleatorio();
	a2 = aleatorio();
	a3 = aleatorio();

	while (a0 * a0 + a1 * a1 <= 1 && a2 * a2 + a3 * a3 <= 1) {

	*b0 = a0;
	*b1 = a1;
	*b2 = a2 * sqrt((1 - (a0 * a0 + a1 * a1)) / a2 * a2 + a3 * a3);
	*b3 = a3 * sqrt((1 - (a0 * a0 + a1 * a1)) / a2 * a2 + a3 * a3);


	}
	
}*/


/* void hotStart() {

	int n1, n2, n3, n4;
	int mu;
	double bux0, bux1, bux2, bux3;


	for (n1 = 0; n1 < N; n1++) {
		for (n2 = 0; n2 < N; n2++) {
			for (n3 = 0; n3 < N; n3++) {
				for (n4 = 0; n4 < N; n4++) {
					for (mu = 0; mu < 4; mu++) {


						marsaglia(&bux0, &bux1, &bux2, &bux3);

						U[n1][n2][n3][n4][mu][0] = bux0;
						U[n1][n2][n3][n4][mu][1] = bux1;
						U[n1][n2][n3][n4][mu][2] = bux2;
						U[n1][n2][n3][n4][mu][3] = bux3;


					}
				}
			}
		}
	}
}
*/




#include <stdio.h>
#include "funcoes_SU(2).h"

void coldStart() {

	int n1, n2, n3, n4;
	int mu;

	for (n1 = 0; n1 < N; n1++) {
		for (n2 = 0; n2 < N; n2++) {
			for (n3 = 0; n3 < N; n3++) {
				for (n4 = 0; n4 < NT; n4++) {
					for (mu = 0; mu < d; mu++) {


						U[n1][n2][n3][n4][mu][0] = 1.0;
						U[n1][n2][n3][n4][mu][1] = 0.0;
						U[n1][n2][n3][n4][mu][2] = 0.0;
						U[n1][n2][n3][n4][mu][3] = 0.0;


					}
				}
			}
		}
	}
}



void inicializationG() {

	int n1, n2, n3, n4;

	for (n1 = 0; n1 < N; n1++) {
		for (n2 = 0; n2 < N; n2++) {
			for (n3 = 0; n3 < N; n3++) {
				for (n4 = 0; n4 < NT; n4++) {


						g[n1][n2][n3][n4][0] = 1.0;
						g[n1][n2][n3][n4][1] = 0.0;
						g[n1][n2][n3][n4][2] = 0.0;
						g[n1][n2][n3][n4][3] = 0.0;


					
				}
			}
		}
	}
}

