#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//FONKSİYONLAR

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void swapCh(char* xp, char* yp)
{
	char temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void printfunction(int* arr, int size) {
	for (int k = 0; k < size; k++) {
		printf("%d\t", arr[k]);

	}
	printf("\n");
}

// INSERTION SORT FONKSİYONU

void Insertionsort(int num[], int size) {
	int element, j, i;
	for (i = 1; i < size; i++) {
		element = num[i];
		for (j = i - 1; j >= 0 && num[j] > element; j--) {
			num[j + 1] = num[j];
		}
		num[j + 1] = element;
	}
	

}
void InsertionsortChar(char name[], int size) {
	int element, j, i;
	for (i = 1; i < size; i++) {
		element = name[i];
		for (j = i - 1; j >= 0 && name[j] > element; j--) {
			name[j + 1] = name[j];
		}
		name[j + 1] = element;
	}
	

	
}


//SELECTİON SORT FONKSİYONU

void SelectionSort(int* num, int size) {
	int i, j, min, temp;
	for (i = 0; i < size; i++) {
		min = num[i];
		for (j = i + 1; j < size; j++) {
			if (num[j] < num[i]) {
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}

		}
	}


}
void SelectionSortChar(char* name, int size) {
	int i, j, min, temp;
	for (i = 0; i < size; i++) {
		min = name[i];
		for (j = i + 1; j < size; j++) {
			if (name[j] < name[i]) {
				temp = name[i];
				name[i] = name[j];
				name[j] = temp;
			}

		}
	}
	
}

// BUBBLE SORT

void BubbleSort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)          
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 
void BubbleSortChar(char arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)          
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swapCh(&arr[j], &arr[j+1]); 
}

//MERGE SORT

void merge(int arr[], int l, int m, int r)
{
	int lside = m - l + 1;
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

// QUICK SORT

int partition(int arr[], int min, int max) {
	int pivot = arr[max];
	int i = (min - 1);
	int j;
	for (j = min; j <= max - 1; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[max]);
	return (i + 1);
}

void quickSort(int arr[], int min, int max) {
	if (min < max) {
		int part = partition(arr, min, max);

		quickSort(arr, min, part - 1);
		quickSort(arr, part + 1, max);
	}
}

char partitionCh(char arr[], int min, int max) {
	int pivot = arr[max];
	int i = (min - 1);
	int j;
	for (j = min; j <= max - 1; j++) {
		if (arr[j] < pivot) {
			i++;
			swapCh(&arr[i], &arr[j]);
		}
	}
	swapCh(&arr[i + 1], &arr[max]);
	return (i + 1);
}

void quickSortCh(char arr[], int min, int max) {
	if (min < max) {
		int part = partitionCh(arr, min, max);

		quickSortCh(arr, min, part - 1);
		quickSortCh(arr, part + 1, max);
	}
}

//HEAP SORT

void heap(int arr[], int n, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i) {
		swap(&arr[i], &arr[largest]);
		heap(arr, n, largest);
	}
}

void heapSort(int arr[], int n) {
	int i, j;
	for (i = n / 2 - 1; i >= 0; i--)
		heap(arr, n, i);

	for (j = n - 1; j > 0; j--) {
		swap(&arr[0], &arr[j]);
		heap(arr, j, 0);
	}
}

void heapCh(char arr[], int n, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i) {
		swapCh(&arr[i], &arr[largest]);
		heapCh(arr, n, largest);
	}
}

void heapSortCh(char arr[], int n) {
	int i, j;
	for (i = n / 2 - 1; i >= 0; i--)
		heapCh(arr, n, i);

	for (j = n - 1; j > 0; j--) {
		swapCh(&arr[0], &arr[j]);
		heapCh(arr, j, 0);
	}
}

