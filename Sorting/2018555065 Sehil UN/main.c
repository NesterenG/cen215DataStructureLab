#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h>

/*
	Number : 2018555065;
	Name : Sehil ÜN;
*/

void printFunc(int array[], int n)
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

void swapChar(char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}



//Quick sort algorithm

int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = (low - 1);
    int j;
    for(j = low; j <= high - 1; j++) {
        if(array[j] < pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i+1);
}

void quickSort(int array[], int low, int high) {
    if (low < high) { 
        int part = partition(array, low, high); 

        quickSort(array, low, part - 1); 
        quickSort(array, part + 1, high); 
    } 
}

char partitionChar(char array[], int low, int high) {
    int pivot = array[high];
    int i = (low - 1);
    int j;
    for(j = low; j <= high - 1; j++) {
        if(array[j] < pivot) {
            i++;
            swapChar(&array[i], &array[j]);
        }
    }
    swapChar(&array[i + 1], &array[high]);
    return (i+1);
}

void quickSortChar(char array[], int low, int high) {
    if (low < high) { 
        int part = partitionChar(array, low, high); 

        quickSortChar(array, low, part - 1); 
        quickSortChar(array, part + 1, high); 
    } 
}

//Heap sort algorithm

void heapify(int array[], int n, int i) { 
    int largest = i;
    int l = 2*i + 1; 
    int r = 2*i + 2;

    if (l < n && array[l] > array[largest]) {
    	largest = l;
	}
 
    if (r < n && array[r] > array[largest]) {
    	largest = r; 
	}
        
    if (largest != i) { 
        swap(&array[i], &array[largest]); 
        heapify(array, n, largest); 
    } 
} 

void heapSort(int array[], int n) { 
    int i,j;
    for (i = n / 2 - 1; i >= 0; i--) {
    	heapify(array, n, i);
	}
         

    for (j=n-1; j>0; j--) { 
        swap(&array[0], &array[j]); 
        heapify(array, j, 0); 
    } 
} 

void heapifyChar(char array[], int n, int i) { 
    int largest = i;
    int l = 2*i + 1; 
    int r = 2*i + 2;

    if (l < n && array[l] > array[largest]){
    	largest = l;
	} 
         
    if (r < n && array[r] > array[largest]){
    	largest = r;
	} 
         
    if (largest != i) { 
        swapChar(&array[i], &array[largest]); 
        heapifyChar(array, n, largest); 
    } 
} 

void heapSortChar(char array[], int n) { 
    int i,j;
    for (i = n / 2 - 1; i >= 0; i--){
    	heapifyChar(array, n, i);
	} 
         
    for (j=n-1; j>0; j--) { 
        swapChar(&array[0], &array[j]); 
        heapifyChar(array, j, 0); 
    } 
} 


// Bubble Sort Algorithm
void bubbleSort(int array[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)
       for (j = 0; j < n-i-1; j++)
           if (array[j] > array[j+1])
              swap(&array[j], &array[j+1]);
}

void bubbleCharSort(char arrChar[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)
       for (j = 0; j < n-i-1; j++)
       {
           if (arrChar[j] > arrChar[j+1])
           {
               swapChar(&arrChar[j], &arrChar[j+1]);            	
		   }    	
	   }

}

