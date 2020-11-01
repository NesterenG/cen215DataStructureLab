#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


void printArray(int array[], int n)
{
    int i;
    for (i = 0; i < n; i++){
        printf("%d ", array[i]);
    }
     printf("\n");
}
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void swap_char(char *xp, char *yp)
{
    char temp = *xp;
    *xp = *yp;
    *yp = temp;
}
//ÝNSERTÝON SORT
void InsertionSort(int array[], int n)
{
    int i, k, j;
    for (i = 1; i < n; i++) {
        k = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > k) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = k;
    }
}
void InsertionSort_char(char array[], int n)
{
    int i, j;
    char k;
    for(i = 1; i < n; i++) {
        k = array[i];
        j = i - 1;
        while(j >= 0 && array[j] > k) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = k;
    }
}

//SELECTÝON SORT

void SelectionSort(int arr[], int n)
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

void SelectionSort_char(char array[], int n)
{
    int i, j;
    char min;
    for (i = 0; i < n-1; i++)
    {
        min = i;
        for (j = i+1; j < n; j++)
          if (array[j] < array[min])
            min = j;
        swap_char(&array[min], &array[i]);
    }
}

// BUBBLE SORT

void BubbleSort(int array[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)
       for (j = 0; j < n-i-1; j++)
           if (array[j] > array[j+1])
              swap(&array[j], &array[j+1]);
}

void BubbleSort_char(char array[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)
       for (j = 0; j < n-i-1; j++)
           if (array[j] > array[j+1])
               swap_char(&array[j], &array[j+1]);
}

// MERGE SORT

void Merge(int array[], int l, int m, int r)
{
    int i, j, k, n1, n2;
    n1 = m - l + 1;
    n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (j = 0; j < n2; j++)
        R[j] = array[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        }
        else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int array[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        MergeSort(array, l, m);
        
        MergeSort(array, m + 1, r);

        Merge(array, l, m, r);
    }
}

void Merge_char(char arr[], int x, int y, int z)
{
    int i, j, k, n1, n2;
    n1 = y - x + 1;
    n2 = z - y;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[x + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[y + 1 + j];

    i = 0;
    j = 0;
    k = x;

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


void MergeSort_char(char arr[], int x, int y)
{
    if (x < y) {
        int m = x + (y - x) / 2;

        MergeSort_char(arr, x, m);
        
        MergeSort_char(arr, m + 1, y);

        Merge_char(arr, x, m, y);
    }
}

// QUICK SORT
void QuickSort(int array[],int first,int last){
    int i; 
    int j; 
    int pivot; 
    char temp; 
    pivot=first; 
   
    
    if(last>first){
        pivot=first;
        i=first;
        j=last;
        while (i<j){
            while (array[i]<=array[pivot] && i<last && j>i){ 
                i++;
            }
            while (array[j]>=array[pivot] && j>=first && j>=i){
                j--;
            }
            if (j>i){ 
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
       
        temp=array[j];
        array[j]=array[pivot];
        array[pivot]=temp;
        QuickSort(array,first,j-1);
        QuickSort(array,j+1,last);
    }
}
void QuickSort_char(char array[],char first,char last){
    int i; 
    int j; 
    char pivot; 
    int temp; 
    pivot=first; 
   
    
    if(last>first){
        pivot=first;
        i=first;
        j=last;
        while (i<j){
            while (array[i]<=array[pivot] && i<last && j>i){ 
                i++;
            }
            while (array[j]>=array[pivot] && j>=first && j>=i){
                j--;
            }
            if (j>i){ 
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
       
        temp=array[j];
        array[j]=array[pivot];
        array[pivot]=temp;
        QuickSort_char(array,first,j-1);
        QuickSort_char(array,j+1,last);
    }
}

// HEAP SORT
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

void HeapSort(int arr[], int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (i=n-1; i>=0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
      
      void heapify_char(char arr[], int n, int i)
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
        swap_char(&arr[i], &arr[largest]); 
        heapify_char(arr, n, largest); 
    }
}

void HeapSort_char(char arr[], int n)
{
	int i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify_char(arr, n, i);

    for (i=n-1; i>=0; i--)
    {
        swap_char(&arr[0], &arr[i]);
        heapify_char(arr, i, 0);
    }
}


int main() {

    printf(" OGUZHAN INANMIS - 2018555459 \n\n\n");
    
    clock_t time;

    //Ýnsertion
    int no[] = { 2, 0, 1, 8, 5, 5, 5, 4, 5, 9 };
    
    char name[] = "oguzhan inanmýis";
    
    int n = sizeof(no) / sizeof(no[0]);
    
    int char_size = strlen(name);

    time = clock();
    InsertionSort(no, n);
    time = clock() - time;
    printArray(no, n);
    printf("Insertion sort time: %f \n", ((double)time) / CLOCKS_PER_SEC);
    InsertionSort_char(name, char_size);
    time = clock() - time;
    printf("%s \n", name);
    printf("Insertion char sort time: %f\n", ((double)time) / CLOCKS_PER_SEC);

    //Selection 
    

    SelectionSort(no, n);
    time = clock() - time;
    printArray(no, n);
    printf("Selection sort time: %f \n", ((double)time) / CLOCKS_PER_SEC);

    SelectionSort_char(name, char_size);
    time = clock() - time;
    printf("%s \n", name);
    printf("Selection char sort time: %f\n", ((double)time) / CLOCKS_PER_SEC);


    //Bubble 

    BubbleSort(no, n);
    time = clock() - time;
    printArray(no, n); 
    printf("Bubble sort time: %f \n", ((double)time) / CLOCKS_PER_SEC);

    BubbleSort_char(name, char_size);
    time = clock() - time;
    printf("%s \n", name);
    printf("Bubble char sort time: %f \n", ((double)time) / CLOCKS_PER_SEC);


    //Merge 

    MergeSort(no, 0, n - 1);
    time= clock() - time;
    printArray(no, n);
    printf("Merge sort time: %f \n", ((double)time) / CLOCKS_PER_SEC);
    MergeSort_char(name, 0, char_size - 1);
    time = clock() - time;
    printf("%s \n", name);
    printf("Merge char sort time: %f\n", ((double)time) / CLOCKS_PER_SEC);
    
    //Quick 
    
      time = (double)clock();
      QuickSort(no, 0, n-1);
      time = (double)clock()-time;
      printArray(no,n);
      printf("Quick sort time: %f \n", ((double)time) / CLOCKS_PER_SEC);
      QuickSort_char(name, 0, char_size-1);
      time = (double)clock()-time;
      printf("%s \n", name);
      printf("Quick char sort time: %f\n", ((double)time) / CLOCKS_PER_SEC);
      
      //Heap
      
      time = (double)clock();
      HeapSort(no, n);
      printArray(no,n);
      printf("Heap sort time: %f \n", ((double)time) / CLOCKS_PER_SEC);
      HeapSort_char(name,char_size);
      time = (double)clock()-time;
      printf("%s \n", name);
      printf("Heap char sort time: %f\n", ((double)time) / CLOCKS_PER_SEC);

    return 0;
}
