#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
void swapchar(char* a, char* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
  
//Bubble sort
void bubbleSort(int arr[], int size){
     int temp;
     int a, b;
     int c;
     
     
     for (a=1; a<size; a++)
     {
        c = size-a;
        
        for (b=0; b<c; b++)
         {
            if(arr[b] > arr[b+1])
             {
                temp = arr[b];
                arr[b] = arr[b+1];
                arr[b+1] = temp;
             }
         }
    }
}

void bubblechar(char arr[], int size){
     char temp;
     int a, b;
     int c;
     
     
     for (a=1; a<size; a++)
     {
       c=size-a;
       for (b=0; b<c; b++)
       {
          if(arr[b] > arr[b+1])
           {
            temp = arr[b];
            arr[b] = arr[b+1];
             arr[b+1] = temp;
             }
         }
    }
}



//Insertion Sort
void InsertionSort(int arr[], int number)
{
	int x, key, y;
	for (x = 1; x < number; x++) {
		key = arr[x];
		y = x - 1;
		
		while (y >= 0 && arr[y] > key) {
		    
			arr[y + 1] = arr[y];
			y = y - 1;
		}
		arr[y + 1] = key;
	}
}

void Insertionchar(char arr[], int number){
	int a,b;
	char key;
	for (a=1; a<number; a++){
		key = arr[a];
		b = a-1;
		while(b >= 0 && arr[b] > key){
			arr[b+1] = arr[b];
			b = b-1;
		}
		arr[b+1] = key;
	}
}

//Selection Sort
void SelectionSort(int *p, int size)
{
   int   x, y, temp, min;

   for (x = 0; x < size - 1; x++) {
      min = x;
      for (y = x + 1; y < size; y++)
         if (p[min] > p[y])
            min = y;
      temp = p[min];
      p[min] = p[x];
      p[x] = temp;
   }
}

void Selectionchar(char arr[], int number)
{
      int  x, y, min;
      char temp;


   for (x = 0; x < number - 1; x++) {
      min = x;
      for (y = x+ 1; y < number; y++)
         if (arr[min] > arr[y])
            min = y;
      temp = arr[min];
      arr[min] = arr[x];
      arr[x] = temp;
}
}



//Merge Sort
void merge(int *Arr, int start, int mid, int end) {

	int temp[end - start + 1];
	int x = start ;
	int y = mid+1 ;
	int k = 0;

	while(x <= mid && y <= end) {
		if(Arr[x] <= Arr[y]) {
			temp[k] = Arr[x];
			k += 1; 
			x += 1;
		}
		else {
			temp[k] = Arr[y];
			k += 1;
			y += 1;
		}
	}
	while(x <= mid) {
		temp[k] = Arr[x];
		k += 1; 
		x += 1;
	}

	while(y <= end) {
		temp[k] = Arr[y];
		k += 1; 
		y += 1;
	}

	for(x = start; x <= end; x += 1) {
		Arr[x] = temp[x - start];
	}
}
void mergeSort(int *Arr, int start, int end) {

	if(start < end) {
		int mid = ((start + end) / 2);
		mergeSort(Arr, start, mid);
		mergeSort(Arr, mid+1, end);
		merge(Arr, start, mid, end);
	}
}

 void mergesort(char *Arr, int start, int mid, int end) {

	int temp[end - start + 1];
	int x = start, y = mid+1, k = 0;

	while(x <= mid && y <= end) {
		if(Arr[x] <= Arr[y]) {
			temp[k] = Arr[x];
			k += 1; x+= 1;
		}
		else {
			temp[k] = Arr[y];
			k += 1; y += 1;
		}
	}
	while(x <= mid) {
		temp[k] = Arr[x];
		k += 1; x += 1;
	}

	while(y <= end) {
		temp[k] = Arr[y];
		k += 1; y += 1;
	}

	for(x = start; x <= end; x += 1) {
		Arr[x] = temp[x - start];
	}
}
void mergesortchar(char *Arr, int start, int end) {

	if(start < end) {
		int mid = (start + end) / 2;
		mergesortchar(Arr, start, mid);
		mergesortchar(Arr, mid+1, end);
		mergesort(Arr, start, mid, end);
	}
}

 // quickSort
int quick (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1); 
  
    for (int j = low; j <= high- 1; j++) 
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
int quickchar (char arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] < pivot) 
        { 
            i++;     
            swapchar(&arr[i], &arr[j]); 
        } 
    } 
    swapchar(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 

        int pi = quick(arr, low, high); 
  
 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
void quickSortchar(char arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        
        int pi = quickchar(arr, low, high); 
        quickSortchar(arr, low, pi - 1); 
        quickSortchar(arr, pi + 1, high); 
    } 
} 

