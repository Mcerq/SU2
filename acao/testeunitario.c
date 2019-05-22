#include <stdio.h>
#include <math.h>
#include "funcoes_SU(2).h"
#include <stdlib.h>


void testeunitario(double a0, double a1, double a2, double a3) {

	double m;
	double Y;

	m = a0*a0 + a1*a1+a2*a2+a3*a3;	
	Y = abs(m) - 1.0;

	if (Y > 1e-14) {

		printf("ERROR na unitariedade do link\n\n");
		

	}
 }
