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

void swapNum(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void swapChar(char *num1, char *num2)
{
    char temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

/* insertion sort for num array */
void insertSortNum(int num[], int size)
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


/* insertion sort for name array */
void insertSortName(char name[], int size)
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

/* Selection sort for num array */

void selectionSortNum(int num[], int size)
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

/* Selection sort for name array */

void selectionSortName(char name[], int size)
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

/* Merge sort for number array */

void mergeNum(int num[], int l, int m, int r)
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

void mergeSortNum(int num[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSortNum(num, l, m);
        mergeSortNum(num, m + 1, r);

        mergeNum(num, l, m, r);
    }
}

/* Merge sort for name array*/

void mergeName(char num[], int l, int m, int r)
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

void mergeSortName(char num[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSortName(num, l, m);
        mergeSortName(num, m + 1, r);

        mergeName(num, l, m, r);
    }
}


/* Bubble sort for num array*/

void bubbleSortNum(int num[], int size)
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

/* Bubble sort for name array*/

void bubbleSortName(char name[], int size)
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







/* Quick sort for number array */

int partitionNum(int num[], int low, int high)
{

    char pivot = num[high];

    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (num[j] < pivot)
        {
            i++;
            swapNum(&num[i], &num[j]);
        }
    }

    swapNum(&num[i + 1], &num[high]);
    return i + 1;
}

void quickSortNum(int num[], int low, int high)
{
    int pivot;
    if (low < high)
    {
        pivot = partitionNum(num, low, high);
        quickSortNum(num, low, pivot - 1);
        quickSortNum(num, pivot + 1, high);
    }
}

/* Quick sort for name array */

int partitionName(char name[], int low, int high)
{

    int pivot = name[high];

    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (name[j] < pivot)
        {
            i++;
            swapChar(&name[i], &name[j]);
        }
    }

    swapChar(&name[i + 1], &name[high]);
    return i + 1;
}

void quickSortName(char name[], int low, int high)
{
    int pivot;
    if (low < high)
    {
        pivot = partitionName(name, low, high);
        quickSortName(name, low, pivot - 1);
        quickSortName(name, pivot + 1, high);
    }
}

/* Heap sort for number array */

void heapifyNum(int num[], int size, int root)
{

    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (size > left && num[left] > num[largest])
        largest = left;
    if (size > right && num[right] > num[largest])
        largest = right;

    if (largest != root)
    {
        swapNum(&num[largest], &num[root]);

        heapifyNum(num, size, largest);
    }
}

void heapSortNum(int num[], int size)
{

    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapifyNum(num, size, i);
    }

    for (int i = size - 1; i > 0; i--)
    {
        swapNum(&num[0], &num[i]);

        heapifyNum(num, i, 0);
    }
}


/* Heap sort for name array */

void heapifyName(char name[], int size, int root)
{

    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (size > left && name[left] > name[largest])
        largest = left;
    if (size > right && name[right] > name[largest])
        largest = right;

    if (largest != root)
    {
        swapChar(&name[largest], &name[root]);

        heapifyName(name, size, largest);
    }
}

void heapSortName(char name[], int size)
{

    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapifyName(name, size, i);
    }

    for (int i = size - 1; i > 0; i--)
    {
        swapChar(&name[0], &name[i]);

        heapifyName(name, i, 0);
    }
}





int main(int argc, char const *argv[])
{
    int num[] = {2, 0, 1, 8, 5, 5, 5, 0, 1, 9};
    char name[] = "baki duman";
    int sizeNum = sizeof(num) / sizeof(num[0]);
    int sizeName = (sizeof(name) / sizeof(name[0])) - 1;
    clock_t start, end;
    double total;

    //Insertion sort for number array
    start = clock();
    insertSortNum(num, sizeNum);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Insertion sort for number array : \n");
    printArray(num, sizeNum);
    printf("time = %f", total);
    //END Insertion sort for number array

    //Insertion sort for name array
    start = clock();
    insertSortName(name, sizeName);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nInsertion sort for name array : \n");
    printf("%s\n", name);
    printf("time = %f", total);
    //Insertion sort for name array

    int num2[] = {2, 0, 1, 8, 5, 5, 5, 0, 1, 9};
    char name2[] = "baki duman";

    //Selection sort for number array
    start = clock();
    selectionSortNum(num2, sizeNum);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nSelection sort for number array : \n");
    printArray(num2, sizeNum);
    printf("time = %f", total);
    //END Selection sort for number array

    //Selection sort for name array
    start = clock();
    selectionSortName(name2, sizeName);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nSelection sort for name array : \n");
    printf("%s\n", name2);
    printf("time = %f\n", total);
    //END Selection sort for name array

    int num3[] = {2, 0, 1, 8, 5, 5, 5, 0, 1, 9};
    char name3[] = "baki duman";

    //Merge sort for num array
    start = clock();
    mergeSortNum(num3, 0, sizeNum - 1);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nMerge sort for number array : \n");
    printArray(num3, sizeNum);
    printf("time = %f", total);
    //END Merge sort for num array

    //Merge sort for name array
    start = clock();
    mergeSortName(name3, 0, sizeName - 1);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nMerge sort for name array : \n");
    printf("%s\n", name3);
    printf("time = %f\n", total);
    //END Merge sort for name array

    int num4[] = {2, 0, 1, 8, 5, 5, 5, 0, 1, 9};
    char name4[] = "baki duman";

    //Bubble sort for num array
    start = clock();
    bubbleSortNum(num4, sizeNum);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nBubble sort for number array : \n");
    printArray(num4, sizeNum);
    printf("time = %f", total);
    //END Bubble sort for num array

    //Bubble sort for name array
    start = clock();
    bubbleSortName(name4, sizeName);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nBubble sort for name array : \n");
    printf("%s\n", name4);
    printf("time = %f\n", total);
    //END Bubble sort for name array







	int num5[] = {2, 0, 1, 8, 5, 5, 5, 0, 1, 9};
    char name5[] = "baki duman";

    //Quick sort for num array
    start = clock();
    quickSortNum(num5, 0, sizeNum - 1);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nQuick sort for number array : \n");
    printArray(num5, sizeNum);
    printf("time = %f", total);
    //End Quick sort for num array

    //Quick sort for name array
    start = clock();
    quickSortName(name5, 0, sizeName - 1);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nQuick sort for name array : \n");
    printf("%s\n", name5);
    printf("time = %f\n", total);
    //End Quick sort for name array

    int num6[] = {2, 0, 1, 8, 5, 5, 5, 0, 1, 9};
    char name6[] = "baki duman";

    //Heap sort for num array
    start = clock();
    heapSortNum(num6, sizeNum);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nHeap sort for number array : \n");
    printArray(num6, sizeNum);
    printf("time = %f", total);
    //End Heap sort for num array

    //Heap sort for name array
    start = clock();
    heapSortName(name6, sizeName);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nHeap sort for name array : \n");
    printf("%s\n", name6);
    printf("time = %f\n", total);
    //End Heap sort for name array
    
    
    
    

    return 0;
}
