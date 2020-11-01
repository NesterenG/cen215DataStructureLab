#include<stdio.h>
#include<string.h>
#include<time.h>
void Swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void SwapChar(char* a, char* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void PrintArray(int x[],int size) {
	
	int i;
	printf("\t");
	for (i = 0; i < size; i++) {
		printf("%3d", x[i]);
	}
}


void PrintChar(char a[], int size) {
	
	int i;
	printf("\t");
	for (i = 0; i < size; i++) {
		printf("%3c", a[i]);
	}

}


void Insertionsort(int NO[],int size) {
	
	int i, j, min;
	for (i = 1; i < 10; i++) {
		min = NO[i];
		for (j = i - 1; j >= 0 && min < NO[j]; j--) {
			NO[j + 1] = NO[j];
		}

		NO[j + 1] = min;
	}
	
}


void InsertionsortChar(char x[], int size) {

	 int i, j, min;
	
	 for (i = 1; i < size; i++) {
		 min = x[i];
		 for (j = i - 1; j >= 0 && min < x[j]; j--) {
			 x[j + 1] = x[j];
		 }
		 x[j + 1] = min;
	 }

 }


void Selectionsort(int NO[],int size ) {
	
	int index, min, i, j;
	for (i = 0; i < size-1; i++) {
		min = NO[i + 1];
		index = i + 1;
		for (j = i; j < size; j++) {
			if ( NO[j]<min) {
				min = NO[j];
				index = j;
			}
		}
		if (i != index) {
			NO[index] = NO[i];
			NO[i] = min;
		}
	}

	
}


void SelectionsortChar(char x[],int size1) {

	int index, min, i, j;
	for (i = 0; i < size1 - 1; i++) {
		min = x[i + 1];
		index = i + 1;
		for (j = i; j < size1; j++) {
			if (x[j] < min) {
				min = x[j];
				index = j;
			}
		}
		if (i != index) {
			x[index] = x[i];
			x[i] = min;
		}
	}

}


void Bublesort(int NO[],int size1) {

	int temp, i, j;
	for (i = 0; i <size1; i++)
	{
		for (j = 0; j < size1 - 1; j++) {
			if (NO[j + 1] < NO[j]) {
				temp = NO[j];
				NO[j] = NO[j + 1];
				NO[j+1] = temp;
			}
		}
	}
	
}


void BublesortChar(char x[] , int size2) {

	int temp, i, j;
	
	for (i = 0; i < size2; i++)
	{
		for (j = 0; j < size2 - 1; j++) {
			if (x[j + 1] < x[j]) {
				temp = x[j];
				x[j] = x[j + 1];
				x[j + 1] = temp;
			}
		}
	}

}

void Mergesort(int num[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = num[l + i];
	for (j = 0; j < n2; j++)
		R[j] = num[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			num[k] = L[i];
			i++;
		}
		else
		{
			num[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		num[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		num[k] = R[j];
		j++;
		k++;
	}
}
void Sort(int num[], int i, int j)
{
	if (i < j)
	{

		int avg = i + (j - i) / 2;

		Sort(num, i, avg);
		Sort(num, avg + 1, j);

		Mergesort(num, i, avg, j);
	}
}

void MergesortChar(char x[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	char L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = x[l + i];
	for (j = 0; j < n2; j++)
		R[j] = x[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			x[k] = L[i];
			i++;
		}
		else
		{
			x[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		x[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		x[k] = R[j];
		j++;
		k++;
	}
}
void sortChar(char x[], int i, int j)
{
	if (i < j)
	{

		int avg = i + (j - i) / 2;

		sortChar(x, i, avg);
		sortChar(x, avg + 1, j);

		MergesortChar(x, i, avg, j);
	}
}
void SortingQuick(int arr[], int low, int high) {
	int first, last, pivot;
	first = low;
	last = high;

	pivot = arr[(last + first) / 2];
	do {
		while (arr[first] < pivot && first < last) {
			first++;
		}
		while (arr[last] > pivot && last > first) {
			last--;
		}
		if (first <= last) {
			Swap(&arr[first], &arr[last]);
			first++;
			last--;
		}
	} while (first <= last);

	if (low < last) {
		SortingQuick(arr, low, last);
	}
	if (first < high) {
		SortingQuick(arr, first, high);
	}

}
void CharSortingQuick(char arr[], int low, int high) {
	int i, j;
	i = low;
	j = high;
	char pivot = arr[(low + high) / 2];
	do {

		while (arr[i] < pivot && i < high) {
			i++;
		}
		while (arr[j] > pivot && j > low) {
			j--;
		}
		if (i <= j) {
			SwapChar(&arr[i], &arr[j]);
			i++;
			j--;
		}
	} while (i <= j);


	if (low < j) {
		CharSortingQuick(arr, low, j);
	}
	if (i < high) {
		CharSortingQuick(arr, i, high);
	}
}
void Heapify(int arr[], int size, int i) {
	int left_child, right_child, max;
	max = i;
	left_child = i * 2 + 1;
	right_child = i * 2 + 2;
	if (arr[left_child] > arr[max] && left_child < size) {
		max = left_child;
	}
	if (arr[right_child] > arr[max] && right_child < size) {
		max = right_child;
	}
	if (i != max) {
		Swap(&arr[i], &arr[max]);
		Heapify(arr, size, max);
	}
}
void SortingHeap(int arr[], int size) {
	int i;
	for (i = size / 2 - 1; i >= 0; i--) {
		Heapify(arr, size, i);
	}
	for (i = size - 1; i >= 0; i--) {
		Swap(&arr[i], &arr[0]);
		Heapify(arr, i, 0);
	}
}
void CharHeapify(char arr[], int size, int i) {
	int left_child, right_child, max;
	max = i;
	left_child = i * 2 + 1;
	right_child = i * 2 + 2;
	if (arr[left_child] > arr[max] && left_child < size) {
		max = left_child;
	}
	if (arr[right_child] > arr[max] && right_child < size) {
		max = right_child;
	}
	if (i != max) {
		SwapChar(&arr[i], &arr[max]);
		CharHeapify(arr, size, max);
	}
}
void CharSortingHeap(char arr[], int size) {
	int i;
	for (i = size / 2 - 1; i >= 0; i--) {
		CharHeapify(arr, size, i);
	}
	for (i = size - 1; i >= 0; i--) {
		SwapChar(&arr[i], &arr[0]);
		CharHeapify(arr, i, 0);
	}
}

int main(){

	clock_t timer;
	int NO1[10] = { 2, 0, 1, 8, 5, 5, 5, 0, 5, 2 };
	char Name1[] = "deniz parlar";
	int k = sizeof(Name1);
	int size=sizeof(NO1)/sizeof(NO1[0]);
	printf("\t\t My number: ");
	for (int i = 0; i < 10; i++) {
		printf("%d", NO1[i]);
	}
	printf("\n \t\t My name: %s\n\n\n", Name1);
	printf("Sorting with Insertion: \n");
	timer = clock();
	Insertionsort(NO1, 10);
	timer = clock() - timer;
	PrintArray(NO1, 10);
	printf("\nInsertion_time_of_int : %f \n", (((double)timer) / CLOCKS_PER_SEC));
	printf("\n");
	timer = clock();
	InsertionsortChar(Name1, k);
	timer = clock()-timer;
	PrintChar(Name1, k);
	printf("\nInsertion_time_of_char: %f", (((double)timer) / CLOCKS_PER_SEC));
	printf("\n\n\n");




	int NO2[10] = { 2, 0, 1, 8, 5, 5, 5, 0, 5, 2 };
	char Name2[] = "deniz parlar";
	printf("Sorting with Selection: \n");
	timer = clock();
	Selectionsort(NO2, 10);
	timer = clock() - timer;
	PrintArray(NO2, 10);
	printf("\nSelection_time_of_int: %f", (((double)timer) / CLOCKS_PER_SEC));
	printf("\n");
	timer = clock();
	SelectionsortChar(Name2, k);
	timer = clock() - timer;
	PrintChar(Name2, k);
	printf("\nSelection_time_of_char: %f", (((double)timer) / CLOCKS_PER_SEC));
	printf("\n\n\n");
	



	int NO3[10] = { 2, 0, 1, 8, 5, 5, 5, 0, 5, 2 };
	char Name3[] = "deniz parlar";
	printf("Sorting with Bubble: \n");
	timer = clock();
	Bublesort(NO3,10);
	timer = clock() - timer;
	PrintArray(NO3, 10);
	printf("\nBuble_time_of_int: %f", (((double)timer) / CLOCKS_PER_SEC));
	printf("\n");
	timer = clock();
	BublesortChar(Name3, k);
	timer = clock() - timer;
	PrintChar(Name3, k);
	printf("\nBuble_time_of_char: %f", (((double)timer) / CLOCKS_PER_SEC));
	printf("\n\n\n");
	




	int NO4[10] = { 2, 0, 1, 8, 5, 5, 5, 0, 5, 2 };
	char Name4[] = "deniz parlar";
	printf("Sorting with Merge: \n");
	timer = clock();
	Sort(NO4,0, 9);
	timer = clock() - timer;
	PrintArray(NO4, 10);
	printf("\nMerge_time_of_int: %f", (((double)timer) / CLOCKS_PER_SEC));
	printf("\n");
	timer = clock();
	sortChar(Name4, 0, k);
	timer = clock() - timer;
	PrintChar(Name4, k+1);
	printf("\nMerge_time_of_char: %f", (((double)timer) / CLOCKS_PER_SEC));
	printf("\n\n\n");
	
	int NO5[10] = { 2, 0, 1, 8, 5, 5, 5, 0, 5, 2 };
	char Name5[] = "deniz parlar";
	printf("Sorting with Quick: \n");
	timer = clock();
	SortingQuick(NO5,0,size-1);
	timer = clock() - timer;
	PrintArray(NO5, size);
	printf("\nQuick_time_of_int: %f", (((double)timer) / CLOCKS_PER_SEC));
	printf("\n");
	timer = clock();
	CharSortingQuick(Name5,0, k-1);
	timer = clock() - timer;
	PrintChar(Name5, k);
	printf("\nQuick_time_of_char: %f", (((double)timer) / CLOCKS_PER_SEC));
	printf("\n\n\n");


        int NO6[10] = { 2, 0, 1, 8, 5, 5, 5, 0, 5, 2 };
	char Name6[] = "deniz parlar";
	printf("Sorting with Heap: \n");
	timer = clock();
	SortingHeap(NO6,size);
	timer = clock() - timer;
	PrintArray(NO6, size);
	printf("\nHeap_time_of_int: %f", (((double)timer) / CLOCKS_PER_SEC));
	printf("\n");
	timer = clock();
	CharSortingHeap(Name6,k);
	timer = clock() - timer;
	PrintChar(Name6, k);
	printf("\nHeap_time_of_char: %f", (((double)timer) / CLOCKS_PER_SEC));
	printf("\n\n");
}
