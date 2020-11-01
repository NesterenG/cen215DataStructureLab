#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//Melissa Coskun 2019555301//


//putting the name in the previous order//
void undoname(char arr[], int size) {
	char m[] = " Melissa Coskun ";
	for (int i = 0; i < size; i++) {
		arr[i] = m[i];
	}
}

//putting the array in the previous order//
void undoarray(int* aa, int size) {
	int m[] = { 2,0,1,9,5,5,5,3,0,1 };
	int i;
	for (i = 0; i < size; i++) {
		(aa[i]) = m[i];
	}
}

//swaping characters//
void swapchar(char* a, char* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//swaping numbers//
void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

//merge sort function 2 for number//
void merge(int d[], int left, int k, int right) {
	int i, j, l = 0;
	int m[10];
	for (i = left, j = k + 1; (i <= k) && (j <= right);) {
		if (d[i] < d[j]) {
			m[l] = d[i];
			i++;
			l++;
		}
		else {
			m[l] = d[j];
			j++;
			l++;
		}
	}
	while (i <= k) {
		m[l] = d[i];
		i++;
		l++;
	}
	while (j <= right) {
		m[l] = d[j];
		j++;
		l++;
	}
	for (i = left, l = 0; i <= right; i++, l++) {
		d[i] = m[l];
	}
}

//mergesort function 1 for number//
void mergesort(int d[], int left, int right) {
	int k;
	if (left < right) {
		k = (left + right) / 2;// index of the middlepoint//
		mergesort(d, left, k);
		mergesort(d, k + 1, right);
		merge(d, left, k, right);
	}
}

//mergesort function 2 for name //
void mergechar(char d[], int left, int k, int right) {
	int i, j, l = 0;
	int m[16];
	for (i = left, j = k + 1; (i <= k) && (j <= right);) {
		if (d[i] < d[j]) {
			m[l] = d[i];
			i++;
			l++;
		}
		else {
			m[l] = d[j];
			j++;
			l++;
		}
	}
	while (i <= k) {
		m[l] = d[i];
		i++;
		l++;
	}
	while (j <= right) {
		m[l] = d[j];
		j++;
		l++;
	}
	for (i = left, l = 0; i <= right; i++, l++) {
		d[i] = m[l];
	}
}

//mergesort function 1 for name//
void mergesortchar(char d[], int left, int right) {
	int k;
	if (left < right) {
		k = (left + right) / 2;// index of the middlepoint//
		mergesortchar(d, left, k);
		mergesortchar(d, k + 1, right);
		mergechar(d, left, k, right);
	}
}

//insertion sort function for number //
void insertionsort(int arr[], int size) {
	int i,j,key;
	for (i = 1; i < size; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

//insertion sort function for name//
void insertionsortchar(char arr[], int size) {
	int i, j ;
		char key;
	for (i = 1; i < size; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

//bubble sort function for number//
void bubblesort(int arr[], int size) {
	int i, j;
	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}

		}
	}
}

//bubble sort function for name//
void bubblesortchar(char arr[], int size) {
	int i, j;
	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				swapchar(&arr[j], &arr[j + 1]);
			}

		}
	}
}

