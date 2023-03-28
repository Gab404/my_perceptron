#include <stdlib.h>
#include "../includes/header.h"

void initNetwork(network_t *network)
{
    network->neuron = malloc(sizeof(neuron_t));
    handleMalloc(network->neuron);

    network->learningRate = 0.01;

    network->neuron->activateFunction = &sigmoidFunction;
    network->neuron->lossFunction = &logLoss;
    network->neuron->bias = ((float)(rand() % (100 + 1 - 1) + 1)) / 100;
}

void freeNetwork(network_t *net)
{
    for (int i = 0; i < net->nbInput; i++) {
        free(net->trainData[i]);
        free(net->testData[i]);
    }
    free(net->trainData);
    free(net->testData);
    free(net->labelTrain);
    free(net->labelTest);
    free(net->networkOut);

    free(net->neuron->w);
    free(net->neuron);
    free(net);
}

void computeNetOut(network_t *network, float **x, int len)
{
    float result;

    for (int i = 0; i < len; i++) {
        result = linearFunction(network, i, x);
        result = network->neuron->activateFunction(result);
        network->networkOut[i] = result;
    }
}