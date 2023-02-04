#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
bool verify(FILE* inputFile, FILE* outputFile, char* number) {
    int arraySize = 0;
    int nr1 = 0, nr2 = 0;

    FILE* testFile = fopen("./in/test1.in", "r");
    fscanf(testFile, "%d", &arraySize);
    fclose(testFile);

    fscanf(inputFile, "%d", &nr1);
    fscanf(inputFile, "%d", &nr2);
    if (nr1 > nr2) {
        fprintf(outputFile, "Test %s failed\n", number);
        return false;
    }
    nr1 = nr2;
    for (int i = 1; i < arraySize - 1; i++) {
        fscanf(inputFile, "%d", &nr2);
        if (nr1 > nr2) {
            fprintf(outputFile, "Test %s failed\n", number);
            return false;
        }
        nr1 = nr2;
    }
    fprintf(outputFile, "Test %s passed\n", number);
}

void createFile(char* fileName, char* number, FILE* outputFile) {
    FILE *inputFile;
    strcpy(fileName, "./out/test");
    strcat(fileName, number);
    strcat(fileName, ".out");
    inputFile = fopen(fileName, "r");
    verify(inputFile, outputFile, number);
    fclose(inputFile);
}


int main() {
    FILE *outputFile;
    char *outputFileName = malloc(60);
    strcpy(outputFileName, "./out/verifyResult.txt");
    outputFile = fopen(outputFileName, "w");

    FILE *numbersFile;
    numbersFile = fopen("./numbersFile.txt", "r");

    int testsNumber;
    fscanf(numbersFile, "%d", &testsNumber);
    int arraySize = 0;
    char *fileName;
    char *number = malloc(10);
    for (int i = 0; i < testsNumber; i++) {
        fscanf(numbersFile, "%s", number);
        fileName = malloc(50);
        createFile(fileName, number, outputFile);
        free(fileName);
    }
    return 0;
}