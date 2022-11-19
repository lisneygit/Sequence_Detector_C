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
    int expected, resultat;

    len_array = 1000;
    len_seq = 4;


    int *seq, *array;
    seq     = (int *) calloc(len_seq,sizeof(int));
    array   = (int *) calloc(len_array,sizeof(int));

    seq[0] = 1;
    seq[1] = 0;
    seq[2] = 1;
    seq[3] = 1;
    random_data(array, len_array);


    printf("sequence of length = 3: ");
    for (int i = 0; i < 3; i++) { printf(" %d", seq[i]); } printf("\n");
    printf("sequence of length = 4: ");
    for (int i = 0; i < 4; i++) { printf(" %d", seq[i]); } printf("\n");
    
    printf("data: ");
    for (int i = 0; i < len_array; i++) { printf(" %d", array[i]); } printf("\n");

    expected = sequence_detector_len3(array, len_array, seq, len_seq);
    resultat = sequence_detector_101(array, len_array, seq, len_seq);
    if (expected != resultat)
    {
        printf("ERROR in detector of length = 3: expected = %d, obtained = %d\n", expected, resultat);
        return -1;
    }
    printf("SIMULATION PASSED: number of sequences = %d\n", resultat);


    expected = sequence_detector_len4(array, len_array, seq, len_seq);
    resultat = sequence_detector_1011(array, len_array, seq, len_seq);
    if (expected != resultat)
    {
        printf("ERROR in detector of length = 4: expected = %d, obtained = %d\n", expected, resultat);
        return -1;
    }
    printf("SIMULATION PASSED: number of sequences = %d\n", resultat);

   return 0;
}