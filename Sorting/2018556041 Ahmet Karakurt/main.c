#include <time.h>
#include <stdio.h>
#include <string.h>

//swap things
void swapChar(char* a, char* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}


void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

//insertion sort part
void insertionSort(int arr[], int n){
	
	int i, j;
	int temp;
	for(i=0;i < n; i++){
		j= i-1;
		temp = arr[i];
		while(j >= 0 && arr[j] > temp){
			arr[j+1] = arr[j];
			j = j -1;
		}
		arr[j+1] = temp;	
	}
	
}
void insertionSortChar(char arr[], int size){
	int i, j;
	char temp;
	for(i=1;i<size;i++){
		j = i-1;
		temp = arr[i];
		while(j>=0&&arr[j]>temp){
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = temp;
	}
}

//merge sort parts
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

void mergeSort(int arr[], int left, int right){
	int m;
	if (left < right) {
		m = (left+right)/2;
		mergeSort(arr, left, m);
		mergeSort(arr, m+1, right);
		merge(arr, left, m, right);
		
	}
}



//merge sort for characters
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


void mergesortchar(char d[], int left, int right) {
	int k;
	if (left < right) {
		k = (left + right) / 2;
		mergesortchar(d, left, k);
		mergesortchar(d, k + 1, right);
		mergechar(d, left, k, right);
	}
}

//bubble sort parts

void bubbleSort(int arr[], int size) {
	int i, j;
	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}

		}
	}
}

