#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h>

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
// Char array insertion sort

void InsertionSort(char arr[], int n)
{
    int i, j;
    char key;
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
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void swapChar(char* xp, char* yp)
{
    char temp = *xp;
    *xp = *yp;
    *yp = temp;
}

//Selection Algorithm
void selectionSort(int arr[], int n)
{
    int i, j, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;
        swap(&arr[min], &arr[i]);

    }
}

void SelectionSort(char arr[], int n)
{
    int i, j;
    char min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;
        swapChar(&arr[min], &arr[i]);
    }
}
// Bubble Sort Algorithm
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void BubbleSort(char arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swapChar(&arr[j], &arr[j + 1]);
}
// Merge sort algorithm
void merge(int arr[], int l, int m, int r)
{
    int i, j, k, n1, n2;
    n1 = m - l + 1;
    n2 = r - m;

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

void mergeChar(char arr[], int l, int m, int r)
{
    int i, j, k, n1, n2;
    n1 = m - l + 1;
    n2 = r - m;

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

void mergeSortChar(char arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSortChar(arr, l, m);
        mergeSortChar(arr, m + 1, r);

        mergeChar(arr, l, m, r);
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


void quicksort(int* arr, int left, int right) {
    int low;
    int high;
    int pivot;
    pivot = left;


    if (right > right) {
        pivot = left;
        low = left;
        high = right;
        while (low < high) {
            while (arr[low] <= arr[pivot] && low<right && high>low) {
                low++;
            }
            while (arr[high] >= arr[pivot] && high >= left && high >= low) {
                high--;
            }
            if (high > low) {
                swap(&arr[low], &arr[high]);
            }
        }

        swap(&arr[low], &arr[pivot]);
        quicksort(arr, left, high - 1);
        quicksort(arr, high + 1, right);
    }
}
void quicksortchar(char* array, char left, char right) {
    int low;
    int high;
    char pivot;
    pivot = left;


    if (right > left) {
        pivot = left;
        low = left;
        high = right;
        while (low < high) {
            while (array[low] <= array[pivot] && low<right && high>low) {
                low++;
            }
            while (array[high] >= array[pivot] && high >= left && high >= low) {
                high--;
            }
            if (high > low) {
                swapChar(&array[low], &array[high]);
            }
        }

        swapChar(&array[low], &array[pivot]);
        quicksortchar(array, left, high - 1);
        quicksortchar(array, high + 1, right);
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n) {
    int s, k;
    for (s = n / 2 - 1; s >= 0; s--)
        heapify(arr, n, s);

    for (k = n - 1; k > 0; k--) {
        swap(&arr[0], &arr[k]);
        heapify(arr, k, 0);
    }
}

void heapifychar(char arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swapChar(&arr[i], &arr[largest]);
        heapifychar(arr, n, largest);
    }
}

void heapsortchar(char arr[], int n) {
    int i, j;
    for (i = n / 2 - 1; i >= 0; i--)
        heapifychar(arr, n, i);

    for (j = n - 1; j > 0; j--) {
        swapChar(&arr[0], &arr[j]);
        heapifychar(arr, j, 0);
    }
}


int main() {
    clock_t x;
    x = clock();

    int ID = 2018556301;
    int number[] = { 2,0,1,8,5,5,6,3,0,1 };
    int size = sizeof(number) / sizeof(number[0]);
    char name[] = "Muhammed Nur Aldin Halubi";
    int len = strlen(name);

    printf("My ID: %d\n", ID);
    printf("My Name: %s\n", name);

    printf("InsertionSort");
    printf("\n");
    insertionSort(number, size);
    printArray(number, size);
    InsertionSort(name, len);
    printf("%s\n", name);
    printf("%f", (float)x / CLOCKS_PER_SEC);

    x = clock() - x;
    printf("\n\n");

    printf("SelecetionSort");
    printf("\n");
    selectionSort(number, size);
    printArray(number, size);
    SelectionSort(name, len);
    printf("%s \n", name);
    printf("%f", (float)x / CLOCKS_PER_SEC);

    x = clock() - x;
    printf("\n\n");

    printf("BubbleSort");
    printf("\n");
    bubbleSort(number, size);
    printArray(number, size);
    BubbleSort(name, len);
    printf("%s\n", name);
    printf("%f", (float)x / CLOCKS_PER_SEC);

    x = clock() - x;
    printf("\n\n");

    printf("mergeSort");
    printf("\n");
    mergeSort(number, 0, size - 1);
    printArray(number, size);
    mergeSortChar(name, 0, len - 1);
    printf("%s\n", name);
    printf("%f", (float)x / CLOCKS_PER_SEC);

    x = clock() - x;
    printf("\n\n");

    printf("quicksort");
    printf("\n");
    quicksort(number, 0, size - 1);
    printArray(number, size);
    quicksortchar(name, 0, len - 1);
    printf("%s\n", name);
    printf("%f", (float)x / CLOCKS_PER_SEC);

    x = clock() - x;
    printf("\n\n");

    printf("heapsort");
    printf("\n");
    heapsort(number, size);
    printArray(number, size);
    heapsortchar(name, size);
    printf("%s\n", name);
    printf("%f", (float)x / CLOCKS_PER_SEC);


    return 0;
}