#include <stdlib.h>
#include "../includes/header.h"

void initNetwork(network_t *network)
{
    network->neuron = malloc(sizeof(neuron_t));
    handleMalloc(network->neuron);

    network->learningRate = 0.01;

    network->neuron->activateFunction = &sigmoidFunction;
    network->neuron->lossFunction = &logLoss;
    network->neuron->w1 = ((float)(rand() % (100 + 1 - 1) + 1)) / 100;
    network->neuron->w2 = ((float)(rand() % (100 + 1 - 1) + 1)) / 100;
    network->neuron->bias = ((float)(rand() % (100 + 1 - 1) + 1)) / 100;
}

void freeNetwork(network_t *network)
{
    free(network->x1);
    free(network->x2);
    free(network->label);
    free(network->networkOut);

    free(network->neuron);
    free(network);
}

void computeNetOut(network_t *network)
{
    float result;

    for (int i = 0; i < network->nb_data; i++) {
        result = linearFunction(network->neuron, network->x1[i], network->x2[i]);
        result = network->neuron->activateFunction(result);
        network->networkOut[i] = result;
    }
}