//bubble sort for characters
void bubbleSortChar(char arr[], int size) {
	int i, j;
	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				swapChar(&arr[j], &arr[j + 1]);
			}

		}
	}
}
//selection sort part 
void selectionSort(int arr[], int n) 
{ 
    int i, j, min;  
    for (i = 0; i < n-1; i++) 
    { 
        min = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min]) 
            min = j; 
        swap(&arr[min], &arr[i]); 
    } 
} 
//selection sort for characters
void selectionSortChar(char arr[], int n) 
{ 
    int i, j;
    char min;  
    for (i = 0; i < n-1; i++) 
    { 
        min = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min]) 
            min = j; 
        swapChar(&arr[min], &arr[i]); 
    } 
} 
// quick sort for numbers
int Partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);     
	int j;
    for (j = low; j <= high - 1; j++)
    {

        if (arr[j] < pivot)
        {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSortNum(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = Partition(arr, low, high);
        quickSortNum(arr, low, pi - 1);
        quickSortNum(arr, pi + 1, high);
    }
}

//quick sort for characters
int QuickSortChar(char name[], int low, int high){
	
	int pivot = name[high];
	int i = (low - 1);
	int j;
	for ( j = low; j <= high- 1; j++){
		if (name[j] <= pivot){
			i++;
			swapChar(&name[i], &name[j]);
		}
	}
	swapChar(&name[i + 1], &name[high]);
	return (i + 1);
}
void quickSortChar(char name[], int low, int high){
	if (low < high){
		int pi = QuickSortChar(name, low, high);
		quickSortChar(name, low, pi - 1);
		quickSortChar(name, pi + 1, high);
	}
}

//heapify for numbers
void heapifyNum(int number[], int size, int i){
	int largest = i;
	int leftChild = 2 * i + 1;
	int rightChild = 2 * i + 2;
	if(number[leftChild] > number[largest] && leftChild < size){
		largest = leftChild;
	}
	if(number[rightChild] > number[largest] && rightChild < size){
		largest = rightChild;
	}
	if(largest != i){
		swap(&number[i], &number[largest]);
		heapifyNum(number, size, largest);
	}
}
//heapify for characters
void heapifyChar(char arr[], int size, int i){
	int largest = i;
	int leftChild = 2 * i + 1;
	int rightChild = 2 * i + 2;
	if(arr[leftChild] > arr[largest] && leftChild < size){
		largest = leftChild;
	}
	if(arr[rightChild] > arr[largest] && rightChild < size){
		largest = rightChild;
	}
	if(largest != i){
		swapChar(&arr[i], &arr[largest]);
		heapifyChar(arr, size, largest);
	}
	
}

//heapsort for numbers
void heapSortNum(int number[], int size){
	int i;
	for(i = size/2 -1; i >= 0; i--){
		heapifyNum(number, size, i);
	}
	
	for(i = size-1; i>0; i--){
		swap(&number[0], &number[i]);
		heapifyNum(number, i, 0);
	}
}

//heap sort for characters

void heapSortChar(char arr[], int size){
	int i;
	for(i = size/2 -1; i >= 0; i--){
		heapifyChar(arr, size, i);
	}
	
	for(i = size-1; i>0; i--){
		swapChar(&arr[0], &arr[i]);
		heapifyChar(arr, i, 0);
	}	
	
}

void printArray(int arr[], int n){
	 int i; 
    for (i = 0; i < n; i++){
		printf("%d ", arr[i]); 
	}
    printf("\n");
}

int main() {
    clock_t t;
	//okul numarasý
    int scno[] = {2,0,1,8,5,5,6,0,4,1}; 
    //Ad soyad
    char name[] = "ahmet karakurt"; 
	int n = sizeof(scno) / sizeof(scno[0]); 
	int charSize = strlen(name);
	
	//insertion sort
    t = clock();
    insertionSort(scno, n);
    t = clock() - t;
    printArray(scno, n); 
    printf("insertion sort time: %f\n\n\n", ((double)t) / CLOCKS_PER_SEC);
    
    insertionSortChar(name, charSize);
    
    t = clock() - t;
    printf("%s\n", name);
    
    printf("insertion char sort time: %f\n\n\n", ((double)t) / CLOCKS_PER_SEC);

    int scno1[] = {2,0,1,8,5,5,6,0,4,1};     
    char name1[] = "ahmet karakurt";
	 
    selectionSort(scno1, n);
    t = clock() - t;
    printArray(scno1, n); 
    printf("selection sort time: %f\n\n\n", ((double)t) / CLOCKS_PER_SEC);

    selectionSortChar(name1, charSize);
    t = clock() - t;
    printf("%s\n", name1);
    printf("selection char sort time: %f\n\n\n", ((double)t) / CLOCKS_PER_SEC);


    //Bubble Sort
    int scno2[] = {2,0,1,8,5,5,6,0,4,1};     
    char name2[] = "ahmet karakurt";
    
    bubbleSort(scno2, n);
    t = clock() - t;
    printArray(scno2, n); 
    printf("bubble sort time: %f\n\n\n", ((double)t) / CLOCKS_PER_SEC);

    bubbleSortChar(name2, charSize);
    t = clock() - t;
    printf("%s\n", name2);
    printf("bubble char sort time: %f\n\n\n", ((double)t) / CLOCKS_PER_SEC);


    //Merge Sort
    int scno3[] = {2,0,1,8,5,5,6,0,4,1};     
    char name3[] = "ahmet karakurt";
    
	mergeSort(scno3, 0, n - 1);
    t = clock() - t;
    printArray(scno3, n); 
    printf("merge sort time: %f\n\n\n", ((double)t) / CLOCKS_PER_SEC);
    mergesortchar(name3, 0, charSize - 1);
    t = clock() - t;
    printf("%s\n", name3);
    printf("merge char sort time: %f\n\n\n", ((double)t) / CLOCKS_PER_SEC);
    
    //Quick Sort
    int scno4[] = {2,0,1,8,5,5,6,0,4,1};     
    char name4[] = "ahmet karakurt";
    
	quickSortNum(scno4, 0, n-1);
    t = clock() - t;
    printArray(scno4, n);
    printf("quick sort time: %f\n\n\n", ((double)t) / CLOCKS_PER_SEC);
    quickSortChar(name4, 0, charSize - 1);
    t = clock() - t;
    printf("%s\n", name4);
    printf("quick char sort time: %f\n\n\n", ((double)t) / CLOCKS_PER_SEC);
    
    // Heap sort
    int scno5[] = {2,0,1,8,5,5,6,0,4,1};     
    char name5[] = "ahmet karakurt";
    heapSortNum(scno5, n);
    t = clock() - t;
    printArray(scno5, n);
    printf("heap sort time: %f\n\n\n", ((double)t) / CLOCKS_PER_SEC);
    heapSortChar(name5, charSize);
    t = clock() - t;
    printf("%s\n", name5);
    printf("heap char sort time: %f\n\n\n", ((double)t) / CLOCKS_PER_SEC);
    
    
    printf("Ahmet Karakurt 2018556041");

    return 0;
}
