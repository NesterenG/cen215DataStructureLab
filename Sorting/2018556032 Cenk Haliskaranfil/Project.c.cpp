#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>

clock_t start1, end1, start2, end2, start3, end3, start4, end4, start5, end5, start6, end6;

void InsertionSort(int array[], int size) {
	
	int i, k, key;
	for (i = 1; i < size; i++) {

		key = array[i];

		for (k = i - 1; k >= 0 && key <= array[k]; k--) {
			array[k + 1] = array[k];
		
		}

		array[k + 1] = key;
		
	}

	

}

void swap(int *x, int *y) {
	
	int temp = *x;
	*x = *y;
	*y = temp;
	
}

void SelectionSort(int array[], int size) {
	
	int CurrentMin;
	for (int i = 0; i < size - 1; i++) {

		CurrentMin = i;
		for (int j = i + 1; j < size; j++) {
			if (array[j] < array[CurrentMin]) {
				CurrentMin = j;
			}
		}

		swap(&array[CurrentMin], &array[i]);

	}

	
}

void BubbleSort(int array[], int size) {
	
	for (int i = 0; i < size-1; ++i) {
		for (int j = 0; j < size-i-1; ++j) {
			if (array[j] > array[j + 1])
				swap(&array[j], &array[j + 1]);
		}
	}

}


void merge(int arr[], int left, int middle, int right)
{
	
	int Left[50], Right[50];
	int i, j, k;
	int lsize = middle - left + 1;
	int rsize = right - middle;
	
	
	Left[lsize], Right[rsize];

	
	for (i = 0; i < lsize; i++)
		Left[i] = arr[left + i];
	for (j = 0; j < rsize; j++)
		Right[j] = arr[middle + 1 + j];

	
	i = 0; 
	j = 0;  
	k = left;
	while (i < lsize && j < rsize)
	{
		if (Left[i] <= Right[j])
		{
			arr[k] = Left[i];
			i++;
		}
		else
		{
			arr[k] = Right[j];
			j++;
		}
		k++;
	}

	while (i < lsize)
	{
		arr[k] = Left[i];
		i++;
		k++;
	}

	while (j < rsize)
	{
		arr[k] = Right[j];
		j++;
		k++;
	}
	
}



void MergeSort(int array[],int left,int right) {
	
	if (left < right) {
		int middle = (left + right) / 2;
		MergeSort(array, left, middle);
		MergeSort(array, middle + 1, right);

		merge(array, left, middle, right);
	}
	

}
void QuickSort(int number[], int first, int last) {
	int i, j, pivot, temp;
	if (first < last) {
		pivot = first;
		i = first;
		j = last;
		while (i < j) {
			while (number[i] <= number[pivot] && i < last)
				i++;
			while (number[j] > number[pivot])
				j--;
			if (i < j) {
				temp = number[i];
				number[i] = number[j];
				number[j] = temp;
			}
		}
		temp = number[pivot];
		number[pivot] = number[j];
		number[j] = temp;
		QuickSort(number, first, j - 1);
		QuickSort(number, j + 1, last);
	}
}
void Heapify(int number[], int size, int i) {
	int largest = i;
	int leftchild = 2 * i + 1;
	int rightchild = 2 * i + 2;
	if (number[leftchild] > number[largest] && leftchild < size)
		largest = leftchild;

	if (number[rightchild] > number[largest] && rightchild < size)
		largest = rightchild;

	if (largest != i) {
		swap(&number[i], &number[largest]);
		Heapify(number, size, largest);
	}




}


void HeapSort(int number[], int size) {
	for (int i = size / 2 - 1; i >= 0; i--) {
		Heapify(number, size, i);
	}
	for (int i = size - 1; i > 0; i--) {
		swap(&number[0], &number[i]);
		Heapify(number, i, 0);
	}


}

void printArray(int array[],int size){

	for (int i = 0; i < size; i++) {
		printf("%d\t", array[i]);
	}
	printf("\n");
}

void printStringArray(int array[], int size) {

	for (int i = 0; i < size; i++) {
		printf("%c   ", array[i]);
	}


}

