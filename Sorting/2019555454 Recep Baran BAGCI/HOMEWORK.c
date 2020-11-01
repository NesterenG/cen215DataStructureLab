#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h>

void printArray(int array[], int n)
{
    int i;
    for (i = 0; i < n; i++){
        printf("%d ", array[i]);
    }
     printf("\n");
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_char(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

//INSERTION SORT
void insertion_sort(int array[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}
void insertion_sort_char(char array[], int n)
{
    int i, j;
    char key;
    for(i = 1; i < n; i++) {
        key = array[i];
        j = i - 1;
        while(j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

//SELECTION SORT
void selection_sort(int arr[], int n)
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

void selection_sort_char(char array[], int n)
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
//BUBBLE SORT
void bubble_sort(int array[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)
       for (j = 0; j < n-i-1; j++)
           if (array[j] > array[j+1])
              swap(&array[j], &array[j+1]);
}

void bubble_sort_char(char array[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)
       for (j = 0; j < n-i-1; j++)
           if (array[j] > array[j+1])
               swap_char(&array[j], &array[j+1]);
}
//MERGE SORT
void merge(int array[], int l, int m, int r)
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

void merge_sort(int array[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
 
        merge_sort(array, l, m);
        merge_sort(array, m + 1, r);
 
        merge(array, l, m, r);
    }
}
 
void merge_char(char arr[], int x, int y, int z)
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

void merge_sort_char(char arr[], int x, int y)
{
    if (x < y) {
        int m = x + (y - x) / 2;
 
        merge_sort_char(arr, x, m);
        merge_sort_char(arr, m + 1, y);
 
        merge_char(arr, x, m, y);
    }
}

//QUICK SORT
void quickSort(int *array,int first,int last){
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
        quickSort(array,first,j-1);
        quickSort(array,j+1,last);
    }
}
void quickSortChar(char *array,char first,char last){
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
        quickSort(array,first,j-1);
        quickSort(array,j+1,last);
    }
}

//HEAP SORT

void heapSort (int *x, int size)
{
   int  left, right, temp;
 
   if (size <= 1)
      return;
   left = size / 2;
   right = size - 1;
 
   while (--left >= 0)
      heapify(x, left, right);
 
   for (;;) {
      temp = x[0];
      x[0] = x[right];
      x[right] = temp;
      if (--right <= 0)
         break;
      heapify(x, 0, right);
   }
}


void heapify(int *x, int left, int right)
{
   int temp, i;
 
   i = left +left +1;
    temp = x[left];
 
   do {
      if (i < right && x[i] < x[i+1])
         i++;
      if (temp >= x[i])
         break;
      x[left] = x[i];
      left = i;
      i = 2 * i + 1;
   } while (i <= right);
   x[left] = temp;
}
void heapSortChar (char *x, int size)
{
   int  left, right, temp;
 
   if (size <= 1)
      return;
   left = size / 2;
   right = size - 1;
 
   while (--left >= 0)
      heapify(x, left, right);
 
   for (;;) {
      temp = x[0];
      x[0] = x[right];
      x[right] = temp;
      if (--right <= 0)
         break;
      heapify(x, 0, right);
   }
}


int main() {
 
    clock_t time;

    int ogr_no[] = { 2, 0, 1, 9, 5, 5, 5, 4, 5, 4};
    char name[] = "RECEP BARAN BAGCI";
    int n = sizeof(ogr_no) / sizeof(ogr_no[0]);
    int char_size = strlen(name);
    
    

    time = clock();
    
	//INSERTION SORT
	
	insertion_sort(ogr_no, n);
    time = clock() - time;
    printArray(ogr_no, n);
    printf("INSERTION SORT NUMBER TIME: %f\n", ((double)time) / CLOCKS_PER_SEC);
    insertion_sort_char(name, char_size);
    time = clock() - time;
    printf("%s\n", name);
    printf("INSERTION SORT NAME TIME: %f\n", ((double)time) / CLOCKS_PER_SEC);

    //SELECTION SORT
    
    selection_sort(ogr_no, n);
    time = clock() - time;
    printArray(ogr_no, n);
    printf("SELECTION SORT NUMBER TIME: %f\n", ((double)time) / CLOCKS_PER_SEC);
    
    selection_sort_char(name, char_size);
    time = clock() - time;
    printf("%s\n", name);
    printf("SELECTION SORT NAME TIME: %f\n", ((double)time) / CLOCKS_PER_SEC);


    //BUBBLE SORT
  


    bubble_sort(ogr_no, n);
    time = clock() - time;
    printArray(ogr_no, n);
    printf("BUBBLE SORT NUMBER TIME: %f\n", ((double)time) / CLOCKS_PER_SEC);

    bubble_sort_char(name, char_size);
    time = clock() - time;
    printf("%s\n", name);
    printf("BUBBLE SORT NAME TIME: %f\n", ((double)time) / CLOCKS_PER_SEC);

    
    //MERGE SORT


    
    merge_sort(ogr_no, 0, n - 1);
    time= clock() - time;
    printArray(ogr_no, n);
    printf("MERGE SORT NUMBER TIME: %f\n", ((double)time) / CLOCKS_PER_SEC);
    merge_sort_char(name, 0, char_size - 1);
    time = clock() - time;
    printf("%s\n", name);
    printf("MERGE SORT NAME TIME: %f\n", ((double)time) / CLOCKS_PER_SEC);
    
    //QUICK SORT
    quickSort(ogr_no,0,n-1);
    time = clock() - time;
    printArray(ogr_no, n);
    printf("QUICK SORT NUMBER TIME: %f\n", ((double)time) / CLOCKS_PER_SEC);
    quickSortChar(name,0,char_size-99);
    time = clock() - time;
    printf("%s\n", name);
    printf("QUICK SORT NAME TIME: %f\n", ((double)time) / CLOCKS_PER_SEC);   
   
    //HEAP SORT
	
    heapSort(ogr_no, n);
    time = clock() - time;
    printArray(ogr_no, n);
    printf("HEAP SORT NUMBER TIME: %f\n", ((double)time) / CLOCKS_PER_SEC);
    heapSortChar(name,0);
    time = clock() - time;
    printf("%s\n", name);
    printf("HEAP SORT NAME TIME: %f\n", ((double)time) / CLOCKS_PER_SEC); 

    printf("\n NAME: RECEP BARAN BAGCI \n NUM : 2019555454");
    return 0;
}

