#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../includes/header.h"

int main(void)
{
    network_t *network = malloc(sizeof(network_t));
    int epochs = 20;
    float loss;

    srand(time(NULL));
    handleMalloc(network);
    initNetwork(network);
    getData(network, "./data/iris-dataset.data");

    for (int i = 0; i < epochs; i++) {
        computeNetOut(network);
        loss = logLoss(network->networkOut, network->label, network->nb_data);
        updateNetwork(network);
        printf("loss = %f\tw1 = %f\tw2 = %f\tb = %f\n\n", loss, network->neuron->w1, network->neuron->w2, network->neuron->bias);
    }

    freeNetwork(network);
    return 0;
}