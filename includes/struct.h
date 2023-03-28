#ifndef STRUCT_H
    #define STRUCT_H

typedef struct neuron_s {
    float w1;
    float w2;
    float bias;
    float (*activateFunction)(float);
    float (*lossFunction)(float *, float *, float);
} neuron_t;

typedef struct network_s {
    float *x1;
    float *x2;
    float *label;
    float *networkOut;
    float nb_data;
    float learningRate;
    neuron_t *neuron;
} network_t;

#endif /* STRUCT_H */