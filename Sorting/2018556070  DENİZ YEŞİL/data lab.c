// DENIZ YESIL    2018556070



#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h>


void printArray(int array[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}




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




void insertionSortChar(char arr[], int n)
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

void swap(int* dy, int* yd)
{
    int temp = *dy;
    *dy = *yd;
    *yd = temp;
}

void swapChar(char* dy, char* yd)
{
    char temp = *dy;
    *dy = *yd;
    *yd = temp;
}




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




void selectionSortChar(char arr[], int n)
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




void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}




void bubbleSortChar(char arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swapChar(&arr[j], &arr[j + 1]);
}




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

void mergeChar(char arr[], int l, int m, int r)
{
    int i, j, k;
    int n1, n2;
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



int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    int j;
    for ( j = low; j <= high- 1; j++)
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


void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}



    int partitionChar(char arr[], int low, int high)
    {
        int pivot = arr[high];
        int i = (low - 1);
        int j;
        for ( j = low; j <= high- 1; j++)
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


    void quickSortChar(char arr[], int low, int high)
    {
        if (low < high)
        {
            int pi = partitionChar(arr, low, high);
            quickSortChar(arr, low, pi - 1);
            quickSortChar(arr, pi + 1, high);
        }
    }


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
		
        

        for (int i=n-1; i>=0; i--)
        {
            swap(&arr[0], &arr[i]);
            heapify(arr, i, 0);
        }
    }


    void heapifyChar(char arr[], int n, int i)
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
            swapChar(&arr[i], &arr[largest]);
            heapifyChar(arr, n, largest);
        }
    }


    void heapSortChar(char arr[], int n)
    {
        for (int i = n / 2 - 1; i >= 0; i--)
            heapifyChar(arr, n, i);

        for (int i=n-1; i>=0; i--)
        {
            swapChar(&arr[0], &arr[i]);
            heapifyChar(arr, i, 0);
        }
    }



int main()
{

    printf("Name: Deniz Yesil, Number: 2018556070\n\n");
    int number[] = { 2,0,1,8,5,5,6,0,7,0 };
    char name[] = "Deniz Yesil";
    int numSize = sizeof(number) / sizeof(number[0]);
    int nameSize = strlen(name);
    clock_t start, end;
    double totaltime;

   

    start = clock();
    insertionSort(number, numSize);
    end = clock();
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;

  
    printf("\nInsertion sort for number array : ");
    printArray(number, numSize);
    printf("Time for insertion sort integer array : %f", totaltime);

  
    start = clock();
    insertionSortChar(name, nameSize);
    end = clock();
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;

   
    printf("\nInsertion sort for name array : ");
    printf("%s", name);
    printf("\nTime for insertion sort char array : %f\n", totaltime);
    printf("/////////////////////////////////////////////////////");
   
   
   
    int number2[] = { 2,0,1,8,5,5,6,0,7,0 };
    char name2[] = "Deniz Yesil";

    start = clock();
    selectionSort(number2, numSize);
    end = clock();
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;

  
    printf("\nSelection sort for number array : ");
    printArray(number2, numSize);
    printf("Time for selection sort with int array : %f", totaltime);

   
    start = clock();
    selectionSortChar(name2, nameSize);
    end = clock();
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;

 
    printf("\nSelection sort for name array : ");
    printf("%s", name2);
    printf("\nTime for selection sort with char array : %f\n", totaltime);

    printf("///////////////////////////////////////////////////////");
  

  
    int number3[] = { 2,0,1,8,5,5,6,0,7,0 };
    char name3[] = "Deniz Yesil";

    start = clock();
    bubbleSort(number3, numSize);
    end = clock();
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;

   
    printf("\nBubble sort for number array : ");
    printArray(number3, numSize);
    printf("Time for bubble sort with int array : %f\n", totaltime);

  
    start = clock();
    bubbleSortChar(name3, nameSize);
    end = clock();
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;

 
    printf("Bubble sort for name array : ");
    printf("%s\n", name3);
    printf("Time for bubble sort with char array : %f\n", totaltime);
    printf("/////////////////////////////////////////////////////////");
   
   
   
    int number4[] = { 2,0,1,8,5,5,6,0,7,0};
    char name4[] = "Deniz Yesil";

  
    start = clock();
    mergeSort(number4, 0, numSize - 1);
    end = clock();
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;

  
    printf("\nMerge sort for int array : ");
    printArray(number4, numSize);
    printf("Time for merge sort with int array : %f", totaltime);

  
    start = clock();
    mergeSortChar(name4, 0, nameSize - 1);
    end = clock();
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;

 
    printf("\nMerge sort for name array : ");
    printf("%s", name4);
    printf("\nTime for merge sort with char array : %f", totaltime);
    printf("\n/////////////////////////////////////////////////////////");
    
    
     
    int number5[] = {2,0,1,8,5,5,6,0,7,0};
    char name5[] = "Deniz Yesil";

    start = clock();
    quickSort(number5, 0, numSize - 1);
    end = clock();
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nQuick sort for int array : ");
    printArray(number5, numSize);
    printf("Time for quick sort with int array : %f", totaltime);

    start = clock();
    quickSortChar(name5, 0, nameSize - 1);
    end = clock();
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nQuick sort for name array : ");
    printf("%s", name5);
    printf("\nTime for quick sort with char array : %f", totaltime);
    printf("\n////////////////////////////////////////////////");
    
    
    int number6[] = {2,0,1,8,5,5,6,0,7,0};
    char name6[] = "Deniz Yesil";

    start = clock();
    heapSort(number6, numSize );
    end = clock();
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nHeap sort for int array : ");
    printArray(number6, numSize);
    printf("Time for heap sort with int array : %f", totaltime);

    start = clock();
    heapSortChar(name6, nameSize );
    end = clock();
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nHeap sort for name array : ");
    printf("%s", name6);
    printf("\nTime for heap sort with char array : %f", totaltime);


    return 0;
} 
