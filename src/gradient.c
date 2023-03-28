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
    for (int i = 0; i < net->nbInput; i++)
        net->neuron->w[i] -= net->learningRate * calcGradientWeight(net->neuron->w[i], net->networkOut, net->labelTrain, net->trainData[i], net->lenDataTrain);

    net->neuron->bias -= net->learningRate * calcGradientBias(net->neuron->bias, net->networkOut, net->labelTrain, net->lenDataTrain);
}