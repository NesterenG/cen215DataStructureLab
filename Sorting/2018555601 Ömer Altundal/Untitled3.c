#include <stdio.h>
#include <stdlib.h>
#include <time.h>
	
void print_func_for_num(int array[],int size)
{
	int i=0;
	for(i;i<size;i++)
	printf("%d",array[i]);
}
void print_func_for_char(char array[],int size)
{
	int i=0;
	for(i;i<size;i++)
	printf("%c",array[i]);
}


void buble_sort_for_number(int arr[],int size)
{
	int temp, k, i;
	for (i = 0; i < (size-1); i++){
	for (k = 0; k < (size-1-i); k++){
	if (arr[k] > arr[k+1]){ 
	temp = arr[k];
	arr[k] = arr[k+1];
	arr[k+1] = temp;
	}
	}
	}
	printf("\n\n\nMy number is sorted with buble sort:");
	print_func_for_num(arr,size);
}

void buble_sort_for_name(char arr[],int size)
{
	int temp, k, i;
	for (i = 0; i < (size-1); i++){
	for (k = 0; k < (size-1-i); k++){
	if (arr[k] > arr[k+1]){ 
	temp = arr[k];
	arr[k] = arr[k+1];
	arr[k+1] = temp;
	}
	}
	}
	printf("\nMy name is sorted with buble sort:");
	print_func_for_char(arr,size);
}

void insertion_sort_for_number(int arr[], int size)
{
	int i, k, key;
	for (i = 1; i < size; i++)
	{
	key = arr[i];
	for (k = i-1; k>=0 && key <= arr[k]; k--)
	arr[k+1] = arr[k]; 
	arr[k+1] = key; 
	}
	printf("\n\n\nMy number is sorted with insertion sort:");
	print_func_for_num(arr,size);
}

void insertion_sort_for_name(char arr[], int size)
{
	int i, k, key;
	for (i = 1; i < size; i++)
	{
	key = arr[i];
	for (k = i-1; k>=0 && key <= arr[k]; k--)
	arr[k+1] = arr[k]; 
	arr[k+1] = key; 
	}
	printf("\nMy name is sorted with insertion sort:");
	print_func_for_char(arr,size);
}

void selection_sort_for_number(int arr[], int size) 
{
	int i, index, j, min;
	for (i = 0; i < (size-1); i++) {
	min = arr[size-1];
	index = size-1;
	for (j = i; j < (size-1); j++){
	if (arr[j] < min){
	min = arr[j];
	index = j;
	}
	}
	if (i != index){
	arr[index] = arr[i];
	arr[i] = min;
	}
	}
	printf("\n\n\nMy number is sorted with selecetion sort:");
	print_func_for_num(arr,size);
}

