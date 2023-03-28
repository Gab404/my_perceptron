#include "../includes/header.h"

float calcGradientWeight(float w, float *networkOut, float *label, float *x, float nb_data)
{
    float result = 0;

    for (int i = 0; i < nb_data; i++)
        result += ((networkOut[i] - label[i]) * x[i]);

    return ((float)(1 / nb_data) * result);
}

float calcGradientBias(float b, float *networkOut, float *label, float nb_data)
{
    float result = 0;

    for (int i = 0; i < nb_data; i++)
        result += (networkOut[i] - label[i]);

    return ((float)(1 / nb_data) * result);
}

void updateNetwork(network_t *net)
{
    net->neuron->w1 -= net->learningRate * calcGradientWeight(net->neuron->w1, net->networkOut, net->label, net->x1, net->nb_data);
    net->neuron->w2 -= net->learningRate * calcGradientWeight(net->neuron->w2, net->networkOut, net->label, net->x2, net->nb_data);
    net->neuron->bias -= net->learningRate * calcGradientBias(net->neuron->bias, net->networkOut, net->label, net->nb_data);
}