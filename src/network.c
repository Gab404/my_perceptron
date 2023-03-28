#include <stdlib.h>
#include <time.h>
#include "../includes/header.h"

void initNetwork(network_t *network)
{
    srand(time(NULL));
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

void createNetwork(network_t *network, char *dataFilepath)
{
    initNetwork(network);
    getData(network, "./data/iris-dataset.data");

    network->neuron->w = malloc(sizeof(float) * network->nbInput);
    handleMalloc(network->neuron->w);
    for (int i = 0; i < network->nbInput; i++)
        network->neuron->w[i] = ((float)(rand() % (50 + 1 - 1) + 1)) / 100;
}