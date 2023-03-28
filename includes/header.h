#ifndef HEADER_H
    #define HEADER_H

#include "struct.h"

float linearFunction(network_t *net, int index, float **x);
float sigmoidFunction(float linearResult);
float logLoss(float *networkOut, float *label, float nb_data);

void updateNetwork(network_t *network);

void initNetwork(network_t *network);
void freeNetwork(network_t *network);
void computeNetOut(network_t *network, float **x, int len);

void handleMalloc(void *var);

void getData(network_t *net,char *filepath);

#endif /* HEADER_H */