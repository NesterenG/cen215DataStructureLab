#include <stdio.h>
#include <string.h>
#include <time.h>

void printArray(int arr[], int size) 
{
	int i;
    for (i = 0; i < size; i++) 
	{
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void swapNum(int* num1, int* num2) 
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void swapChar(char* num1, char* num2) 
{
    char temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
 master
void heapifyName(char arr[], int n, int i)
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
        heapifyName(arr, n, largest); 
    }
}
void heapSortName(char arr[], int n)
{
	int i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapifyName(arr, n, i);

    for (i=n-1; i>=0; i--)
    {
        swapChar(&arr[0], &arr[i]);
        heapifyName(arr, i, 0);
    }
}
void heapify(int arr[], int n, int i) 
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    if (largest != i) 
	{
      swapNum(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n) 
{
	int i;
    for (i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  
    for (i = n - 1; i >= 0; i--) 
	{
      swapNum(&arr[0], &arr[i]);
      heapify(arr, i, 0);
    }
}
int partitionName (char arr[], int low, int high) 
{ 
    int pivot = arr[high];    
    int i = (low - 1);   
    int j;
    for (j = low; j <= high- 1; j++) 
    { 
        if (arr[j] < pivot) 
        { 
            i++;    
            swapChar(&arr[i], &arr[j]); 
        } 
    } 
    swapChar(&arr[i + 1], &arr[high]); 
    return (i + 1); 
}
void quickSortName(char arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partitionName(arr, low, high); 
        quickSortName(arr, low, pi - 1); 
        quickSortName(arr, pi + 1, high); 
    } 
}
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];
    int i = (low - 1);
    int j;
    for (j = low; j <= high- 1; j++) 
    { 
        if (arr[j] < pivot) 
        { 
            i++;
            swapNum(&arr[i], &arr[j]); 
        } 
    } 
    swapNum(&arr[i + 1], &arr[high]); 
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

 master
void insertionSortByNum(int num[], int size) 
{
    int i, j;
    int x;
    for (i = 1; i < size; i++)
	{
        x = num[i];

        for (j = i - 1; j >= 0 && num[j] > x; j--) 
		{
            num[j + 1] = num[j];
        }
        num[j + 1] = x;
    }
}
void insertionSortByName(char name[], int size) 
{
    int i, j;
    char x;
    for (i = 1; i < size; i++) 
	{
        x = name[i];
        for (j = i - 1; j >= 0 && name[j] > x; j--) 
		{
            name[j + 1] = name[j];
        }
        name[j + 1] = x;
    }
}
void selectionSortByNum(int num[], int size) 
{
    int i, j, min, temp;
    for (i = 0; i < size - 1; i++) 
	{
        min = i;
        for (j = i + 1; j < size; j++) 
		{
            if (num[min] > num[j]) 
			{
                min = j;
            }
        }
        swapNum(&num[i], &num[min]);
    }
}
void selectionSortByName(char name[], int size) 
{
    int i, j, min, temp;
    for (i = 0; i < size - 1; i++) 
	{
        min = i;
        for (j = i + 1; j < size; j++) 
		{
            if (name[min] > name[j]) 
			{
                min = j;
            }
        }
        swapChar(&name[i], &name[min]);
    }
}
void mergeByNum(int num[], int l, int m, int r) 
{
    int i, j, k;
    int leftSize = m - l + 1;
    int rightSize = r - m;
    int left[leftSize], right[rightSize];
    for (i = 0; i < leftSize; i++) 
	{
        left[i] = num[l + i];
    }
    for (j = 0; j < rightSize; j++) 
	{
        right[j] = num[m + 1 + j];
    }
    j = 0, i = 0, k = l;
    while (leftSize > i && rightSize > j) 
	{
        if (left[i] <= right[j]) 
		{
            num[k] = left[i];
            i++;
        }
        else 
		{
            num[k] = right[j];
            j++;
        }
        k++;
    }
    while (leftSize > i) 
	{
        num[k] = left[i];
        k++;
        i++;
    }
    while (rightSize > j) 
	{
        num[k] = right[j];
        k++;
        j++;
    }
}
void mergeSortByNum(int num[], int l, int r)
{
    if (l < r) 
	{
        int m = l + (r - l) / 2;
        mergeSortByNum(num, l, m);
        mergeSortByNum(num, m + 1, r);
        mergeByNum(num, l, m, r);
    }
}
void mergeByName(char num[], int l, int m, int r) 
{
    int i, j, k;
    int leftSize = m - l + 1;
    int rightSize = r - m;
    int left[leftSize], right[rightSize];
    for (i = 0; i < leftSize; i++) 
	{
        left[i] = num[l + i];
    }
    for (j = 0; j < rightSize; j++) 
	{
        right[j] = num[m + 1 + j];
    }
    j = 0, i = 0, k = l;
    while (leftSize > i && rightSize > j) 
	{
        if (left[i] <= right[j]) 
		{
            num[k] = left[i];
            i++;
        }
        else 
		{
            num[k] = right[j];
            j++;
        }
        k++;
    }
    while (leftSize > i) 
	{
        num[k] = left[i];
        k++;
        i++;
    }
    while (rightSize > j)
	{
        num[k] = right[j];
        k++;
        j++;
    }
}
void mergeSortByName(char num[], int l, int r) 
{
    if (l < r) 
	{
        int m = l + (r - l) / 2;
        mergeSortByName(num, l, m);
        mergeSortByName(num, m + 1, r);
        mergeByName(num, l, m, r);
    }
}
void bubbleSortByNum(int num[], int size) 
{
    int swapped = 0, i = 0, j;
    do 
	{
        swapped = 0;
        for (j = 0; j < size - i - 1; j++) 
		{
            if (num[j] > num[j + 1]) 
			{
                swapNum(&num[j], &num[j + 1]);
                swapped = 1;
            }
        }
        i++;
    } while (swapped);
}
void bubbleSortByName(char name[], int size) 
{
    int swapped = 0, i = 0, j;
    do 
	{
        swapped = 0;
        for (j = 0; j < size - i - 1; j++) 
		{
            if (name[j] > name[j + 1]) 
			{
                swapChar(&name[j], &name[j + 1]);
                swapped = 1;
            }
        }
        i++;
    } while (swapped);
}
int main() 
{
    int num[] = {2,0,1,9,5,5,6,4,0,1};
    char name[] = "safak ertas";
    int sizeofNumber = sizeof(num) / sizeof(num[0]);
    int sizeName = (sizeof(name) / sizeof(name[0])) - 1;
    clock_t start, end;
 master
    double total,total2,total3,total4,total5,total6,total7,total8,total9,total10,total11,total12;

    double total,total2,total3,total4,total5,total6,total7,total8;
 master

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
    total2 = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nInsertion sort for name array : \n");
    printf("%s\n", name);
    printf("Time = %f\n", total2);

    int num2[] = {2,0,1,9,5,5,6,4,0,1};
    char name2[] = "safak ertas";

    start = clock();
    selectionSortByNum(num2, sizeofNumber);
    end = clock();
    total3 = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nSelection sort for number array : \n");
    printArray(num2, sizeofNumber);
    printf("Time = %f\n", total3);

    start = clock();
    selectionSortByName(name2, sizeName);
    end = clock();
    total4 = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nSelection sort for name array : \n");
    printf("%s\n", name2);
    printf("Time = %f\n\n", total4);

    int num3[] = {2,0,1,9,5,5,6,4,0,1};
    char name3[] = "safak ertas";

    start = clock();
    bubbleSortByNum(num3, sizeofNumber);
    end = clock();
    total5 = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nBubble sort for number array : \n");
    printArray(num3, sizeofNumber);
    printf("Time = %f\n", total5);

    start = clock();
    bubbleSortByName(name3, sizeName);
    end = clock();
    total6 = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nBubble sort for name array : \n");
    printf("%s\n", name3);
    printf("Time = %f\n\n", total6);

    int number4[] = {2,0,1,9,5,5,6,4,0,1};
    char name4[] = "safak ertas";

    start = clock();
    mergeSortByNum(number4, 0, sizeofNumber - 1);
    end = clock();
    total7 = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nMerge sort for number array : \n");
    printArray(number4, sizeofNumber);
    printf("Time = %f\n", total7);

    start = clock();
    mergeSortByName(name4, 0, sizeName - 1);
    end = clock();
    total8 = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nMerge sort for name array : \n");
    printf("%s\n", name4);
    printf("Time = %f\n\n", total8);
 master
    
    int num5[] = {2,0,1,9,5,5,6,4,0,1};
    char name5[] = "safak ertas";
    
    start = clock();
    quickSort(num5, 0, sizeofNumber - 1);
    end = clock();
    total9 = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\nQuick sort for number array : \n");
    printArray(num5, sizeofNumber);
    printf("Time = %f\n",total9);
    
    start=clock();
    quickSortName(name5, 0, sizeName-1);
    end =clock();
    total10=(double)(end - start) / CLOCKS_PER_SEC;
    printf("\n Quick sort for name array : \n");
    printf("%s\n",name5);
    printf("Time = %f\n",total10);
    
    int num6[] = {2,0,1,9,5,5,6,4,0,1};
    char name6[] = "safak ertas";
    
    start = clock();
    heapSort(num6, sizeofNumber);
    end = clock();
    total11 = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\n Heap sort for number array : \n");
    printArray(num6,sizeofNumber);
    printf("Time = %f\n",total11);
    
    start = clock();
    heapSortName(name6,sizeName);
    end = clock();
    total12 = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\n Heap sort for name array : \n");
    printf("%s\n",name6);
    printf("Time = %f\n",total12);
    

 master
    return 0;
}
