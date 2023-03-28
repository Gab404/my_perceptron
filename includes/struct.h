#ifndef STRUCT_H
    #define STRUCT_H

typedef struct neuron_s {
    float *w;
    float bias;
    float (*activateFunction)(float);
    float (*lossFunction)(float *, float *, float);
} neuron_t;

typedef struct network_s {
    float **trainData;
    float **testData;
    float *labelTrain;
    float *labelTest;
    float *networkOut;
    float lenDataTrain;
    int lenDataTest;
    int nbInput;
    float learningRate;
    neuron_t *neuron;
} network_t;

#endif /* STRUCT_H */