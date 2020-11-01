#include <stdio.h>
#include <string.h>
#include <time.h>

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
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

/* Insertion Sort for Num Array */
void insertionSortForNum(int num[], int size)
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

/* END Insertion Sort for Num Array */

/* Insertion Sort for Name Array */
void insertionSortForName(char name[], int size)
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
/* END Insertion Sort for Name Array */

/* Selection Sort for Num Array */

void selectionSortForNum(int num[], int size)
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

/* END Selection Sort for Num Array */

/* Selection Sort for Name Array */

void selectionSortForName(char name[], int size)
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

/* END Selection Sort for Name Array */

/* Merge Sort for Number Array */

void mergeForNum(int num[], int l, int m, int r)
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

void mergeSortForNum(int num[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSortForNum(num, l, m);
        mergeSortForNum(num, m + 1, r);

        mergeForNum(num, l, m, r);
    }
}

/* END Merge Sort for Number Array*/

/* Merge Sort for Name Array*/

void mergeForName(char num[], int l, int m, int r)
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

void mergeSortForName(char num[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSortForName(num, l, m);
        mergeSortForName(num, m + 1, r);

        mergeForName(num, l, m, r);
    }
}

/* END Merge Sort for Name Array*/

/* Bubble Sort for Num Array*/

void bubbleSortForNum(int num[], int size)
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

/* END Bubble Sort for Num Array*/

/* Bubble Sort for Name Array*/

void bubbleSortForName(char name[], int size)
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

/* END Bubble Sort for Name Array*/

/* Quick Sort for Number Array */

int partitionForNum(int num[], int low, int high)
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

void quickSortForNum(int num[], int low, int high)
{
    int pivot;
    if (low < high)
    {
        pivot = partitionForNum(num, low, high);
        quickSortForNum(num, low, pivot - 1);
        quickSortForNum(num, pivot + 1, high);
    }
}

/* END Quick Sort for Number Array */

/* Quick Sort for Name Array */

int partitionForName(char name[], int low, int high)
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

void quickSortForName(char name[], int low, int high)
{
    int pivot;
    if (low < high)
    {
        pivot = partitionForName(name, low, high);
        quickSortForName(name, low, pivot - 1);
        quickSortForName(name, pivot + 1, high);
    }
}

/* END Quick Sort for Name Array */

/* Heap Sort for Number Array */

void heapifyForNum(int num[], int size, int root)
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

        heapifyForNum(num, size, largest);
    }
}

void heapSortForNum(int num[], int size)
{

    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapifyForNum(num, size, i);
    }

    for (int i = size - 1; i > 0; i--)
    {
        swapNum(&num[0], &num[i]);

        heapifyForNum(num, i, 0);
    }
}

/* END Heap Sort for Number Array */

/* Heap Sort for Name Array */

void heapifyForName(char name[], int size, int root)
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

        heapifyForName(name, size, largest);
    }
}

void heapSortForName(char name[], int size)
{

    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapifyForName(name, size, i);
    }

    for (int i = size - 1; i > 0; i--)
    {
        swapChar(&name[0], &name[i]);

        heapifyForName(name, i, 0);
    }
}

/* END Heap Sort for Number Array */

int main(int argc, char const *argv[])
{
    int num[] = {2, 0, 1, 8, 5, 5, 5, 0, 1, 6};
    char name[] = "ibrahim deniz";
    int sizeNum = sizeof(num) / sizeof(num[0]);
    int sizeName = (sizeof(name) / sizeof(name[0])) - 1;
    clock_t start, end;
    double total;

    //Insertion sort for number array
    start = clock();
    insertionSortForNum(num, sizeNum);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Insertion sort for number array : \n");
    printArray(num, sizeNum);
    printf("time = %f", total);
    //END Insertion sort for number array

    //Insertion sort for name array
    start = clock();
    insertionSortForName(name, sizeName);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nInsertion sort for name array : \n");
    printf("%s\n", name);
    printf("time = %f", total);
    //Insertion sort for name array

    int num2[] = {2, 0, 1, 8, 5, 5, 5, 0, 1, 6};
    char name2[] = "ibrahim deniz";

    //Selection sort for number array
    start = clock();
    selectionSortForNum(num2, sizeNum);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nSelection sort for number array : \n");
    printArray(num2, sizeNum);
    printf("time = %f", total);
    //END Selection sort for number array

    //Selection sort for name array
    start = clock();
    selectionSortForName(name2, sizeName);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nSelection sort for name array : \n");
    printf("%s\n", name2);
    printf("time = %f\n", total);
    //END Selection sort for name array

    int num3[] = {2, 0, 1, 8, 5, 5, 5, 0, 1, 6};
    char name3[] = "ibrahim deniz";

    //Merge sort for num array
    start = clock();
    mergeSortForNum(num3, 0, sizeNum - 1);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nMerge sort for number array : \n");
    printArray(num3, sizeNum);
    printf("time = %f", total);
    //END Merge sort for num array

    //Merge sort for name array
    start = clock();
    mergeSortForName(name3, 0, sizeName - 1);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nMerge sort for name array : \n");
    printf("%s\n", name3);
    printf("time = %f\n", total);
    //END Merge sort for name array

    int num4[] = {2, 0, 1, 8, 5, 5, 5, 0, 1, 6};
    char name4[] = "ibrahim deniz";

    //Bubble sort for num array
    start = clock();
    bubbleSortForNum(num4, sizeNum);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nBubble sort for number array : \n");
    printArray(num4, sizeNum);
    printf("time = %f", total);
    //END Bubble sort for num array

    //Bubble sort for name array
    start = clock();
    bubbleSortForName(name4, sizeName);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nBubble sort for name array : \n");
    printf("%s\n", name4);
    printf("time = %f\n", total);
    //END Bubble sort for name array

    int num5[] = {2, 0, 1, 8, 5, 5, 5, 0, 1, 6};
    char name5[] = "ibrahim deniz";

    //Quick sort for num array
    start = clock();
    quickSortForNum(num5, 0, sizeNum - 1);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nQuick sort for number array : \n");
    printArray(num5, sizeNum);
    printf("time = %f", total);
    //END Quick sort for num array

    //Quick sort for name array
    start = clock();
    quickSortForName(name5, 0, sizeName - 1);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nQuick sort for name array : \n");
    printf("%s\n", name5);
    printf("time = %f\n", total);
    //END Quick sort for name array

    int num6[] = {2, 0, 1, 8, 5, 5, 5, 0, 1, 6};
    char name6[] = "ibrahim deniz";

    //Heap sort for num array
    start = clock();
    heapSortForNum(num6, sizeNum);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nHeap sort for number array : \n");
    printArray(num6, sizeNum);
    printf("time = %f", total);
    //END Heap sort for num array

    //Heap sort for name array
    start = clock();
    heapSortForName(name6, sizeName);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nHeap sort for name array : \n");
    printf("%s\n", name6);
    printf("time = %f\n", total);
    //END Heap sort for name array

    return 0;
}