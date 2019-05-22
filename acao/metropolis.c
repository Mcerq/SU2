#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funcoes_SU(2).h"



void metropolis(int n1, int n2, int n3, int n4, int mu, double *b0, double *b1, double *b2, double *b3){

	double r0, r1, r2, r3;
	double x0, x1, x2, x3;
	double sign;
	double epsilon;
	double r, x;
	double u0, u1, u2, u3;
	double a0, a1, a2, a3;

	epsilon = 0.1;

	r0 = ranmar() - 0.5 ;
	r1 = ranmar() - 0.5;
	r2 = ranmar() - 0.5;
	r3 = ranmar() - 0.5;

	
	if( r0 < 0.0){
		sign = -1.0;
	}  else if (r0 > 0.0){
		sign = 1.0;
	}

//	printf("r0 = %f, r1 = %f, r2 = %f, r3 = %f,  sign = %f, epsilon = %f\n", r0, r1, r2, r3, sign, epsilon);

	r = sqrt(r1*r1+r2*r2+r3*r3);

	x0 = sign * sqrt(1.0 - pow(epsilon,2));
	x1 = epsilon*r1/r;
	x2 = epsilon*r2/r;
	x3 = epsilon*r3/r;

	x = x0*x0+x1*x1+x2*x2+x3*x3;
//	printf("x0 = %f, x1 = %f, x2 = %f, x3 = %f\n", x0, x1, x2, x3);
//	printf("|x| = %f\n", x);

	u0 = U[n1][n2][n3][n4][mu][0];
	u1 = U[n1][n2][n3][n4][mu][1];
	u2 = U[n1][n2][n3][n4][mu][2];
	u3 = U[n1][n2][n3][n4][mu][3];



	prodMatriz(x0, x1, x2, x3, u0, u1, u2, u3, &a0, &a1, &a2, &a3);

	*b0 = a0;
	*b1 = a1;
	*b2 = a2;
	*b3 = a3;	


}

double novaacaoMetropolis(int n1, int n2, int n3, int n4, int mu, double *a0, double *a1, double *a2, double *a3, double *b0, double*b1, double *b2, double *b3){

                double aux;
                double u0, u1, u2, u3;
                double ax0, ax1, ax2, ax3;
                double aux0, aux1, aux2, aux3;
                // Em primeiro lugar vamos guardar os valores do link para o cálculo de 'dS'

                u0 = U[n1][n2][n3][n4][mu][0];
                u1 = U[n1][n2][n3][n4][mu][1];
                u2 = U[n1][n2][n3][n4][mu][2];
                u3 = U[n1][n2][n3][n4][mu][3];

		*a0 = u0;
		*a1 = u1;
		*a2 = u2;
		*a3 = u3;

                testeunitario(u0, u1, u2, u3);

               
		metropolis(n1, n2, n3, n4, mu, aux0, aux1, aux2, aux3);

		*b0 = aux0;
		*b1 = aux1;
		*b2 = aux2;
		*b3 = aux3;



 //             U[n1][n2][n3][n4][mu][0] = aux0;
 //              U[n1][n2][n3][n4][mu][1] = aux1;
 //               U[n1][n2][n3][n4][mu][2] = aux2;
 //                U[n1][n2][n3][n4][mu][3] = aux3;

                testeunitario(aux0, aux1, aux2, aux3);


                aux = 0.5*beta*(ax0 * (u0 - aux0) -
                        ax1 * (u1 - aux1) -
                        ax2 * (u2 - aux2) -
                        ax3 * (u3 - aux3));

                return aux;

}


double acceptMetropolis(int n1, int n2, int n3, int n4, int mu){



	double delta, metr;
	double r;

	r = ranmar();

	delta = novaacaoMetropolis(n1, n2, n3, n4, mu, &a0, &a1, &a2, &a3, &b0, &b1, &b2, &b3);

	metr = exp(-delta);



	if(r <= metr){
	
		U[n1][n2][n3][n4][mu][0] = b0;
		U[n1][n2][n3][n4][mu][1] = b1;
		U[n1][n2][n3][n4][mu][2] = b2;
		U[n1][n2][n3][n4][mu][3] = b3;
	} else {

		U[n1][n2][n3][n4][mu][0] = a0;
		U[n1][n2][n3][n4][mu][1] = a1;
		U[n1][n2][n3][n4][mu][2] = a2;
		U[n1][n2][n3][n4][mu][3] = a3;
	}






}
	
