#include <stdio.h>
#include<string.h>
#include<time.h>
void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
void swapName(char* xp, char* yp)
{
	char temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void selectionSort(int array[], int size) {
	int currentMin;
	int i, j;
	for (i = 0; i < size - 1; ++i) {
		currentMin = i;
		for (j = i + 1; j < size; ++j) {
			if (array[j] < array[currentMin]) {
				currentMin = j;
			}
		}
		swap(&array[currentMin], &array[i]);
	}
}
void selectionSortName(char array[], int size) {
	char currentMin;
	int i, j;
	for (i = 0; i < size - 1; ++i) {
		currentMin = i;
		for (j = i + 1; j < size; ++j) {
			if (array[j] < array[currentMin]) {
				currentMin = j;
			}
		}
		swapName(&array[currentMin], &array[i]);
	}
}


void bubblesort(int array[], int size) {
	int i, j;
	for (i = 0; i < size; ++i) {
		for (j = 0; j < size - i - 1; ++j) {
			if (array[j] > array[j + 1]) {
				swap(&array[j], &array[j + 1]);
			}
		}
	}
}
void bubblesortName(char array[], int size) {
	int i, j;
	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				swapName(&array[j], &array[j + 1]);
			}
		}
	}
}


void merge(int array[], int left, int middle, int right) {
	int lsize;
	int rsize;
	lsize = middle - left + 1;
	rsize = right - middle;
	int Left[lsize];
	int Right[rsize];
	int i = 0;
	int j = 0;

	for (i = 0; i < lsize; ++i) {
		Left[i] = array[left + i];
	}
	for (j = 0; j < rsize; ++j) {
		Right[j] = array[middle + 1 + j];
	}
	i = 0; j = 0; int org = left;
	while (i < lsize && j < rsize) {
		if (Left[i] <= Right[j]) {
			array[org] = Left[i];
			i++;
		}
		else {
			array[org] = Right[j];
			j++;
		}
		org++;
	}
	while (i < lsize) {
		array[org] = Left[i];
		org++;
		i++;
	}
	while (j < rsize) {
		array[org] = Right[j];
		org++;
		j++;
	}
}


void mergesort(int array[], int left, int right) {
	if (left < right) {
		int middle = left + (right - left) / 2;
		mergesort(array, left, middle); //left
		mergesort(array, middle + 1, right); //right  //tekrar bak middle+1 olbilir

		merge(array, left, middle, right);
	}
}

void mergename(char array[], int left, int middle, int right) {
	int lsize;
	int rsize;
	lsize = middle - left + 1;
	rsize = right - middle;
	int Left[lsize];
	int Right[rsize];
	int i = 0;
	int j = 0;

	for (i = 0; i < lsize; ++i) {
		Left[i] = array[left + i];
	}
	for (j = 0; j < rsize; ++j) {
		Right[j] = array[middle + 1 + j];
	}
	i = 0; j = 0; int org = left;
	while (i < lsize && j < rsize) {
		if (Left[i] <= Right[j]) {
			array[org] = Left[i];
			i++;
		}
		else {
			array[org] = Right[j];
			j++;
		}
		org++;
	}
	while (i < lsize) {
		array[org] = Left[i];
		org++;
		i++;
	}
	while (j < rsize) {
		array[org] = Right[j];
		org++;
		j++;
	}
}


void mergesortname(char array[], int left, int right) {
	if (left < right) {
		int middle = left + (right - left) / 2;
		mergesortname(array, left, middle); //left
		mergesortname(array, middle + 1, right); //right  //tekrar bak middle+1 olbilir

		mergename(array, left, middle, right);
	}
}

void insertionsort(int array[], int size) {
	int i, j;
	int key;
	for (i = 1; i < size; i++) {
		key = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > key) {
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
	}
}
void insertionsortname(char array[], int size) {
	int i, j;
	char key;
	for (i = 1; i < size; i++) {
		key = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > key) {
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
	}
}




