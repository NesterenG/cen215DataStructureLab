#include<stdio.h>
#include<string.h>
#include<time.h>

void printArray(int num[], int count) {

	for (int j = 0; j < count; ++j) {
		printf("%d\t", num[j]);
	}
}

void insertionSort(int num[], int count) {

	int i, k, key;

	for (i = 1; i < count; ++i) {

		key = num[i];

		for (k = i - 1; num[k] > key&& k >= 0; --k) {

			num[k + 1] = num[k];
		}
		num[k + 1] = key;
	}
}

void insertionSortChar(char str[], int count) {

	int i, k, key;

	for (i = 1; i < count; ++i) {

		key = str[i];

		for (k = i - 1; str[k] > key&& k >= 0; --k) {

			str[k + 1] = str[k];
		}
		str[k + 1] = key;
	}
}

void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void swapChar(char* x, char* y) {
	char temp = *x;
	*x = *y;
	*y = temp;
}

void selectionSort(int num[], int count) {

	int currentMin;

	for (int i = 0; i < count - 1; ++i) {

		currentMin = i;

		for (int j = i + 1; j < count; ++j) {

			if (num[j] < num[currentMin]) {
				currentMin = j;
			}
		}
		swap(&num[currentMin], &num[i]);
	}
}

void selectionSortChar(char str[], int count) {

	char currentMin;

	for (int i = 0; i < count - 1; ++i) {

		currentMin = i;

		for (int j = i + 1; j < count; ++j) {

			if (str[j] < str[currentMin]) {
				currentMin = j;
			}
		}
		swapChar(&str[currentMin], &str[i]);
	}
}

void bubbleSort(int num[], int count) {

	for (int i = 0; i < count - 1; ++i) {
		
		for (int j = 0; j < count-i-1; ++j) {
			
			if (num[j] > num[j+1]) {
				swap(&num[j], &num[j+1]);
			}
		}
	}
}

void bubbleSortChar(char str[], int count) {

	for (int i = 0; i < count - 1; ++i) {

		for (int j = 0; j < count - i - 1; ++j) {

			if (str[j] > str[j + 1]) {
				swapChar(&str[j], &str[j + 1]);
			}
		}
	}
}

void merge(int num[],int l,int m,int r) {

	int lsize = m - l + 1;
	int rsize = r - m;
	int Left[lsize];
	int Right[rsize];
	int i, j;
	for (i = 0; i < lsize; ++i) {
		Left[i] = num[l + i];
	}
	for (j = 0; j < rsize; ++j) {
		Right[j] = num[m + 1 + j];
	}
	i = 0; j = 0; int org = l;
	while (i < lsize && j < rsize) {
		if (Left[i] <= Right[j]){
			num[org] = Left[i];
			i++;
		}
		else
		{
			num[org] = Right[j];
			j++;
		}
		org++;
	}
	while (i < lsize) {
		num[org] = Left[i];
		org++;
		i++;
	}
	while (j < rsize) {
		num[org] = Right[j];
		org++;
		j++;
	}
}

void mergeSort(int num[], int left, int right) {

	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(num, left, mid);
		mergeSort(num, mid+1, right);

		merge(num, left, mid, right);
	}
}

void mergeChar(char str[], int l, int m, int r) {

	int lsize = m - l + 1;
	int rsize = r - m;
	char Left[lsize];
	char Right[rsize];
	int i, j;
	for (i = 0; i < lsize; ++i) {
		Left[i] = str[l + i];
	}
	for (j = 0; j < rsize; ++j) {
		Right[j] = str[m + 1 + j];
	}
	i = 0; j = 0; int org = l;
	while (i < lsize && j < rsize) {
		if (Left[i] <= Right[j]) {
			str[org] = Left[i];
			i++;
		}
		else
		{
			str[org] = Right[j];
			j++;
		}
		org++;
	}
	while (i < lsize) {
		str[org] = Left[i];
		org++;
		i++;
	}
	while (j < rsize) {
		str[org] = Right[j];
		org++;
		j++;
	}
}

void mergeSortChar(char str[], int left, int right) {

	if (left < right) {
		int mid = (left + right) / 2;
		mergeSortChar(str, left, mid);
		mergeSortChar(str, mid + 1, right);
			
		mergeChar(str, left, mid, right);
	}
}

int partition(int num[], int lo, int hi) {
	int pivot = num[hi];
	int i = (lo - 1);
	for (int j = lo; j <= hi - 1; ++j) {
		if (num[j] <= pivot) {
			++i;
			swap(&num[i], &num[j]);
		}
	}
	swap(&num[i + 1], &num[hi]);
	return(i + 1);
}

int partitionChar(char str[], int lo, int hi) {
	int pivot = str[hi];
	int i = (lo - 1);
	for (int j = lo; j <= hi - 1; ++j) {
		if (str[j] <= pivot) {
			++i;
			swapChar(&str[i], &str[j]);
		}
	}
	swapChar(&str[i + 1], &str[hi]);
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
		swap(&num[i], &num[largest]);
		heapify(num, count, largest);
	}
}

