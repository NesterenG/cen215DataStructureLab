
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>


//Print
void printarraynum(int array[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}
/////////////////////////

//swap
void swapnum(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void swapname(char *xp, char *yp) 
{ 
    char temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
/////////////////////////

//Insertion Sort
void insertionsortnum(int arr[], int size) {
  for (int step = 1; step < size; step++) {
    int key = arr[step];
    int j = step - 1;

    while (key < arr[j] && j >= 0) {
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = key;
    
  }
}


void insertionsortname(char arr[], int size) {
  for (int step = 1; step < size; step++) {
    char key = arr[step];
    int j = step - 1;

    while (key < arr[j] && j >= 0) {
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = key;  
  }
}
////////////////////////////

//Selection Sort
void selectionsortnum(int arr[], int size) 
{ 
    int i, j, key; 
  
    
    for (i = 0; i < size-1; i++) 
    { 
         
        key = i; 
        for (j = i+1; j < size; j++) 
          if (arr[j] < arr[key]) 
            key = j; 
  
        
        swapnum(&arr[key], &arr[i]); 
    } 
} 

void selectionsortname(char arr[], int size) 
{ 
    int i, j;
    char key;
    
    for (i = 0; i < size-1; i++) 
    { 
        
        key = i; 
        for (j = i+1; j < size; j++) 
          if (arr[j] < arr[key]) 
            key = j; 
  
        
        swapname(&arr[key], &arr[i]); 
    } 
} 
//////////////////////////

//Merge Sort
void mergesortnum(int arr[],int first,int middle,int last){
int i,j,k;
int n1 = middle - first + 1;
int n2 = last - middle; 
int *f=(int*)malloc(sizeof(int)*n1);
int *s=(int*)malloc(sizeof(int)*n2);


    for (i = 0; i < n1; i++) 
        f[i] = arr[first + i]; 
    for (j = 0; j < n2; j++) 
        s[j] = arr[middle + 1 + j]; 
 
    
    i = 0; 
    j = 0; 
    k = first; 
    while (i < n1 && j < n2) { 
        if (f[i] <= s[j]) { 
            arr[k] = f[i]; 
            i++; 
        } 
        else { 
            arr[k] = s[j]; 
            j++; 
        } 
        k++; 
    } 
 
    while (i < n1) { 
        arr[k] = f[i]; 
        i++; 
        k++; 
    } 

    while (j < n2) { 
        arr[k] = s[j]; 
        j++; 
        k++; 
    } 
} 
 

void mergesortname(char arr[],int first,int middle,int last){
int i,j,k;
int n1 = middle - first + 1;
int n2 = last - middle; 
int *f=(int*)malloc(sizeof(int)*n1);
int *s=(int*)malloc(sizeof(int)*n2);

    for (i = 0; i < n1; i++) 
        f[i] = arr[first + i]; 
    for (j = 0; j < n2; j++) 
        s[j] = arr[middle + 1 + j]; 
 
    i = 0;  
    j = 0; 
    k = first; 
    while (i < n1 && j < n2) { 
        if (f[i] <= s[j]) { 
            arr[k] = f[i]; 
            i++; 
        } 
        else { 
            arr[k] = s[j]; 
            j++; 
        } 
        k++; 
    } 
 
    while (i < n1) { 
        arr[k] = f[i]; 
        i++; 
        k++; 
    } 
 
    while (j < n2) { 
        arr[k] = s[j]; 
        j++; 
        k++; 
    } 
} 

void mergesort(int arr[], int first, int last) 
{ 
    if (first < last) { 

        int middle = first + (last - first) / 2; 
 
        mergesort(arr,first, middle); 
        mergesort(arr, middle + 1, last); 
 
        mergesortnum(arr, first, middle, last); 
        
    } 
} 

void mergesortn(char arr[], int first, int last) 
{ 
    if (first < last) { 

        int middle = first + (last - first) / 2; 
 
         
        mergesortn(arr,first, middle); 
        mergesortn(arr, middle + 1, last); 
 
        mergesortname(arr, first, middle, last); 
        
    } 
} 
////////////////////////////////////////////////

//Bubble Sort
void bubblesortnum(int arr[], int size) 
{ 
   int i, j; 
   for (i = 0; i < size-1; i++)          
       for (j = 0; j < size-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swapnum(&arr[j], &arr[j+1]); 
} 

void bubblesortname(char arr[], int size) 
{ 
   int i, j; 
   for (i = 0; i < size-1; i++)        
       for (j = 0; j < size-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swapname(&arr[j], &arr[j+1]); 
} 

///////////////////////////////////////////////

//Quick Sort
int partitionnum(int num[], int low, int high)
{

    char pivot = num[high];

    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (num[j] < pivot)
        {
            i++;
            swapnum(&num[i], &num[j]);
        }
    }

    swapnum(&num[i + 1], &num[high]);
    return i + 1;
}

void quicksortnum(int num[], int low, int high)
{
    int pivot;
    if (low < high)
    {
        pivot = partitionnum(num, low, high);
        quicksortnum(num, low, pivot - 1);
        quicksortnum(num, pivot + 1, high);
    }
}

int partitionname(char name[], int low, int high)
{

    int pivot = name[high];

    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (name[j] < pivot)
        {
            i++;
            swapname(&name[i], &name[j]);
        }
    }

    swapname(&name[i + 1], &name[high]);
    return i + 1;
}

void quicksortname(char name[], int low, int high)
{
    int pivot;
    if (low < high)
    {
        pivot = partitionname(name, low, high);
        quicksortname(name, low, pivot - 1);
        quicksortname(name, pivot + 1, high);
    }
}
//////////////////////////////////////

//Heap Sort
void heapifynum(int num[], int size, int root)
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
        swapnum(&num[largest], &num[root]);

        heapifynum(num, size, largest);
    }
}

void heapsortnum(int num[], int size)
{

    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapifynum(num, size, i);
    }

    for (int i = size - 1; i > 0; i--)
    {
        swapnum(&num[0], &num[i]);

        heapifynum(num, i, 0);
    }
}


void heapifyname(char name[], int size, int root)
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
        swapname(&name[largest], &name[root]);

        heapifyname(name, size, largest);
    }
}