int main()
{
	

	int num1[50], num2[50], num3[50], num4[50], num5[50], num6[50],adressofletters1[50], adressofletters2[50], adressofletters3[50], adressofletters4[50], adressofletters5[50],adressofletters6[50];
	
	int num[]={2, 0, 1, 8, 5, 5, 6, 0, 3, 2};
	char name[] =  "Cenk Haliskaranfil" ;
	int adressofletters[50];
	
	
	int size = sizeof(num) / sizeof(num[0]);
	int strsize = sizeof(name) / sizeof(name[0]);
	for (int i = 0; i < size; i++) {
		num1[i] = num[i];
		num2[i] = num[i];
		num3[i] = num[i];
		num4[i] = num[i];
		num5[i] = num[i];
		num6[i] = num[i];
	}

	for (int i = 0; i < strsize; i++) {
		name[i]=tolower(name[i]);
	}
	
	for (int i = 0; i < strsize; i++) {
		adressofletters[i] = name[i];
		adressofletters1[i] = adressofletters[i];
		adressofletters2[i] = adressofletters[i];
		adressofletters3[i] = adressofletters[i];
		adressofletters4[i] = adressofletters[i];
		adressofletters5[i] = adressofletters[i];
		adressofletters6[i] = adressofletters[i];
	}
	printf("Original arrays: \nNumber: 2018556032");
	printf("\nName: Cenk Haliskaranfil\n\nSorted arrays:\n\n");
	
	start1 = clock();
	InsertionSort(num1, size);
	InsertionSort(adressofletters1,strsize );
	end1 = clock();
	printArray(num1,size);
	printStringArray(adressofletters1, strsize);
	
	float time_taken1 = ((float)(end1 - start1)) / CLOCKS_PER_SEC;
	printf("\n\nIt took %.20lf seconds to sort arrays with Insertion Sort\n\n", time_taken1);
	
	

	start2 = clock();
	SelectionSort(num2,size);
	SelectionSort(adressofletters2, strsize);
	end2 = clock();
	printArray(num2, size);
	printStringArray(adressofletters2, strsize);
	
	double time_taken2 = ((double)(end2 - start2)) / CLOCKS_PER_SEC;
	printf("\n\nIt took %.20lf seconds to sort arrays with Selection Sort\n\n", time_taken2);


	

	start3 = clock();
	BubbleSort(num3, size);
	BubbleSort(adressofletters3, strsize);
	end3 = clock();
	printArray(num3, size);
	printStringArray(adressofletters3, strsize);
	double time_taken3 = ((double)(end3 - start3)) / CLOCKS_PER_SEC;
	printf("\n\nIt took %.20lf seconds to sort arrays with Bubble Sort\n\n", time_taken3);

	
	start4 = clock();
	MergeSort(num4,0,size-1);
	MergeSort(adressofletters4, 0, strsize - 1);
	end4 = clock();
	printArray(num4, size);
	printStringArray(adressofletters4, strsize);
	double time_taken4 = ((double)(end4-start4)) / CLOCKS_PER_SEC;
	printf("\n\nIt took %.20lf seconds to sort arrays with Merge Sort\n\n", time_taken4);

	start5 = clock();
	QuickSort(num5, 0, size - 1);
	QuickSort(adressofletters5, 0, strsize - 1);
	end5 = clock();
	printArray(num5, size);
	printStringArray(adressofletters5, strsize);
	double time_taken5 = ((double)(end5 - start5)) / CLOCKS_PER_SEC;
	printf("\n\nIt took %.20lf seconds to sort arrays with Quick Sort\n\n", time_taken5);


	start6 = clock();
	HeapSort(num6, size);
	HeapSort(adressofletters6, strsize);
	end6 = clock();
	printArray(num6, size);
	printStringArray(adressofletters6, strsize);
	double time_taken6 = ((double)(end6 - start6)) / CLOCKS_PER_SEC;
	printf("\n\nIt took %.20lf seconds to sort arrays with Heap Sort\n\n", time_taken6);



	return 0;
}
