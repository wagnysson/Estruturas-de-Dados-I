#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#include "NumberVector.h"
#include "StopWatch.h"
#include "FileManager.h"

// int getLargestNumber(numberVector_t numberVector)
// {
//     int largestNumber = INT_MIN;
//     int actualNumber;

//     for(int i = 0; i < numberVector.vectorSize; ++i)
//     {
//         actualNumber = numberVector.numbers[i];
//         if(actualNumber > largestNumber)
//             largestNumber = actualNumber;
//     }

//     return largestNumber;
// }

void swap(int *a, int *b){ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

void bubbleSort(int *v, int n){ 
    if (n < 1)
        return; 
 
    for (int i=0; i<n; i++) 
        if (v[i] > v[i+1]) 
            swap(&v[i], &v[i+1]);  
    bubbleSort(v, n-1); 
} 

int busca_binaria_rec (int elem_buscado, int vetor[], int e, int d)
{
    int meio = (e + d)/2;
    if (vetor[meio] == elem_buscado)
        return meio;
    if (e >= d)
        return -1; // não encontrado
    else
        if (vetor[meio] < elem_buscado)
            return busca_binaria_rec(elem_buscado, vetor, meio+1, d);
        else
            return busca_binaria_rec(elem_buscado, vetor, e, meio-1);
}



int main()
{
    numberVector_t numberVector;
    int nExecutions, vectorSize, largestNumber;
    double averageTime = 0.0;
    clock_t startTime, endTime;

    scanf("%d %d", &vectorSize, &nExecutions);

    numberVector = readNumberBinaryFile(vectorSize);

    bubbleSort(numberVector.numbers, numberVector.vectorSize);

    for(int i = 0; i < nExecutions; ++i)
    {
        startTime = clock();
        largestNumber = busca_binaria_rec(10, numberVector.numbers, 0, numberVector.vectorSize-1);
        endTime = clock();
        #ifdef DEBUG
            printf("The largest number is: %d\n", largestNumber);
        #else
            averageTime+=getExecutionTime(startTime, endTime);
        #endif
    }

    #ifndef DEBUG
        averageTime = averageTime/(double)nExecutions;
        saveTimeToFile(vectorSize, averageTime, nExecutions);
    #endif

    free(numberVector.numbers);

}