//heapSort
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
  
 void heapifychar(char arr[], int n, int i) 
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
        swapchar(&arr[i], &arr[largest]); 
  
        heapifychar(arr, n, largest); 
    } 
} 
void heapSort(int arr[], int n) 
{ 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    for (int i=n-1; i>0; i--) 
    { 
        swap(&arr[0], &arr[i]); 
  
        heapify(arr, i, 0); 
    } 
} 
void heapSortchar(char arr[], char n) 
{ 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapifychar(arr, n, i); 
  
    for (int i=n-1; i>0; i--) 
    { 
        swapchar(&arr[0], &arr[i]); 
  
        heapifychar(arr, i, 0); 
    } 
} 


 void prints(int arr[], int size){
      int a;
      for(a = 0; a < size ; a++){
          
          printf("%d ",arr[a]);
          
      }
}




 int main(){
     
     
     clock_t t;
     
     //BubbleSort
      int arr[] ={2,0,1,8,5,5,5,4,5,3} ;
      int x = sizeof(arr)/sizeof(arr[0]);
      char name[] = "murat ozcan";
      int char0 = strlen(name);

      t = (double)clock();
      bubbleSort(arr, x);
      printf("\nSorted numbers in Bubble Sort:");
      prints(arr,x);
      bubblechar(name,char0);
      t = clock()-t;
      printf("\nSorted name in Bubble Sort : %s\n",name);
      printf("Running time of Bubble Sort: %f\n",((double)t) / CLOCKS_PER_SEC);



      //SelectionSort
 	  int ar1[] = {2,0,1,8,5,5,5,4,5,3};
      int y = sizeof(arr)/sizeof(ar1[0]);
      char name1[] = "murat ozcan";
      int char1 = strlen(name1);

      t = (double)clock();

      SelectionSort(ar1, y);
      printf("\nSorted numbers in Selection Sort:");
      prints(ar1,y);
      Selectionchar(name1,char1);
      t =(double)clock()-t;
      printf("\nSorted name in Selection Sort : %s\n",name1);
      printf("Running time of Selection Sort : %f\n",((double)t) / CLOCKS_PER_SEC);

      //MergeSort
      int ar2[] ={2,0,1,8,5,5,5,4,5,3} ;
      int z = sizeof(arr)/sizeof(ar2[0]);
      char name2[] = "murat ozcan";
      int char2 = strlen(name2);

      t = (double)clock();
      mergeSort(ar2,0, z-1);
      printf("\nSorted numbers in Merge Sort:");
      prints(ar2,z);
      mergesortchar(name2,0,char2-1);
      t = (double)clock()-t;
      printf("\nSorted name in Merge Sort : %s\n",name2);
      printf("Running time of Merge Sort: %f\n",((double)t) / CLOCKS_PER_SEC);
      
       	  //InsertionSort
 	  int ar3[] = {2,0,1,8,5,5,5,4,5,3};
      int f = sizeof(arr)/sizeof(ar3[0]);
      char name3[] = "murat ozcan";
      int char3 = strlen(name3);

      t = (double)clock();
      InsertionSort(ar3, f);
      printf("\nSorted numbers in InsertionSort:");
      prints(ar3,f);
      Insertionchar(name3,char3);
      t = (double)clock()-t;
      printf("\nSorted name in Insertion Sort : %s\n",name3);
      printf("Running time of Insertion Sort: %f\n",((double)t) / CLOCKS_PER_SEC);
      
      // quickSort
      int ar4[] ={2,0,1,8,5,5,5,4,5,3} ;
      int p = sizeof(arr)/sizeof(ar4[0]);
      char name5[] = "murat ozcan";
      int char6 = strlen(name5);
      t = (double)clock();

      quickSort(ar4,0, p-1);
      printf("\nSorted numbers in   quick Sort:");
      prints(ar4,p);
      quickSortchar(name5,0,char6-1);
      t = (double)clock()-t;
      printf("\nSorted name in  quick Sort : %s\n",name5);
      printf("Running time of quick Sort: %f \n",((double)t) / CLOCKS_PER_SEC);

     //heapSort
    int ar8[] = {2,0,1,8,5,5,5,4,5,3}; 
    int n = sizeof(arr)/sizeof(ar8[0]);
    char name8[] = "murat ozcan";
    int char8 = strlen(name8);
    t = (double)clock();

    
    heapSort(ar8, n); 
    printf("\nSorted array in heapSort:"); 
    prints(ar8, n); 
    heapSortchar(name8,char8);
    t = (double)clock()-t;
    printf("\nSorted name in heapSort: %s \n ",name8);
    printf("Running time of heapSort: %f \n",((double)t) / CLOCKS_PER_SEC);

    return 0;
