#include <stdlib.h>
#include "../includes/header.h"

int main(void)
{
    network_t *network = malloc(sizeof(network_t));

    handleMalloc(network);
    loadNetwork(network, "./save/myWeights.conf");
    getData(network, "./data/iris-dataset.data");

    test(network);

    return 0;
}