#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h>


void InsertionSort(int ary[], int n) 
{ 
    int i, a, j; 
    for (i = 1; i < n; i++) { 
        a = ary[i]; 
        j = i - 1; 
        while (j >= 0 && ary[j] > a) { 
            ary[j + 1] = ary[j]; 
            j = j - 1; 
        } 
        ary[j + 1] = a; 
    } 
} 
    

void InsertionSortChar(char ary[], int n) 
{
    int i, j;
    char a;
    for(i = 1; i < n; i++) {
        a = ary[i];
        j = i - 1;
        while(j >= 0 && ary[j] > a) {
            ary[j + 1] = ary[j];
            j = j - 1;
        }
        ary[j + 1] = a;
    }
}
void Swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void SwapChar(char *x, char *y) 
{ 
    char temp = *x; 
    *x = *y; 
    *y = temp; 
} 

    
void SelectionSort(int ary[], int n) 
{ 
    int i, j, MIN;  
    for (i = 0; i < n-1; i++) 
    { 
        MIN = i; 
        for (j = i+1; j < n; j++) 
          if (ary[j] < ary[MIN]) 
            MIN = j; 
        Swap(&ary[MIN], &ary[i]); 
    } 
} 

void SelectionSortChar(char ary[], int n) 
{ 
    int i, j;
    char MIN;  
    for (i = 0; i < n-1; i++) 
    { 
        MIN = i; 
        for (j = i+1; j < n; j++) 
          if (ary[j] < ary[MIN]) 
            MIN = j; 
        SwapChar(&ary[MIN], &ary[i]); 
    } 
} 
    
    
void BubbleSort(int ary[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)          
       for (j = 0; j < n-i-1; j++)  
           if (ary[j] > ary[j+1]) 
              Swap(&ary[j], &ary[j+1]); 
} 

