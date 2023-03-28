#ifndef HEADER_H
    #define HEADER_H
#include <stdbool.h>
#include "struct.h"

float linearFunction(network_t *net, int index, float **x);
float sigmoidFunction(float linearResult);
float logLoss(float *networkOut, float *label, float nb_data);

void updateNetwork(network_t *network);

void initNetwork(network_t *network);
void freeNetwork(network_t *network);
void createNetwork(network_t *network, char *dataFilepath);
void computeNetOut(network_t *network, float **x, int len);

void handleMalloc(void *var);

void getData(network_t *net,char *filepath);

void saveWeights(network_t *net, char *name);

void loadNetwork(network_t *net, char *filepath);

void test(network_t *net);
void train(network_t *net, int epochs, bool isSave);

#endif /* HEADER_H */