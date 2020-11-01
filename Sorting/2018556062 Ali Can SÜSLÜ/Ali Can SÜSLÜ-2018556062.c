#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h>

void printArray(int arr[], int x)
{
	for (int i = 0;i < x;i++)
		printf("%d",arr[i]);
	printf("\n");
}

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


     //İnsertion Sort
void insertionSort(int arr[], int size)
{
	int i, j, element;
	for (i = 1; i < size; i++) {
		element = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > element) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = element;
	}
}
void insertionSortChar(char arr[], int size)
{
	int i, j;
	char element;
	for (i = 1; i < size; i++) {
		element = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > element) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = element;
	}
}
     //Bubble Sort
void bubbleSort(int arr[], int size)
{
	int i, j;
	for (i = 0; i < size - 1; i++) 
		for (j = 0; j < size - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}
void bubbleSortChar(char arr[], int size)
{
	int i, j;
	for (i = 0; i < size - 1; i++)
		for (j = 0; j < size - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swapch(&arr[j], &arr[j + 1]);
}
     //Selection Sort
void selectionSort(int arr[], int size)
{
	int i, j, min;
	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
			if (arr[j] < arr[min])
				min = j;
		swap(&arr[min], &arr[i]);
	}
}
void selectionSortChar(char arr[], int size)
{
	int i, j;
	char min;
	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
			if (arr[j] < arr[min])
				min = j;
		swapch(&arr[min], &arr[i]);
	}
}

     //Merge Sort
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

void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

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

void mergeSortChar(char arr[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;

		mergeSortChar(arr, l, m);
		mergeSortChar(arr, m + 1, r);

		mergeChar(arr, l, m, r);
	}
}

 //Quick Sort
void quickSort(int* arr, int L, int R) {
	int lo;
	int hi;
	int pivot;
	pivot = L;


	if (R > L) {
		pivot = L;
		lo = L;
		hi = R;
		while (lo < hi) {
			while (arr[lo] <= arr[pivot] && lo<R && hi>lo) {
				lo++;
			}
			while (arr[hi] >= arr[pivot] && hi >= L && hi >= lo) {
				hi--;
			}
			if (hi > lo) {
				swap(&arr[lo], &arr[hi]);
			}
		}

		swap(&arr[lo], &arr[pivot]);
		quickSort(arr, L, hi - 1);
		quickSort(arr, hi + 1, R);
	}
}
void quickSortChar(char* array, char L, char R) {
	int lo;
	int hi;
	char pivot;
	pivot = L;


	if (R > L) {
		pivot = L;
		lo = L;
		hi = R;
		while (lo < hi) {
			while (array[lo] <= array[pivot] && lo<R && hi>lo) {
				lo++;
			}
			while (array[hi] >= array[pivot] && hi >= L && hi >= lo) {
				hi--;
			}
			if (hi > lo) {
				swapch(&array[lo], &array[hi]);
			}
		}

		swapch(&array[lo], &array[pivot]);
		quickSortChar(array, L, hi - 1);
		quickSortChar(array, hi + 1, R);
	}
}

      //Heap Sort
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

void heapSort(int arr[], int n) {
	int s, k;
	for (s = n / 2 - 1; s >= 0; s--)
		heapify(arr, n, s);

	for (k = n - 1; k > 0; k--) {
		swap(&arr[0], &arr[k]);
		heapify(arr, k, 0);
	}
}

void heapifyChar(char arr[], int n, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i) {
		swapch(&arr[i], &arr[largest]);
		heapifyChar(arr, n, largest);
	}
}

void heapSortChar(char arr[], int n) {
	int i, j;
	for (i = n / 2 - 1; i >= 0; i--)
		heapifyChar(arr, n, i);

	for (j = n - 1; j > 0; j--) {
		swapch(&arr[0], &arr[j]);
		heapifyChar(arr, j, 0);
	}
}




int main() {

clock_t t;
t = clock(); 

//------ MY NUMBER
int num[] = { 2, 0, 1, 8, 5, 5, 6, 5, 0, 6, 2 };
char name[] = "ALICAN SÜSLÜ";
//------ NAME AND SURNAME

int n = sizeof(num) / sizeof(num[0]);
int namesize = strlen(name);



               // insertion sort
printf("insertion Sort:\n");
insertionSort(num, n);
t = clock() - t;
printArray(num, n);
printf("insertion sort time: %f\n", ((double)t) / CLOCKS_PER_SEC); 

insertionSortChar(name, namesize);
t = clock() - t;
printf("%s\n", name);
printf("insertion char sort time: %f\n", ((double)t) / CLOCKS_PER_SEC);
printf("\n");


              // Selection Sort
printf("Selection Sort:\n");
selectionSort(num, n);
t = clock() - t;
printArray(num, n);
printf("selection sort time: %f\n", ((double)t) / CLOCKS_PER_SEC);

selectionSortChar(name, namesize);
t = clock() - t;
printf("%s\n", name);
printf("selection char sort time: %f\n", ((double)t) / CLOCKS_PER_SEC);
printf("\n");


           //Bubble Sort
printf("Bubble Sort:\n");
bubbleSort(num, n);
t = clock() - t;
printArray(num, n);
printf("bubble sort time: %f\n", ((double)t) / CLOCKS_PER_SEC);

bubbleSortChar(name, namesize);
t = clock() - t;
printf("%s\n", name);
printf("bubble char sort time: %f\n", ((double)t) / CLOCKS_PER_SEC);


		  //Merge Sort
	printf("Merge Sort:\n");
	mergeSort(num, 0, n - 1);
	t = clock() - t;
	printArray(num, n);
	printf("merge sort time: %f\n", ((double)t) / CLOCKS_PER_SEC);
	mergeSortChar(name, 0, namesize - 1);
	t = clock() - t;
	printf("%s\n", name);
	printf("merge char sort time: %f\n", ((double)t) / CLOCKS_PER_SEC);

	   //Quick Sort
	printf("Quick Sort:-----------------------\n");
	quickSort(num, 0, n - 1);
	t = clock() - t;
	printArray(num, n);
	printf("Quick sort time: %f\n", ((double)t) / CLOCKS_PER_SEC);
	quickSortChar(name, 0, namesize - 99);
	t = clock() - t;
	printf("%s\n", name);
	printf("Quick char sort time: %f\n", ((double)t) / CLOCKS_PER_SEC);
	printf("\n");

	//Heap Sort
	printf("Heap Sort:-----------------------\n");
	heapSort(num, n);
	t = clock() - t;
	printArray(num, n);
	printf("Heap sort time: %f\n", ((double)t) / CLOCKS_PER_SEC);
	heapSortChar(name, namesize);
	t = clock() - t;
	printf("%s\n", name);
	printf("Heap char sort time: %f\n", ((double)t) / CLOCKS_PER_SEC);
	printf("\n");




	return 0;
}