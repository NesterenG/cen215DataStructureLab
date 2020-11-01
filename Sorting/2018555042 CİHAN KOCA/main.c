#include<stdio.h>
#include<string.h>
#include<time.h>

void swapId(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;

}

void swapName(char* x, char* y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSortId(int arr[], int size) {
    int i, j, k;
    for (i = 0; i < size - 1; ++i) {
        k = i;
        for (j = i + 1; j < size; ++j) {
            if (arr[j] < arr[k])
                k = j;
        }
        swapId(&arr[k], &arr[i]);
    }

}

void selectionSortName(char arr[], int size) {
    int i, j, k;
    for (i = 0; i < size - 1; ++i) {
        k = i;
        for (j = i + 1; j < size; ++j) {
            if (arr[j] < arr[k])
                k = j;
        }
        swapName(&arr[k], &arr[i]);
    }

}

void insertionSortId(int arr[], int size) {
    int i, j, k;
    for (i = 1; i < size; i++) {
        k = arr[i];
        for (j = i - 1; j >= 0 && arr[j] >= k; j--) {
            arr[j + 1] = arr[j];
        }
        k = arr[j + 1];
    }

}

void insertionSortName(char arr[], int size) {
    int i, j, k;
    for (i = 1; i < size; i++) {
        k = arr[i];
        for (j = i - 1; j >= 0 && arr[j] >= k; j--) {
            arr[j + 1] = arr[j];
        }
        k = arr[j + 1];

    }
}

void bubbleSortId(int arr[], int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swapId(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void bubbleSortName(char arr[], int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swapName(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void mergeId(int arr[], int left, int mid, int right)
{
    int i, j, l = 0;
    int array[15];

    for (i = left, j = mid + 1; (i <= mid) && (j <= right);)
    {
        if (arr[i] < arr[j]) {
            array[l] = arr[i];
            i++;
            l++;
        }
        else {
            array[l] = arr[j];
            j++;
            l++;
        }
    }

    while (i <= mid) {
        array[l] = arr[i];
        i++;
        l++;
    }
    while (j <= right) {
        array[l] = arr[j];
        j++;
        l++;
    }
    for (i = left, l = 0; i <= right; i++, l++) {
        arr[i] = array[l];
    }

}

void mergeName(char arr[], int left, int mid, int right)
{
    int i, j, l = 0;
    char array[20];

    for (i = left, j = mid + 1; (i <= mid) && (j <= right);)
    {
        if (arr[i] < arr[j]) {
            array[l] = arr[i];
            i++;
            l++;
        }
        else {
            array[l] = arr[j];
            j++;
            l++;
        }
    }

    while (i <= mid) {
        array[l] = arr[i];
        i++;
        l++;
    }
    while (j <= right) {
        array[l] = arr[j];
        j++;
        l++;
    }
    for (i = left, l = 0; i <= right; i++, l++) {
        arr[i] = array[l];
    }

}

void  mergeSortId(int arr[], int left, int right) {
    int mid;
    if (left < right)
    {
        mid = (left + right) / 2;

        mergeSortId(arr, left, mid);
        mergeSortId(arr, mid + 1, right);

        mergeId(arr, left, mid, right);

    }
}

void mergeSortName(char arr[], int left, int right) {
    int mid;
    if (left < right)
    {
        mid = (left + right) / 2;

        mergeSortName(arr, left, mid);
        mergeSortName(arr, mid + 1, right);
        mergeName(arr, left, mid, right);

    }
}



int partitionId(int arr[], int left, int right)
{
    int pivot = arr[right];
    int low = (left - 1);
    int high;
    
    for ( high = left; high <= right- 1; high++)
    {
        if (arr[high] <= pivot)
        {
            low++;
            swapId(&arr[low], &arr[high]);
        }
    }
    swapId(&arr[low + 1], &arr[right]);
    return (low + 1);
}

void quickSortId(int arr[], int left, int right)
{
    if (left < right)
    {
        int pivot = partitionId(arr, left, right);
        quickSortId(arr, left, pivot - 1);
        quickSortId(arr, pivot + 1, right);
    }
}

char partitionName(char arr[],int left,int right){
    int pivot = arr[right];
    int low = (left - 1);
    int high;
    
    for ( high = left; high <= right- 1; high++)
    {
        if (arr[high] <= pivot)
        {
            low++;
            swapName(&arr[low], &arr[high]);
        }
    }
    swapName(&arr[low + 1], &arr[right]);
    return (low + 1);
}

void quickSortName(char arr[], int left, int right)
{
    if (left < right)
    {
        int pivot = partitionName(arr, left, right);
        quickSortName(arr, left, pivot - 1);
        quickSortName(arr, pivot + 1, right);
    }
}


void heapifyId(int arr[],int size,int i) {
	int largest = i;
	int leftChild = 2 * i + 1;
	int rightChild = 2 * i + 2;
	
	if (arr[leftChild] > arr[largest] && leftChild<size) 
		largest = leftChild;

		if (arr[rightChild] > arr[largest] && rightChild<size) 
			largest = rightChild;
		if (largest != i) {
			swapId(&arr[i], &arr[largest]);
			heapifyId(arr, size, largest);
		}

}
void heapSortId(int arr[],int size) {
	int i;
	for (i = size / 2 - 1; i >= 0;i-- ) {
		heapifyId(arr, size, i);
	}

	for (i = size - 1; i > 0; i--) {
		swapId(&arr[0],&arr[i]);
		heapifyId(arr , i , 0);
	}

}



void heapifyName(char arr[],int size,int i) {
	int largest = i;
	int leftChild = 2 * i + 1;
	int rightChild = 2 * i + 2;
	
	if (arr[leftChild] > arr[largest] && leftChild<size) 
		largest = leftChild;

		if (arr[rightChild] > arr[largest] && rightChild<size) 
			largest = rightChild;
		if (largest != i) {
			swapName(&arr[i], &arr[largest]);
			heapifyName(arr, size, largest);
		}

}
void heapSortName(char arr[],int size) {
	int i;
	for (i = size / 2 - 1; i >= 0;i-- ) {
		heapifyName(arr, size, i);
	}

	for (i = size - 1; i > 0; i--) {
		swapName(&arr[0],&arr[i]);
		heapifyName(arr , i , 0);
	}

}










void printSortId(int arr[], int size) {
    int i;
    for (i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printSortName(char arr[], int size) {
    int i;
    for (i = 0; i < size; ++i) {
        printf("%c ", arr[i]);
    }
    printf("\n");
}


int main() 
{
    int Id[] = { 2,0,1,8,5,5,5,0,4,2 };
    char Name[] = "cihan koca";

    printf("ID: 2018555042\n");
    printf("NAME: CIHAN KOCA \n\n");
    int size1 = sizeof(Id) / sizeof(Id[2]);
    int size2 = strlen(Name);

    clock_t t;
    t = clock();

    printf("--Selection SORT--\n");
    selectionSortId(Id, size1);
    t = clock() - t;
    printSortId(Id, size1);
    printf("Time : %f\n", ((double)(t)) / CLOCKS_PER_SEC);

    selectionSortName(Name, size2);
    t = clock() - t;
    printSortName(Name, size2);
    printf("Time : %f\n\n", ((double)(t)) / CLOCKS_PER_SEC);

    printf("--Insertion SORT-- \n");
    insertionSortId(Id, size1);
    t = clock() - t;
    printSortId(Id, size1);
    printf("Time : %f\n", ((double)(t)) / CLOCKS_PER_SEC);

    insertionSortName(Name, size2);
    t = clock() - t;
    printSortName(Name, size2);
    printf("Time : %f\n\n", ((double)(t)) / CLOCKS_PER_SEC);

    printf("--Bubble SORT--\n");
    bubbleSortId(Id, size1);
    t = clock() - t;
    printSortId(Id, size1);
    printf("Time : %f\n", ((double)(t)) / CLOCKS_PER_SEC);

    bubbleSortName(Name, size2);
    t = clock() - t;
    printSortName(Name, size2);
    printf("Time : %f\n\n", ((double)(t)) / CLOCKS_PER_SEC);

    printf("--Merge SORT--\n");
    mergeSortId(Id, 0, size1 - 1);
    t = clock() - t;
    printSortId(Id, size1);
    printf("Time : %f\n", ((double)(t)) / CLOCKS_PER_SEC);

    mergeSortName(Name, 0, size2 - 1);
    t = clock() - t;
    printSortName(Name, size2);
    printf("Time : %f\n\n", ((double)(t)) / CLOCKS_PER_SEC);



    printf("--Quick SORT--\n");
	quickSortId(Id , 0 , size1-1);
	t = clock() - t;
	printSortId(Id,size1);
	printf("Time : %f\n", ((double)(t)) / CLOCKS_PER_SEC);
	
	quickSortName(Name, 0, size2 - 1);
	t = clock() - t;
	printSortName(Name, size2);
	printf("Time : %f\n\n", ((double)(t)) / CLOCKS_PER_SEC);
	
	
    
    printf("--Heap SORT--\n");
	heapSortId(Id , size1);
	t = clock() - t;
	printSortId(Id,size1);
	printf("Time : %f\n", ((double)(t)) / CLOCKS_PER_SEC);
	
	heapSortName(Name, size2 );
	t = clock() - t;
	printSortName(Name, size2);
	printf("Time : %f\n\n", ((double)(t)) / CLOCKS_PER_SEC);



    return 0;
}
