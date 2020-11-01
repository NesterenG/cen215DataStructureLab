#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>
void swapName(char* xp, char* yp)
{
	char temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void swapNumber(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void insertionName(char name[], int len) {

	int i, key, j;
	for (i = 1; i < len; i++) {
		key = name[i];
		j = i - 1;

		while (j >= 0 && name[j] > key) {
			name[j + 1] = name[j];
			j = j - 1;
		}

		name[j + 1] = key;
	}

}
void insertionNumber(int number[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = number[i];
		j = i - 1;


		while (j >= 0 && number[j] > key) {
			number[j + 1] = number[j];
			j = j - 1;
		}
		number[j + 1] = key;
	}
}

void printArrayName(char name[], int len)
{
	int i;
	for (i = 0; i < len; i++)
		printf("%c ", name[i]);
	printf("\n");
}

void printArrayNumber(int number[], int n)
{
	int i;
	printf("    ");
	for (i = 0; i < n; i++)
		printf("%d ", number[i]);
	printf("\n");
}


void selectionSortNumber(int arr[], int n)
{
	int i, j, min_idx;


	for (i = 0; i < n - 1; i++)
	{
	
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;

	
		swapNumber(&arr[min_idx], &arr[i]);
	}
}

void selectionSortName(char arr[], int len)
{
	int i, j, min_idx;


	for (i = 0; i < len - 1; i++)
	{
		 
		min_idx = i;
		for (j = i + 1; j < len; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;

		 
		swapName(&arr[min_idx], &arr[i]);
	}
}
 
void mergeNumber(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;


	int L[n1], R[n2];

	
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	
	i = 0;  
	j = 0;  
	k = l;  
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}


	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}


	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}


void mergeSortNumber(int arr[], int l, int r)
{
	if (l < r)
	{
	
		int m = l + (r - l) / 2;

		
		mergeSortNumber(arr, l, m);
		mergeSortNumber(arr, m + 1, r);

		mergeNumber(arr, l, m, r);
	}
}

void mergeName(char arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	
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

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}


void mergeSortName(char arr[], int l, int r)
{
	if (l < r)
	{
	 
		int m = l + (r - l) / 2;

	
		mergeSortName(arr, l, m);
		mergeSortName(arr, m + 1, r);

		mergeName(arr, l, m, r);
	}
}



void bubbleSortNumber(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		   
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swapNumber(&arr[j], &arr[j + 1]);
}

void bubbleSortName(char arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		   
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swapName(&arr[j], &arr[j + 1]);
}

int partitionNumber (int arr[], int low, int high) 
{ 
    int pivot = arr[high];   
    int i = (low - 1);  
    
    int j;
    for (j = low; j <= high- 1; j++) 
    { 
       
        if (arr[j] < pivot) 
        { 
            i++;   
            swapNumber(&arr[i], &arr[j]); 
        } 
    } 
    swapNumber(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  

void quickSortNumber(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
       
        int pi = partitionNumber(arr, low, high); 
  
       
        quickSortNumber(arr, low, pi - 1); 
        quickSortNumber(arr, pi + 1, high); 
    } 
}

int partitionName (char arr[], int low, int high) 
{ 
    int pivot = arr[high];    
    int i = (low - 1);   
    
    int j;
    for (j = low; j <= high- 1; j++) 
    { 
        
        if (arr[j] < pivot) 
        { 
            i++;    
            swapName(&arr[i], &arr[j]); 
        } 
    } 
    swapName(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  

void quickSortName(char arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        
        int pi = partitionName(arr, low, high); 
  
        
        quickSortName(arr, low, pi - 1); 
        quickSortName(arr, pi + 1, high); 
    } 
}
  void heapifyNumber(int arr[], int n, int i) {
    
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
   
    if (largest != i) {
      swapNumber(&arr[i], &arr[largest]);
      heapifyNumber(arr, n, largest);
    }
  }
  
  
  void heapSortNumber(int arr[], int n) {
    
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
      heapifyNumber(arr, n, i);
  
     
    int k;
    for (k = n - 1; k >= 0; k--) {
      swapNumber(&arr[0], &arr[k]);
  
      
      heapifyNumber(arr, k, 0);
    }
  }
  void heapifyName(char arr[], int n, int i) {
   
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
   
    if (largest != i) {
      swapName(&arr[i], &arr[largest]);
      heapifyName(arr, n, largest);
    }
  }
  
  
  void heapSortName(char arr[], int n) {
    
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
      heapifyName(arr, n, i);
  
   
    int k;
    for (k = n - 1; k >= 0; k--) {
      swapName(&arr[0], &arr[k]);
  
      
      heapifyName(arr, k, 0);
    }
  }
int main()
{

	char name[] = "Mehmet Ali Dalgic";
	int number[] = {2,0,1,7,5,5,5,0,1,3};
	clock_t time;

	int len = strlen(name);
	int n = sizeof(number) / sizeof(number[0]);

	time = clock();
	printf("-INSERTION SORT\n\n");
	insertionName(name, len);
	time = clock() - time;
	printArrayName(name, len);
	printf("Insertion sort time: %f\n", ((double)time) / CLOCKS_PER_SEC);

	insertionNumber(number, n);
	time = clock() - time;
	printArrayNumber(number, n);
	printf("Insertion sort time: %f\n", ((double)time) / CLOCKS_PER_SEC);

	printf("\n-SELECTION SORT\n\n");
	selectionSortName(name, len);
	time = clock() - time;
	printArrayName(name, len);
	printf("Selection sort time: %f\n", ((double)time) / CLOCKS_PER_SEC);


	selectionSortNumber(number, n);
	time = clock() - time;
	printArrayNumber(number, n);
	printf("Selection sort time: %f\n", ((double)time) / CLOCKS_PER_SEC);

	printf("\n-MERGE SORT\n\n");
	mergeSortName(name, 0, len-2);
	time = clock() - time;
	printArrayName(name, len);
	printf("Merge sort time: %f\n", ((double)time) / CLOCKS_PER_SEC);

	mergeSortNumber(number, 0, n);
	time = clock() - time;
	printArrayNumber(number, n);
	printf("Merge sort time: %f\n", ((double)time) / CLOCKS_PER_SEC);

	printf("\n-BUBBLE SORT\n\n");
	bubbleSortName(name, len);
	time = clock() - time;
	printArrayName(name, len);
	printf("Bubble sort time: %f\n", ((double)time) / CLOCKS_PER_SEC);

	bubbleSortNumber(number, n);
	time = clock() - time;
	printArrayNumber(number, n);
	printf("Bubble sort time: %f\n", ((double)time) / CLOCKS_PER_SEC);
	
	printf("\n-QUICK SORT\n\n");
	quickSortName(name, 0, len-1);
	time = clock() - time;
	printArrayName(name, len);
	printf("Quick sort time: %f\n", ((double)time) / CLOCKS_PER_SEC);

	quickSortNumber(number, 0, n-1);
	time = clock() - time;
	printArrayNumber(number, n);
	printf("Quick sort time: %f\n", ((double)time) / CLOCKS_PER_SEC);
	
	printf("\n-HEAP SORT\n\n");
	heapSortName(name, len);
	time = clock() - time;
	printArrayName(name, len);
	printf("Heap sort time: %f\n", ((double)time) / CLOCKS_PER_SEC);
	
	heapSortNumber(number, n);
	time = clock() - time;
	printArrayNumber(number, n);
	printf("Heap sort time: %f\n", ((double)time) / CLOCKS_PER_SEC);

	return 0;
}

