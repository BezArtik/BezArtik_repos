#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

long long count = 0;
long long count1 = 0;
//���������� ��������
void Merge(float* mas1, int size1, float* mas2, int size2, float* mas12) {
	int j = 0, k = 0; // j - ������ ��� ������� mas1, k - ������ ��� ������� mas2
	for (int i = 0; i < size1 + size2; i++) { // �������� �� ���� ��������� mas12
		if (j == size1) { // ���� ��� �������� �� mas1 ��� ��������� � mas12
			mas12[i] = mas2[k++]; // ��������� ���������� �������� �� mas2
		}
		else {
			if (k == size2) { // ���� ��� �������� �� mas2 ��� ��������� � mas12
				mas12[i] = mas1[j++]; // ��������� ���������� �������� �� mas1
			}
			else { // ���� ��� �������� �������� � ����� ��������
				if (mas1[j] < mas2[k]) { // ���������� ������� �������� mas1 � mas2
					mas12[i] = mas1[j++]; // ���� ������� mas1 ������, ��������� ��� � mas12
				}
				else {
					mas12[i] = mas2[k++]; // ����� ��������� ������� mas2 � mas12
				}
			}
		}
	}
}
void MergeSort(float* mas, int size, float* mas0) {
	if (size <= 1) { // ���� ������ �������� 1 �������, �� ��� ������������
		return;
	}
	
	MergeSort(&mas[0], size / 2, &mas0[0]);   // ���������� ��������� ������ �������� �������
	MergeSort(&mas[size / 2], size - size / 2, &mas0[size / 2]);  // ���������� ��������� ������ �������� �������
	Merge(&mas[0], size / 2, &mas[size / 2], size - size / 2, &mas0[0]);   // ������� ��� ��������������� �������� � ������ mas0
	
	for (int i = 0; i < size; i++) {
		mas[i] = mas0[i];
	}
}

void MergeComplexityOfWork(float* mas1, int size1, float* mas2, int size2, float* mas12) {
	int j = 0, k = 0; 
	for (int i = 0; i < size1 + size2; i++) { 
		if (j == size1) { 
			mas12[i] = mas2[k++]; 
			count++;
		}
		else {
			if (k == size2) { 
				count++;
				mas12[i] = mas1[j++]; 
			}
			else { 
				if (mas1[j] < mas2[k]) { 
					count++;
					mas12[i] = mas1[j++]; 
				}
				else {
					count++;
					mas12[i] = mas2[k++]; 
				}
			}
		}
	}
}
void MergeSortComplexityOfWork(float* mas, int size, float* mas0) {
	if (size <= 1) { 
		return;
	}

	MergeSortComplexityOfWork(&mas[0], size / 2, &mas0[0]);
	MergeSortComplexityOfWork(&mas[size / 2], size - size / 2, &mas0[size / 2]);
	MergeComplexityOfWork(&mas[0], size / 2, &mas[size / 2], size - size / 2, &mas0[0]);

	for (int i = 0; i < size; i++) {
		mas[i] = mas0[i];
		count++;
	}
}

//���������� �������
void SelectionSort(float* mas, int size) {
	int i_min; // ������ ������������ �������� � ������� ��������
	float min; // ����������� �������� � ������� ��������

	for (int i = 0; i < size - 1; i++) {   //�������� �� ���� ��������� �������, ����� ����������
		min = mas[i]; // ������������, ��� ������� ������� - �����������
		i_min = i; // ���������� ������ �������� ������������ ��������

		
		for (int j = i + 1; j < size; j++) {   //���� ����������� ������� � ���������� ����� �������
			if (min > mas[j]) { // ���� ������ ������� ������ �������� ��������
				i_min = j; // ��������� ������ ������������ ��������
				min = mas[j]; // ��������� �������� ��������
			}
		}

		// ����� ����������: ������ ��������� ����������� ������� �� ����� ��������
		float t = mas[i]; 
		mas[i] = mas[i_min]; 
		mas[i_min] = t; 
	}
}

