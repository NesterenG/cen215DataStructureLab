#include <stdio.h>
#include <string.h>
#include <time.h>

void swapChar(char* x, char* y) {

	char temp = *x;
	*x = *y;
	*y = temp;

}

void swap(int* x, int* y) {

	int temp = *x;
	*x = *y;
	*y = temp;

}

void bubbleSortName(char name[], char sizename) {

	char i, j;
	for (  i = 0; i < sizename; i++) {
		for ( j = 0; j < sizename-i-1; j++) {
			if (name[j] > name[j+1]){
		      swapChar(&name[j], &name[j+1]);
			}
	}
  }
}

void bubbleSort(int arr[], int size) {

	int i, j;
	for (  i = 0; i < size-1; i++) {
		for ( j = 0; j < size-i-1; j++) {
			if (arr[j+1] < arr[j]){
		        swap(&arr[j],&arr[j+1] );
			}
	}
  }
}

void insertionSortName(char arr[], char size) {

	char i, j,key;
	for ( int i = 1; i < size; i++) {
		key= arr[i];
		for (j = i - 1; arr[j]>key && j>=0 ; j--) {
			arr[j+1]=arr[j];
		}
		arr[j+1]=key;
		
	}

}

void insertionSort(int arr[], int size) {

	int i, j,key;
	for ( int i = 1; i < size; i++) {
		key= arr[i];
		for (j = i - 1; arr[j]>key && j>=0 ; j--) {
			arr[j+1]=arr[j];
		}
		arr[j+1]=key;
		
	}

}

void selectionSortName(char arr[], char size) {

	char i, j,curMin;
	for ( int i = 0; i < size-1; i++) {
		curMin = i;
		for (j = i + 1; j < size; j++) {
			if (arr[j] < arr[curMin])
				curMin = j;
		}
		swapChar(&arr[curMin],&arr[i] );
	}
}

void selectionSort(int arr[], int size) {

	int i, j,curMin;
	for ( int i = 0; i < size-1; i++) {
		curMin = i;
		for (j = i + 1; j < size; j++) {

			if (arr[j] < arr[curMin])
				curMin = j;
		}
		
		swap(&arr[curMin],&arr[i] );
	}
}

void mergeName(char arr[], int left, int middle, int right) {

	int lsize = middle - left + 1;
	int rsize = right - middle;
	int Left[lsize];
	int Right[rsize];
	int i;
	for ( i = 0; i < lsize; i++) {

		Left[i] = arr[left + i];

	}
	int j;
	for ( j = 0; j < rsize; j++) {

		Right[j] = arr[middle + 1 + j];

	}

	i = 0; j = 0;
	int org=left;
	while (i<lsize && j<rsize) {
		if (Left[i] <= Right[j]) {

			arr[org] = Left[i];
			i++;
		}
		else {
			arr[org] = Right[j];
			j++;
		}
		org++;
			
	}
	while (i < lsize) {
		arr[org] = Left[i];
		i++; 
		org++;
	}
	while (j < rsize) {
		arr[org] = Right[j];
		j++;
		org++;

	}
}

	void mergeSortName(char arr[], int left, int right) {
		
	if (left<right) {

		int middle = (left + right) / 2; 
		mergeSortName(arr,left,middle );
		mergeSortName(arr,middle+1,right );
     	mergeName(arr,left,middle,right);
	}
	
}