//selection sort function for number//
void selectionsort(int arr[], int size) {
	
	int i, j, k, min, temp;
	for (i = 0; i < size - 1; i++) {
		min = i;
		for (j = i + 1; j < size; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		swap(&arr[i], &arr[min]);
	}
}

//selection sort function for name//
void selectionsortchar(char arr[], int size) {
	int i, j;
	char min;
	for (i = 0; i < size - 1; i++) {
		min = i;
		for (j = i + 1; j < size; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		swapchar(&arr[i], &arr[min]);

	}
}

//printf function//
void functionprint(int arr[], int size){

	for (int i = 0; i < size; i++) {
		printf(" %d\t", arr[i]);
	}
}

//Quick Sort For Number//
void quickSort(int* array, int left, int right) {
	int k, j, q, temp;
	k = left;
	j = right;
	q = array[(left + right) / 2];

	do {
		while ((array[k] < q) && (k < right))
			k++;
		while ((array[j] > q) && (j > left))
			j--;
		if (k <= j) {
			swap(&array[k], &array[j]);
			k++;
			j--;
		}
	} while (k <= j);

	if (left < j)
		quickSort(array, left, j);
	if (k < right)
		quickSort(array, k, right);

}


//Quick Sort For Name//
void quickSortchar(char arr[], int left, int right) {
	int k, j, q, temp;
	k = left;
	j = right;
	q = arr[(left + right) / 2];

	do {
		while ((arr[k] < q) && (k < right))
			k++;
		while ((arr[j] > q) && (j > left))
			j--;
		if (k <= j) {
			swapchar(&arr[k], &arr[j]);
			k++;
			j--;
		}
	} while (k <= j);

	if (left < j)
		quickSortchar(arr, left, j);
	if (k < right)
		quickSortchar(arr, k, right);

}
//Heap Sort For Number//
void heapify(int arr[], int n, int i) {
	int largest = i;
	int l = (2 * i) + 1;//left child//
	int r = (2 * i) + 2;//right child//
	if (arr[l] > arr[largest] && l < n)
		largest = l;
	if (arr[r] > arr[largest] && r < n)
		largest = r;

	if (largest != i) {
		swap(&arr[i], &arr[largest]);
		heapify(arr, n, largest);
	}


}
void heapsort(int arr[], int n) {
	int i, j;
	for (i = (n / 2) - 1; i >= 0; i--)
		heapify(arr, n, i);
	for (j = n - 1; j > 0; j--) {
		swap(&arr[0], &arr[j]);
		heapify(arr, j, 0);
	}


}
//Heap Sort For Name

void heapifychar(char name[16], int n, int i) {
	int largest = i;
	int l = (2 * i) + 1;//left child//
	int r = (2 * i) + 2;//right child//
	if (name[l] > name[largest] && l < n)
		largest = l;
	if (name[r] > name[largest] && r < n)
		largest = r;

	if (largest != i) {
		swapchar(&name[i], &name[largest]);
		heapifychar(name, n, largest);
	}


}
void heapsortchar(char name[16], int n) {
	int i, j;
	for (i = (n / 2) - 1; i >= 0; i--)
		heapifychar(name, n, i);
	for (j = n - 1; j > 0; j--) {
		swapchar(&name[0], &name[j]);
		heapifychar(name, j, 0);
	}


}


int main() {

	char name[] = " Melissa Coskun ";
	int a[] = {2,0,1,9,5,5,5,3,0,1};
	int n1 = sizeof(a) / sizeof(a[1]);
	int charsize = strlen(name);
	
	clock_t start,end;
	double totaltime;

	
	
	
	
	printf("\n\nOrginal Array:  ");  functionprint(a, n1);
	printf("\nBubble Sort:    "); start = clock(); bubblesort(a, n1); end = clock();
	totaltime = (double)(end - start) / CLOCKS_PER_SEC;

	functionprint(a, n1);
	printf("\nExecution Time for bubblesort number:%f", totaltime);
	undoarray(&a, n1);

	printf("\n\nOrginal Name:%s", name);
	start = clock(); bubblesortchar(name, charsize); end = clock();
	totaltime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nSorted Name for bubble:%s", name);
	printf("\nExecution Time for bubblesort name:%f", totaltime);

	undoname(name, charsize);

	
	printf("\n\nOrginal Array:  ");  functionprint(a, n1);
	printf("\nInsertion Sort: "); start = clock(); insertionsort(a, n1); end = clock();
	totaltime = (double)(end - start) / CLOCKS_PER_SEC;
	functionprint(a, n1);
	printf("\nExecution Time for insertion sort number:%f", totaltime);
	undoarray(&a, n1);

	printf("\n\nOrginal Name:%s", name);
	start = clock(); insertionsortchar(name, charsize); end = clock();
	totaltime = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\nSorted Name for insertion:%s", name);
	printf("\nExecution Time for insertion sort name:%f", totaltime);

	undoname(name, charsize);
	
	printf("\n\nOrginal Array:  ");  functionprint(a, n1);
	printf("\nMerge Sort:     "); start = clock(); mergesort(a, 0, n1 - 1); end = clock();
	totaltime = (double)(end - start) / CLOCKS_PER_SEC;
	functionprint(a, n1);
	printf("\nExecution Time for merge sort number:%f", totaltime);

	printf("\n\nOrginal Name:%s", name);
	start = clock(); mergesortchar(name, 0, charsize - 1); end = clock();
	totaltime = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\nSorted Name for merge:%s\n", name);
	printf("Execution Time for merge sort name:%f", totaltime);
	undoname(name, charsize);
	undoarray(&a, n1);

	printf("\n\nOrginal Array:  ");  functionprint(a, n1);

	printf("\nSelection Sort:    "); start = clock(); selectionsort(a, n1);
	end = clock();
	totaltime = (double)(end - start) / CLOCKS_PER_SEC;
	functionprint(a, n1);
	printf("\nExecution Time for selectionsort number:%f", totaltime);
	undoarray(&a, n1);

	printf("\n\nOrginal Name:%s", name);
	start = clock(); selectionsortchar(name, charsize);
	end = clock();
	totaltime = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\nSorted Name for selection:%s", name);
	printf("\nExecution Time for selectionsort name:%f\n", totaltime);
	undoname(name, charsize);

	printf("\n\nOrginal Array:  ");  functionprint(a, n1);
	printf("\nQuick Sort:    "); 
	start = clock();
	quickSort(a, 0, n1 - 1);
	end = clock();
	totaltime = (double)(end - start) / CLOCKS_PER_SEC;
	functionprint(a, n1);
	printf("\nExecution Time for quicksort number:%f", totaltime);
	undoarray(&a, n1);

	printf("\n\nOrginal Name:%s", name);
	start = clock(); quickSortchar(name, 0, charsize - 1);
	end = clock();
	totaltime = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\nSorted Name for quicksort:%s", name);
	printf("\nExecution Time for Quicksort name:%f\n", totaltime);
	undoname(name, charsize);


	printf("\n\nOrginal Array:  ");  functionprint(a, n1);
	printf("\nHeap Sort:    ");
	start = clock();
	heapsort(a, n1);
	end = clock();
	totaltime = (double)(end - start) / CLOCKS_PER_SEC;
	functionprint(a, n1);
	printf("\nExecution Time for heapsort number:%f", totaltime);
	undoarray(&a, n1);

	printf("\n\nOrginal Name:%s", name);
	start = clock();
	heapsortchar(name, charsize);
	end = clock();
	totaltime = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\nSorted Name for heapsort:%s", name);
	printf("\nExecution Time for HeapSort name:%f\n", totaltime);
	undoname(name, charsize);

}