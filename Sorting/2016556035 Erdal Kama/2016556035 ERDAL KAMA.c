#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h>


void Swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}


void SwapChar(char *xp, char *yp)
{
	char temp = *xp;
	*xp = *yp;
	*yp = temp;
}


void Merge(int arr[], int l, int m, int r)
{
	int i, j, k, x1, x2;
	x1 = m - l + 1;
	x2 = r - m;

	int L[x1], R[x2];

	for (i = 0; i < x1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < x2; j++)
		R[j] = arr[m + 1 + j];

	i = 0;
	j = 0;
	k = l;

	while (i < x1 && j < x2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < x1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < x2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}


void MergeSort(int arr[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;

		MergeSort(arr, l, m);
		MergeSort(arr, m + 1, r);

		Merge(arr, l, m, r);
	}
}


void MergeChar(char arr[], int l, int m, int r)
{
	int i, j, k, x1, x2;
	x1 = m - l + 1;
	x2 = r - m;

	int L[x1], R[x2];

	for (i = 0; i < x1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < x2; j++)
		R[j] = arr[m + 1 + j];

	i = 0;
	j = 0;
	k = l;

	while (i < x1 && j < x2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < x1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < x2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}


void MergeSortChar(char arr[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;

		MergeSortChar(arr, l, m);
		MergeSortChar(arr, m + 1, r);

		MergeChar(arr, l, m, r);
	}
}


void BubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				Swap(&arr[j], &arr[j + 1]);
}

void BubbleSortChar(char arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				SwapChar(&arr[j], &arr[j + 1]);
}


void InsertionSort(int arr[], int n)
{
	int i, x, j;
	for (i = 1; i < n; i++) {
		x = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > x) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = x;
	}
}


void InsertionSortChar(char arr[], int n)
{
	int i, j;
	char x;
	for (i = 1; i < n; i++) {
		x = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > x) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = x;
	}
}


void SelectionSort(int arr[], int n)
{
	int i, j, min;
	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min])
				min = j;
		Swap(&arr[min], &arr[i]);
	}
}


void SelectionSortChar(char arr[], int n)
{
	int i, j;
	char min;
	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min])
				min = j;
		SwapChar(&arr[min], &arr[i]);
	}
}


int partition(int num[], int lo, int hi) {
	int pivot = num[hi];
	int i = (lo - 1);
	for (int j = lo; j <= hi - 1; ++j) {
		if (num[j] <= pivot) {
			++i;
			Swap(&num[i], &num[j]);
		}
	}
	Swap(&num[i + 1], &num[hi]);
	return(i + 1);
}


int partitionChar(char str[], int lo, int hi) {
	int pivot = str[hi];
	int i = (lo - 1);
	for (int j = lo; j <= hi - 1; ++j) {
		if (str[j] <= pivot) {
			++i;
			SwapChar(&str[i], &str[j]);
		}
	}
	SwapChar(&str[i + 1], &str[hi]);
	return(i + 1);
}


void quickSort(int num[], int left, int right) {

	if (left < right) {
		int pi = partition(num, left, right);

		quickSort(num, left, pi - 1);
		quickSort(num, pi + 1, right);
	}
}


void quickSortChar(char str[], int left, int right) {

	if (left < right) {
		int pich = partitionChar(str, left, right);

		quickSortChar(str, left, pich - 1);
		quickSortChar(str, pich + 1, right);
	}
}


void heapify(int num[], int count, int i) {

	int largest = i;
	int leftChild = 2 * i + 1;
	int rightChild = 2 * i + 2;

	if (num[leftChild] > num[largest] && leftChild < count) {
		largest = leftChild;
	}
	if (num[rightChild] > num[largest] && rightChild < count) {
		largest = rightChild;
	}
	if (largest != i) {
		Swap(&num[i], &num[largest]);
		heapify(num, count, largest);
	}
}


void HeapSort(int num[], int count) {

	for (int i = (count / 2) - 1; i >= 0; i--) {
		heapify(num, count, i);
	}
	for (int i = count - 1; i > 0; i--) {
		Swap(&num[0], &num[i]);
		heapify(num, i, 0);
	}
}


void heapifyChar(char str[], int count, int i) {

	int largest = i;
	int leftChild = 2 * i + 1;
	int rightChild = 2 * i + 2;

	if (str[leftChild] > str[largest] && leftChild < count) {
		largest = leftChild;
	}
	if (str[rightChild] > str[largest] && rightChild < count) {
		largest = rightChild;
	}
	if (largest != i) {
		SwapChar(&str[i], &str[largest]);
		heapifyChar(str, count, largest);
	}
}


