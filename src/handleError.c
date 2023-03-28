#include <stdlib.h>
#include <stdio.h>

void handleMalloc(void *var)
{
    if (var == NULL) {
        printf("Exit Failure: allocation failed\n");
        exit(EXIT_FAILURE);
    }
}