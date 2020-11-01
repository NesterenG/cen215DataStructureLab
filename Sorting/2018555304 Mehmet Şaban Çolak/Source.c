#include <stdio.h>
#include <assert.h>
#include<time.h>
//swap student number
void swapid(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;

}
//swap student name
void swapname(char* x, char* y) {
	char temp = *x;
	*x = *y;
	*y = temp;
}
//student number print function
void print(int number[],int size) {
	for (int i = 0; i <= size-1; i++)
	{
		printf("%d", number[i]);
	}
	printf("\n");
}
//student name print function
void printn(char number[], int size) {
	for (int i = 0; i <= size - 1; i++)
	{
		if(number[i]!='\0' && number[i] != ' ')
		{
			printf("%c", number[i]);
		}
	}
	printf("\n");
}
//insertion sort function for student number
void insertionsort(int number[], int size)
{
	int i, j, temp;
	for (i = 1; i < size; i++) 
	{
		temp = number[i];
		for (j = i - 1; j >= 0 && temp <= number[j]; j--)
			number[j+1] =number[j] ;
		    number[j+1] = temp;
	}
}
//insertion sort function for student name
void insertionsortname(char number[], int size)
{
	int i, j, temp;
	for (i = 1; i < size; i++)
	{
		temp = number[i];
		for (j = i - 1; j >= 0 && temp <= number[j]; j--)
			number[j + 1] = number[j];
		number[j + 1] = temp;
	}
}
//selection sort function for student number
void selectionsort(int number[],int size) 
{
	int i, j,l, temp,min;
	for (i = 0; i < size-1; i++) 
	{
		temp = number[i];
		for (j = i+1; j < size; j++)
			if (number[j] < temp) 
			{
				temp = number[j];
				l = j;
			}
		if (temp != number[i])
		{
			min = number[i];
			number[i] = temp;
			number[l] = min;
		}
	}
}
//selection sort function for student name
void selectionsortn(char number[], int size)
{
	int i, j, l, temp, min;
	for (i = 0; i < size-1; i++)
	{
		temp = number[i];
		for (j = i + 1; j < size-1; j++)
			if (number[j] < temp)
			{
				temp = number[j];
				l = j;
			}
		if (temp != number[i])
		{
			min = number[i];
			number[i] = temp;
			number[l] = min;
		}
	}
}
//bubble sort function for student number
void bubblesort(int number[],int size) {
	int i, j, temp;
	for(i=0;i<size-1;i++)
		for(j=0;j<(size-1-i);j++)
			if (number[j] > number[j+1])
			{
				temp = number[j];
				number[j] = number[j+1];
				number[j+1] = temp;
			}

}
//bubble sort function for student name
void bubblesortn(char number[], int size) {
	int i, j, temp;
	for (i = 0; i < size-1 ; i++)
		for (j = 0; j < size-1-i; j++)
			if (number[j] > number[j + 1])
			{
				temp = number[j];
				number[j] = number[j + 1];
				number[j+1] = temp;
			}
}