//Insertion Sort
void insertionSort(int array[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) 
	{
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key)
	    {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}
void insertionCharSort(char array[], int n)
{
    int i, j;
    char key;
    for(i = 1; i < n; i++) 
	{
        key = array[i];
        j = i - 1;
        while(j >= 0 && array[j] > key) 
		{
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

//Selection Algorithm
void selectionSort(int arr[], int n)
{
    int i, j, min;
    for (i = 0; i < n-1; i++)
    {
        min = i;
        for (j = i+1; j < n; j++)
        {
          if (arr[j] < arr[min])
          {
            min = j;            	
		  }    	      	
		}          
        swap(&arr[min], &arr[i]);
    }
}

void selectionCharSort(char arrChar[], int n)
{
    int i, j;
    char min;
    for (i = 0; i < n-1; i++)
    {
        min = i;
        for (j = i+1; j < n; j++)
        {
          if (arrChar[j] < arrChar[min])
          {
            min = j;            	
		  }    	      	
		}
        swapChar(&arrChar[min], &arrChar[i]);
    }
}

// merge sort algorithm
void mergeFunc(int array[], int l, int m, int r)
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

void mergeSort(int array[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
 
        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);
 
        mergeFunc(array, l, m, r);
    }
}
 
void mergeChar(char arr[], int x, int y, int z)
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

void mergeCharSort(char arr[], int x, int y)
{
    if (x < y) {
        int m = x + (y - x) / 2;
 
        mergeCharSort(arr, x, m);
        mergeCharSort(arr, m + 1, y);
 
        mergeChar(arr, x, m, y);
    }
}



int main() {
	
	printf("Number : 2018555065 \nName : Sehil UN \n");
 
 	int number[] = { 2, 0, 1, 8, 5, 5, 5, 0, 6, 5};
    char name[] = "SEHIL UN";
    int n = sizeof(number) / sizeof(number[0]);
    int char_size = strlen(name);

    clock_t time;
    
    
    //Bubble Sort
  
    bubbleSort(number, n);
    time = clock() - time;
    printf("\n*****Bubble Sorts***** \n");
    printFunc(number, n);
    printf("Bubble Sort Time: %f\n", ((double)time) / CLOCKS_PER_SEC);

    bubbleCharSort(name, char_size);
    time = clock() - time;
    printf("%s\n", name);
    printf("Bubble Char Sort Time: %f\n", ((double)time) / CLOCKS_PER_SEC);
    printf("----------------------------------------------------------------");


    //Insertion Sort
    

    time = clock();
    insertionSort(number, n);
    time = clock() - time;
    printf("\n*****Insertion Sorts***** \n");
    printFunc(number, n);
    printf("Insertion Sort Time: %f\n", ((double)time) / CLOCKS_PER_SEC);
    insertionCharSort(name, char_size);
    time = clock() - time;
    printf("\n");
    printf("%s\n", name);
    printf("Insertion Char Sort Time: %f\n", ((double)time) / CLOCKS_PER_SEC);
    printf("---------------------------------------------------------------");


    //Selection Sort    
    selectionSort(number, n);
    time = clock() - time;
    printf("\n*****Selection Sorts***** \n");
    printFunc(number, n);
    printf("Selection Sort Time: %f\n", ((double)time) / CLOCKS_PER_SEC);
    
    selectionCharSort(name, char_size);
    time = clock() - time;
    printf("%s\n", name);
    printf("Selection Char Sort Time: %f\n", ((double)time) / CLOCKS_PER_SEC);
    printf("----------------------------------------------------------------");


    //Merge Sort
   
    mergeSort(number, 0, n - 1);
    time= clock() - time;
    printf("\n*****Merge Sorts***** \n");
    printFunc(number, n);
    printf("Merge Sort Time: %f\n", ((double)time) / CLOCKS_PER_SEC);
    mergeCharSort(name, 0, char_size - 1);
    time = clock() - time;
    printf("%s\n", name);
    printf("Merge Char Sort Time: %f\n", ((double)time) / CLOCKS_PER_SEC);
    printf("----------------------------------------------------------------");
   
    
     // Quick Sort

    quickSort(number, 0, n - 1);
    time = clock() - time;
    printf("\n*****Quick Sorts***** \n");
    printFunc(number, n); 
    printf("Quick Sort Time: %f\n", ((double)time) / CLOCKS_PER_SEC);
    quickSortChar(name, 0, char_size - 1);
    time = clock() - time;
    printf("%s\n", name);
    printf("Quick Char Sort Time: %f\n", ((double)time) / CLOCKS_PER_SEC);
    printf("----------------------------------------------------------------");


    //Heap Sort

    heapSort(number, n);
    time = clock() - time;
    printf("\n*****Heap Sorts***** \n");    
    printFunc(number, n); 
    printf("Heap Sort Time: %f\n", ((double)time) / CLOCKS_PER_SEC);
    heapSortChar(name, char_size);
    time = clock() - time;
    printf("%s\n", name);
    printf("Heap Char sort Time: %f\n", ((double)time) / CLOCKS_PER_SEC);

    
    return 0;
}
