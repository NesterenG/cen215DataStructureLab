#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h>

//NUMBER 2018555022 NAME SURNAME:ELİF ERTEN

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

//Insertion Sort
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

//Selection Algorithm
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
// Bubble Sort Algorithm
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
// Merge sort algorithm
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
//Quick sort
int partition(int arr[], int low, int high)
{
  int pivot = arr[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++)
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

void quick_sort(int arr[], int low, int high)
{
  if (low < high)
  {
    int pi = partition(arr, low, high);

    quick_sort(arr, low, pi - 1);
      quick_sort(arr, pi + 1, high);
  }
}
char partition_char(char arr[], int low, int high)
{
  int pivot = arr[high];
  int i = (low - 1);
  for (int j = low; j <= high - 1; j++)
  {
    if (arr[j] < pivot)
    {
      i++;
      swap_char(&arr[i], &arr[j]);
    }
  }
    swap_char(&arr[i + 1], &arr[high]);
  return (i + 1);
}
void quick_sort_char(char arr[], int low, int high)
{
  if (low < high)
  {
    int pIndex = partition_char(arr, low, high);

    quick_sort_char(arr, low, pIndex - 1);
    quick_sort_char(arr, pIndex + 1, high);
  }
}

void heap(int arr[], int n, int i)
{
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < n && arr[l] > arr[largest])
    largest = l;

  if (r < n && arr[r] > arr[largest])
    largest = r;

  if (largest != i)
  {
    swap(&arr[i], &arr[largest]);
    heap(arr, n, largest);
  }
}

void heap_sort(int arr[], int n)
{
  int i, j;
  for (i = n / 2 - 1; i >= 0; i--)
  {
    heap(arr, n, i);
  }

  for (j = n - 1; j > 0; j--)
  {
    swap(&arr[0], &arr[j]);
    heap(arr, j, 0);
  }
}

void heap_char(char arr[], int n, int i)
{
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < n && arr[l] > arr[largest])
    largest = l;

  if (r < n && arr[r] > arr[largest])
    largest = r;

  if (largest != i)
  {
      swap_char(&arr[i], &arr[largest]);
      heap_char(arr, n, largest);
  }
}

void heap_sort_char(char arr[], int n)
{
  int i, j;
  for (i = n / 2 - 1; i >= 0; i--)
  {
      heap_char(arr, n, i);
  }

  for (j = n - 1; j > 0; j--)
  {
      swap_char(&arr[0], &arr[j]);
      heap_char(arr, j, 0);
  }
}
int main() {
 
    printf("NAME AND SURNAME = ELİF NUMBER = 2018555022\n\n");
    clock_t zaman1;

    //Selection Sort
    int ogrenci_no[] = { 2, 0, 1, 8, 5, 5, 5, 0, 2, 2 };
    char name[] = "elif erten";
    int n = sizeof(ogrenci_no) / sizeof(ogrenci_no[0]);
    int char_size = strlen(name);

    zaman1 = clock();
    insertion_sort(ogrenci_no, n);
    zaman1 = clock() - zaman1;
    printArray(ogrenci_no, n);
    printf("insertion sort time: %f\n", ((double)zaman1) / CLOCKS_PER_SEC);
    insertion_sort_char(name, char_size);
    zaman1 = clock() - zaman1;
    printf("%s\n", name);
    printf("insertion char sort time: %f\n", ((double)zaman1) / CLOCKS_PER_SEC);

    //Selection Sort
    
    selection_sort(ogrenci_no, n);
    zaman1 = clock() - zaman1;
    printArray(ogrenci_no, n);
    printf("selection sort time: %f\n", ((double)zaman1) / CLOCKS_PER_SEC);
    
    selection_sort_char(name, char_size);
    zaman1 = clock() - zaman1;
    printf("%s\n", name);
    printf("selection char sort time: %f\n", ((double)zaman1) / CLOCKS_PER_SEC);


    //Bubble Sort
  


    bubble_sort(ogrenci_no, n);
    zaman1 = clock() - zaman1;
    printArray(ogrenci_no, n);
    printf("bubble sort time: %f\n", ((double)zaman1) / CLOCKS_PER_SEC);

    bubble_sort_char(name, char_size);
    zaman1 = clock() - zaman1;
    printf("%s\n", name);
    printf("bubble char sort time: %f\n", ((double)zaman1) / CLOCKS_PER_SEC);


    //Merge Sort


    
    merge_sort(ogrenci_no, 0, n - 1);
    zaman1= clock() - zaman1;
    printArray(ogrenci_no, n);
    printf("merge sort time: %f\n", ((double)zaman1) / CLOCKS_PER_SEC);
    merge_sort_char(name, 0, char_size - 1);
    zaman1 = clock() - zaman1;
    printf("%s\n", name);
    printf("merge char sort time: %f\n", ((double)zaman1) / CLOCKS_PER_SEC);
    
    //QUİCK SORT
    
    printf("QUİCK SORT\n");
    quick_sort(ogrenci_no, 0, n - 1);
    zaman1 = clock()-zaman1;
    printArray(ogrenci_no, n);
    printf("quick sort  time: %f\n", (double)zaman1 / CLOCKS_PER_SEC);
    quick_sort_char(name, 0, n-1 );
    zaman1 = clock() - zaman1;
    printf("Sorted char       : %s\n", name);
    printf("quick char sort time: %f\n", (double)zaman1 / CLOCKS_PER_SEC);
     
    // Heap Sort
    printf("HEAP SORT\n");
    heap_sort(ogrenci_no, n);
    zaman1 = clock()-zaman1;
    printArray(ogrenci_no, n);
    printf("Heap sort  time: %f\n", (double)zaman1 / CLOCKS_PER_SEC);
    heap_sort_char(name, n);
    zaman1 = clock()-zaman1;
    printf("Sorted char     : %s\n", name);
    printf("Heap char  time: %f\n", (double)zaman1 / CLOCKS_PER_SEC);

    return 0;
}

