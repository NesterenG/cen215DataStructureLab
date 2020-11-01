#include <stdio.h>

#include <string.h>

#include <time.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swapNum(int * num1, int * num2) {
    int temp = * num1;
    * num1 = * num2;
    * num2 = temp;
}

void swapChar(char * num1, char * num2) {
    char temp = * num1;
    * num1 = * num2;
    * num2 = temp;
}

/* Insertion Sort for Num Array */
void insertionSortByNum(int num[], int size) {

    int i, j;
    int x;
    for (i = 1; i < size; i++) {
        x = num[i];

        for (j = i - 1; j >= 0 && num[j] > x; j--) {
            num[j + 1] = num[j];
        }
        num[j + 1] = x;
    }
}

/* END Insertion Sort for Num Array */

/* Insertion Sort for Name Array */
void insertionSortByName(char name[], int size) {
    int i, j;
    char x;
    for (i = 1; i < size; i++) {
        x = name[i];

        for (j = i - 1; j >= 0 && name[j] > x; j--) {
            name[j + 1] = name[j];
        }
        name[j + 1] = x;
    }
}
/* END Insertion Sort for Name Array */

/* Selection Sort for Num Array */

void selectionSortByNum(int num[], int size) {

    int i, j, min, temp;

    for (i = 0; i < size - 1; i++) {
        min = i;
        for (j = i + 1; j < size; j++) {
            if (num[min] > num[j]) {
                min = j;
            }
        }
        swapNum( & num[i], & num[min]);
    }
}

/* END Selection Sort for Num Array */

/* Selection Sort for Name Array */

void selectionSortByName(char name[], int size) {

    int i, j, min, temp;

    for (i = 0; i < size - 1; i++) {
        min = i;
        for (j = i + 1; j < size; j++) {
            if (name[min] > name[j]) {
                min = j;
            }
        }
        swapChar( & name[i], & name[min]);
    }
}

/* END Selection Sort for Name Array */

/* Merge Sort for Number Array */

void mergeByNum(int num[], int l, int m, int r) {
    int i, j, k;

    int leftSize = m - l + 1;
    int rightSize = r - m;

    int left[leftSize], right[rightSize];

    for (i = 0; i < leftSize; i++) {
        left[i] = num[l + i];
    }
    for (j = 0; j < rightSize; j++) {
        right[j] = num[m + 1 + j];
    }

    j = 0, i = 0, k = l;

    while (leftSize > i && rightSize > j) {
        if (left[i] <= right[j]) {
            num[k] = left[i];
            i++;
        } else {
            num[k] = right[j];
            j++;
        }
        k++;
    }

    while (leftSize > i) {
        num[k] = left[i];
        k++;
        i++;
    }
    while (rightSize > j) {
        num[k] = right[j];
        k++;
        j++;
    }
}

void mergeSortByNum(int num[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortByNum(num, l, m);
        mergeSortByNum(num, m + 1, r);
        mergeByNum(num, l, m, r);
    }
}

/* 
END Merge Sort for Number Array
Merge Sort for Name Array
*/

void mergeByName(char num[], int l, int m, int r) {
    int i, j, k;

    int leftSize = m - l + 1;
    int rightSize = r - m;

    int left[leftSize], right[rightSize];

    for (i = 0; i < leftSize; i++) {
        left[i] = num[l + i];
    }
    for (j = 0; j < rightSize; j++) {
        right[j] = num[m + 1 + j];
    }

    j = 0, i = 0, k = l;

    while (leftSize > i && rightSize > j) {
        if (left[i] <= right[j]) {
            num[k] = left[i];
            i++;
        } else {
            num[k] = right[j];
            j++;
        }
        k++;
    }

    while (leftSize > i) {
        num[k] = left[i];
        k++;
        i++;
    }
    while (rightSize > j) {
        num[k] = right[j];
        k++;
        j++;
    }
}

