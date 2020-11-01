#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <string.h>


void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
void swapch(char* x, char* y){
	char temp = *x;
	*x = *y;
	*y = temp;
}



void merge(int arr[], int l, int m, int r)
{
	int lside = m - l+1;
	int rside = r - m;
	int Left[lside];
	int Right[rside];
	int i, j, k;
	for (i = 0; i < lside; i++)
		Left[i] = arr[l + i];
	for (j = 0; j < rside; j++)
		Right[j] = arr[m + 1 + j];

	i = 0;
	j = 0;
	k = l;

	while (i < lside && j < rside) {
		if (Left[i] <= Right[j]) {
			arr[k] = Left[i];
			i++;
		}
		else {
			arr[k] = Right[j];
			j++;
		}
		k++;
	}

	while (i < lside) {
		arr[k] = Left[i];
		i++;
		k++;
	}

	while (j < rside) {
		arr[k] = Right[j];
		j++;
		k++;
	}
}

void mergesort(int arr[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;

		mergesort(arr, l, m);
		mergesort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

void mergeChar(char arr[], int l, int m, int r)
{
	int i, j, k, n1, n2;
	n1 = m - l + 1;
	n2 = r - m;

	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0;
	j = 0;
	k = l;

	while (i < n1 && j < n2) {
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

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergesortchar(char arr[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;

		mergesortchar(arr, l, m);
		mergesortchar(arr, m + 1, r);

		mergeChar(arr, l, m, r);
	}
}
void selectionsort(int array[], int n) {

	int minimum, temp;
	int i, j;
	for (i = 0; i < n; i++) {
		minimum = i;

		for (j = i; j < n; j++) {

			if (array[j] < array[minimum]) {
				minimum = j;

			}

		}
		temp = array[i];
		array[i] = array[minimum];
		array[minimum] = temp;

	}
}
void selectionsortchar(char array[], int n) {

	int minimum, temp;
	int i, j;
	for (i = 0; i < n; i++) {
		minimum = i;

		for (j = i; j < n; j++) {

			if (array[j] < array[minimum]) {
				minimum = j;

			}


		}
		temp = array[i];
		array[i] = array[minimum];
		array[minimum] = temp;

	}

}
void insertionsort(int array[], int n) {
	int i, j;
	int element;

	for (i = 1; i < n; ++i) {
		element = array[i];

		for (j = i - 1; array[j] > element && j >= 0; --j) {
			array[j + 1] = array[j];
		}
		array[j + 1] = element;
	}

}
void insertionsortchar(char array[], int n) {
	int i, j;
	int constant;

	for (i = 1; i < n; ++i) {
		constant = array[i];

		for (j = i - 1; array[j] > constant && j >= 0; --j) {
			array[j + 1] = array[j];
		}
		array[j + 1] = constant;
	}

}
void bubblesort(int array[], int size) {
	int i, j, temp;

	for (i = 0; i < size; i++) {
		for (j = 1; j < size - i; j++) {
			if (array[j - 1] > array[j]) {
				temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;

			}

		}
	}
}
void bubblesortchar(char array[], int size) {
	int i, j, temp;

	for (i = 0; i < size; i++) {
		for (j = 1; j < size - i; j++) {
			if (array[j - 1] > array[j]) {
				temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;

			}

		}
	}
}
void printarrayint(int arr[], int count) {
	int i;
	for (i = 0; i < count; ++i) {

		printf("%d ", arr[i]);

	}

}
void printarraychar(char arr[], int count) {
	int i;
	for (i = 0; i < count; ++i) {

		printf("%c ", arr[i]);

	}

}
void quicksort(int* arr, int left, int right) {
	int low;
	int high;
	int pivot;
	pivot = left;


	if (right > right) {
		pivot = left;
		low = left;
		high = right;
		while (low < high) {
			while (arr[low] <= arr[pivot] && low<right && high>low) {
				low++;
			}
			while (arr[high] >= arr[pivot] && high >= left && high >= low) {
				high--;
			}
			if (high > low) {
				swap(&arr[low], &arr[high]);
			}
		}

		swap(&arr[low], &arr[pivot]);
		quicksort(arr, left, high - 1);
		quicksort(arr, high + 1, right);
	}
}
void quicksortchar(char* array, char left, char right) {
	int low;
	int high;
	char pivot;
	pivot = left;


	if (right > left) {
		pivot = left;
		low = left;
		high = right;
		while (low < high) {
			while (array[low] <= array[pivot] && low<right && high>low) {
				low++;
			}
			while (array[high] >= array[pivot] && high >= left && high >= low) {
				high--;
			}
			if (high > low) {
				swapch(&array[low], &array[high]);
			}
		}

		swapch(&array[low], &array[pivot]);
		quicksortchar(array, left, high - 1);
		quicksortchar(array, high + 1, right);
	}
}

void heapify(int arr[], int n, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i) {
		swap(&arr[i], &arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapsort(int arr[], int n) {
	int s, k;
	for (s = n / 2 - 1; s >= 0; s--)
		heapify(arr, n, s);

	for (k = n - 1; k > 0; k--) {
		swap(&arr[0], &arr[k]);
		heapify(arr, k, 0);
	}
}

void heapifychar(char arr[], int n, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i) {
		swapch(&arr[i], &arr[largest]);
		heapifychar(arr, n, largest);
	}
}

void heapsortchar(char arr[], int n) {
	int i, j;
	for (i = n / 2 - 1; i >= 0; i--)
		heapifychar(arr, n, i);

	for (j = n - 1; j > 0; j--) {
		swapch(&arr[0], &arr[j]);
		heapifychar(arr, j, 0);
	}
}


int main() {

	clock_t x;
	x = clock();

	char name[] = "emrullah akturk";
	int number[] = { 2,0,1,9,5,5,6,4,5,2 };
	int numbersize = sizeof(number) / sizeof(number[1]);
	int namesize = strlen(name);
	printf("Selection Sort:\n");
    x = clock() - x;
	selectionsort(number, numbersize);
	printf("\nNumber Selection Sort:");
	printarrayint(number, numbersize);
    printf("\nNumber Selection Sort Time : %f", ((double)x) / CLOCKS_PER_SEC);

	x = clock() - x;
	selectionsortchar(name, namesize);
	printf("\nName Selection Sort:");
	printarraychar(name, namesize);
	printf("\nName Selection Sort Time : %f ", ((double)x) / CLOCKS_PER_SEC);
 
 
    char name1[] = "emrullah akturk";
	int number1[] = { 2,0,1,9,5,5,6,4,5,2 };
	
	printf("\n\nInsertion Sort:\n");
	x = clock() - x;
	insertionsort(number1, numbersize);
	printf("\nNumber Insertion Sort:");
	printarrayint(number1, numbersize);
	printf("\nNumber Insertion Sort Time: %f\n", ((double)x) / CLOCKS_PER_SEC);
	

    x = clock() - x;
	insertionsortchar(name1, namesize);
	printf("Name Insertion Sort :");
	printarraychar(name1, namesize);
	printf("\nName Insertion Sort Time : %f\n", ((double)x) / CLOCKS_PER_SEC);


 	char name2[] = "emrullah akturk";
	int number2[] = { 2,0,1,9,5,5,6,4,5,2 };
	
	printf("\n\nBubble Sort:\n");
    x = clock() - x;
	bubblesort(number2, numbersize);
	printf("\nNumber Bubble Sorting:");
	printarrayint(number2, numbersize);
	printf("\nNumber Bubble Sorting Time : %f ", ((double)x) / CLOCKS_PER_SEC);
	

	x = clock() - x;
	bubblesortchar(name, namesize);
	printf("\nName Bubble Sorting:");	
	printarraychar(name, namesize);
	printf("\nName Bubble Sorting Time : %f \n ", ((double)x) / CLOCKS_PER_SEC);
	
	
	char name3[] = "emrullah akturk";
	int number3[] = { 2,0,1,9,5,5,6,4,5,2 };
	
	printf("\nMerge Sort:\n ");
	mergesort(number3, 0, numbersize - 1);
	x = clock() - x;
	printf("\nNumber Merge Sorting:");	
	printarrayint(number3, numbersize);
	printf("\nNumber Merge Sort Time: %f", ((double)x) / CLOCKS_PER_SEC);
	
	
	mergesortchar(name3, 0, namesize - 1);
	x = clock() - x;
	printf("\nName Merge Sorting:");	
	printarraychar(name3,namesize );
	printf("\nName Merge Sort Time: %f\n", ((double)x) / CLOCKS_PER_SEC);
	
	char name4[] = "emrullah akturk";
	int number4[] = { 2,0,1,9,5,5,6,4,5,2 };
	
	printf("\nQuick Sort:\n ");
	quicksort(number4, 0, numbersize - 1);
	x = clock() - x;
	printf("\nNumber Quick Sorting:");	
	printarrayint(number4, numbersize);
	printf("\nNumber Quick Sort Time: %f", ((double)x) / CLOCKS_PER_SEC);
	
	
	quicksortchar(name4, 0, namesize - 1);
	x = clock() - x;
	printf("\nName Quick Sorting:");	
	printarraychar(name4,namesize );
	printf("\nName Quick Sort Time: %f\n", ((double)x) / CLOCKS_PER_SEC);
	
	char name5[] = "emrullah akturk";
	int number5[] = { 2,0,1,9,5,5,6,4,5,2 };
	
	printf("\nHeap Sort:\n ");
	heapsort(number5, numbersize );
	x = clock() - x;
	printf("\nNumber Heap Sorting:");	
	printarrayint(number5, numbersize);
	printf("\nNumber Heap Sort Time: %f", ((double)x) / CLOCKS_PER_SEC);
	
	
	heapsortchar(name,namesize );
	x = clock() - x;
	printf("\nName Heap Sorting:");	
	printarraychar(name,namesize );
	printf("\nName Heap Sort Time: %f\n", ((double)x) / CLOCKS_PER_SEC);

	return 0;
}
