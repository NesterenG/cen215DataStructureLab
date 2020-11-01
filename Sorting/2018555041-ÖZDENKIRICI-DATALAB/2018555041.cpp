#include <math.h> 
#include <stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void printArray1(char arr[],int n){
   for(char i=0;i<n;++i){
   	printf("%c\t",arr[i]);
   }
   printf("\n");	
}
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void swap1(char* xp, char* yp)
{
    char temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// -----MERGE SORT Number-----//
void merge(int arr[], int l, int m, int r)
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

    while (j < n2) {
        arr[k] = R[j];
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


void printArray2(int arr[], int arr_size)
{
    int i;
    for (i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
//MergeSort String//
void merge1(char arr[], char l, char m, char r)
{
    char i, j, k;
    char n1 = m - l + 1;
    char n2 = r - m;

    char L[n1], R[n2];

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

void mergeSort1(char arr[], char l, char r)
{
    if (l < r) {
       
        char m = l + (r - l) / 2;

        
        mergeSort1(arr, l, m);
        mergeSort1(arr, m + 1, r);

        merge1(arr, l, m, r);
    }
}


// -----INSERTION SORT Number-----//
void insertionSort(int arr[], int n)
{

    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    
}
//InsertionSORT String//
void insertionSort1(char arr[], int n)
{
    char i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
// -----SELECTION SORT Number-----//

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
        for (i = 0; i < n - 1; i++)
    {
     
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        
        swap(&arr[min_idx], &arr[i]);
    }
}
//SelectionSORT String//
void selectionSort1(char arr[], int n)
{
   char i, j, min_idx;
        for (i = 0; i < n - 1; i++)
    {
     
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        
        swap1(&arr[min_idx], &arr[i]);
    }
}
// -----BUBBLE SORT Number-----//
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}
//BubbleSort String//
void bubbleSort1(char arr[], int n)
{
    char i, j;
    for (i = 0; i < n - 1; i++)

        
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap1(&arr[j], &arr[j + 1]);
}
//HeapSORT Number//


void heapify(int arr[], int n, int i) 
{ 
    int largest = i;  
    int l = 2*i + 1; 
    int r = 2*i + 2;  
  
    
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
  
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    
    if (largest != i) 
    { 
        swap(&arr[i], &arr[largest]); 
  
     
        heapify(arr, n, largest); 
    } 
} 
  
 
void heapSort(int arr[], int n) 
{ 
    
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    
    for (int i=n-1; i>0; i--) 
    { 
        
        swap(&arr[0], &arr[i]); 
  
        
        heapify(arr, i, 0); 
    } 
}
//HeapSORT String
void heapify1(char arr[], int n, int i) 
{ 
    int largest = i;  
    int l = 2*i + 1; 
    int r = 2*i + 2;  
  
    
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
  
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    
    if (largest != i) 
    { 
        swap1(&arr[i], &arr[largest]); 
  
     
        heapify1(arr, n, largest); 
    } 
} 
  
 
void heapSort1(char arr[], int n) 
{ 
    
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify1(arr, n, i); 
  
    
    for (int i=n-1; i>0; i--) 
    { 
        
        swap1(&arr[0], &arr[i]); 
  
        
        heapify1(arr, i, 0); 
    } 
}
//QUICKSORT NUMBER//
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];   
    int i = (low - 1);  
  
    for (int j = low; j <= high- 1; j++) 
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
  

void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
      
        int pi = partition(arr, low, high); 
  
        
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
//QUICKSORT STRING//
int partition (char arr[], int low, int high) 
{ 
    int pivot = arr[high];   
    int i = (low - 1);  
  
    for (int j = low; j <= high- 1; j++) 
    { 
         
        if (arr[j] < pivot) 
        { 
            i++;     
            swap1(&arr[i], &arr[j]); 
        } 
    } 
    swap1(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  

void quickSort1(char arr[], int low, int high) 
{ 
    if (low < high) 
    { 
      
        int pi = partition(arr, low, high); 
  
        
        quickSort1(arr, low, pi - 1); 
        quickSort1(arr, pi + 1, high); 
    } 
}



int main()
{

    int arr[] = { 2,0,1,8,5,5,5,0,4,1 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    char name[]="OZDENKIRICI";
    
    clock_t start=clock();
    insertionSort(arr, arr_size);
    printf("Insertion Sort: ");
    printArray(arr, arr_size);
    insertionSort1(name,12);
    printf("Insertion Sort: ");
	printArray1(name,12);
	clock_t stop=clock();
	double elapsed=(double)(stop-start)/CLOCKS_PER_SEC;
	printf("\n Time in ms:%f\n",elapsed);
   
    clock_t start1=clock();
    selectionSort(arr, arr_size);
    printf("Selection Sort: ");
    printArray(arr, arr_size);
   	selectionSort1(name,12);
   	printf("Selection Sort:");
	printArray1(name,12);
	clock_t stop1=clock();
	double elapsed1=(double)(stop1-start1)/CLOCKS_PER_SEC;
	printf("\n Time in ms:%f\n",elapsed1);
	
	clock_t start2=clock();
    bubbleSort(arr, arr_size);
    printf("Bubble Sort:    ");
    printArray(arr, arr_size);
    bubbleSort1(name,12);
    printf("Bubble Sort:   ");
	printArray1(name,12);
	clock_t stop2=clock();
	double elapsed2=(double)(stop2-start2)/CLOCKS_PER_SEC;
	printf("\n Time in ms:%f\n",elapsed2);
    
    clock_t start3=clock();
    mergeSort(arr, 0, arr_size - 1);
    printf("Merge Sort:     ");
    printArray2(arr, arr_size);
   	mergeSort1(name,0,11);
   	printf("Merge Sort:    ");
	printArray1(name,12);
	clock_t stop3=clock();
	double elapsed3=(double)(stop3-start3)/CLOCKS_PER_SEC;
	printf("\n Time in ms:%f\n",elapsed3);
    
     clock_t start4=clock();
    heapSort(arr,arr_size);
    printf("Heap Sort:     ");
    printArray(arr,arr_size);
    heapSort1(name,12);
    printf("Heap Sort:   ");
    printArray1(name,12);
    clock_t stop4=clock();
    double elapsed4=(double)(stop4-start4)/CLOCKS_PER_SEC;
    printf("\n Time in ms:%f\n",elapsed4);
    
    clock_t start5=clock();
    quickSort(arr,0,arr_size-1);
    printf("Quick Sort:    ");
    printArray(arr,arr_size);
    quickSort1(name,0,11);
    printf("Quick Sort:   ");
    printArray1(name,12);
    clock_t stop5=clock();
    double elapsed5=(double)(stop5-start5)/CLOCKS_PER_SEC;
    printf("\n Time in ms:%f\n",elapsed5);
    return 0;
}





