

#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <time.h>

long GenerateSeed(void);
void random_data(int *array, int len_array);
int sequence_detector_v1(int *array, int len_array, int *seq, int len_seq);
int sequence_detector_101(int *array, int len_array, int *seq, int len_seq);

#endif