#include <stdio.h>
#include <string.h>
#include <time.h>
/*name Esra Ertsak
number 2017555021*/
void printArray(int array[], int a){
    int i ;
    for ( i = 0; i < a; i++){
    	
    	
        printf("%d ", array[i]);
    }
    
    
     printf("\n");
}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void swapChar(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}
//selection
void selectionSort(int arr[], int n){
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
void selectionSortChar(char array[], int n){
    int i, j;
    char min;
    for (i = 0; i < n-1; i++)
    {
        min = i;
        for (j = i+1; j < n; j++)
          if (array[j] < array[min])
            min = j;
        swapChar(&array[min], &array[i]);
    }
}
//insertion
void insertionSort(int array[], int n){
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
void insertionSortChar(char array[], int n){
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
// bubble
void bubbleSort(int array[], int n){
   int i, j;
   for (i = 0; i < n-1; i++)
       for (j = 0; j < n-i-1; j++)
           if (array[j] > array[j+1])
              swap(&array[j], &array[j+1]);
}
void bubbleSortChar(char array[], int n){
   int i, j;
   for (i = 0; i < n-1; i++)
       for (j = 0; j < n-i-1; j++)
           if (array[j] > array[j+1])
               swapChar(&array[j], &array[j+1]);
}
// merge
void merge(int array[], int l, int m, int r){
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
void mergeSort(int array[], int l, int r){
    if (l < r) {
    	
    	
    	
        int m = l + (r - l) / 2;
 
        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);
 
        merge(array, l, m, r);
        
        
    }
    
    
    
    
}
 
void mergeChar(char arr[], int x, int y, int z){
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
void mergeSortChar(char arr[], int x, int y){
    if (x < y) {
        int m = x + (y - x) / 2;
 
        mergeSortChar(arr, x, m);
        mergeSortChar(arr, m + 1, y);
 
        mergeChar(arr, x, m, y);
    }
}


//quick
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

//heap
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

    printf("name : Esra Ertsak \t number: 2017555021 \n");
    clock_t zaman1;
    int ogrenci_no[] = { 2, 0, 1, 7, 5, 5, 5, 0, 2, 1 };
    char name[] = "esra ertsak";
    int n = sizeof(ogrenci_no) / sizeof(ogrenci_no[0]);
    int char_size = strlen(name);
    //insertion
    zaman1 = clock();
    insertionSort(ogrenci_no, n);
    zaman1 = clock() - zaman1;
    printArray(ogrenci_no, n );
    printf("insertion time: %f\n", ((double)zaman1) / CLOCKS_PER_SEC);
    insertionSortChar(name, char_size);
    zaman1 = clock() - zaman1;
    printf("%s\n", name);
    printf("insertion char time: %f\n", ((double)zaman1) / CLOCKS_PER_SEC);
    printf("-_-_-_-_-_--_-_-_-_-_--_-_-_-_-_--_-_-_-_-_--_-_-_-_-_--_-_-_-_-_--_-_-_-_-_--_-_-_-_-_-\n");
    
    
    
    //bubble
  
    bubbleSort(ogrenci_no, n);
    zaman1 = clock() - zaman1;
    printArray(ogrenci_no, n);
    printf("bubble time: %f\n", ((double)zaman1) / CLOCKS_PER_SEC);
    bubbleSortChar(name, char_size);
    zaman1 = clock() - zaman1;
    printf("%s\n", name);
    printf("bubble char time: %f\n", ((double)zaman1) / CLOCKS_PER_SEC);
printf("-_-_-_-_-_--_-_-_-_-_--_-_-_-_-_--_-_-_-_-_--_-_-_-_-_--_-_-_-_-_--_-_-_-_-_--_-_-_-_-_-\n");
    //selection
    
    
    selectionSort(ogrenci_no, n);
    zaman1 = clock() - zaman1;
    printArray(ogrenci_no, n);
    printf("selection time: %f\n", ((double)zaman1) / CLOCKS_PER_SEC);
    
    selectionSortChar(name, char_size);
    zaman1 = clock() - zaman1;
    printf("%s\n", name);
    printf("selection char  time: %f\n", ((double)zaman1) / CLOCKS_PER_SEC);
    printf("-_-_-_-_-_--_-_-_-_-_--_-_-_-_-_--_-_-_-_-_--_-_-_-_-_--_-_-_-_-_--_-_-_-_-_--_-_-_-_-_-\n");
    
    //merge
    
    mergeSort(ogrenci_no, 0, n - 1);
    zaman1= clock() - zaman1;
    printArray(ogrenci_no, n);
    printf("merge time: %f\n", ((double)zaman1) / CLOCKS_PER_SEC);
    mergeSortChar(name, 0, char_size - 1);
    zaman1 = clock() - zaman1;
    printf("%s\n", name);
    printf("merge char time: %f\n", ((double)zaman1) / CLOCKS_PER_SEC);
    printf("-_-_-_-_-_--_-_-_-_-_--_-_-_-_-_--_-_-_-_-_--_-_-_-_-_--_-_-_-_-_--_-_-_-_-_--_-_-_-_-_-\n");

    //quick
    quickSort(ogrenci_no,0,n-1);
    zaman1 = clock() - zaman1;
    printArray(ogrenci_no, n);
    printf("quick time: %f\n", ((double)zaman1) / CLOCKS_PER_SEC);
    quickSortChar(name,0,char_size-99);
    zaman1 = clock() - zaman1;
    printf("%s\n", name);
    printf("quick char  time: %f\n", ((double)zaman1) / CLOCKS_PER_SEC);
    printf("-_-_-_-_-_--_-_-_-_-_--_-_-_-_-_--_-_-_-_-_--_-_-_-_-_--_-_-_-_-_--_-_-_-_-_--_-_-_-_-_-\n");

    //heap
    heapSort(ogrenci_no,n);
    zaman1 = clock() - zaman1;
    printArray(ogrenci_no, n);
    printf("heap time: %f\n", ((double)zaman1) / CLOCKS_PER_SEC);
    heapSortChar(name,0);
    zaman1 = clock() - zaman1;
    printf("%s\n", name);
    printf("heap char  time: %f\n", ((double)zaman1) / CLOCKS_PER_SEC);


    return 0;
}