void heapSort(int num[], int count) {

	for (int i = (count / 2) - 1; i >= 0; i--) {
		heapify(num, count, i);
	}
	for (int i = count - 1; i > 0; i--) {
		swap(&num[0], &num[i]);
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
		swapChar(&str[i], &str[largest]);
		heapifyChar(str, count, largest);
	}
}

void heapSortChar(char str[], int count) {

	for (int i = (count / 2) - 1; i >= 0; i--) {
		heapifyChar(str, count, i);
	}
	for (int i = count - 1; i > 0; i--) {
		swapChar(&str[0], &str[i]);
		heapifyChar(str, i, 0);
	}
}

int main(int argc, char const* argv[]) {

	clock_t t;

	int number[] = { 2,0,1,4,5,5,6,0,1,5 };
	char name[] = "mitatcan bayraktar";

	int n = sizeof(number) / sizeof(number[1]);
	int size = strlen(name);

	t = (double)clock();
	insertionSort(number, n);
	t = (double)clock() - t;
	printArray(number, n);
	printf("Insertion Sort Time: %f\n", ((double)t) / CLOCKS_PER_SEC);
	
	insertionSortChar(name, size);
	t = (double)clock() - t;
	printf("%s\t\t\t\t\t\t\t\t", name);
	printf("Insertion Sort Char Time: %f\n\n", ((double)t) / CLOCKS_PER_SEC);

	int number2[] = { 2,0,1,4,5,5,6,0,1,5 };
	char name2[] = "mitatcan bayraktar";

	int n2 = sizeof(number2) / sizeof(number2[1]);
	int size2 = strlen(name2);

	selectionSort(number2, n2);
	t = (double)clock() - t;
	printArray(number2, n2);
	printf("Selection Sort Time: %f\n", ((double)t) / CLOCKS_PER_SEC);

	selectionSortChar(name2, size2);
	t = (double)clock() - t;
	printf("%s\t\t\t\t\t\t\t\t", name2);
	printf("Selection Sort Char Time: %f\n\n", ((double)t) / CLOCKS_PER_SEC);

	int number3[] = { 2,0,1,4,5,5,6,0,1,5 };
	char name3[] = "mitatcan bayraktar";

	int n3 = sizeof(number3) / sizeof(number3[1]);
	int size3 = strlen(name3);

	bubbleSort(number3, n3);
	t = (double)clock() - t;
	printArray(number3, n3);
	printf("Bubble Sort Time: %f\n", ((double)t) / CLOCKS_PER_SEC);

	bubbleSortChar(name3, size3);
	t = (double)clock() - t;
	printf("%s\t\t\t\t\t\t\t\t", name3);
	printf("Bubble Sort Char Time: %f\n\n", ((double)t) / CLOCKS_PER_SEC);
	
	int number4[] = { 2,0,1,4,5,5,6,0,1,5 };
	char name4[] = "mitatcan bayraktar";

	int n4 = sizeof(number4) / sizeof(number4[1]);
	int size4 = strlen(name4);

	mergeSort(number4, 0, n4 - 1);
	t = (double)clock() - t;
	printArray(number4, n4);
	printf("Merge Sort Time: %f\n", ((double)t) / CLOCKS_PER_SEC);

	mergeSortChar(name4, 0, size4 - 1);
	t = (double)clock() - t;
	printf("%s\t\t\t\t\t\t\t\t", name4);
	printf("Merge Sort Char Time: %f\n\n", ((double)t) / CLOCKS_PER_SEC);

	int number5[] = { 2,0,1,4,5,5,6,0,1,5 };
	char name5[] = "mitatcan bayraktar";

	int n5 = sizeof(number5) / sizeof(number5[1]);
	int size5 = strlen(name5);

	quickSort(number5, 0, n5 - 1);
	t = (double)clock() - t;
	printArray(number5, n5);
	printf("Quick Sort Time: %f\n", ((double)t) / CLOCKS_PER_SEC);

	quickSortChar(name5, 0, size5 - 1);
	t = (double)clock() - t;
	printf("%s\t\t\t\t\t\t\t\t", name5);
	printf("Quick Sort Char Time: %f\n\n", ((double)t) / CLOCKS_PER_SEC);


	int number6[] = { 2,0,1,4,5,5,6,0,1,5 };
	char name6[] = "mitatcan bayraktar";

	int n6 = sizeof(number6) / sizeof(number6[1]);
	int size6 = strlen(name6);

	heapSort(number6, n6);
	t = (double)clock() - t;
	printArray(number6, n6);
	printf("Heap Sort Time: %f\n", ((double)t) / CLOCKS_PER_SEC);

	heapSortChar(name6, size6);
	t = (double)clock() - t;
	printf("%s\t\t\t\t\t\t\t\t", name6);
	printf("Heap Sort Char Time: %f\n\n", ((double)t) / CLOCKS_PER_SEC);
	
	return 0;
}