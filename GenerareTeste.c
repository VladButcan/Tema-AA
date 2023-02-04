#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int seed = 0;
    int arraySize = 0;
    //printf("Insert matrix size:\n");
    scanf("%d", &arraySize);
    //printf("Insert seed for random function:\n");
    scanf("%d", &seed);
    srand(seed);
    int array[arraySize];
    for (int i = 0; i < arraySize; i++) {
        array[i] = rand() % 100000;
    }

    for (int i = 0; i < arraySize; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}