void mergeSortByName(char num[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSortByName(num, l, m);
        mergeSortByName(num, m + 1, r);

        mergeByName(num, l, m, r);
    }
}

/* 
END Merge Sort for Name Array
Bubble Sort for Num Array
*/

void bubbleSortByNum(int num[], int size) {
    int swapped = 0, i = 0, j;
    do {
        swapped = 0;
        for (j = 0; j < size - i - 1; j++) {
            if (num[j] > num[j + 1]) {
                swapNum( & num[j], & num[j + 1]);
                swapped = 1;
            }
        }
        i++;
    } while (swapped);
}

/*
END Bubble Sort for Num Array
Bubble Sort for Name Array
*/

void bubbleSortByName(char name[], int size) {
    int swapped = 0, i = 0, j;
    do {
        swapped = 0;
        for (j = 0; j < size - i - 1; j++) {
            if (name[j] > name[j + 1]) {
                swapChar( & name[j], & name[j + 1]);
                swapped = 1;
            }
        }
        i++;
    } while (swapped);
}

/* END Bubble Sort for Name Array*/

/* Quick Sort for Number Array */

int partitionByNumber(int num[], int low, int high) {

   char pivot = num[high];

   int i = low - 1;

   for (int j = low; j < high; j++) {
      if (num[j] < pivot) {
         i++;
         swapNum( & num[i], & num[j]);
      }
   }

   swapNum( & num[i + 1], & num[high]);
   return i + 1;
}

void quickSortByNumber(int num[], int low, int high) {
   int pivot;
   if (low < high) {
      pivot = partitionByNumber(num, low, high);
      quickSortByNumber(num, low, pivot - 1);
      quickSortByNumber(num, pivot + 1, high);
   }
}

/* End Quick Sort for Number Array 
Quick Sort for Name Array */

int partitionByName(char name[], int low, int high) {

   int pivot = name[high];

   int i = low - 1;

   for (int j = low; j < high; j++) {
      if (name[j] < pivot) {
         i++;
         swapChar( & name[i], & name[j]);
      }
   }

   swapChar( & name[i + 1], & name[high]);
   return i + 1;
}

void quickSortByName(char name[], int low, int high) {
   int pivot;
   if (low < high) {
      pivot = partitionByName(name, low, high);
      quickSortByName(name, low, pivot - 1);
      quickSortByName(name, pivot + 1, high);
   }
}

/* End Quick Sort for Name Array 
Heap Sort for Number Array */

void heapifyByNumber(int num[], int size, int root) {

   int largest = root;
   int left = 2 * root + 1;
   int right = 2 * root + 2;

   if (size > left && num[left] > num[largest])
      largest = left;
   if (size > right && num[right] > num[largest])
      largest = right;

   if (largest != root) {
      swapNum( & num[largest], & num[root]);

      heapifyByNumber(num, size, largest);
   }
}

void heapSortByNumber(int num[], int size) {

   for (int i = size / 2 - 1; i >= 0; i--) {
      heapifyByNumber(num, size, i);
   }

   for (int i = size - 1; i > 0; i--) {
      swapNum( & num[0], & num[i]);

      heapifyByNumber(num, i, 0);
   }
}

/* End Heap Sort for Number Array 
Heap Sort for Name Array */

void heapifyByName(char name[], int size, int root) {

   int largest = root;
   int left = 2 * root + 1;
   int right = 2 * root + 2;

   if (size > left && name[left] > name[largest])
      largest = left;
   if (size > right && name[right] > name[largest])
      largest = right;

   if (largest != root) {
      swapChar( & name[largest], & name[root]);

      heapifyByName(name, size, largest);
   }
}

void heapSortByName(char name[], int size) {

   for (int i = size / 2 - 1; i >= 0; i--) {
      heapifyByName(name, size, i);
   }

   for (int i = size - 1; i > 0; i--) {
      swapChar( & name[0], & name[i]);

      heapifyByName(name, i, 0);
   }
}

/* End Heap Sort for Number Array */

