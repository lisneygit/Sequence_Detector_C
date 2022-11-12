#include <stdio.h>
#include <stdlib.h>
#include "seq_det.h"

int main()
{
    long seed = 1234;
    seed = GenerateSeed();
    srand48(seed);


    int len_array;
    int len_seq;
    int resultat;

    len_array = 20;
    len_seq = 3;


    int *seq, *array;
    seq     = (int *) calloc(len_seq,sizeof(int));
    array   = (int *) calloc(len_array,sizeof(int));

    seq[0] = 1;
    seq[1] = 0;
    seq[2] = 1;
    random_data(array, len_array);

    printf("sequence: ");
    for (int i = 0; i < len_seq; i++) { printf(" %d", seq[i]); } printf("\n");
    
    printf("sequence: ");
    for (int i = 0; i < len_array; i++) { printf(" %d", array[i]); } printf("\n");


    resultat = sequence_detector_v1(array, len_array, seq, len_seq);
    printf("Ejecucion finalizada %d\n", resultat);

    resultat = sequence_detector_101(array, len_array, seq, len_seq);
    printf("Ejecucion finalizada %d\n", resultat);

   return 0;
}