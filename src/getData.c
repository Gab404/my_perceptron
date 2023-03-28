#include <stdio.h>
#include <stdlib.h>
#include "../includes/header.h"

void splitData(network_t *net, float **x, float *y)
{
    int i = 0;

    for ( ; i < net->lenDataTrain; i++) {
        for (int j = 0; j < net->nbInput; j++)
            net->trainData[j][i] = x[j][i];
        net->labelTrain[i] = y[i];
    }

    for (int k = 0; i < net->lenDataTrain + net->lenDataTest; i++, k++) {
        for (int j = 0; j < net->nbInput; j++)
            net->testData[j][k] = x[j][i];
        net->labelTest[k] = y[i];
    }
}

void shuffleData(network_t *net, FILE *fp)
{
    int size = (int)(net->lenDataTest + net->lenDataTrain);
    float **x = malloc(sizeof(float*) * net->nbInput);
    float *label = malloc(sizeof(float) * size);
    int newIndex;
    float tmpVal;

    handleMalloc(label);
    for (int i = 0; i < net->nbInput; i++) {
        x[i] = malloc(sizeof(float) * size);
        handleMalloc(x[i]);
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < net->nbInput; j++)
            fscanf(fp, "%f", &x[j][i]);
        fscanf(fp, "%f", &label[i]);
    }

    for (int i = 0; i < size; i++) { // loop to shuffle all the data
        newIndex = rand() % size;
        for (int j = 0; j < net->nbInput; j++) {
            tmpVal = x[j][i];
            x[j][i] = x[j][newIndex];
            x[j][newIndex] = tmpVal;
        }
        tmpVal = label[i];
        label[i] = label[newIndex];
        label[newIndex] = tmpVal;
    }
    splitData(net, x, label);
    for (int i = 0; i < net->nbInput; i++)
        free(x[i]);
    free(x);
    free(label);
}

void getData(network_t *net,char *filepath)
{
    FILE * fp;

    fp = fopen(filepath, "r");
    if (fp == NULL) {
        printf("Exit Failure: error when data file opening\n");
        exit(EXIT_FAILURE);
    }

    fscanf(fp, "%f", &net->lenDataTrain);
    fscanf(fp, "%d", &net->nbInput);
    net->neuron->w = malloc(sizeof(float) * net->nbInput);
    handleMalloc(net->neuron->w);
    net->lenDataTest = (20 * net->lenDataTrain) / 100; // Split dataset to 80% to train and 20% to test
    net->lenDataTrain -= net->lenDataTest;

    net->labelTrain = malloc(sizeof(float) * net->lenDataTrain);
    net->labelTest = malloc(sizeof(float) * net->lenDataTest);
    net->trainData = malloc(sizeof(float*) * net->nbInput);
    net->testData = malloc(sizeof(float*) * net->nbInput);
    handleMalloc(net->trainData);
    handleMalloc(net->testData);
    handleMalloc(net->labelTrain);
    handleMalloc(net->labelTest);

    for (int i = 0; i < net->nbInput; i++) {
        net->trainData[i] = malloc(sizeof(float) * net->lenDataTrain);
        net->testData[i] = malloc(sizeof(float) * net->lenDataTest);
        handleMalloc(net->trainData[i]);
        handleMalloc(net->testData[i]);
    }
    net->networkOut = malloc(sizeof(float) * net->lenDataTrain);
    handleMalloc(net->networkOut);

    shuffleData(net, fp);

    fclose(fp);
}
