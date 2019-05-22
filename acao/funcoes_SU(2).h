#include <stdio.h>	
# define  N		         8				    // É uma rede 3d com todas as direções iguais.
# define  NT       	 	 8			 	    // Direção temporal da rede.
# define  d                      4				    // Dimensão do espaço-tempo.
# define  beta	                 2.25			    // Constante de acoplamento.
# define  pi		         3.14159265358979323846      	    // Número pi.
#define NR			 8.0
#define NTR			 8.0
#define dR			 4.0
#define passosMC		 1000

//====================================================================================
// Definindo os arquivos que serão utilizados no programa.
//====================================================================================

FILE *arquivoU;
FILE *arquivoU2;
//FILE *arquivoU3;


//====================================================================================
// Definindo as variáveis globais que serão utilizadas no programa.
//====================================================================================

double S;												// Valor da ação.
double plaqt;											// Valor da plaqueta.				
double MEDIA;
double mlp;												// Valor global da média do loop de polyakov.

														
														
														
														
//====================================================================================
// Definindo os vetores e matrizes do programa. 
//====================================================================================
int vd[N][N][N][NT][d][4];							// Definindo os vizinhos da direita.
int ve[N][N][N][NT][d][4];							// Definindo os vizinhos da esquerda.
double g[N][N][N][NT][4];							// Definindo as variáveis de gauge.
double U[N][N][N][NT][d][4];							// Definindo as variáveis de link.
double Ug[N][N][N][NT][d][4];							// Definindo as variáveis de link depois da transformação de gauge.
double Un[N][N][N][NT][d][4];							// Definindo as novas variáveis de link.
double Up[N][N][N][NT - 1][4];							// Definindo as variaveis secundarias de link.(resulto dos produtos de link no loop de polyakov)
double A[N][N][N][NT][d][3];
double Ac[3][N][N][N][NT][d];														
//====================================================================================
// Gerador de números aleatórios Ranmar (ranmar.c)
//====================================================================================

double ranmar(void);
void rmarin(int, int);
static double u[97], c, cd, cm;
int i97, j97;
double aleatorio();





//====================================================================================
// Inicialização do programa (inicializacao.c)
//====================================================================================

void coldStart();



//====================================================================================
// Testes do programa (testes.c)
//====================================================================================

void testeunitario(double a0, double a1, double a2, double a3);





//====================================================================================
// Tabela de vizinhos (vizinhos.c)
//====================================================================================

void vizinhoPeriDir();
void vizinhoPeriEsq();


//====================================================================================
//Produto de matrizes (ProdutoMatrizes.c)
//====================================================================================

void prodMatriz(double e0, double e1, double e2, double e3,
				double f0, double f1, double f2, double f3,
				double *g0, double *g1, double *g2, double *g3);





//====================================================================================
//Acao e plaqueta (Acao.c)
//====================================================================================

double plaqueta(int n1, int n2, int n3, int n4, int mu, int nu);
void acao();

//====================================================================================
// Funções para os grampos no cálculo de algoritmos de monte carlo (grampos.c)
//====================================================================================

void grampoSuperior(int x, int y, int z, int t, int i, int j, double *e0, double*e1, double *e2, double *e3);
void grampoInferior(int x, int y, int z, int t, int i, int j, double *e0, double*e1, double *e2, double *e3);
void somaGrampos(int x, int y, int z, int t, int i, double *b0, double *b1, double *b2, double *b3);



//====================================================================================
// Funções para cálculo de banho térmico (banhoTermico.c)
//====================================================================================

void banhoTermico(int x, int y, int z, int t, int i, double*f0, double *f1, double *f2, double *f3, double *e0, double *e1, double *e2, double *e3);
double novaacaoHeatBath(int n1, int n2, int n3, int n4, int mu);
void heatSweep();
void termalizacaoHeatBath();

//===================================================================================
//Funções para cálculo de metropolis (metropolis.c)
//====================================================================================

//void metropolis();
//double novaacaoMetropolis();
//void metroSweep();
//void termalizacaoMetro();

//====================================================================================
//Funções para cálculo de Overrelaxation  (overRelaxation.c)
//====================================================================================

void overelaxation (int n1, int n2, int n3, int n4, int mu,
                    double *f0, double *f1, double *f2, double *f3,
                    double *e0, double *e1, double *e2, double *e3);
double novaacaoOver (int n1, int n2, int n3, int n4, int mu);
void overSweep();
void termalizacaoOver();




//====================================================================================
// Loop de Polyakov (PolyakovLoop.c)
// ===================================================================================

double polyakovloop(int n1, int n2, int n3);
void mediapolyakovloop();



void load_lattice(double * lattice , char * file_name);
void save_lattice(double * lattice, char * file_name);






