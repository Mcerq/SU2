#include "funcoes_SU(2).h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


double ranmar() { /*gerador de numero aleatorio real */
	double uni;
	uni = u[i97 - 1] - u[j97 - 1];
	if (uni < 0l) uni++;
	u[i97 - 1] = uni;
	i97--;
	if (i97 == 0) i97 = 97;
	j97--;
	if (j97 == 0) j97 = 97;
	c -= cd;
	if (c < 0l) c += cm;
	uni -= c;
	if (uni < 0l) uni++;
	return uni;
} /* ranmar */

void rmarin(int ij, int kl) {
	double s, t;
	int i, j, k, l, m;
	int ii, jj;

	i = ((ij / 177) % 177) + 2;
	j = (ij % 177) + 2;
	k = ((kl / 169) % 178) + 1;
	l = kl % 169;
	/* printf ("\n\nRanmar initialized: %d %d\n\n", ij, kl); */
	for (ii = 0; ii < 97; ii++) {
		s = 0.0;
		t = 0.5;
		for (jj = 0; jj < 24; jj++) {
			m = (((i * j) % 179) * k) % 179;
			i = j;
			j = k;
			k = m;
			l = (53 * l + 1) % 169;
			if (((l * m) % 64) >= 32) s += t;
			t *= 0.5;
		}
		u[ii] = s;
	}
	c = (double) 362436.0 / (double) 16777216.0;
	cd = (double) 7654321.0 / (double) 16777216.0;
	cm = (double) 16777213.0 / (double) 16777216.0;
	i97 = 97;
	j97 = 33;
}



double aleatorio() {

	double r;

	r = 2.0 * ranmar() - 1.0;


	return r;


}

