#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../includes/header.h"

void saveWeights(network_t *net, char *name)
{
    char *filepath = malloc(sizeof(char) * (strlen(name) + strlen("./save/.conf")));
    FILE *fp;

    strcpy(filepath, "./save/");
    strcat(filepath, name);
    strcat(filepath, ".conf");

    if ((fp = fopen(filepath, "w")) == NULL) {
        printf("Error: save failed\n");
        return;
    }

    fprintf(fp, "%.0f ", (net->lenDataTrain + net->lenDataTest));
    fprintf(fp, "%i\n", net->nbInput);
    fprintf(fp, "%f\n", net->learningRate);
    
    for (int i = 0; i < net->nbInput; i++)
        fprintf(fp, "%f\n", net->neuron->w[i]);
    fprintf(fp, "%f\n", net->neuron->bias);

    fclose(fp);
    free(filepath);
}