void printArray(int array[], int size) {
	int i;
	for (i = 0; i < size; ++i) {
		printf("%d\t", array[i]);
	}
	printf("\n");
}

int partition(int array[], int low, int high) {

	int pivot = array[high];
	int i = (low - 1);
	int j;

	for (j = low; j < high; j++) {
		if (array[j] <= pivot) {
			i++;
			swap(&array[i], &array[j]);
		}
	}

	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

void quickSort(int array[], int low, int high) {
	if (low < high) {

		int pi = partition(array, low, high);

		quickSort(array, low, pi - 1);

		quickSort(array, pi + 1, high);
	}
}

char partitionChar(char array[], int low, int high) {

	int pivot = array[high];
	int i = (low - 1);
	int j;

	for (j = low; j < high; j++) {
		if (array[j] <= pivot) {
			i++;
			swapName(&array[i], &array[j]);
		}
	}

	swapName(&array[i + 1], &array[high]);
	return (i + 1);
}

void quickSortName(char array[], int low, int high) {
	if (low < high) {

		int pi = partitionChar(array, low, high);

		quickSortName(array, low, pi - 1);

		quickSortName(array, pi + 1, high);
	}
}

void heapify(int array[], int size, int i) {

	int largest = i; //our loot is largest
	int leftChild = 2 * i + 1;
	int rightChild = 2 * i + 2;
	if (array[leftChild] > array[largest] && leftChild < size)
	{
		largest = leftChild;
	}
	if (array[rightChild] > array[largest] && rightChild < size)
	{
		largest = rightChild;
	}
	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		heapify(array, size, largest);
	}

}

void heapSort(int array[], int size) {
	int i;
	for (i = size / 2 - 1; i >= 0; i--)
	{
		heapify(array, size, i);
	}
	int k;
	for (k = size - 1; k > 0; k--)
	{
		swap(&array[0], &array[k]);

		heapify(array, k, 0);
	}
}

void heapifyName(char array[], int size, int i) {

	int largest = i; //our loot is largest
	int leftChild = 2 * i + 1;
	int rightChild = 2 * i + 2;
	if (array[leftChild] > array[largest] && leftChild < size)
	{
		largest = leftChild;
	}
	if (array[rightChild] > array[largest] && rightChild < size)
	{
		largest = rightChild;
	}
	if (largest != i)
	{
		swapName(&array[i], &array[largest]);
		heapifyName(array, size, largest);
	}

}

void heapSortName(char array[], int size) {
	int i;
	for (i = size / 2 - 1; i >= 0; i--)
	{
		heapifyName(array, size, i);
	}
	int k;
	for (k = size - 1; k > 0; k--)
	{
		swapName(&array[0], &array[k]);

		heapifyName(array, k, 0);
	}
}

