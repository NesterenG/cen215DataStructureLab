#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>

void
insertionSort_N (int arr[], int n)
{
  int i, k, j;

  for (i = 1; i < n; i++)
    {
      k = arr[i];
      j = i - 1;

      while (j >= 0 && arr[j] > k)
	{
	  arr[j + 1] = arr[j];
	  j = j - 1;
	}
      arr[j + 1] = k;
    }
}

void
insertionSort_C (char arr[], int n)
{
  int i, j;
  char c;

  for (i = 1; i < n; i++)
    {
      c = arr[i];
      j = i - 1;

      while (j >= 0 && arr[j] > c)
	{
	  arr[j + 1] = arr[j];
	  j = j - 1;
	}
      arr[j + 1] = c;
    }
}

void
swap_Number (int *xp, int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void
swap_Char (char *xp, char *yp)
{
  char temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void
selectionSort_N (int arr[], int n2)
{
  int i, j, m;

  for (i = 0; i < n2 - 1; i++)
    {
      m = i;
      for (j = i + 1; j < n2; j++)
	{
	  if (arr[j] < arr[m])
	    m = j;
	}
      swap_Number (&arr[m], &arr[i]);
    }
}

void
selectionSort_C (char arr[], int n2)
{
  int i, j;
  char m;

  for (i = 0; i < n2 - 1; i++)
    {
      m = i;
      for (j = i + 1; j < n2; j++)
	{
	  if (arr[j] < arr[m])
	    m = j;
	}
      swap_Char (&arr[m], &arr[i]);
    }
}

void
bubbleSort_N (int arr[], int n3)
{
  int i, j;
  for (i = 0; i < n3 - 1; i++)
    {
      for (j = 0; j < n3 - i - 1; j++)
	{
	  if (arr[j] > arr[j + 1])
	    {
	      swap_Number (&arr[j], &arr[j + 1]);
	    }
	}
    }
}

void
bubbleSort_C (char arr[], int n3)
{
  int i, j;
  
  for (i = 0; i < n3 - 1; i++)
    {
      for (j = 0; j < n3 - i - 1; j++)
	{
	  if (arr[j] > arr[j + 1])
	    {
	      swap_Char (&arr[j], &arr[j + 1]);
	    }
	}
	
    }
}

void
merge_N (int arr[], int l, int m, int r)
{
  int i, j, k;
  int n = m - l + 1;
  int n2 = r - m;
  int L[n], R[n2];

  for (i = 0; i < n; i++)
    L[i] = arr[l + i];

  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];


  i = 0;
  j = 0;
  k = l;

  while (i < n && j < n2)
    {
      if (L[i] <= R[j])
	{
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

  while (i < n)
    {
      arr[k] = L[i];
      i++;
      k++;
    }

  while (j < n2)
    {
      arr[k] = R[j];
      j++;
      k++;
    }
}

void
mergeSort_N (int arr[], int l, int r)
{
  if (l < r)
    {
      int m = l + (r - l) / 2;

      mergeSort_N (arr, l, m);
      mergeSort_N (arr, m + 1, r);
      merge_N (arr, l, m, r);
    }
}

void
merge_C (char arr[], int l, int m, int r)
{
  int i, j, k;
  int n = m - l + 1;
  int n2 = r - m;
  int L[n], R[n2];

  for (i = 0; i < n; i++)
    L[i] = arr[l + i];

  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];


  i = 0;
  j = 0;
  k = l;

  while (i < n && j < n2)
    {
      if (L[i] <= R[j])
	{
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

  while (i < n)
    {
      arr[k] = L[i];
      i++;
      k++;
    }

  while (j < n2)
    {
      arr[k] = R[j];
      j++;
      k++;
    }
}

void
mergeSort_C (char arr[], int l, int r)
{
  if (l < r)
    {
      int m = l + (r - l) / 2;

      mergeSort_C (arr, l, m);
      mergeSort_C (arr, m + 1, r);
      merge_C (arr, l, m, r);
    }
}

void

quicksort_N(int num[], int x, int y)
{
	int z, w, pivot, temp;

	if (x < y) 
	{
		pivot = x;
		z = x;
		w = y;

		while (z < w) 
		{
			while (num[z] <= num[pivot] && x < y)
				z++;
			while (num[w] > num[pivot])
				w--;
				
			if (z < w)
			{
				temp = num[z];
				num[z] = num[w];
				num[w] = temp;
			}
		}

		temp = num[pivot];
		num[pivot] = num[w];
		num[w] = temp;
		quicksort_N(num, x, w - 1);
		quicksort_N(num, w + 1, y);

	}
}

void
quicksort_C(char name[], int x, int y)
{
	int z, w, pivot, temp;

	if (x < y) 
	{
		pivot = x;
		z = x;
		w = y;

		while (z < w) 
		{
			while (name[z] <= name[pivot] && x < y)
				z++;
			while (name[w] > name[pivot])
				w--;
				
			if (z < w)
			{
				temp = name[z];
				name[z] = name[w];
				name[w] = temp;
			}
		}

		temp = name[pivot];
		name[pivot] = name[w];
		name[w] = temp;
		quicksort_C(name, x, w - 1);
		quicksort_C(name, w + 1, y);

	}
}

void
heap_number(int num[], int size, int i)
{
	int temp;
	int x = i;
	int z = 2 * i + 1;
	int c = 2 * i + 2;

	if (z < size && num[z] >num[x])
	{
		x = z;
	}
	
	if (c < size && num[c] > num[x])
	{	
	    x = c;
	}   

	if (x!= i)
	{
		temp = num[i];
		num[i] = num[x];
		num[x] = temp;
		heap_number(num, size, x);
	}
}

void
heap_N(int num[], int size)
{
    
	int temp, i;
	
	for (i = size / 2 - 1; i >= 0; i--)
	{
		heap_number(num, size, i);
	}
	
	for (i = size - 1; i >= 0; i--)
	{
		temp = num[0];
		num[0] = num[i];
		num[i] = temp;
		heap_number(num, i, 0);
	}
}

void
heap_name(char name[], int size, int i)
{
	int temp;
	int x = i;
	int z = 2 * i + 1;
	int c = 2 * i + 2;

	if (z < size && name[z] > name[x])
	{
		x = z;
	}
	
	if (c < size && name[c] > name[x])
	{	
	    x = c;
	}   

	if (x!= i)
	{
		temp = name[i];
		name[i] = name[x];
		name[x] = temp;
		heap_name(name, size, x);
	}
}

void
heap_C(char name[], int size)
{
    
	int temp, i;
	
	for (i = size / 2 - 1; i >= 0; i--)
	{
		heap_name(name, size, i);
	}
	
	for (i = size - 1; i >= 0; i--)
	{
		temp = name[0];
		name[0] = name[i];
		name[i] = temp;
		heap_name(name, i, 0);
	}
}

void

printArray (int arr[], int n)
{
  int i;
  for (i = 0; i < n; i++)
    printf ("%d ", arr[i]);
  printf ("\n");
}

int
main ()
{

  //Insertion
  int num[] = { 2, 0, 1, 7, 5, 5, 6, 0, 4, 2 };
  char name[] = "can ogutken";

  clock_t start;

  int n = sizeof (num) / sizeof (num[0]);
  int charSize = strlen (name);

  start = clock ();
  insertionSort_N (num, n);
  start = clock () - start;

  printArray (num, n);
  printf ("Time of Insertion Sort: %f\n", ((double) start) / CLOCKS_PER_SEC);

  insertionSort_C (name, charSize);

  start = clock () - start;

  printf ("%s\n", name);
  printf ("Time of char Insertion  Sort:  %f\n\n",
	  ((double) start) / CLOCKS_PER_SEC);
  //-----------------

  //Selection
  int num1[] = { 2, 0, 1, 7, 5, 5, 6, 0, 4, 2 };
  char name1[] = "can ogutken";

  int n1 = sizeof (num1) / sizeof (num1[0]);
  int charSize1 = strlen (name1);

  selectionSort_N (num1, n1);
  start = clock () - start;

  printArray (num1, n1);
  printf ("Time of Selection Sort: %f\n", ((double) start) / CLOCKS_PER_SEC);

  selectionSort_C (name1, charSize1);
  start = clock () - start;

  printf ("%s \n", name1);
  printf ("Time of char Selection Sort: %f\n\n",
	  ((double) start) / CLOCKS_PER_SEC);
  //-----------------

  //Bubble
  int num2[] = { 2, 0, 1, 7, 5, 5, 6, 0, 4, 2 };
  char name2[] = "can ogutken";

  int n2 = sizeof (num2) / sizeof (num2[0]);
  int charSize2 = strlen (name2);

  bubbleSort_N (num2, n2);
  start = clock () - start;

  printArray (num2, n2);
  printf ("Time of Bubble Sort: %f\n", ((double) start) / CLOCKS_PER_SEC);

  bubbleSort_C (name2, charSize2);

  start = clock () - start;

  printf ("%s\n", name2);
  printf ("Time of char Bubble Sort: %f\n\n",
	  ((double) start) / CLOCKS_PER_SEC);
  //-----------------

  //Merge
  int num3[] = { 2, 0, 1, 7, 5, 5, 6, 0, 4, 2 };
  char name3[] = "can ogutken";

  int n3 = sizeof (num3) / sizeof (num3[0]);
  int charSize3 = strlen (name3);

  mergeSort_N (num3, 0, n3 - 1);
  start = clock () - start;

  printArray (num3, n3);
  printf ("Time of Merge Sort: %f\n", ((double) start) / CLOCKS_PER_SEC);

  mergeSort_C (name3, 0, charSize3 - 1);
  start = clock () - start;

  printf ("%s\n", name3);
  printf ("Time of char Merge Sort: %f\n\n",
	  ((double) start) / CLOCKS_PER_SEC);

 //-----------------
 
 //Quick
  int num4[] = { 2, 0, 1, 7, 5, 5, 6, 0, 4, 2 };
  char name4[] = "can ogutken";

  int n4 = sizeof (num4) / sizeof (num4[0]);
  int charSize4 = strlen (name4);

  quicksort_N(num4, 0, n3 - 1);
  start = clock () - start;

  printArray (num4, n4);
  printf ("Time of Quick Sort: %f\n", ((double) start) / CLOCKS_PER_SEC);

  quicksort_C(name4, 0, charSize3 - 1);
  start = clock () - start;

  printf ("%s\n", name4);
  printf ("Time of char Quick Sort: %f\n\n",
	  ((double) start) / CLOCKS_PER_SEC);
 //-----------------
 
 //Heap
  int num5[] = { 2, 0, 1, 7, 5, 5, 6, 0, 4, 2 };
  char name5[] = "can ogutken";

  int n5 = sizeof (num5) / sizeof (num5[0]);
  int charSize5 = strlen (name5);

  heap_N(num5, n5);
  start = clock () - start;

  printArray (num5, n5);
  printf ("Time of Heap Sort: %f\n", ((double) start) / CLOCKS_PER_SEC);

  heap_C(name5, charSize5);
  start = clock () - start;

  printf ("%s\n", name5);
  printf ("Time of char Heap Sort: %f\n\n",
	  ((double) start) / CLOCKS_PER_SEC);


  return 0;
}