void selection_sort_for_name(char arr[], int size) 
{
	int i, index, j, min;
	for (i = 0; i < (size-1); i++) {
	min = arr[size-1];
	index = size-1;
	for (j = i; j < (size-1); j++){
	if (arr[j] < min){
	min = arr[j];
	index = j;
	}
	}
	if (i != index){
	arr[index] = arr[i];
	arr[i] = min;
	}
	}
	printf("\nMy name is sorted with selecetion sort:");
	print_func_for_char(arr,size);
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
    else 
	{ 
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
 

void merge_sort_for_number(int arr[], int l, int r) 
{ 
    if (l < r) { 
    int m = l + (r - l) / 2; 
        
    merge_sort_for_number(arr, l, m); 
    merge_sort_for_number(arr, m + 1, r); 
   
    merge(arr, l, m, r); 
    } 
} 

void merge1(char arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m;    
    char L[n1], R[n2]; 

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
 

void merge_sort_for_name(char arr[], int l, int r) 
{ 
    if (l < r) { 
    int m = l + (r - l) / 2; 
    merge_sort_for_name(arr, l, m); 
    merge_sort_for_name(arr, m + 1, r); 
    
	merge1(arr, l, m, r); 
    } 
} 

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
  

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];   
    int i = (low - 1);   
  	int j=low;
    for (j; j <= high- 1; j++) 
    { 
  
        if (arr[j] < pivot) 
        { 
            i++;    
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
void quick_sort_for_number(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
		quick_sort_for_number(arr, low, pi - 1); 
        quick_sort_for_number(arr, pi + 1, high); 
    } 
} 
void swap_name(char* a, char* b) 
{ 
    char t = *a; 
    *a = *b; 
    *b = t; 
} 
  


int partition_name (char arr[], int low, int high) 
{ 
    char pivot = arr[high];   
    int i = (low - 1);   
  	int j=low;
    for (j; j <= high- 1; j++) 
    { 
  
        if (arr[j] < pivot) 
        { 
            i++;    
            swap_name(&arr[i], &arr[j]); 
        } 
    } 
    swap_name(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
void quick_sort_for_name(char arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition_name(arr, low, high); 
        
		quick_sort_for_name(arr, low, pi - 1); 
        quick_sort_for_name(arr, pi + 1, high); 
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
  
void heap_sort_for_number(int arr[], int n) 
{ 
	int i;
    for ( i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  	int j;
    for (j=n-1; j>0; j--) 
    { 
        swap(&arr[0], &arr[j]); 
        heapify(arr, j, 0); 
    } 
} 

void heapify_name(char arr[], int n, int i) 
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
        swap_name(&arr[i], &arr[largest]); 
  
        heapify_name(arr, n, largest); 
    } 
} 
  
void heap_sort_for_name(char arr[], int n) 
{ 
	int i ;
    for (i = n / 2 - 1; i >= 0; i--) 
        heapify_name(arr, n, i); 
  	int j;
    for (j=n-1; j>0; j--) 
    { 
        swap_name(&arr[0],&arr[j]); 
        heapify_name(arr, j, 0); 
    } 
} 


int main()
{
	int my_number[]={2,0,1,8,5,5,5,6,0,1};
	char my_name[]="OMER ALTUNDAL";
	int my_number_size=(sizeof(my_number)/(sizeof(my_number[0])));
	int my_name_size=(sizeof(my_name)/(sizeof(my_name[2])));
	
	printf("My name is: ");
	print_func_for_char(my_name,my_name_size);
	printf("\nMy number is: ");
	print_func_for_num(my_number,my_number_size);

		
	clock_t t1;
	t1=clock();
	buble_sort_for_number(my_number,my_number_size);	
	buble_sort_for_name(my_name,my_name_size);
	t1=clock() - t1;
	printf("\nBuble sort worked %f seconds.",((float)t1)/CLOCKS_PER_SEC);
	
	clock_t t2;
	t2=clock();
	insertion_sort_for_number(my_number,my_number_size);	
	insertion_sort_for_name(my_name,my_name_size);
	t2=clock()-t2;
	printf("\nInsertion sort worked %f seconds.",((float)t2)/CLOCKS_PER_SEC);
	
	clock_t t3;
	t3=clock();
	selection_sort_for_number(my_number,my_number_size);	
	selection_sort_for_name(my_name,my_name_size);
	t3=clock()-t3;
	printf("\nSelection sort worked %f seconds.",((float)t3)/CLOCKS_PER_SEC); 
	
	clock_t t4;
	t4=clock();
	merge_sort_for_number(my_number,0,my_number_size-1);
	printf("\n\n\nMy number is sorted with merge sort:");
	print_func_for_num(my_number,my_number_size);
	merge_sort_for_name(my_name,0,my_name_size-1);
	printf("\nMy name is sorted with merge sort:");
	print_func_for_char(my_name,my_name_size);
	t4=clock()-t4;
	printf("\nMerge sort worked %f seconds.",((float)t4)/CLOCKS_PER_SEC); 
	

	clock_t t5;
	t5=clock();
	quick_sort_for_number(my_number,0,my_number_size-1);
	printf("\n\n\nMy number sorted with quick sort:");
	print_func_for_num(my_number,my_number_size);
	quick_sort_for_name(my_name,0,my_name_size-1);
	printf("\nMy name sorted with quick sort:");
	print_func_for_char(my_name,my_name_size);
	t5=clock()-t5;
	printf("\nQuick sort worked %f seconds.",((float)t5/CLOCKS_PER_SEC));
	
	clock_t t6;
	t6=clock();
	heap_sort_for_number(my_number,my_number_size);
	printf("\n\n\nMy number is sorted with heap sort:");
	print_func_for_num(my_number,my_number_size);	
	heap_sort_for_name(my_name,my_name_size);
	printf("\nMy name sorted with heap sort:");
	print_func_for_char(my_name,my_name_size);
	t6=clock()-t6;
	printf("\nHeap sort worked %f seconds.",((float)t6/CLOCKS_PER_SEC));
	
	return 0;
}