void BubbleSortChar(char ary[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)          
       for (j = 0; j < n-i-1; j++)  
           if (ary[j] > ary[j+1]) 
              SwapChar(&ary[j], &ary[j+1]); 
} 
    
    
void Merge(int ary[], int l, int m, int r) 
{ 
    int i, j, k, n1, n2; 
    n1 = m - l + 1; 
    n2 = r - m; 

    int L[n1], R[n2]; 

    for (i = 0; i < n1; i++) 
        L[i] = ary[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = ary[m + 1 + j]; 
 
    i = 0; 
    j = 0; 
    k = l; 

    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            ary[k] = L[i]; 
            i++; 
        } 
        else { 
            ary[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
 
    while (i < n1) { 
        ary[k] = L[i]; 
        i++; 
        k++; 
    } 
 
    while (j < n2) { 
        ary[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void MergeSort(int ary[], int l, int r) 
{ 
    if (l < r) { 
        int x = l + (r - l) / 2; 
 
        MergeSort(ary, l, x); 
        MergeSort(ary, x + 1, r); 
 
        Merge(ary, l, x, r); 
    } 
} 
 
void MergeChar(char ary[], int l, int m, int r) 
{ 
    int i, j, k, n1, n2; 
    n1 = m - l + 1; 
    n2 = r - m; 

    int L[n1], R[n2]; 

    for (i = 0; i < n1; i++) 
        L[i] = ary[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = ary[m + 1 + j]; 
 
    i = 0; 
    j = 0; 
    k = l; 

    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            ary[k] = L[i]; 
            i++; 
        } 
        else { 
            ary[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
 
    while (i < n1) { 
        ary[k] = L[i]; 
        i++; 
        k++; 
    } 
 
    while (j < n2) { 
        ary[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void MergeSortChar(char ary[], int l, int r) 
{ 
    if (l < r) { 
        int x = l + (r - l) / 2; 
 
        MergeSortChar(ary, l, x); 
        MergeSortChar(ary, x + 1, r); 
 
        MergeChar(ary, l, x, r); 
    } 
}



int Partition(int ary[], int Low, int High) {
    int temp = ary[High];
    int i = (Low - 1);
    int j;
    for(j = Low; j <= High - 1; j++) {
        if(ary[j] < temp) {
            i++;
            Swap(&ary[i], &ary[j]);
        }
    }
    Swap(&ary[i + 1], &ary[High]);
    return (i+1);
}

void QuickSort(int ary[], int Low, int High) {
    if (Low < High) { 
        int x = Partition(ary, Low, High); 

        QuickSort(ary, Low, x - 1); 
        QuickSort(ary, x + 1, High); 
    } 
}

char PartitionChar(char ary[], int Low, int High) {
    int pivot = ary[High];
    int i = (Low - 1);
    int j;
    for(j = Low; j <= High - 1; j++) {
        if(ary[j] < pivot) {
            i++;
            SwapChar(&ary[i], &ary[j]);
        }
    }
    SwapChar(&ary[i + 1], &ary[High]);
    return (i+1);
}

void QuickSortChar(char ary[], int Low, int High) {
    if (Low < High) { 
        int part = PartitionChar(ary, Low, High); 

        QuickSortChar(ary, Low, part - 1); 
        QuickSortChar(ary, part + 1, High); 
    } 
}

void Heapify(int ary[], int n, int i) { 
    int temp1 = i;
    int l = 2*i + 1; 
    int r = 2*i + 2;

    if (l < n && ary[l] > ary[temp1]) 
        temp1 = l; 

    if (r < n && ary[r] > ary[temp1]) 
        temp1 = r; 

    if (temp1 != i) { 
        Swap(&ary[i], &ary[temp1]); 
        Heapify(ary, n, temp1); 
    } 
} 

void HeapSort(int ary[], int n) { 
    int i,j;
    for (i = n / 2 - 1; i >= 0; i--) 
        Heapify(ary, n, i); 

    for (j=n-1; j>0; j--) { 
        Swap(&ary[0], &ary[j]); 
        Heapify(ary, j, 0); 
    } 
} 

void HeapifyChar(char ary[], int n, int i) { 
    int temp1 = i;
    int l = 2*i + 1; 
    int r = 2*i + 2;

    if (l < n && ary[l] > ary[temp1]) 
        temp1 = l; 

    if (r < n && ary[r] > ary[temp1]) 
        temp1 = r; 

    if (temp1 != i) { 
        SwapChar(&ary[i], &ary[temp1]); 
        HeapifyChar(ary, n, temp1); 
    } 
} 

void HeapSortChar(char ary[], int n) { 
    int i,j;
    for (i = n / 2 - 1; i >= 0; i--) 
        HeapifyChar(ary, n, i); 

    for (j=n-1; j>0; j--) { 
        SwapChar(&ary[0], &ary[j]); 
        HeapifyChar(ary, j, 0); 
    } 
} 
void PrintArray(int ary[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", ary[i]); 
    printf("\n"); 
} 


int main() {
    
    clock_t start;

    int StudentNum[] ={ 2, 0, 1, 7, 5, 5, 5, 0, 3, 4 }; 
    char StudentName[] = "YUSUF KAYA"; 
    
    int x = sizeof(StudentNum) / sizeof(StudentNum[0]); 
    int CharSize = strlen(StudentName);

    start = clock();
    InsertionSort(StudentNum, x);
    start = clock() - start;
    PrintArray(StudentNum, x); 
    printf("time for insertion sort: %f\n", ((double)start) / CLOCKS_PER_SEC);
    InsertionSortChar(StudentName, CharSize);
    start = clock() - start;
    printf("%s\n", StudentName);
    printf("time for insertion char sort: %f\n", ((double)start) / CLOCKS_PER_SEC);

    int StudentNumber1[] = { 2, 0, 1, 7, 5, 5, 5, 0, 3, 4 }; 
    char StudentName1[] = "YUSUF KAYA"; 
    int y = sizeof(StudentNumber1) / sizeof(StudentNumber1[0]); 
    int CharSize1 = strlen(StudentName1);
    SelectionSort(StudentNumber1, y);
    start = clock() - start;
    PrintArray(StudentNumber1, y); 
    printf("time for selection sort: %lf\n", ((double)start) / CLOCKS_PER_SEC);
    SelectionSortChar(StudentName1, CharSize1);
    start = clock() - start;
    printf("%s\n", StudentName1);
    printf("time for selection char sort: %lf\n", ((double)start) / CLOCKS_PER_SEC);

    
    int StudentNum2[] ={ 2, 0, 1, 7, 5, 5, 5, 0, 3, 4 };
    char StudentName2[] = "YUSUF KAYA"; 
    int z = sizeof(StudentNum2) / sizeof(StudentNum2[0]); 
    int CharSize2 = strlen(StudentName2);
    BubbleSort(StudentNum2, z);
    start = clock() - start;
    PrintArray(StudentNum2, z); 
    printf("time for bubble sort: %f\n", ((double)start) / CLOCKS_PER_SEC);
    BubbleSortChar(StudentName2, CharSize2);
    start = clock() - start;
    printf("%s\n", StudentName2);
    printf("time for bubble char sort: %f\n", ((double)start) / CLOCKS_PER_SEC);

 
    int StudentNum3[] = { 2, 0, 1, 7, 5, 5, 5, 0, 3, 4 }; 
    char StudentName3[] = "YUSUF KAYA"; 
    int i = sizeof(StudentNum3) / sizeof(StudentNum3[0]); 
    int CharSize3 = strlen(StudentName3);
    MergeSort(StudentNum3, 0, i - 1);
    start = clock() - start;
    PrintArray(StudentNum3, i); 
    printf("time for merge sort: %f\n", ((double)start) / CLOCKS_PER_SEC);
    MergeSortChar(StudentName3, 0, CharSize3 - 1);
    start = clock() - start;
    printf("%s\n", StudentName3);
    printf("time for merge char sort: %f\n", ((double)start) / CLOCKS_PER_SEC);
    
    
    int StudentNum4[] = { 2, 0, 1, 7, 5, 5, 5, 0, 3, 4 }; 
    char StudentName4[] = "YUSUF KAYA"; 
    int j = sizeof(StudentNum4) / sizeof(StudentNum4[0]); 
    int CharSize4 = strlen(StudentName4);
    QuickSort(StudentNum4, 0, j - 1);
    start = clock() - start;
    PrintArray(StudentNum4, j); 
    printf("time for quick sort: %f\n", ((double)start) / CLOCKS_PER_SEC);
    QuickSortChar(StudentName4, 0, CharSize4 - 1);
    start = clock() - start;
    printf("%s\n", StudentName4);
    printf("time for quick char sort: %f\n", ((double)start) / CLOCKS_PER_SEC);

 
    int StudentNum5[] ={ 2, 0, 1, 7, 5, 5, 5, 0, 3, 4 }; 
    char StudentName5[] = "YUSUF KAYA"; 
    int k = sizeof(StudentNum5) / sizeof(StudentNum5[0]); 
    int CharSize5 = strlen(StudentName5);
    HeapSort(StudentNum5, k);
    start = clock() - start;
    PrintArray(StudentNum5, k); 
    printf("time for heap sort: %f\n", ((double)start) / CLOCKS_PER_SEC);
    HeapSortChar(StudentName5, CharSize5);
    start = clock() - start;
    printf("%s\n", StudentName5);
    printf("time for heap char sort: %f\n", ((double)start) / CLOCKS_PER_SEC);

    return 0;
}