int main() {
	clock_t t;
	t = clock();

	
	// INSERTION
 	int num[] = { 2,0,1,8,5,5,6,0,3,6 };
	char name[] = "HAKAN KABAYEL";
	int size = sizeof(num) / sizeof(num[0]);
	int sizechar = strlen(name);
	printf("Insertion Sort:\n");
	Insertionsort(num, size);
	t = clock() - t;
	printfunction(num, size);
	printf("insertion sort time: %f\n", ((double)t) / CLOCKS_PER_SEC);
	InsertionsortChar(name, sizechar);
	t = clock() - t;
	printf("%s\n", name);
	printf("InsertionChar sort  time: %f\n", ((double)t) / CLOCKS_PER_SEC);
	printf("\n");
	
	//SELECTION
	int num1[] = { 2,0,1,8,5,5,6,0,3,6 };
	char name1[] = "HAKAN KABAYEL";
	int size1 = sizeof(num) / sizeof(num[0]);
	int sizechar1 = strlen(name);
	printf("Selection Sort:\n");
	SelectionSort(num1, size1);
	t = clock() - t;
	printfunction(num1, size1);
	printf("Selection sort time: %f\n", ((double)t) / CLOCKS_PER_SEC);
	SelectionSortChar(name1, size1);
	t = clock() - t;
	printf("%s\n", name);
	printf("SelectionChar sort  time: %f\n", ((double)t) / CLOCKS_PER_SEC);
	printf("\n");


	// BUBBLE SORT
	int num2[] = { 2,0,1,8,5,5,6,0,3,6 };
	char name2[] = "HAKAN KABAYEL";
	int size2 = sizeof(num) / sizeof(num[0]);
	int sizechar2 = strlen(name);
	printf("Bubble Sort:\n");
	BubbleSort(num2, size2);
	t = clock() - t;
	printfunction(num2, size2);
	printf("Bubble sort time: %f\n", ((double)t) / CLOCKS_PER_SEC);
	BubbleSortChar(name2, size2);
	t = clock() - t;
	printf("%s\n", name);
	printf("BubbleChar sort  time: %f\n", ((double)t) / CLOCKS_PER_SEC);
	printf("\n");

	//MERGE SORT
	int num3[] = { 2,0,1,8,5,5,6,0,3,6 };
	char name3[] = "HAKAN KABAYEL";
	int size3 = sizeof(num) / sizeof(num[0]);
	int sizechar3 = strlen(name);
	printf("Merge Sort:\n");
	mergeSort(num3, 0, size3 - 1);
	t = clock() - t;
	printfunction(num3, size3);
	printf("merge sort time: %f\n", ((double)t) / CLOCKS_PER_SEC);
	mergeSortChar(name3, 0, sizechar3 - 1);
	t = clock() - t;
	printf("%s\n", name);
	printf("MergeChar sort time: %f\n", ((double)t) / CLOCKS_PER_SEC);
	printf("\n");
	
	// QUICK SORT
	int num4[] = { 2,0,1,8,5,5,6,0,3,6 };
	char name4[] = { "HAKAN KABAYEL" };
	int size4 = sizeof(num4) / sizeof(num4[0]);
	int sizeChar4 = strlen(name4);
	printf("Qucik Sort:\n");
	quickSort(num4, 0, size4 - 1);
	t = clock() - t;
	printfunction(num4, size4);
	printf("Quick sort time: %f\n", ((double)t) / CLOCKS_PER_SEC);
	quickSortCh(name4, 0, sizeChar4 - 1);
	t = clock() - t;
	printf("%s\n", name4);
	printf("quick char sort time: %f\n", ((double)t) / CLOCKS_PER_SEC);
	printf("\n");
	
	//HEAP SORT
	int num5[] = { 2,0,1,8,5,5,6,0,3,6 };
	char name5[] = { "HAKAN KABAYEL" };
	int size5 = sizeof(num5) / sizeof(num5[0]);
	int sizeChar5 = strlen(name5);
	printf("Heap Sort:\n");
	heapSort(num5, size5);
	t = clock() - t;
	printfunction(num5, size5);
	printf("heap sort time: %f\n", ((double)t) / CLOCKS_PER_SEC);
	heapSortCh(name5, sizeChar5);
	t = clock() - t;
	printf("%s\n", name5);
	printf("heap char sort time: %f\n", ((double)t) / CLOCKS_PER_SEC);


	return 0;
}