void heapsortname(char name[], int size)
{

    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapifyname(name, size, i);
    }

    for (int i = size - 1; i > 0; i--)
    {
        swapname(&name[0], &name[i]);

        heapifyname(name, i, 0);
    }
}
//////////////////////////////////////


int main() {
  clock_t i,in,s,sn,m,mn,b,bn,q,qn,h,hn;

  //Insertion Sort
  int num[] = {2,0,1,9,5,5,5,0,5,8};
  int size = sizeof(num) / sizeof(num[0]);
  char name[] = "anil onal";
  int sizec = strlen(name);
  printf("\t\tInsertion Sort\n");
  i=clock();
  insertionsortnum(num, size);
  i=clock()-i;
  printarraynum(num, size);
  printf("number's function duration %f\n",((float)i)/(CLOCKS_PER_SEC/1000));
  in=clock();
  insertionsortname(name, sizec);
  in=clock()-in;
  printf("%s\n", name);
  printf("name's function duration %f\n",((float)in)/(CLOCKS_PER_SEC/1000));
  ////////////////////////////////////

  //Selection Sort
  int num1[] = {2,0,1,9,5,5,5,0,5,8};
  int size1 = sizeof(num1) / sizeof(num1[0]);
  char name1[] = "anil onal";
  int sizec1 = strlen(name1);
  printf("\n\t\tSelection Sort\n");
  s=clock();
  selectionsortnum(num1,size1);
  s=clock()-s;
  printarraynum(num1, size1);
  printf("number's function duration %f\n",((float)s)/CLOCKS_PER_SEC);
  sn=clock();
  selectionsortname(name1,sizec1);
  sn=clock()-sn;
  printf("%s\n",name1);
  printf("name's function duration %f\n",((float)sn)/CLOCKS_PER_SEC);
  //////////////////////////////////

  //Merge Sort
  int num2[] = {2,0,1,9,5,5,5,0,5,8};
  int size2 = sizeof(num2) / sizeof(num2[0]);
  char name2[] = "anil onal";
  int sizec2 = strlen(name2);
  printf("\n\t\tMerge Sort\n");
  m=clock();
  mergesort(num2,0,size2-1);
  m=clock()-m;
  printarraynum(num2,size2);
  printf("number's function duration %f\n",((float)m)/CLOCKS_PER_SEC);
  mn=clock();
  mergesortn(name2,0,sizec2-1);
  mn=clock()-mn;
  printf("%s\n",name2);
  printf("name's function duration %f\n",((float)mn)/CLOCKS_PER_SEC);
  //////////////////////////////////////

  //Bubble Sort
  int num3[] = {2,0,1,9,5,5,5,0,5,8};
  int size3 = sizeof(num3) / sizeof(num3[0]);
  char name3[] = "anil onal";
  int sizec3 = strlen(name3);
  printf("\n\t\tBubble Sort\n");
  b=clock();
  bubblesortnum(num3, size3);
  b=clock()-b;
  printarraynum(num3,size3);
  printf("number's function duration %f\n",((float)b)/CLOCKS_PER_SEC);
  bn=clock();
  bubblesortname(name3, sizec3);
  bn=clock()-bn;
  printf("%s\n",name3);
  printf("name's function duration %f\n",((float)bn)/CLOCKS_PER_SEC);
  ///////////////////////////////////////

  //Quick Sort
  int num4[] = {2,0,1,9,5,5,5,0,5,8};
  int size4 = sizeof(num4) / sizeof(num4[0]);
  char name4[] = "anil onal";
  int sizec4 = strlen(name4);
  printf("\n\t\tQuick Sort\n");
  q=clock();
  quicksortnum(num4,0,size4-1);
  q=clock()-q;
  printarraynum(num4,size4);
  printf("number's function duration %f\n",((float)q)/CLOCKS_PER_SEC);
  qn=clock();
  quicksortname(name4,0,sizec4-1);
  qn=clock()-qn;
  printf("%s\n",name4);
  printf("name's function duration %f\n",((float)qn)/CLOCKS_PER_SEC);
  /////////////////////////////////////////////////////

  //Heap Sort
  int num5[] = {2,0,1,9,5,5,5,0,5,8};
  int size5 = sizeof(num5) / sizeof(num5[0]);
  char name5[] = "anil onal";
  int sizec5 = strlen(name5);
  printf("\n\t\tHeap Sort\n");
  h=clock();
  heapsortnum(num5, size5);
  h=clock()-h;
  printarraynum(num5,size5);
  printf("number's function duration %f\n",((float)h)/CLOCKS_PER_SEC);
  hn=clock();
  heapsortname(name5, sizec5);
  hn=clock()-hn;
  printf("%s\n",name5);
  printf("name's function duration %f\n",((float)hn)/CLOCKS_PER_SEC);

 return 0;
}