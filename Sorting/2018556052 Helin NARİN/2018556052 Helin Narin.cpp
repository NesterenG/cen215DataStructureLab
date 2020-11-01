#include<stdio.h>
#include<time.h>
#include<math.h>

int argc;
char argv[100];
int minimum;

void printarray(int arr[]) {
	int i;
	for (i = 0; i < 10; i++) {
		printf("%d\t", arr[i]);
	}
	printf("\n");
}
void printchararray(char arr[]) {
	int i;
	for (i = 1; i < 11; i++) {
		printf("%c\t", arr[i]);
	}
	printf("\n");
}

//INSERTIONSORT 
void insertionsort(int arr[]) {

	int i, j;
	for (i = 1; i < 10; i++) {
		argc = arr[i];
		j = i - 1;
		while (argc < arr[j] && j >= 0) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = argc;
	}
}
void insertionsortchar(char arr[]) {
	int i, j;
	char argc;
	for (i = 1; i < 11; i++) {
		argc = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > argc) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = argc;
	}
}

// SELECTIONSORT

void selectionsort(int arr[]) {

	int i, j, temp;
	for (i = 0; i < 9; i++) {
		minimum = i;
		for (j = i + 1; j < 10; j++) {
			if (arr[j] < arr[minimum])
				minimum = j;
		}
		temp = arr[i];
		arr[i] = arr[minimum];
		arr[minimum] = temp;
	}
}
void selectionsortchar(char arr[]) {

	int i, j, temp;
	for (i = 0; i < 9; i++) {
		minimum = i;
		for (j = i + 1; j < 10; j++) {
			if (arr[j] < arr[minimum])
				minimum = j;
		}
		temp = arr[i];
		arr[i] = arr[minimum];
		arr[minimum] = temp;
	}
}

//BUBBLESORT