void SelectionSortComplexityOfWork(float* mas, int size) {
	int i_min; 
	float min; 
	for (int i = 0; i < size - 1; i++) {   
		min = mas[i];
		count++;
		i_min = i; 
		count++;

		for (int j = i + 1; j < size; j++) {   
			count++;
			if (min > mas[j]) {
				count++;
				i_min = j; 
				count++;
				min = mas[j]; 
				count++;
			}
		}
		float t = mas[i];
		count++;
		mas[i] = mas[i_min];
		count++;
		mas[i_min] = t;
		count++;
	}
}

//���������� ���������
void CombSort(float* mas, int size) {
	int gap = size;  // ��������� ���
	int ratio = 2;  // ����������� ���������� ����
	int flag = 1;  // ���� ��� ������������ �������

	while (gap > 1 || flag) {
		gap /= ratio;  // ��������� ���
		if (gap < 1) {
			gap = 1;
		}
		flag = 0;
		for (int i = 0; i < size - gap; i++) {  // ���������� �������� � ������ ��
			if (mas[i] > mas[i + gap]) {
				float t = mas[i];
				mas[i] = mas[i + gap];
				mas[i + gap] = t;
				flag = 1;  // ����� ���������
			}
		}
	}
}
void CombSortComplexityOfWork(float* mas, int size) {
	int gap = size;  
	int ratio = 2;  
	int flag = 1;  
	while (gap > 1 || flag) {
		gap /= ratio;  
		if (gap < 1) {
			gap = 1;
		}
		flag = 0;
		for (int i = 0; i < size - gap; i++) {  
			if (mas[i] > mas[i + gap]) {
				count++;
				float t = mas[i];
				mas[i] = mas[i + gap];
				mas[i + gap] = t;
				flag = 1;  
			}
		}
	}
}

//����������� ����������
void Fcount(float* mas, unsigned int counter[], int size, int offset) {
	unsigned char* b = (unsigned char*)mas; // �������� ��������� �� ������ float � unsigned char
	memset(counter, 0, 256 * sizeof(unsigned int)); // �������� ������� ��� 256 ��������� �������� ������

	for (int i = 0; i < size; i++) {  // ������� ���������� ��������� ������� �����
		counter[b[i * sizeof(float) + offset]]++; // ����������� ������� ��� �������� �����
	}

	for (int i = 1; i < 256; i++) {  // ����������� ������� � ������� ��� ����������
		counter[i] += counter[i - 1]; // ��������� �������� ��� ��������� ��������
	}
}

void RadixSort(float* mas, int size) {
	unsigned int counter[256]; // ������ ��� �������� ��������� ������
	float* mas1 = (float*)malloc(size * sizeof(float)); // �������� ������ ��� ���������� �������
	if (mas1 == NULL) { 
		return;
	}

	unsigned char* b = (unsigned char*)mas; // �������� ��������� �� ������ float � unsigned char

	for (int i = 0; i < sizeof(float); i++) {  // �������� ���� �� ������� ����� float (4 �����)
		Fcount(mas, counter, size, i); // �������� ������� Fcount ��� �������� ��������� ������

		for (int j = size - 1; j >= 0; j--) {   // ����������� ��������� � ��������������� ������ mas1
			mas1[counter[b[j * sizeof(float) + i]] - 1] = mas[j]; // ������������ �������� � ������ mas1 �� �������� �� counter
			counter[b[j * sizeof(float) + i]]--; // ��������� �������
		}
		// �������� ��������������� �������� ������� � ������������ ������ mas
		memcpy(mas, mas1, size * sizeof(float)); // �������� �������� �� mas1 ������� � mas
		
	}
	free(mas1); // ����������� ������, ���������� ��� ������ mas1
}
void RadixSortWithSign(float* mas, int size) {
	float* pos = (float*)malloc(size * sizeof(float)); // �������� ������ ��� ������� ������������� � ������� ������������� �����
	float* neg = (float*)malloc(size * sizeof(float));
	int posCount = 0, negCount = 0;
	if (pos == NULL || neg == NULL) {
		return;
	}
	// ��������� ������������� � ������������� �����
	for (int i = 0; i < size; i++) {
		if (mas[i] >= 0) {
			pos[posCount++] = mas[i];
		}
		else {
			neg[negCount++] = mas[i];
		}
	}
	
	// ��������� ������������� � ������������� ����� ��������
	RadixSort(neg, negCount);
	RadixSort(pos, posCount);

	// ���������� ��������������� �������
	for (int i = 0; i < negCount; i++) {
		mas[i] = neg[negCount - i - 1]; // �������� ������� ��� ������������� �����
	}

	for (int i = 0; i < posCount; i++) {
		mas[negCount + i] = pos[i]; // ������������� ����� ���� ����� �������������
	}

	free(pos);
	free(neg);
}

