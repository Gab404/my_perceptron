#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "../includes/header.h"

int main(void)
{
    network_t *network = malloc(sizeof(network_t));
    int epochs = 20;
    float loss;
    int goodPred = 0;

    srand(time(NULL));
    handleMalloc(network);
    initNetwork(network);
    getData(network, "./data/iris-dataset.data");

    for (int i = 0; i < network->nbInput; i++)
        network->neuron->w[i] = ((float)(rand() % (100 + 1 - 1) + 1)) / 100;

    for (int i = 0; i < epochs; i++) { // train loop
        computeNetOut(network, network->trainData, network->lenDataTrain);
        loss = logLoss(network->networkOut, network->labelTrain, network->lenDataTrain);
        updateNetwork(network);
        printf("epoch = %d/%d\tloss = %f\n", i + 1, epochs, loss);
    }


    computeNetOut(network, network->testData, network->lenDataTest);
    for (int i = 0; i < network->lenDataTest; i++) {
        // printf("%i | pred = %f | result = %f\n", i, network->networkOut[i], network->labelTest[i]);
        if (roundf(network->networkOut[i]) == network->labelTest[i])
            goodPred++;
    }
    printf("Accuracy = %d%%\n", (goodPred * 100) / network->lenDataTest);

    freeNetwork(network);
    return 0;
}