void bubblesort(int arr[]) {
	int i, j, temp;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void bubblesortchar(char arr[]) {
	int i, j, temp;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//MERGESORT 


void printarraymergesort(int arr[], int measure) {
	int i;
	for (i = 0; i < measure; i++) {
		printf("%d\t", arr[i]);
	}
	printf("\n");
}
void merge(int arr[], int h, int l, int n) {
	int i, j, k, a1, a2;
	a1 = l - h + 1;
	a2 = n - l;
	int L[a1], R[a2];
	for (i = 0; i < a1; i++) {
		L[i] = arr[h + i];
	}
	for (j = 0; j < a2; j++) {
		R[j] = arr[l + 1 + j];
	}
	i = 0; j = 0; k = h;
	while (i < a1 && j < a2) {
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

	while (i < a1) {
		arr[k] = L[i];
		k++;
		i++;
	}
	while (j < a2) {
		arr[k] = R[j];
		k++;
		j++;
	}
}
void mergesort(int arr[], int h, int n) {

	if (h < n) {
		int l = (h + n) / 2;
		mergesort(arr, h, l);
		mergesort(arr, l + 1, n);
		merge(arr, h, l, n);
	}
}
void printarraymergesortchar(char arr[], int measure) {
	int i;
	for (i = 0; i < measure; i++) {
		printf("%c\t", arr[i]);
	}
	printf("\n");
}
void mergechar(char arr[], int h, int l, int n) {
	int i, j, k, a1, a2;
	a1 = l - h + 1;
	a2 = n - l;
	int L[a1], R[a2];
	for (i = 0; i < a1; i++) {
		L[i] = arr[h + i];
	}
	for (j = 0; j < a2; j++) {
		R[j] = arr[l + 1 + j];
	}
	i = 0; j = 0; k = h;
	while (i < a1 && j < a2) {
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

	while (i < a1) {
		arr[k] = L[i];
		k++;
		i++;
	}
	while (j < a2) {
		arr[k] = R[j];
		k++;
		j++;
	}
}
void mergesortchar(char arr[], int h, int n) {

	if (h < n) {
		int l = (h + n) / 2;
		mergesortchar(arr, h, l);
		mergesortchar(arr, l + 1, n);
		mergechar(arr, h, l, n);
	}
}
void swap(int* h, int* n) {
	int temp = *h;
	*h = *n;
	*n = temp;
}
void charswap(char* h, char* n) {
	char temp = *h;
	*h = *n;
	*n = temp;
}
void printarray(int number[], int measure) {
	for (int i = 0; i < measure; i++) {
		printf("%d\t", number[i]);
	}
	printf("\n");
}
void printarraychar(char name[], int measure) {
	for (int i = 0; i < measure; i++) {
		printf("%c\t", name[i]);
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
      charswap(&array[i], &array[j]);
    }
  }

  charswap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSortName(char array[], int low, int high) {
  if (low < high) {

    int pi = partitionChar(array, low, high);

    quickSortName(array, low, pi - 1);

    quickSortName(array, pi + 1, high);
  }
}
// heapsort
void heapify(int number[], int measure, int i) {
	int largest = i;
	int leftchild = 2 * i + 1;
	int rightchild = 2 * i + 2;

	if (number[leftchild] > number[largest] && leftchild < measure)
		largest = leftchild;
	if (number[rightchild] > number[largest] && rightchild < measure)
		largest = rightchild;
	if (largest != i) {
		swap(&number[i], &number[largest]);
		heapify(number, measure, largest);
	}
}
void heapsort(int number[], int measure) {
	for (int i = measure / 2 - 1; i >= 0; i--) {
		heapify(number, measure, i);
	}
	for (int i = measure - 1; i > 0; i--) {
		swap(&number[0], &number[i]);
		heapify(number, i, 0);
	}
}
void charheapify(char name[], int measure, int i) {
	int largest = i;
	int leftchild = 2 * i + 1;
	int rightchild = 2 * i + 2;

	if (name[leftchild] > name[largest] && leftchild < measure)
		largest = leftchild;
	if (name[rightchild] > name[largest] && rightchild < measure)
		largest = rightchild;
	if (largest != i) {
		charswap(&name[i], &name[largest]);
		charheapify(name, measure, largest);
	}
}

void charheapsort(char name[], int measure) {
	for (int i = measure / 2 - 1; i >= 0; i--) {
		charheapify(name, measure, i);
	}
	for (int i = measure - 1; i > 0; i--) {
		charswap(&name[0], &name[i]);
		charheapify(name, i, 0);
	}
}

int main() {

	clock_t start, end;
	double time_used;
	int number[] = { 2,0,1,8,5,5,6,0,5,2 };
	char name[] = "Helin Narin";
	int size = sizeof(number) / sizeof(number[0]);

	printf("My number: 2018556052.\n");
	printf("My name: Helin Narin.\n");

	printf("------Insertion sort time------\n");
	start = clock();
	insertionsort(number);
	printarray(number);

	printf("Insertion sort char time:%f\n", time_used);
	insertionsortchar(name);
	printchararray(name);
	end = clock();
	time_used = ((double)(end - start)) / CLOCKS_PER_SEC;




	printf("------Selection sort time------\n");
	selectionsort(number);
	printarray(number);

	printf("Selection sort char time: %f\n", time_used);
	selectionsortchar(name);
	printchararray(name);
	end = clock();
	time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

	printf("------Bubble sort time------\n");
	bubblesort(number);
	printarray(number);


	printf("Bubblesort char time: %f\n", time_used);
	bubblesortchar(name);
	printchararray(name);
	end = clock();
	time_used = ((double)(end - start)) / CLOCKS_PER_SEC;


	printf("------Merge sort time------\n");
	mergesort(number, 0, size - 1);
	printarraymergesort(number, size);

	printf("Merge sort char time:%f\n", time_used);
	mergesortchar(name, 0, size - 1);
	printarraymergesortchar(name, size + 1);
	end = clock();
	time_used = ((double)(end - start)) / CLOCKS_PER_SEC;


	printf("------quick sort time------\n");
	start = clock();
	quickSort(number, 0, size - 1);
	printarray(number, size);

	printf("quick sort char time:%f\n", time_used);
	quickSortName(name, 0, size - 1);
	printarraychar(name, size + 1);
	end = clock();
	time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

	printf("------heap sort time------\n");
	start = clock();
	heapsort(number, size);
	printarray(number, size);

	printf("heap sort char time:%f\n", time_used);
	charheapsort(name, size);
	printarraychar(name, size + 1);
	end = clock();
	time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

	return 0;

}
