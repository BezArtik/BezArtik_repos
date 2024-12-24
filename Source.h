#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void Merge(float* mas1, int size1, float* mas2, int size2, float* mas12);

void MergeSort(float* mas, int size, float* mas0);

void MergeComplexityOfWork(float* mas1, int size1, float* mas2, int size2, float* mas12);

void MergeSortComplexityOfWork(float* mas, int size, float* mas0);

void SelectionSort(float* mas, int size);

void SelectionSortComplexityOfWork(float* mas, int size);

void CombSort(float* mas, int size);

void CombSortComplexityOfWork(float* mas, int size);

void Fcount(float* mas, unsigned int counter[], int n, int offset);

void RadixSort(float* mas, int size);

void RadixSortWithSign(float* mas, int size);

void FcountComplexityOfWork(float* mas, unsigned int counter[], int size, int offset);

void RadixSortComplexityOfWork(float* mas, int size);

void RadixSortWithSignComplexityOfWork(float* mas, int size);

void TimeOfWork(void (*f)(float* mas, int size), int size);

void TimeOfWorkMerge(void (*f)(float* mas, int size,float* mas0), int size);

void ComplexityOfWork(void (*f)(float* mas, int size), int size);

void ComplexityOfWorkMerge(void (*f)(float* mas, int size, float* mas0), int size);

void ComplexityOfWorkRadix(void (*f)(float* mas, int size), void (*f1)(float* mas, int size), int size);

int cmp(const void* a, const void* b);

void ConfirmationOfCorrectness(void (*f)(float* mas, int size), int size);

void ConfirmationOfCorrectnessMerge(void (*f)(float* mas, int size, float* mas0), int size);