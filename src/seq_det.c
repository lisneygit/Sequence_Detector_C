#include <stdio.h>
#include <stdlib.h>
#include "seq_det.h"

long GenerateSeed(void)
{
    long seed; 
	int heure, minute, seconde;
    char chaine[10];

    time_t temps;
    time(&temps);
    strftime(chaine,10,"%H %M %S", localtime(&temps));
    sscanf(chaine,"%2d %2d %2d", &heure, &minute, &seconde);
    seed = heure+minute*11+seconde*1237;
    seed = seed%2==0 ? seed+1 : seed;

    return seed;
}

void random_data(int *array, int len_array)
{
	double r;

	for (int i = 0; i < len_array; i++)
	{
		r = drand48();
		
		if ( r < 0.5)
			array[i] = 0;
		else
			array[i] = 1;
	}
}

int sequence_detector_len3(int *array, int len_array, int *seq, int len_seq)
{
	int cont;
	
	cont = 0;
	for(int i =0 ; i < len_array; i++)
	{
		if(array[i]==seq[0] && array[i+1]==seq[1] && array[i+2]==seq[2])
		{
			cont = cont + 1;
		}
	}
	printf("\nnumber of sequences: %d \n", cont);
   return cont;
}

int sequence_detector_101(int *array, int len_array, int *seq, int len_seq)
{
	int i;
	int cont;
	
	i = 0;
	cont = 0;
	
state_0:
	if (i == len_array) goto END;
	
	if (array[i] == 1) { printf(" 1 "); i++; goto state_1; }
	else { i++; goto state_0; }

state_1:
	if (i == len_array) goto END;

	if (array[i] == 0) { printf(" 0 "); i++; goto state_2; }
	else { i++; goto state_1; }

state_2:
	if (i == len_array) goto END;

	if (array[i] == 1) { printf(" 1 \n"); i++; cont ++; goto state_1; }
	else { i++; goto state_0; }

END:
	printf("\nnumber of sequences: %d \n", cont);
	
   return cont;
}

int sequence_detector_len4(int *array, int len_array, int *seq, int len_seq)
{
	int cont;
	
	cont = 0;

	for(int i =0 ; i < len_array; i++)
	{
		if(array[i]==seq[0] && array[i+1]==seq[1] && array[i+2]==seq[2] && array[i+3]==seq[3])
		{
			cont = cont + 1;
		}

	}
	printf("\nnumber of sequences: %d \n", cont);
   return cont;
}

int sequence_detector_1011(int *array, int len_array, int *seq, int len_seq)
{
	int i;
	int cont;
	
	i = 0;
	cont = 0;

state_0:
	if (i == len_array) goto END;
	
	if (array[i] == 1) { printf(" 1 "); i++; goto state_1; }
	else { i++; goto state_0; }

state_1:
	if (i == len_array) goto END;

	if (array[i] == 0) { printf(" 0 "); i++; goto state_2; }
	else { i++; goto state_1; }

state_2:
	if (i == len_array) goto END;

	if (array[i] == 1) { printf(" 1 "); i++; goto state_3; }
	else { i++; goto state_0; }

state_3:
	if (i == len_array) goto END;

	if (array[i] == 1) { printf(" 1 \n"); i++; cont ++; goto state_1; }
	else { i++; goto state_2; }

END:
	printf("\nnumber of sequences: %d \n", cont);
	
   return cont;
}