int main(int argc, char
    const * argv[]) {
    int num[] = {
        2,
        1,
        0,
        8,
        3,
        0,
        1,
        9,
        0,
        4
    };
    char name[] = "rasit colakel";
    int sizeofNumber = sizeof(num) / sizeof(num[0]);
    int sizeName = (sizeof(name) / sizeof(name[0])) - 1;
    clock_t start, end;
    double total;

    start = clock();
    insertionSortByNum(num, sizeofNumber);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Insertion sort for number array : \n");
    printArray(num, sizeofNumber);
    printf("Time = %f\n", total);
    start = clock();
    insertionSortByName(name, sizeName);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nInsertion sort for name array : \n");
    printf("%s\n", name);
    printf("Time = %f\n", total);
    

    int num2[] = {
        2,
        1,
        0,
        8,
        3,
        0,
        1,
        9,
        0,
        4
    };
    char name2[] = "rasit colakel";

    
    start = clock();
    selectionSortByNum(num2, sizeofNumber);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nSelection sort for number array : \n");
    printArray(num2, sizeofNumber);
    printf("Time = %f\n", total);
    

    
    start = clock();
    selectionSortByName(name2, sizeName);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nSelection sort for name array : \n");
    printf("%s\n", name2);
    printf("Time = %f\n\n", total);
    

    int num3[] = {
        2,
        1,
        0,
        8,
        3,
        0,
        1,
        9,
        0,
        4
    };
    char name3[] = "rasit colakel";

    
    start = clock();
    bubbleSortByNum(num3, sizeofNumber);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nBubble sort for number array : \n");
    printArray(num3, sizeofNumber);
    printf("Time = %f\n", total);
    

    
    start = clock();
    bubbleSortByName(name3, sizeName);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nBubble sort for name array : \n");
    printf("%s\n", name3);
    printf("Time = %f\n\n", total);
    

    int number4[] = {
        2,
        1,
        0,
        8,
        3,
        0,
        1,
        9,
        0,
        4
    };
    char name4[] = "rasit colakel";

    
    start = clock();
    mergeSortByNum(number4, 0, sizeofNumber - 1);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nMerge sort for number array : \n");
    printArray(number4, sizeofNumber);
    printf("Time = %f\n", total);
    

    
    start = clock();
    mergeSortByName(name4, 0, sizeName - 1);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nMerge sort for name array : \n");
    printf("%s\n", name4);
    printf("Time = %f\n\n", total);

   int number5[] = {
      2,
      1,
      0,
      8,
      3,
      0,
      1,
      9,
      0,
      4
   };
   char name5[] = "rasit colakel";
   start = clock();
   quickSortByNumber(number5, 0, sizeofNumber - 1);
   end = clock();
   total = (double)(end - start) / CLOCKS_PER_SEC;

   printf("\nQuick sort for number array: \n");
   printArray(number5, sizeofNumber);
   printf("Time =  %f\n", total);

   start = clock();
   quickSortByName(name5, 0, sizeName - 1);
   end = clock();
   total = (double)(end - start) / CLOCKS_PER_SEC;

   printf("\nQuick sort for name array: \n");
   printf("%s\n", name5);
   printf("Time =  %f\n", total);

   int number6[] = {
      2,
      1,
      0,
      8,
      3,
      0,
      1,
      9,
      0,
      4
   };
   char name6[] = "rasit colakel";

   start = clock();
   heapSortByNumber(number6, sizeofNumber);
   end = clock();
   total = (double)(end - start) / CLOCKS_PER_SEC;

   printf("\nHeap sort for number array: \n");
   printArray(number6, sizeofNumber);
   printf("Time =  %f\n", total);

   start = clock();
   heapSortByName(name6, sizeName);
   end = clock();
   total = (double)(end - start) / CLOCKS_PER_SEC;

   printf("\nHeap sort for name array: \n");
   printf("%s\n", name6);
   printf("Time =  %f\n", total);

   return 0;
}