void HeapSortChar(char str[], int count) {

	for (int i = (count / 2) - 1; i >= 0; i--) {
		heapifyChar(str, count, i);
	}
	for (int i = count - 1; i > 0; i--) {
		SwapChar(&str[0], &str[i]);
		heapifyChar(str, i, 0);
	}
}


void PrintArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


int main() {

	printf("------------ERDAL KAMA 2016556035------------\n");


	int number[] = { 2,0,1,6,5,5,6,0,3,5 };


	clock_t t;


	char name[] = "ERDAL KAMA";


	int n = sizeof(number) / sizeof(number[0]);


	int charSize = strlen(name);


	t = clock();


	printf("------------INSERTION SORT------------\n");


	InsertionSort(number, n);


	t = clock() - t;


	PrintArray(number, n);


	printf("Insertion Sort Time: %lf\n", ((double)t) / CLOCKS_PER_SEC);


	InsertionSortChar(name, charSize);


	t = clock() - t;


	printf("%s\n", name);


	printf("Insertion Char Sort Time: %lf\n", ((double)t) / CLOCKS_PER_SEC);


	int numX[] = { 2,0,1,6,5,5,6,0,3,5 };


	char nameX[] = "ERDAL KAMA";


	int x1 = sizeof(numX) / sizeof(numX[0]);


	int charSizeX = strlen(nameX);


	printf("------------SELECTION SORT------------\n");


	SelectionSort(numX, x1);


	t = clock() - t;


	PrintArray(numX, x1);


	printf("Selection Sort Time: %lf\n", ((double)t) / CLOCKS_PER_SEC);


	SelectionSortChar(nameX, charSizeX);


	t = clock() - t;


	printf("%s\n", nameX);


	printf("Selection Char Sort Time: %lf\n", ((double)t) / CLOCKS_PER_SEC);


	int numY[] = { 2, 0, 1, 6, 5, 5, 6, 0, 3, 5 };


	char nameY[] = "ERDAL KAMA";


	int nY = sizeof(numY) / sizeof(numY[0]);


	int charSizeY = strlen(nameY);


	printf("------------BUBBLE SORT------------\n");


	BubbleSort(numY, nY);


	t = clock() - t;


	PrintArray(numY, nY);


	printf("Bubble Sort Time: %lf\n", ((double)t) / CLOCKS_PER_SEC);


	BubbleSortChar(nameY, charSizeY);


	t = clock() - t;


	printf("%s\n", nameY);


	printf("Bubble Char Sort Time: %lf\n", ((double)t) / CLOCKS_PER_SEC);


	int numZ[] = { 2, 0, 1, 6, 5, 5, 6, 0, 3, 5 };


	char nameZ[] = "ERDAL KAMA";


	int nZ = sizeof(numZ) / sizeof(numZ[0]);


	int charSizeZ = strlen(nameZ);


	printf("------------MERGE SORT------------\n");


	MergeSort(numZ, 0, nZ - 1);


	t = clock() - t;


	PrintArray(numZ, nZ);


	printf("Merge Sort Time: %lf\n", ((double)t) / CLOCKS_PER_SEC);


	MergeSortChar(nameZ, 0, charSizeZ - 1);


	t = clock() - t;


	printf("%s\n", nameZ);


	printf("Merge Sort Char Time: %lf\n", ((double)t) / CLOCKS_PER_SEC);


	printf("------------HEAP SORT------------\n");


	int numA[] = { 2,0,1,6,5,5,6,0,3,5 };


	char nameA[] = "ERDAL KAMA";


	int nA = sizeof(numA) / sizeof(numA[1]);


	int sizeA = strlen(nameA);


	HeapSort(numA, nA);


	t = clock() - t;


	PrintArray(numA, nA);


	printf("Heap Sort Time: %lf\n", ((double)t) / CLOCKS_PER_SEC);


	HeapSortChar(nameA, sizeA);


	t = clock() - t;


	printf("%s\n", nameA);


	printf("Heap Sort Char Time: %lf\n", ((double)t) / CLOCKS_PER_SEC);


	printf("------------QUÝCK SORT------------\n");


	int numB[] = { 2,0,1,6,5,5,6,0,3,5 };


	char nameB[] = "ERDAL KAMA";


	int n5 = sizeof(numB) / sizeof(numB[1]);


	int sizeB = strlen(nameB);


	quickSort(numB, 0, n5 - 1);


	t = clock() - t;


	PrintArray(numB, n5);


	printf("Quick Sort Time: %lf\n", ((double)t) / CLOCKS_PER_SEC);


	quickSortChar(nameB, 0, sizeB - 1);


	t = clock() - t;


	printf("%s\n", nameB);


	printf("Quick Sort Char Time: %lf\n", ((double)t) / CLOCKS_PER_SEC);

	
	return 0;
}