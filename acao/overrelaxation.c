#include <stdio.h>
#include <math.h>
#include "funcoes_SU(2).h"



	void overelaxation (int n1, int n2, int n3, int n4, int mu, 
			    double *f0, double *f1, double *f2, double *f3,
		            double *e0, double *e1, double *e2, double *e3) {

	double a0, a1, a2, a3;
	double b0, b1, b2, b3;
	double a;
	double V0, V1, V2, V3;
	double c0, c1, c2, c3;
	double d0, d1, d2, d3;

		//Valores referentes a atualização do link no banho termico.


	a0 = U[n1][n2][n3][n4][mu][0];
	a1 = U[n1][n2][n3][n4][mu][1];
	a2 = U[n1][n2][n3][n4][mu][2];
	a3 = U[n1][n2][n3][n4][mu][3];

	somaGrampos (n1, n2, n3, n4, mu, &b0, &b1, &b2, &b3);

	a = sqrt(b0*b0 + b1*b1 + b2*b2 + b3*b3);

	V0 = b0/a;
	V1 = b1/a;
	V2 = b2/a;
	V3 = b3/a;

	*f0 = b0;
	*f1 = b1;
	*f2 = b2;
	*f3 = b3;
	

	prodMatriz(V0, -V1, -V2, -V3, a0, -a1, -a2, -a3, &c0, &c1, &c2, &c3);
	prodMatriz(c0, -c1, -c2, -c3, V0, -V1, -V2, -V3, &d0, &d1, &d2, &d3);

//	U[n1][n2][n3][n4][mu][0] = d0;
//	U[n1][n2][n3][n4][mu][1] = d1;
//	U[n1][n2][n3][n4][mu][2] = d2;
//	U[n1][n2][n3][n4][mu][3] = d3;

	*e0 = d0;
	*e1 = d1;
	*e2 = d2;
	*e3 = d3;

	}


	double novaacaoOver (int n1, int n2, int n3, int n4, int mu){

		double u0, u1, u2, u3;
		double a0, a1, a2, a3;
		double b0, b1, b2, b3;
		double aux;

		u0 = U[n1][n2][n3][n4][mu][0];
		u1 = U[n1][n2][n3][n4][mu][1];
		u2 = U[n1][n2][n3][n4][mu][2];
		u3 = U[n1][n2][n3][n4][mu][3];

		testeunitario(u0, u1, u2, u3);

 	 overelaxation (n1, n2, n3, n4, mu,
                        &a0, &a1, &a2, &a3,
                        &b0, &b1, &b2, &b3);

	        U[n1][n2][n3][n4][mu][0] = b0;
                U[n1][n2][n3][n4][mu][1] = b1;
                U[n1][n2][n3][n4][mu][2] = b2;
                U[n1][n2][n3][n4][mu][3] = b3;

                testeunitario(b0, b1, b2, b3);

	aux = 0.5*beta*(a0 * (u0 - b0) -
                        a1 * (u1 - b1) -
                        a2 * (u2 - b2) -
                        a3 * (u3 - b3));

                return aux;
        }

	void overSweep(){

		int n1, n2, n3, n4;
		int mu;

		    for (n1 = 0; n1 < N; n1++) {
                        for (n2 = 0; n2 < N; n2++) {
                                for (n3 = 0; n3 < N; n3++) {
                                        for (n4 = 0; n4 < NT; n4++) {
                                                for (mu = 0; mu < d; mu++) {

                                                        S = S + novaacaoOver(n1, n2, n3, n4, mu);
                                                }
                                        }
                                }
                        }
                }

        }


	void termalizacaoOver() {

		int i;

		 for (i = 0; i < 500; i++) {
                        heatSweep();
			overSweep();
                        printf("%d, %f\n", i, S);

                }


        }

