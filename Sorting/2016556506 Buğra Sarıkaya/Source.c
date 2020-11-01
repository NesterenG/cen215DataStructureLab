#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int no[] = { 2,0,1,6,5,5,6,5,0,6 }; //size=10;
char name[] = "BUGRA SARIKAYA"; //size=15-1=14
void insertion_sort_int(int no[], int size) {
	int i, j;
	int mem;
	for (i = 1; i < size; i++) {
		mem = no[i];
		j = i - 1;
		while (j >= 0 && no[j] > mem) {
			no[j + 1] = no[j];
			j = j - 1;
		}
		no[j + 1] = mem;
	}
}
void insertion_sort_char(char name[], int size) {
	int i, j;
	int mem;
	for (i = 1; i < size; i++) {
		mem = name[i];
		j = i - 1;
		while (j >= 0 && name[j] > mem) {
			name[j + 1] = name[j];
			j = j - 1;
		}
		name[j + 1] = mem;
	}
}
void merge_int(int no[], int l, int m, int r){
	int i, j, k, n1, n2;
	n1 = m - l + 1;
	n2 = r - m;


	int*L = (int *)malloc(n1 * sizeof(int));
	int*R = (int *)malloc(n2 * sizeof(int));

	for (i = 0; i < n1; i++)
		L[i] = no[l + i];
	for (j = 0; j < n2; j++)
		R[j] = no[m + 1 + j];

	i = 0;
	j = 0;
	k = l;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			no[k] = L[i];
			i++;
		}
		else {
			no[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		no[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		no[k] = R[j];
		j++;
		k++;
	}
}

void merge_sort_int(int no[], int l, int r){
	if (l < r) {
		int m = l + (r - l) / 2;

		merge_sort_int(no, l, m);
		merge_sort_int(no, m + 1, r);

		merge_int(no, l, m, r);
	}
}
void merge_char(char name[], int l, int m, int r){
	int i, j, k, n1, n2;
	n1 = m - l + 1;
	n2 = r - m;

	int*L = (int *)malloc(n1 * sizeof(int));
	int*R = (int *)malloc(n2 * sizeof(int));

	for (i = 0; i < n1; i++)
		L[i] = name[l + i];
	for (j = 0; j < n2; j++)
		R[j] = name[m + 1 + j];

	i = 0;
	j = 0;
	k = l;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			name[k] = L[i];
			i++;
		}
		else {
			name[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		name[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		name[k] = R[j];
		j++;
		k++;
	}
}
void merge_sort_char(char name[], int l, int r){
	if (l < r) {
		int m = l + (r - l) / 2;

		merge_sort_char(name, l, m);
		merge_sort_char(name, m + 1, r);

		merge_char(name, l, m, r);
	}
}
void swap_int(int *element_1, int *element_2){
	int temp = *element_1;
	*element_1 = *element_2;
	*element_2 = temp;
}
void swap_char(char *element_1, char *element_2){
	char temp = *element_1;
	*element_1 = *element_2;
	*element_2 = temp;
}
void heapify_int(int no[], int n, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < n && no[left] > no[largest])
		largest = left;
	if (right < n && no[right] > no[largest])
		largest = right;
	if (largest != i) {
		swap_int(&no[i], &no[largest]);
		heapify_int(no, n, largest);
	}
}
void heap_sort_int(int no[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify_int(no, n, i);
	for (int i = n - 1; i >= 0; i--) {
		swap_int(&no[0], &no[i]);
		heapify_int(no, i, 0);
	}
}
void heapify_char(char name[], int n, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < n && name[left] > name[largest])
		largest = left;
	if (right < n && name[right] > name[largest])
		largest = right;
	if (largest != i) {
		swap_char(&name[i], &name[largest]);
		heapify_char(name, n, largest);
	}
}
void heap_sort_char(char name[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify_char(name, n, i);
	for (int i = n - 1; i >= 0; i--) {
		swap_char(&name[0], &name[i]);
		heapify_char(name, i, 0);
	}
}
int partition_int(int no[], int low, int high){
	int pivot = no[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (no[j] < pivot)
		{
			i++;
			swap_int(&no[i], &no[j]);
		}
	}
	swap_int(&no[i + 1], &no[high]);
	return (i + 1);
}
void quick_sort_int(int no[], int low, int high){
	if (low < high)
	{
		int pi = partition_int(no, low, high);
		quick_sort_int(no, low, pi - 1);
		quick_sort_int(no, pi + 1, high);
	}
}
int partition_char(char name[], int low, int high){
	int pivot = name[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (name[j] < pivot)
		{
			i++;
			swap_char(&name[i], &name[j]);
		}
	}
	swap_char(&name[i + 1], &name[high]);
	return (i + 1);
}
void quick_sort_char(char name[], int low, int high){
	if (low < high)
	{
		int pi = partition_char(name, low, high);
		quick_sort_char(name, low, pi - 1);
		quick_sort_char(name, pi + 1, high);
	}
}
void bubble_sort_int(int no[], int n){
	int i, j;
	for (i = 0; i < n - 1; i++)

		for (j = 0; j < n - i - 1; j++)
			if (no[j] > no[j + 1])
				swap_int(&no[j], &no[j + 1]);
}
void bubble_sort_char(char name[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (name[j] > name[j + 1])
				swap_char(&name[j], &name[j + 1]);
}
void selection_sort_int(int no[], int n){
	int i, j, min_idx;
	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (no[j] < no[min_idx])
				min_idx = j;
		swap_int(&no[min_idx], &no[i]);
	}
}
void selection_sort_char(char name[], int n){
	int i, j, min_idx;
	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (name[j] < name[min_idx])
				min_idx = j;
		swap_char(&name[min_idx], &name[i]);
	}
}
void show_no(int no[], int size) {
	for (int i = 0; i < size; i++)
		printf("%d ", no[i]);
}
void show_name(char name[], int size) {
	for (int i = 0; i < size; i++)
		printf("%c ", name[i]);
}
void show_original(int size_no, int size_name, int no[], char name[]) {
	printf("---Original--");
	printf("\n");
	show_no(no, size_no);
	printf("\n");
	show_name(name, size_name);
}
void establish_insertion_sort(int size_no, int size_name, int no[], char name[]) {
	clock_t begin, end;
	printf("---Insertion Sort---");
	printf("\n");
	begin = clock();
	insertion_sort_int(no, size_no);
	end = clock();
	show_no(no, size_no);
	printf("\n");
	printf("Time: %f", (float)(end-begin)/CLOCKS_PER_SEC);
	printf("\n");
	begin = clock();
	insertion_sort_char(name, size_name);
	end = clock();
	show_name(name, size_name);
	printf("\n");
	printf("Time: %f", (float)(end - begin) / CLOCKS_PER_SEC);
}
void establish_merge_sort(int size_no, int size_name, int no[], char name[]) {
	clock_t begin, end;
	printf("---Merge Sort---");
	printf("\n");
	begin = clock();
	merge_sort_int(no, 0, size_no - 1);
	end = clock();
	show_no(no, size_no);
	printf("\n");
	printf("Time: %f", (float)(end - begin) / CLOCKS_PER_SEC);
	printf("\n");
	begin = clock();
	merge_sort_char(name, 0, size_name - 1);
	end = clock();
	show_name(name, size_name);
	printf("\n");
	printf("Time: %f", (float)(end - begin) / CLOCKS_PER_SEC);
}
void establish_bubble_sort(int size_no, int size_name, int no[], char name[]) {
	clock_t begin, end;
	printf("---Bubble Sort---");
	printf("\n");
	begin = clock();
	bubble_sort_int(no, size_no);
	end = clock();
	show_no(no, size_no);
	printf("\n");
	printf("Time: %f", (float)(end - begin) / CLOCKS_PER_SEC);
	printf("\n");
	begin = clock();
	bubble_sort_char(name, size_name);
	end = clock();
	show_name(name, size_name);
	printf("\n");
	printf("Time: %f", (float)(end - begin) / CLOCKS_PER_SEC);
}
void establish_selection_sort(int size_no, int size_name, int no[], char name[]) {
	clock_t begin, end;
	printf("---Selection Sort---");
	printf("\n");
	begin = clock();
	selection_sort_int(no, size_no);
	end = clock();
	show_no(no, size_no);
	printf("\n");
	printf("Time: %f", (float)(end - begin) / CLOCKS_PER_SEC);
	printf("\n");
	begin = clock();
	selection_sort_char(name, size_name);
	end = clock();
	show_name(name, size_name);
	printf("\n");
	printf("Time: %f", (float)(end - begin) / CLOCKS_PER_SEC);
}
void establish_selection_quick_sort(int size_no, int size_name, int no[], char name[]) {
	clock_t begin, end;
	printf("---Quick Sort---");
	printf("\n");
	begin = clock();
	quick_sort_int(no, 0, size_no-1);
	end = clock();
	show_no(no, size_no);
	printf("\n");
	printf("Time: %f", (float)(end - begin) / CLOCKS_PER_SEC);
	printf("\n");
	begin = clock();
	quick_sort_char(name, 0, size_name-1);
	end = clock();
	show_name(name, size_name);
	printf("\n");
	printf("Time: %f", (float)(end - begin) / CLOCKS_PER_SEC);
}
void establish_selection_heap_sort(int size_no, int size_name, int no[], char name[]) {
	clock_t begin, end;
	printf("---Heap Sort---");
	printf("\n");
	begin = clock();
	heap_sort_int(no, size_no);
	end = clock();
	show_no(no, size_no);
	printf("\n");
	printf("Time: %f", (float)(end - begin) / CLOCKS_PER_SEC);
	printf("\n");
	begin = clock();
	heap_sort_char(name, size_name);
	end = clock();
	show_name(name, size_name);
	printf("\n");
	printf("Time: %f", (float)(end - begin) / CLOCKS_PER_SEC);
}
void redefinition_no() {
	no[0] = 2;
	no[1] = 0;
	no[2] = 1;
	no[3] = 6;
	no[4] = 5;
	no[5] = 5;
	no[6] = 6;
	no[7] = 5;
	no[8] = 0;
	no[9] = 6;
}
void redefinition_name() {
	name[0] = 'B';
	name[1] = 'U';
	name[2] = 'G';
	name[3] = 'R';
	name[4] = 'A';
	name[5] = ' ';
	name[6] = 'S';
	name[7] = 'A';
	name[8] = 'R';
	name[9] = 'I';
	name[10] = 'K';
	name[11] = 'A';
	name[12] = 'Y';
	name[13] = 'A';
	name[14] = '\0';
}
void redefinition() {
	redefinition_no();
	redefinition_name();
}
int main() {
	int size_no = sizeof(no) / sizeof(no[0]);
	int size_name = (sizeof(name) / sizeof(name[0])) - 1;
	show_original(size_no, size_name, no, name);
	printf("\nn");
	establish_insertion_sort(size_no, size_name, no, name);
	printf("\n\n");
	redefinition();
	establish_merge_sort(size_no, size_name, no, name);
	printf("\n\n");
	redefinition();
	establish_bubble_sort(size_no, size_name, no, name);
	printf("\n\n");
	redefinition();
	establish_selection_sort(size_no, size_name, no, name);
	printf("\n\n");
	redefinition();
	establish_selection_quick_sort(size_no, size_name, no, name);
	printf("\n\n");
	redefinition();
	establish_selection_heap_sort(size_no, size_name, no, name);
	printf("\n\n");
	return 0;

}