int main() {
	clock_t t;

	printf("Meyra Can / 2019555403\n");
	int selectionnum[] = { 2,0,1,9,5,5,5,4,0,3 };
	char selectionname[] = "Meyra CAN";
	int selectionsize = sizeof(selectionnum) / sizeof(selectionnum[0]);
	int selectionnamesize = strlen(selectionname);

	t = (double)clock();
	selectionSort(selectionnum, selectionsize);
	t = (double)clock() - t;
	printf("Selection Sort Number\n");
	printArray(selectionnum, selectionsize);
	printf("Performance: %f\n\n", ((double)t) / CLOCKS_PER_SEC);

	t = (double)clock();
	selectionSortName(selectionname, selectionnamesize);
	t = (double)clock() - t;

	printf("Selection Sort Name \n %s\nPerformance: %f\n\n\n", selectionname, ((double)t) / CLOCKS_PER_SEC);

	int bubblenum[] = { 2,0,1,9,5,5,5,4,0,3 };
	char bubblename[] = "Meyra CAN";
	int bubblesize = sizeof(bubblenum) / sizeof(bubblenum[0]);
	int bubblenamesize = strlen(bubblename);
	t = (double)clock();
	bubblesort(bubblenum, bubblesize);
	t = (double)clock() - t;
	printf("Bubble Sort for Number\n");
	printArray(bubblenum, bubblesize);
	printf("Performance: %f\n\n", ((double)t) / CLOCKS_PER_SEC);

	t = (double)clock();
	bubblesortName(bubblename, bubblenamesize);
	t = (double)clock() - t;
	printf("Bubble Sort Name \n %s\nPerformance: %f\n\n\n", bubblename, ((double)t) / CLOCKS_PER_SEC);

	int mergenum[] = { 2,0,1,9,5,5,5,4,0,3 };
	char mergename[] = "Meyra CAN";
	int mergesize = sizeof(mergenum) / sizeof(mergenum[0]);
	int mergenamesize = strlen(mergename);

	t = (double)clock();
	mergesort(mergenum, 0, mergesize - 1);
	t = (double)clock() - t;
	printf("Merge Sort\n");
	printArray(mergenum, mergesize);
	printf("Performance: %f\n\n", ((double)t) / CLOCKS_PER_SEC);

	t = (double)clock();
	mergesortname(mergename, 0, mergenamesize - 1);
	t = (double)clock() - t;
	printf("Merge Sort Name \n %s\nPerformance Name: %f\n\n\n", mergename, ((double)t) / CLOCKS_PER_SEC);

	int insertionnum[] = { 2,0,1,9,5,5,5,4,0,3 };
	char insertionname[] = "Meyra CAN";
	int insertionsize = sizeof(insertionnum) / sizeof(insertionnum[0]);
	int insertionnamesize = strlen(insertionname);

	t = (double)clock();
	insertionsort(insertionnum, insertionsize);
	t = (double)clock() - t;
	printf("Insertion Sort \n");
	printArray(insertionnum, insertionsize);
	printf("Performance: %f\n\n", ((double)t) / CLOCKS_PER_SEC);
	t = (double)clock();
	insertionsortname(insertionname, insertionnamesize);
	t = (double)clock() - t;
	printf("Insertion Sort Name \n %s\nPerformance: %f\n\n\n", insertionname, ((double)t) / CLOCKS_PER_SEC);

	int quicksortnum[] = { 2,0,1,9,5,5,5,4,0,3 };
	char quicksortname[] = "Meyra CAN";
	int quicksortsize = sizeof(quicksortnum) / sizeof(quicksortnum[0]);
	int quicksortnamesize = strlen(quicksortname);
	t = (double)clock();
	quickSort(quicksortnum, 0, quicksortsize - 1);
	t = (double)clock() - t;
	printf("Quick for Number\n");
	printArray(quicksortnum, quicksortsize);
	printf("Quick Sort Performance for Number: %f\n\n", ((double)t) / CLOCKS_PER_SEC);
	t = (double)clock();
	quickSortName(quicksortname, 0, quicksortnamesize - 1);
	t = (double)clock() - t;
	printf("Quick Sort for Name \n %s\nQuick Sort Performance for Name: %f\n\n\n", quicksortname, ((double)t) / CLOCKS_PER_SEC);

	int heapsortnum[] = { 2,0,1,9,5,5,5,4,0,3 };
	char heapsortname[] = "Meyra CAN";
	int heapsortsize = sizeof(quicksortnum) / sizeof(quicksortnum[0]);
	int heapsortnamesize = strlen(quicksortname);
	t = (double)clock();
	heapSort(heapsortnum, heapsortsize);
	t = (double)clock() - t;
	printf("Heap for Number\n");
	printArray(heapsortnum, heapsortsize);
	printf("Heap Sort Performance for Number: %f\n\n", ((double)t) / CLOCKS_PER_SEC);
	t = (double)clock();
	heapSortName(heapsortname, heapsortnamesize);
	t = (double)clock() - t;
	printf("Heap Sort for Name \n %s\nHeap Sort Performance for Name: %f\n\n\n", heapsortname, ((double)t) / CLOCKS_PER_SEC);

	return 0;
}