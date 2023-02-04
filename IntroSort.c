#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

void InsertionSort(int* data, int count) {
	for (int i = 1; i < count; ++i)
	{
		int j = i;

		while (j > 0)
		{
			if (data[j - 1] > data[j])
			{
				data[j - 1] ^= data[j];
				data[j] ^= data[j - 1];
				data[j - 1] ^= data[j];

				--j;
			}
			else
			{
				break;
			}
		}
	}
}

void MaxHeapify(int* data, int heapSize, int index) {
	int left = (index + 1) * 2 - 1;
	int right = (index + 1) * 2;
	int largest = 0;

	if (left < heapSize && data[left] > data[index])
		largest = left;
	else
		largest = index;

	if (right < heapSize && data[right] > data[largest])
		largest = right;

	if (largest != index)
	{
		int temp = data[index];
		data[index] = data[largest];
		data[largest] = temp;

		MaxHeapify(data, heapSize, largest);
	}
}

void HeapSort(int* data, int count) {
	int heapSize = count;

	for (int p = (heapSize - 1) / 2; p >= 0; --p)
		MaxHeapify(data, heapSize, p);

	for (int i = count - 1; i > 0; --i)
	{
		int temp = data[i];
		data[i] = data[0];
		data[0] = temp;

		--heapSize;
		MaxHeapify(data, heapSize, 0);
	}
}

int Partition(int* data, int left, int right) {
	int pivot = data[right];
	int temp;
	int i = left;

	for (int j = left; j < right; ++j)
	{
		if (data[j] <= pivot)
		{
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;
			i++;
		}
	}

	data[right] = data[i];
	data[i] = pivot;

	return i;
}

void QuickSortRecursive(int* data, int left, int right) {
	if (left < right)
	{
		int q = Partition(data, left, right);
		QuickSortRecursive(data, left, q - 1);
		QuickSortRecursive(data, q + 1, right);
	}
}

void IntroSort(int* data, int count) {
	int partitionSize = Partition(data, 0, count - 1);

	if (partitionSize < 16)
	{
		InsertionSort(data, count);
	}
	else if (partitionSize >(2 * log(count)))
	{
		HeapSort(data, count);
	}
	else
	{
		QuickSortRecursive(data, 0, count - 1);
	}
}

void printArray(int array[], int arraySize, int testsNumber, char* number, int timeForProgramm)
{
    FILE *outputFile;
    char *fileName = malloc(50);
    strcpy(fileName, "./out/test");
    strcat(fileName, number);
    strcat(fileName, ".out");
    outputFile = fopen(fileName, "w");
    //fprintf(outputFile, "%d\n", arraySize);
    for (int j = 0; j < arraySize; j++) {
        fprintf(outputFile, "%d ", array[j]);
    }
    fprintf(outputFile, "\n");
    fprintf(outputFile, "Run Time: %f\n", (float)timeForProgramm / CLOCKS_PER_SEC);
    free(fileName);
    fclose(outputFile);
}

int main() {
    FILE *file;
    FILE *numbersFile;
    numbersFile = fopen("numbersFile.txt", "r");
    int testsNumber;
    fscanf(numbersFile, "%d", &testsNumber);
    int arraySize = 0;
    char *fileName;
    char *number = malloc(10);
    fileName = malloc(30);
    int programmTimeStart = 0;
    int programmTimeEnd = 0;
    int timeForProgramm = 0;
    int arrayTimeProgramm[testsNumber];
    float mediumRunTime = 0.0;
    for (int i = 1; i <= testsNumber; i++) {
        strcpy(fileName, "./in/test");
        fscanf(numbersFile, "%s", number);
        strcat(fileName, number);
        strcat(fileName, ".in");
        file = fopen(fileName, "r");
        fscanf(file, "%d", &arraySize);
        int array[arraySize];
        for (int j = 0; j < arraySize; j++) {
            fscanf(file, "%d", &array[j]);
        }
        programmTimeStart = clock();
        IntroSort(array, arraySize);
        programmTimeEnd = clock();
        timeForProgramm = programmTimeEnd - programmTimeStart;
        arrayTimeProgramm[i - 1] = timeForProgramm;
        mediumRunTime += ((float)timeForProgramm / CLOCKS_PER_SEC);
        free(fileName);
        fileName = malloc(30);
        fclose(file);
        printArray(array, arraySize, testsNumber, number, timeForProgramm);
    }
    fclose(numbersFile);
    printf("RunTime result:\n");
    for (int i = 0; i < testsNumber; i++) {
        printf("Test %d: %0.9f seconds\n", i + 1, (float)arrayTimeProgramm[i] / CLOCKS_PER_SEC);
    }
    printf("\n");
    IntroSort(arrayTimeProgramm, testsNumber);
    mediumRunTime /= testsNumber;
    printf("Best runTime: %0.9f\n", (float)arrayTimeProgramm[0] / CLOCKS_PER_SEC);
    printf("Medium runTime: %0.9f\n", mediumRunTime);
    printf("Worst runTime: %0.9f\n", (float)arrayTimeProgramm[testsNumber - 1] / CLOCKS_PER_SEC);
    return 0;
}
