#include <stdio.h>
#include <stdlib.h>
#include "../includes/header.h"

void loadNetwork(network_t *net, char *filepath)
{
    FILE *fp = fopen(filepath, "r");
    char c;

    if (fp == NULL) {
        printf("Exit Failure: error when opening file: '%s'\n", filepath);
        exit(EXIT_FAILURE);
    }
    initNetwork(net);
    fscanf(fp, "%f", &net->lenDataTrain);
    fscanf(fp, "%i", &net->nbInput);
    net->lenDataTest = (20 * net->lenDataTrain) / 100;
    net->lenDataTrain -= net->lenDataTest;
    fscanf(fp, "%f", &net->learningRate);

    net->neuron->w = malloc(sizeof(float) * net->nbInput);
    handleMalloc(net->neuron->w);
    for (int i = 0; i < net->nbInput; i++)
        fscanf(fp, "%c%f", &c, &net->neuron->w[i]);
    fscanf(fp, "%f", &net->neuron->bias);

    fclose(fp);
}
