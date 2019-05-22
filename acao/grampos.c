#include <stdio.h>
#include "funcoes_SU(2).h"

void grampoSuperior(int n1, int n2, int n3, int n4, int mu, int nu, double *e0, double*e1, double *e2, double *e3) {

        int m1, m2, m3, m4;
        int p1, p2, p3, p4;
        double a0, a1, a2, a3;
        double b0, b1, b2, b3;
        double c0, c1, c2, c3;
        double d0, d1, d2, d3;
        double ax0, ax1, ax2, ax3;
        double ay0, ay1, ay2, ay3;


        //Vamos analisar o vizinho da direita mu (n+mu):

        m1 = vd[n1][n2][n3][n4][mu][0];
        m2 = vd[n1][n2][n3][n4][mu][1];
        m3 = vd[n1][n2][n3][n4][mu][2];
        m4 = vd[n1][n2][n3][n4][mu][3];

        // Para a matriz U(n+mu,nu):

        a0 = U[m1][m2][m3][m4][nu][0];
        a1 = U[m1][m2][m3][m4][nu][1];
        a2 = U[m1][m2][m3][m4][nu][2];
        a3 = U[m1][m2][m3][m4][nu][3];

        // Vamos analisar o vizinho da direita nu (n+nu):

        p1 = vd[n1][n2][n3][n4][nu][0];
        p2 = vd[n1][n2][n3][n4][nu][1];
        p3 = vd[n1][n2][n3][n4][nu][2];
        p4 = vd[n1][n2][n3][n4][nu][3];

        // Para a matriz U(n+nu,mu):

        b0 = U[p1][p2][p3][p4][mu][0];
        b1 = U[p1][p2][p3][p4][mu][1];
        b2 = U[p1][p2][p3][p4][mu][2];
        b3 = U[p1][p2][p3][p4][mu][3];

	        // Produto matricial U = U(n+mu,nu)U^(+)(n+nu,mu):

        prodMatriz(a0, a1, a2, a3, b0, -b1, -b2, -b3, &ax0, &ax1, &ax2, &ax3);

        c0 = ax0;
        c1 = ax1;
        c2 = ax2;
        c3 = ax3;


        // Matriz U(n,nu):

        d0 = U[n1][n2][n3][n4][nu][0];
        d1 = U[n1][n2][n3][n4][nu][1];
        d2 = U[n1][n2][n3][n4][nu][2];
        d3 = U[n1][n2][n3][n4][nu][3];

        // Produto matricial  entre U e U(n,j) :

        prodMatriz(c0, c1, c2, c3, d0, -d1, -d2, -d3, &ay0, &ay1, &ay2, &ay3);

        *e0 = ay0;
        *e1 = ay1;
        *e2 = ay2;
        *e3 = ay3;

}


void grampoInferior(int n1, int n2, int n3, int n4, int mu, int nu, double *e0, double*e1, double *e2, double *e3) {

        int m1, m2, m3, m4;
        int p1, p2, p3, p4;
        double a0, a1, a2, a3;
        double b0, b1, b2, b3;
        double c0, c1, c2, c3;
        double d0, d1, d2, d3;
        double ax0, ax1, ax2, ax3;
        double ay0, ay1, ay2, ay3;

      //Vamos analisar o vizinho da esquerda nu (n-nu):

        m1 = ve[n1][n2][n3][n4][nu][0];
        m2 = ve[n1][n2][n3][n4][nu][1];
        m3 = ve[n1][n2][n3][n4][nu][2];
        m4 = ve[n1][n2][n3][n4][nu][3];

        // Vamos analisar o vizinho da direira n+mu-nu:

        p1 = vd[m1][m2][m3][m4][mu][0];
        p2 = vd[m1][m2][m3][m4][mu][1];
        p3 = vd[m1][m2][m3][m4][mu][2];
        p4 = vd[m1][m2][m3][m4][mu][3];

        // Para a matriz U(n+mu-nu,nu):

        a0 = U[p1][p2][p3][p4][nu][0];
        a1 = U[p1][p2][p3][p4][nu][1];
        a2 = U[p1][p2][p3][p4][nu][2];
        a3 = U[p1][p2][p3][p4][nu][3];

        //Vamos analisar o vizinho da esquerda nu (n-nu):

        m1 = ve[n1][n2][n3][n4][nu][0];
        m2 = ve[n1][n2][n3][n4][nu][1];
        m3 = ve[n1][n2][n3][n4][nu][2];
        m4 = ve[n1][n2][n3][n4][nu][3];
        // Para a matriz U(n-nu,mu):

        b0 = U[m1][m2][m3][m4][mu][0];
        b1 = U[m1][m2][m3][m4][mu][1];
        b2 = U[m1][m2][m3][m4][mu][2];
        b3 = U[m1][m2][m3][m4][mu][3];


        // Produto matricial U = U^(+)(n+mu-nu,ni)U^(+)(n-nu,mu)

        prodMatriz(a0, -a1, -a2, -a3, b0, -b1, -b2, -b3, &ax0, &ax1, &ax2, &ax3);

        c0 = ax0;
        c1 = ax1;
        c2 = ax2;
        c3 = ax3;


	 // Matriz U(n-nu,nu) O vizinho da esquerda foi reutilizado.

        d0 = U[m1][m2][m3][m4][nu][0];
        d1 = U[m1][m2][m3][m4][nu][1];
        d2 = U[m1][m2][m3][m4][nu][2];
        d3 = U[m1][m2][m3][m4][nu][3];

        // Produto matricial entre U() e U(n-nu,nu)

        prodMatriz(c0, c1, c2, c3, d0, d1, d2, d3, &ay0, &ay1, &ay2, &ay3);

        *e0 = ay0;
        *e1 = ay1;
        *e2 = ay2;
        *e3 = ay3;


}

void somaGrampos(int n1, int n2, int n3, int n4, int mu, double *b0, double *b1, double *b2, double *b3) {

        double a0, a1, a2, a3;
        double ax0, ax1, ax2, ax3;
        double ay0, ay1, ay2, ay3;
        int nu;

        a0 = 0.0;
        a1 = 0.0;
        a2 = 0.0;
        a3 = 0.0;

        for (nu = 0; nu < d; nu++) {
                if (mu != nu) {
                        grampoSuperior(n1, n2, n3, n4, mu, nu, &ax0, &ax1, &ax2, &ax3);


                        a0 = a0 + ax0;
                        a1 = a1 + ax1;
                        a2 = a2 + ax2;
                        a3 = a3 + ax3;

                        grampoInferior(n1, n2, n3, n4, mu, nu, &ay0, &ay1, &ay2, &ay3);

                        a0 = a0 + ay0;
                        a1 = a1 + ay1;
                        a2 = a2 + ay2;
                        a3 = a3 + ay3;

                }
        }



        *b0 = a0;
        *b1 = a1;
        *b2 = a2;
        *b3 = a3;
}