void FcountComplexityOfWork(float* mas, unsigned int counter[], int n, int offset) {
	unsigned char* b = (unsigned char*)mas; 
	memset(counter, 0, 256 * sizeof(unsigned int)); 
	for (int i = 0; i < n; i++) {  
		counter[b[i * sizeof(float) + offset]]++;
	}

	for (int i = 1; i < 256; i++) {  
		counter[i] += counter[i - 1]; 
	}
}

void RadixSortComplexityOfWork(float* mas, int size) {
	unsigned int counter[256]; 
	float* mas1 = (float*)malloc(size * sizeof(float)); 
	if (mas1 == NULL) { 
		return;
	}

	unsigned char* c = (unsigned char*)mas; 

	for (int i = 0; i < sizeof(float); i++) {  
		FcountComplexityOfWork(mas, counter, size, i);

		for (int j = size - 1; j >= 0; j--) {   
			mas1[counter[c[j * sizeof(float) + i]] - 1] = mas[j]; 
			count++;
			counter[c[j * sizeof(float) + i]]--;
		}

		memcpy(mas, mas1, size * sizeof(float));
	}
	free(mas1); 
}
void RadixSortWithSignComplexityOfWork(float* mas, int size) {
	float* pos = (float*)malloc(size * sizeof(float));
	float* neg = (float*)malloc(size * sizeof(float));
	int posCount = 0, negCount = 0;
	if (pos == NULL || neg == NULL) {
		return;
	}
	for (int i = 0; i < size; i++) {
		if (mas[i] >= 0) {
			pos[posCount++] = mas[i];
			count1++;
		}
		else {
			neg[negCount++] = mas[i];
			count1++;
		}
	}

	RadixSort(neg, negCount);
	RadixSort(pos, posCount);

	for (int i = 0; i < negCount; i++) {
		mas[i] = neg[negCount - i - 1]; 
		count1++;
	}

	for (int i = 0; i < posCount; i++) {
		mas[negCount + i] = pos[i]; 
		count1++;
	}

	free(pos);
	free(neg);
}


//������� ������� ������ ���������
void TimeOfWork(void (*f)(float* mas, int size), int size) {
	float* mas = (float*)malloc(sizeof(float) * size);
	if (mas == NULL) {
			return;
	}
	for (int i = 0; i < size; i++) {
		mas[i] = (float)rand() / (float)(RAND_MAX / (float)2000000) - 1000000;
	}
	clock_t start = clock();
	f(mas, size);
	clock_t finish = clock();
	double time_taken = ((double)(finish - start)) / CLOCKS_PER_SEC;
	printf("%f seconds\n",time_taken);
	
	free(mas);
}

void TimeOfWorkMerge(void (*f)(float* mas, int size,float* mas0), int size) {
	float* mas = (float*)malloc(sizeof(float) * size);
	float* mas0 = (float*)malloc(sizeof(float) * size);
	if (mas == NULL || mas0 == NULL) {
			return;
	}
	for (int i = 0; i < size; i++) {
		mas[i] = (float)rand() / (float)(RAND_MAX / (float)2000000) - 1000000;
		mas0[i] = 0;
	}
	clock_t start = clock();
	f(mas, size,mas0);
	clock_t finish = clock();
	double time_taken = ((double)(finish - start)) / CLOCKS_PER_SEC;
	printf("%f seconds\n", time_taken);
	
	free(mas);
	free(mas0);
}

