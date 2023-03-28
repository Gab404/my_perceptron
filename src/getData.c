#include <stdio.h>
#include <stdlib.h>
#include "../includes/header.h"

void getData(network_t *net,char *filepath)
{
    FILE * fp;

    fp = fopen(filepath, "r");
    if (fp == NULL) {
        printf("Exit Failure: error when data file opening\n");
        exit(EXIT_FAILURE);
    }

    fscanf(fp, "%f", &net->nb_data);

    net->x1 = malloc(sizeof(float) * net->nb_data);
    net->x2 = malloc(sizeof(float) * net->nb_data);
    net->label = malloc(sizeof(float) * net->nb_data);
    net->networkOut = malloc(sizeof(float) * net->nb_data);
    handleMalloc(net->x1);
    handleMalloc(net->x2);
    handleMalloc(net->label);
    handleMalloc(net->networkOut);

    for (int i = 0; i < net->nb_data; i++) {
        fscanf(fp, "%f", &net->x1[i]);
        fscanf(fp, "%f", &net->x2[i]);
        fscanf(fp, "%f", &net->label[i]);
    }

    fclose(fp);
}