// merge sort function for student number
void merge(int number[], int left, int m, int right)
{
	int i, j, k, n1, n2;
	n1 = m - left + 1;
	n2 = right - m;

	int L[10], R[10];

	for (i = 0; i < n1; i++)
		L[i] = number[left + i];
	for (j = 0; j < n2; j++)
		R[j] = number[m + 1 + j];

	i = 0;
	j = 0;
	k = left;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			number[k] = L[i];
			i++;
		}
		else {
			number[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		number[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		number[k] = R[j];
		j++;
		k++;
	}
}

void mergesort(char number[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;

		mergesort(number, l, m);
		mergesort(number, m + 1, r);

		merge(number, l, m, r);
	}
}
// merge sort function for student name
void mergen(char number[], int left, int m, int right)
{
	int i, j, k, n1, n2;
	n1 = m - left + 1;
	n2 = right - m;

	int L[10], R[10];

	for (i = 0; i < n1; i++)
		L[i] = number[left + i];
	for (j = 0; j < n2; j++)
		R[j] = number[m + 1 + j];

	i = 0;
	j = 0;
	k = left;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			number[k] = L[i];
			i++;
		}
		else {
			number[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		number[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		number[k] = R[j];
		j++;
		k++;
	}
}

void mergesortn(char number[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;

		mergesortn(number, l, m);
		mergesortn(number, m + 1, r);

		mergen(number, l, m, r);
	}
}
// partition for student number
int partitionnumber(int arr[], int left, int right)
{
	int pivot = arr[right];
	int low = (left - 1);
	int high;

	for (high = left; high <= right - 1; high++)
	{
		if (arr[high] <= pivot)
		{
			low++;
			swapid(&arr[low], &arr[high]);
		}
	}
	swapid(&arr[low + 1], &arr[right]);
	return (low + 1);
}
// quick sort function for student number
void quicksortnumber(int arr[], int left, int right)
{
	if (left < right)
	{
		int pivot = partitionnumber(arr, left, right);
		quicksortnumber(arr, left, pivot - 1);
		quicksortnumber(arr, pivot + 1, right);
	}
}
// partition for student name
int partitionname(char arr[], int left, int right)
{
	int pivot = arr[right];
	int low = (left - 1);
	int high;

	for (high = left; high <= right - 1; high++)
	{
		if (arr[high] <= pivot)
		{
			low++;
			swapname(&arr[low], &arr[high]);
		}
	}
	swapname(&arr[low + 1], &arr[right]);
	return (low + 1);
}
// quick sort function for student name
void quicksortname(char arr[], int left, int right)
{
	if (left < right)
	{
		int pivot = partitionname(arr, left, right);
		quicksortname(arr, left, pivot - 1);
		quicksortname(arr, pivot + 1, right);
	}
}
// heapify student number
void heapifyid(int arr[], int size, int i) {
	int largest = i;
	int leftChild = 2 * i + 1;
	int rightChild = 2 * i + 2;

	if (arr[leftChild] > arr[largest] && leftChild < size)
		largest = leftChild;

	if (arr[rightChild] > arr[largest] && rightChild < size)
		largest = rightChild;
	if (largest != i) {
		swapid(&arr[i], &arr[largest]);
		heapifyid(arr, size, largest);
	}
}
// heap sort function for student number
void heapsortid(int arr[], int size) {
	int i;
	for (i = size / 2 - 1; i >= 0; i--) {
		heapifyid(arr, size, i);
	}

	for (i = size - 1; i > 0; i--) {
		swapid(&arr[0], &arr[i]);
		heapifyid(arr, i, 0);
	}

}
// heapify student name
void heapifyname(char arr[], int size, int i) {
	int largest = i;
	int leftChild = 2 * i + 1;
	int rightChild = 2 * i + 2;

	if (arr[leftChild] > arr[largest] && leftChild < size)
		largest = leftChild;

	if (arr[rightChild] > arr[largest] && rightChild < size)
		largest = rightChild;
	if (largest != i) {
		swapname(&arr[i], &arr[largest]);
		heapifyname(arr, size, largest);
	}
}
// heap sort function for student name
void heapsortname(char arr[], int size) {
	int i;
	for (i = size / 2 - 1; i >= 0; i--) {
		heapifyname(arr, size, i);
	}

	for (i = size - 1; i > 0; i--) {
		swapname(&arr[0], &arr[i]);
		heapifyname(arr, i, 0);
	}

}
int main()
{
	clock_t time;
	int number[] = { 2,0,1,8,5,5,5,3,0,4 };
	char name[] = "mehmet saban colak";
	int size = sizeof(number) / sizeof(number[0]);
	int sizen = sizeof(name) / sizeof(name[0]);
	time = clock();
	insertionsort(number,size);
	time = clock()-time;
	print(number, size);
	printf("insertion sort time of student number: %f\n", ((double)time) / CLOCKS_PER_SEC);
	insertionsortname(name, sizen);
	time = clock()-time;
	printn(name, sizen);
	printf("insertion sort time of name: %f\n", ((double)time) / CLOCKS_PER_SEC);

	int number1[] = { 2,0,1,8,5,5,5,3,0,4 };
	char name1[] = "mehmet saban colak";
	selectionsort(number1, size);
	time = clock() - time;
	print(number1, size);
	printf("selection sort time of student number: %f\n", ((double)time) / CLOCKS_PER_SEC);
	selectionsortn(name1, sizen);
	time = clock()-time;
	printn(name1, sizen);
	printf("selection sort time of name: %f\n", ((double)time) / CLOCKS_PER_SEC);

	int number2[] = { 2,0,1,8,5,5,5,3,0,4 };
	char name2[] = "mehmet saban colak";
	bubblesort(number2, size);
	time = clock() - time;
	print(number2, size);
	printf("bubble sort time of student number: %f\n", ((double)time) / CLOCKS_PER_SEC);
	bubblesortn(name2, sizen);
	time = clock() - time;
	printn(name2, sizen);
	printf("bubble sort time of name: %f\n", ((double)time) / CLOCKS_PER_SEC);

	int number3[] = { 2,0,1,8,5,5,5,3,0,4 };
	char name3[] = "mehmet saban colak";
	mergesort(number3, 0,size-1);
	time = clock() - time;
	print(number3, size);
	printf("merge sort time of student number: %f\n", ((double)time) / CLOCKS_PER_SEC);
	mergesortn(name3,0,sizen-1);
	time = clock() - time;
	printn(name3, sizen);
	printf("merge sort time of name: %f\n", ((double)time) / CLOCKS_PER_SEC);
	
	int number4[] = { 2,0,1,8,5,5,5,3,0,4 };
	char name4[] = "mehmet saban colak";
	quicksortnumber(number4, 0, size - 1);
	time = clock() - time;
	print(number4, size);
	printf("quick sort time of student number: %f\n", ((double)time) / CLOCKS_PER_SEC);
	quicksortname(name4, 0, sizen - 1);
	time = clock() - time;
	printn(name4, sizen);
	printf("quick sort time of student name: %f\n", ((double)time) / CLOCKS_PER_SEC);

	int number5[] = { 2,0,1,8,5,5,5,3,0,4 };
	char name5[] = "mehmet saban colak";
	heapsortid(number5, size);
	time = clock() - time;
	print(number5, size);
	printf("heap sort time of student number: %f\n", ((double)time) / CLOCKS_PER_SEC);
	heapsortname(name5, sizen);
	time = clock() - time;
	printn(name5, sizen);
	printf("heap sort time of student name: %f\n", ((double)time) / CLOCKS_PER_SEC);
	return 0;
}