//������� ��������� ������ ���������
void ComplexityOfWork(void (*f)(float* mas, int size), int size) {
	float* mas = (float*)malloc(sizeof(float) * size);
	if (mas == NULL) {
			return;
	}
	for (int i = 0; i < size; i++) {
		mas[i] = (float)rand() / (float)(RAND_MAX / (float)2000000) - 1000000;
	}

	f(mas, size);
	
	printf("%lli operation\n", count);
	free(mas);
}

void ComplexityOfWorkMerge(void (*f)(float* mas, int size, float* mas0), int size) {
	float* mas = (float*)malloc(sizeof(float) * size);
	float* mas0 = (float*)malloc(sizeof(float) * size);
	if (mas == NULL || mas0 == NULL) {
			return;
	}
	for (int i = 0; i < size; i++) {
		mas[i] = (float)rand() / (float)(RAND_MAX / (float)2000000) - 1000000;
		mas0[i] = 0;
	}

	f(mas, size, mas0);

	printf("%lli operation\n", count);
	free(mas);
	free(mas0);
}

void ComplexityOfWorkRadix(void (*f)(float* mas, int size), void (*f1)(float* mas, int size), int size) {
	float* mas = (float*)malloc(sizeof(float) * size);
	if (mas == NULL) {
		return;
	}
	for (int i = 0; i < size; i++) {
		mas[i] = (float)rand() / (float)(RAND_MAX / (float)2000000) - 1000000;
	}

	f(mas, size);
	f1(mas, size);

	printf("%lli operation\n", count+count1);
	free(mas);
}

int cmp(const void* a, const void* b) {
	return (*(float*)a > *(float*)b) - (*(float*)a < *(float*)b);
}

//������������� ������������ ����������
void ConfirmationOfCorrectness(void (*f)(float* mas, int size), int size) {
	float* mas = (float*)malloc(sizeof(float) * size);
	float* mas1 = (float*)malloc(sizeof(float) * size);
	int flag = 1;
	if (mas == NULL || mas1 == NULL) {
		return;
	}
	for (int i = 0; i < size; i++) {
		mas[i] = (float)rand() / (float)(RAND_MAX / (float)2000000) - 1000000;
		mas1[i] = mas[i];
	}
	f(mas, size);
	qsort(mas1, size, sizeof(float), cmp);
	for (int i = 0; i < size; i++) {
		if (mas[i] != mas1[i]) {
			flag = 0;
			break;
		}
	}
	if (flag == 1) {
		printf("The array has been sorted successfully!\n");
	}
	else {
		printf("The array wasn't sorted.\n");
	}
	free(mas);
	free(mas1);
}
void ConfirmationOfCorrectnessMerge(void (*f)(float* mas, int size, float* mas0),  int size) {
	float* mas = (float*)malloc(sizeof(float) * size);
	float* mas0 = (float*)malloc(sizeof(float) * size);
	float* mas1 = (float*)malloc(sizeof(float) * size);
	int flag = 1;
	if (mas == NULL || mas1 == NULL || mas0 == NULL) {
		return;
	}
	for (int i = 0; i < size; i++) {
		mas[i] = (float)rand() / (float)(RAND_MAX / (float)2000000) - 1000000;
		mas1[i] = mas[i];
		mas0[i] = 0;
	}
	f(mas, size, mas0);
	qsort(mas1, size, sizeof(float), cmp);
	for (int i = 0; i < size; i++) {
		if (mas[i] != mas1[i]) {
			flag = 0;
			break;
		}
	}
	if (flag == 1) {
		printf("The array has been sorted successfully!\n");
	}
	else {
		printf("The array wasn't sorted.\n");
	}
	free(mas);
	free(mas0);
	free(mas1);
}