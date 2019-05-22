#include <stdio.h>
#include "funcoes_SU(2).h"
#include <stdlib.h>


void save_lattice(double * lattice, char * file_name){
        //always use double quotes to pass file_name
        FILE * fl;
        fl = fopen( file_name , "wb");
        if( fwrite(lattice, sizeof(double) , N*N*N*NT*4*4 , fl) ) {
                printf("\n Lattice saved");
        }
        else{
                perror("Error saving lattice");
                exit(EXIT_FAILURE);
        }
}       

void load_lattice(double * lattice , char * file_name){
        FILE * fl;
        fl = fopen( file_name, "rb" );
        if( fread( lattice, sizeof(double) , N*N*N*NT*4*4 , fl) ){
                printf("\n Lattice loaded");
        }
        else{
                perror("Error loading lattice");
                exit(EXIT_FAILURE);
        }
}