void merge(int arr[], int left, int middle, int right) {

	int lsize = middle - left + 1;
	int rsize = right - middle;
	int Left[lsize];
	int Right[rsize];
	int i;
	for ( i = 0; i < lsize; i++) {

		Left[i] = arr[left + i];

	}
	int j;
	for ( j = 0; j < rsize; j++) {

		Right[j] = arr[middle + 1 + j];

	}

	i = 0; j = 0;
	int org=left;
	while (i<lsize && j<rsize) {
		if (Left[i] <= Right[j]) {

			arr[org] = Left[i];
			i++;
		}
		else {
			arr[org] = Right[j];
			j++;
		}
		org++;
			
	}
	while (i < lsize) {
		arr[org] = Left[i];
		i++; 
		org++;
	}
	while (j < rsize) {
		arr[org] = Right[j];
		j++;
		org++;

	}
}

	void mergeSort(int arr[], int left, int right) {
		
	if (left<right) {

		int middle = (left + right) / 2; 
		mergeSort(arr,left,middle );
		mergeSort(arr,middle+1,right );
		merge(arr,left,middle,right);
	}
}
//Homework 2//
//-->>

    int partitionName(char arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i = (low - 1);  
 
    for (int j = low; j <= high- 1; j++)
    {
        
        if (arr[j] <= pivot)
        {
            i++;    
            swapChar(&arr[i], &arr[j]);
        }
    }
    swapChar(&arr[i + 1], &arr[high]);
 
    return (i + 1);
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i = (low - 1);  
 
    for (int j = low; j <= high- 1; j++)
    {
        
        if (arr[j] <= pivot)
        {
            i++;    
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
 
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

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

    void heapifyName(char arr[], int size, int i)
{
	int largest = i;
	int leftchild = 2*i+1;
	int rightchild = 2*i+2;
	
	if(arr[leftchild] > arr[largest] && leftchild < size)
	    largest = leftchild;
	if(arr[rightchild] > arr[largest] && rightchild < size)
	    largest = rightchild;
		
	if(largest != i)
	{
		swapChar(&arr[i], &arr[largest]);
		heapifyName(arr, size, largest);
	}
	    	    
}

void heapify(int arr[], int size, int i)
{
	int largest = i;
	int leftchild = 2*i+1;
	int rightchild = 2*i+2;
	
	if(arr[leftchild] > arr[largest] && leftchild < size)
	    largest = leftchild;
	if(arr[rightchild] > arr[largest] && rightchild < size)
	    largest = rightchild;
		
	if(largest != i)
	{
		swap(&arr[i], &arr[largest]);
		heapify(arr, size, largest);
	}
	    	    
}

void heapSortName(char arr[], int size)
{
	for(int i = size/2-1; i>=0; i--)
		heapifyName(arr, size, i);
	for(int i = size-1; i>0 ; i--)
	{
		swapChar(&arr[0], &arr[i]);
		heapifyName(arr, i, 0);
	}	
	
}

void heapSort(int arr[], int size)
{
	for(int i = size/2-1; i>=0; i--)
		heapify(arr, size, i);
	for(int i = size-1; i>0 ; i--)
	{
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}	
	
}
//--<<

void printArray(int arr[],int size){

	for ( int i = 0; i < size; i++) {
		printf("%3d", arr[i]);
	}

}

int main()
{ 

     clock_t start, end;
     double result;

     // bubble sort for number
     printf("bubble sort\n");
     int arr1[] = { 2,0,1,9,5,5,5,0,1,8 };
	 int size1 = sizeof(arr1) / sizeof(arr1[0]);

     start= clock();
	 bubbleSort(arr1,size1);
	 end= clock();
	 result = (double)(end - start) / CLOCKS_PER_SEC;

	 printArray(arr1,size1);
	 printf("\nTimeNum = %f\n", result);
     
     //bubble sort for name
	 char name1[]= "caner cetin";
	 int sizeName1= strlen(name1);

	  start= clock();
	 bubbleSortName(name1,sizeName1);
	  end= clock();
      result = (double)(end - start) / CLOCKS_PER_SEC;

	 printf("%s\n", name1);
     printf("TimeName = %f\n", result);

     //insertion sort number 
     printf("insertion sort\n");
     int arr2[] = { 2,0,1,9,5,5,5,0,1,8 };
	 int size2 = sizeof(arr2) / sizeof(arr2[0]);

     start= clock();
	 bubbleSort(arr2,size2);
	 end= clock();
	 result = (double)(end - start) / CLOCKS_PER_SEC;

	 printArray(arr2,size2);
	 printf("\nTimeNum = %f\n", result);

     //insertion sort for name
     char name2[]= "caner cetin";
	 int sizeName2= strlen(name2);

	  start= clock();
	 insertionSortName(name2,sizeName2);
	  end= clock();
      result = (double)(end - start) / CLOCKS_PER_SEC;

	 printf("%s\n", name2);
     printf("TimeName = %f\n", result);

     // selection sort for number
     printf("selection sort\n");
     int arr3[] = { 2,0,1,9,5,5,5,0,1,8 };
	 int size3 = sizeof(arr3) / sizeof(arr3[0]);

     start= clock();
	 bubbleSort(arr3,size3);
	 end= clock();
	 result = (double)(end - start) / CLOCKS_PER_SEC;

	 printArray(arr3,size3);
	 printf("\nTimeNum = %f\n", result);

     //selection sort for name
     char name3[]= "caner cetin";
	 int sizeName3= strlen(name3);

	  start= clock();
	 insertionSortName(name3,sizeName3);
	  end= clock();
      result = (double)(end - start) / CLOCKS_PER_SEC;

	 printf("%s\n", name3);
     printf("TimeName = %lf\n", result);
      
      // merge sort for number
       printf("merge sort\n");
     int arr4[] = { 2,0,1,9,5,5,5,0,1,8 };
	 int size4 = sizeof(arr4) / sizeof(arr4[0]);

     start= clock();
	 bubbleSort(arr4,size4);
	 end= clock();
	 result = (double)(end - start) / CLOCKS_PER_SEC;

	 printArray(arr4,size4);
	 printf("\nTimeNum = %f\n", result);


     // merge sort for name
     char name4[]= "caner cetin";
	 int sizeName4= strlen(name4);

	  start= clock();
	 mergeSortName(name4,0,sizeName4-1);
	  end= clock();
      result = (double)(end - start) / CLOCKS_PER_SEC;

	 printf("%s\n", name4);
     printf("TimeName = %f\n", result);
     
     //Homework 2
     //-->>
     	// quick sort for number
     printf("quick sort\n\n");
      int arr5[] = { 2,0,1,9,5,5,5,0,1,8 };
	  int size5 = sizeof(arr5) / sizeof(arr5[0]);
	  
	 start= clock();
	 quickSort(arr5, 0, size5-1);
	 end= clock();
	 result = (double)(end - start) / CLOCKS_PER_SEC;
     
     printArray(arr5,size5);
	 printf("\nTimeNum = %f\n", result);
	 
	 // quick sort for name
       char name5[]= "caner cetin";
	   int sizeName5= strlen(name5);
    
	 start= clock();
	 quickSortName(name5, 0, sizeName5-1);
	 end= clock();
     result = (double)(end - start) / CLOCKS_PER_SEC;

	 printf("%s\n", name5);
     printf("TimeName = %f\n", result);
     
     	// heap sort for number
     printf("heap sort\n\n");
      int arr6[] = { 2,0,1,9,5,5,5,0,1,8 };
	  int size6 = sizeof(arr6) / sizeof(arr6[0]);
	  
	 start= clock();
	 heapSort(arr6, size6);
	 end= clock();
	 result = (double)(end - start) / CLOCKS_PER_SEC;
     
     printArray(arr6,size6);
	 printf("\nTimeNum = %f\n", result);
	 
	 // heap sort for name
	 char name6[]= "caner cetin";
	 int sizeName6= strlen(name6);

	  start= clock();
	  heapSortName(name6,sizeName6);
	  end= clock();
      result = (double)(end - start) / CLOCKS_PER_SEC;

	 printf("%s\n", name6);
     printf("TimeName = %f\n", result);
     //--<<
     

	 return 0;
  
}
