#include <math.h>
#include <stdio.h>
#include "../includes/header.h"

float linearFunction(network_t *net, int index, float **x)
{
    float result = 0;

    for (int i = 0; i < net->nbInput; i++)
        result += (x[i][index] * net->neuron->w[i]);

    return result + net->neuron->bias; // Linear function => w1*x1 + ... + wn*xn + b
}

float sigmoidFunction(float linearResult)
{
    return (float)(1 / (1 + exp(-(linearResult)))); // Sigmoid function to linearize results
}

float logLoss(float *networkOut, float *label, float nb_data)
{
    float result = 0;

    for (int i = 0; i < nb_data; i++)
        result += label[i] * (float)log(networkOut[i]) + (1 - label[i]) * (float)log(1 - networkOut[i]);

    return (float)((-1 / nb_data) * result);
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