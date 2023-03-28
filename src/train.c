#include <stdio.h>
#include <math.h>
#include "../includes/header.h"

void test(network_t *net)
{
    int goodPred = 0;
    
    computeNetOut(net, net->testData, net->lenDataTest);

    for (int i = 0; i < net->lenDataTest; i++)
        if (roundf(net->networkOut[i]) == net->labelTest[i])
            goodPred++;

    printf("\n----Accuracy = %d%%----\n\n", (goodPred * 100) / net->lenDataTest);
}

void train(network_t *net, int epochs, bool isSave)
{
    float loss;
    char name[50];

    fflush(stdin);
    printf("file path of data file:\n");
    scanf("%s", &name);
    createNetwork(net, name);

    for (int i = 0; i < epochs; i++) { // train loop
        computeNetOut(net, net->trainData, net->lenDataTrain);
        loss = logLoss(net->networkOut, net->labelTrain, net->lenDataTrain);
        updateNetwork(net);
        printf("epoch = %d/%d\tloss = %f\n", i + 1, epochs, loss);
    }

    test(net);

    if (isSave) {
        fflush(stdin);
        printf("save file's name:\n");
        scanf("%s", &name);
        saveWeights(net, name);
    }

    freeNetwork(net);
}