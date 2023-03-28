#ifndef HEADER_H
    #define HEADER_H

#include "struct.h"

float linearFunction(neuron_t *neuron, float x1, float x2);
float sigmoidFunction(float linearResult);
float logLoss(float *networkOut, float *label, float nb_data);

void updateNetwork(network_t *network);

void initNetwork(network_t *network);
void freeNetwork(network_t *network);
void computeNetOut(network_t *network);

void handleMalloc(void *var);

void getData(network_t *net,char *filepath);

#endif /* HEADER_H */