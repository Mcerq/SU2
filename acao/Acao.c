#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>	
#include <stdlib.h>
#include <math.h>
#include "funcoes_SU(2).h"



double plaqueta(int n1, int n2, int n3, int n4, int mu, int nu) {


	double a0, a1, a2, a3;
	double b0, b1, b2, b3;
	double c0, c1, c2, c3;
	double d0, d1, d2, d3;
	double f0, f1, f2, f3;
	double g0, g1, g2, g3;
	int m1, m2, m3, m4;
	int p1, p2, p3, p4;
	double ax0, ax1, ax2, ax3;
	double ay0, ay1, ay2, ay3;
	double traco;


	//Elementos da primeira matriz U(n,mu)


	a0 = U[n1][n2][n3][n4][mu][0];
	a1 = U[n1][n2][n3][n4][mu][1];
	a2 = U[n1][n2][n3][n4][mu][2];
	a3 = U[n1][n2][n3][n4][mu][3];

	// Coordenadas do ponto vizinho n+mu


	m1 = vd[n1][n2][n3][n4][mu][0];
	m2 = vd[n1][n2][n3][n4][mu][1];
	m3 = vd[n1][n2][n3][n4][mu][2];
	m4 = vd[n1][n2][n3][n4][mu][3];

	// Elementos da segunda matriz U(n+mu,nu)

	b0 = U[m1][m2][m3][m4][nu][0];
	b1 = U[m1][m2][m3][m4][nu][1];
	b2 = U[m1][m2][m3][m4][nu][2];
	b3 = U[m1][m2][m3][m4][nu][3];

	// Produto matricial entre U(n,mu) e U(n+mu,nu):

	prodMatriz(a0, a1, a2, a3, b0, b1, b2, b3, &ax0, &ax1, &ax2, &ax3);

	// Componentes deste produto matricial.

	c0 = ax0;
	c1 = ax1;
	c2 = ax2;
	c3 = ax3;

	// Coordenadas do ponto vizinho n+nu

	p1 = vd[n1][n2][n3][n4][nu][0];
	p2 = vd[n1][n2][n3][n4][nu][1];
	p3 = vd[n1][n2][n3][n4][nu][2];
	p4 = vd[n1][n2][n3][n4][nu][3];


	// Elementos da terceira matriz U(n+nu,mu)

	d0 = U[p1][p2][p3][p4][mu][0];
	d1 = U[p1][p2][p3][p4][mu][1];
	d2 = U[p1][p2][p3][p4][mu][2];
	d3 = U[p1][p2][p3][p4][mu][3];


	// Elementos da quarta matriz U(n,nu)

	f0 = U[n1][n2][n3][n4][nu][0];
	f1 = U[n1][n2][n3][n4][nu][1];
	f2 = U[n1][n2][n3][n4][nu][2];
	f3 = U[n1][n2][n3][n4][nu][3];

	// Produto entre as matrizes U(n+j,i) e U(n,j), lembrando que temos que elas são
	// matrizes com "dagger", no qual suas componentes espaciais ganham sinal de (-)
	// em relação a matriz U normal.

	prodMatriz(d0, -d1, -d2, -d3, f0, -f1, -f2, -f3, &ay0, &ay1, &ay2, &ay3);

	g0 = ay0;
	g1 = ay1;
	g2 = ay2;
	g3 = ay3;


	// Calculo do traço de um valor:


	traco = 2.0*(c0 * g0 - c1 * g1 - c2 * g2 - c3 * g3);

	return traco;

}



void acao() {

	int n1, n2, n3, n4;
	int mu, nu;
	double plaq;

	plaq = 0.0;

	for (n1 = 0; n1 < N; n1++) {
		for (n2 = 0; n2 < N; n2++) {
			for (n3 = 0; n3 < N; n3++) {
				for (n4 = 0; n4 < NT; n4++) {
					for (mu = 0; mu < d; mu++) {
						for (nu = mu + 1; nu < d; nu++) {
							  plaq = plaq + plaqueta(n1, n2, n3, n4, mu, nu);
							  
						}
					}
				}
			}
		}
	}

//	S = 0.5*beta*(4.0 - traco / (6.0*N*N*N*NT));
//	S = 0.5*beta*(2.0 - traco/(6.0*N*N*N*NT));    ESSE É O CORRETO APARENTEMENTE
	S = 0.5*beta*(2.0*6.0*NR*NR*NR*NTR - plaq);
//	S = 0.5*beta*(12.0*N*N*N*NT - traco);

	//S =  traco / (6.0*N*N*N*N);
	

	printf("\n%f\n\n", S);

}
