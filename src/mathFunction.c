#include <math.h>
#include <stdio.h>
#include "../includes/header.h"

float linearFunction(neuron_t *neuron, float x1, float x2)
{
    return (neuron->w1 * x1) + (neuron->w2 * x2) + neuron->bias; // Linear function => w1*x1 + w2*x2 + b
}

float sigmoidFunction(float linearResult)
{
    return (float)(1 / (1 + exp(-(linearResult)))); // Sigmoid function to linearize results
}

float logLoss(float *networkOut, float *label, float nb_data)
{
    float result = 0;

    for (int i = 0; i < nb_data; i++) {
        result += label[i] * (float)log(networkOut[i]) + (1 - label[i]) * (float)log(1 - networkOut[i]);
        // printf("%f\t%f\t%f\n", result, label[i], networkOut[i]);
    }
    // printf("----------END LogLoss----------\n");
    // printf("%f\n", result);

    //printf("%f\n", (-1 / nb_data) *result);
    return (float)((-1 / nb_data) * result);
}