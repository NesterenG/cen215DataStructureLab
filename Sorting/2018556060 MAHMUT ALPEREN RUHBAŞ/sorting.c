#include <stdio.h>
#include <string.h>
#include <time.h>


                                                            /////////////////// Global Printer Functions
void number_printer(char number[], int sizeofnum, double timer, char sorttype[])
{
    printf("########## %s Sort #########", sorttype);
    printf("\nThis is my %s sorted number ", sorttype);
    int k;
    for (k = 0; k < sizeofnum; k++)
        printf("%d ", number[k]);
    putchar('\n');
    printf("Performance of the %s Sort for number %f \n", sorttype, (timer / CLOCKS_PER_SEC));
}
                                                                void name_printer(char myname[], int sizeofname, double timer, char sorttype[])
                                                                {
                                                                    printf("This is my %s sorted name.", sorttype);
                                                                    int k;
                                                                    for (k = 0; k < sizeofname; k++)
                                                                        printf("%c ", myname[k]);
                                                                    putchar('\n');
                                                                    printf("Performance of the %s Sort for name %f \n\n", sorttype, (timer / CLOCKS_PER_SEC));
                                                                }

                                                            /////////////////// Selection Sort Function
void selection_sort_for_number(char number[], int sizeofnum)
{
    int k, l, temp, min;
    for (k = 0; k < sizeofnum - 1; k++) {
        min = k;
        for (l = k + 1; l < sizeofnum; l++)
            if (number[min] > number[l])
            min = l;
        temp = number[min];
        number[min] = number[k];
        number[k] = temp;
    }
}
                                                                void selection_sort(char unsorted[], int sizeofnum)
                                                                {
                                                                    int k, l, temp, min;

                                                                    for (k = 0; k < sizeofnum - 1; k++) {
                                                                        min = k;
                                                                        for (l = k + 1; l < sizeofnum; l++)
                                                                            if (unsorted[min] > unsorted[l])
                                                                            min = l;
                                                                        temp = unsorted[min];
                                                                        unsorted[min] = unsorted[k];
                                                                        unsorted[k] = temp;
                                                                    }
                                                                }

                                                            /////////////////// Bubble Sort
void bubble_sort_number(char number[], int sizeofnum) 
{ 
	int k, l, temp; 
	for (k = 0; k < sizeofnum; ++k) {
		for (l = 0; l < sizeofnum - k - 1; ++l) {
			if (number[l] > number[l + 1]) {
				temp = number[l];
                number[l] = number[l+1];
                number[l+1] = temp;
			}
		}
	}
}
                                                                void bubble_sort_name(char unsorted[], int sizeofname) 
                                                                { 
                                                                    int k, l, temp;
                                                                    for (k = 0; k < sizeofname - 1; k++) {
                                                                        for (l = 0; l < sizeofname - k - 1; l++) {
                                                                            if (unsorted[l] > unsorted[l + 1]) {
                                                                                temp = unsorted[l];
                                                                                unsorted[l] = unsorted[l+1];
                                                                                unsorted[l+1] = temp;
                                                                            }
                                                                        }
                                                                    }
                                                                }


                                                            /////////////////// Merge Sort
void base_merge(char unsorted[], int left, int middle, int right) {
	int leftsize = middle - left + 1;
	int rightsize = right - middle;
	int RightArr[rightsize], LeftArr[leftsize];
	int k = 0, l = 0;

	for (k = 0; k < leftsize; ++k) {
		LeftArr[k] = unsorted[left + k];
	}
        for (l = 0; l < rightsize; ++l) {
            RightArr[l] = unsorted[middle + 1 + l];
        }
	k = 0; l = 0; int sub = left;
	while (k < leftsize && l < rightsize) {
		if (LeftArr[k] <= RightArr[l]) {
			unsorted[sub] = LeftArr[k];
			k++;
		}
		else {
			unsorted[sub] = RightArr[l];
			l++;
		}
		sub++;
	}
	while (k < leftsize) {
		unsorted[sub] = LeftArr[k];
		sub++;
		k++;
	}
        while (l < rightsize) {
            unsorted[sub] = RightArr[l];
            sub++;
            l++;
        }
}

                void merge_sort(char unsorted[], int left, int right) {
                    if (left < right) {
                        int middle = left + (right - left) / 2;
                        merge_sort(unsorted, left, middle);
                        merge_sort(unsorted, middle + 1, right);

                        base_merge(unsorted, left, middle, right);
                    }
                }

                                                            /////////////////// Insertion Sort
                                                    void insertion_sort(char unsorted[], int allsize) {
                                                        int k, l;
                                                        int check;
                                                        for (k = 1; k < allsize; k++) {
                                                            check = unsorted[k];
                                                            l = k - 1;
                                                            while (l >= 0 && unsorted[l] > check) {
                                                                unsorted[l + 1] = unsorted[l];
                                                                l = l - 1;
                                                            }
                                                            unsorted[l + 1] = check;
                                                        }
                                                    }

                                                            /////////////////// Heap Sort Function
void base_heap(char unsorted[], int allsize, int k ) {
	int temp; int largeone = k; int left = 2 * k + 1; int right = 2 * k + 2;
	if (unsorted[left] > unsorted[largeone] && left < allsize) 
	{
		largeone = left;	
	}
	if (unsorted[right] > unsorted[largeone] && right < allsize) 
	{
		largeone = right;	
	}
	if (largeone != k) 
	{
        temp = unsorted[k];
        unsorted[k] = unsorted[largeone];
        unsorted[largeone] = temp;
		base_heap(unsorted, allsize, largeone);
	}
}
                                                    void heap_sort(char unsorted[], int allsize){
                                                        int l, temp;
                                                        for(l= allsize/2-1; l>=0 ;l--)
                                                        {
                                                            base_heap(unsorted, allsize, l);
                                                        }
                                                        int k;
                                                        for (k = allsize-1; k > 0 ;k--)
                                                        {
                                                            temp = unsorted[0];
                                                            unsorted[0] = unsorted[k];
                                                            unsorted[k] = temp;
                                                            base_heap(unsorted, k, 0);
                                                        }
                                                    }
                                                            /////////////////// Quick Sort Function
void quick_sort(char unsorted[],int first,int last){
    int k, l, pivot, temp;
    pivot=first;
    if(last>first){
        pivot=first;
        k=first;
        l=last;
        while (k<l){
            while (unsorted[k]<=unsorted[pivot] && k<last && l>k)
            {
                k++;
            }
            while (unsorted[l]>=unsorted[pivot] && l>=first && l>=k)
            {
                l--;
            }
            if (l>k)
            { 
                temp=unsorted[k];
                unsorted[k]=unsorted[l];
                unsorted[l]=temp;
            }
        }
        temp=unsorted[l];
        unsorted[l]=unsorted[pivot];
        unsorted[pivot]=temp;
        quick_sort(unsorted,first,l-1);
        quick_sort(unsorted,l+1,last);
    }
}
                                                            /////////////////// Total Performance List
void performance_list(double selection, double bubble, double merge, double invertion, double heap, double quick, double selection2, double bubble2, double merge2, double invertion2, double heap2, double quick2)
{
    printf("############# Selection --- Bubble ---- Merge ---- Insertion ---- Heap ---- Quick #############\n");
    printf("Number Sort : %f --- %f --- %f --- %f --- %f --- %f #############\n", (selection / CLOCKS_PER_SEC), (bubble / CLOCKS_PER_SEC), (merge / CLOCKS_PER_SEC), (invertion / CLOCKS_PER_SEC), (heap / CLOCKS_PER_SEC), (quick / CLOCKS_PER_SEC));
    printf("Name   Sort : %f --- %f --- %f --- %f --- %f --- %f #############\n", (selection2 / CLOCKS_PER_SEC), (bubble2 / CLOCKS_PER_SEC), (merge2 / CLOCKS_PER_SEC), (invertion2 / CLOCKS_PER_SEC), (heap2 / CLOCKS_PER_SEC), (quick2 / CLOCKS_PER_SEC));
}
                                                            /////////////////// Main Function
int main()
{
    printf("Hi, my name is Mahmut Alperen Ruhbas and my number is 2018556060 \n");
    clock_t selectiontimer;
    clock_t bubbletimer;
    clock_t mergetimer;
    clock_t invertiontimer;
    clock_t heaptimer;
    clock_t quicktimer;
    clock_t selectiontimer2;
    clock_t bubbletimer2;
    clock_t mergetimer2;
    clock_t invertiontimer2;
    clock_t heaptimer2;
    clock_t quicktimer2;
    char name[] = "Mahmut Alperen Ruhbas";
    char num[] = {2, 0, 1, 8, 5, 5, 6, 0, 6, 0};
    int SIZEOFNUMBER = sizeof(num) / sizeof(num[0]);
    int SIZEOFNAME = strlen(name);
                                                            /////////////////// Selection Sort
                        char sorttype[] = "Selection";
                        char selectionname[SIZEOFNAME], selectionnumber[SIZEOFNUMBER];
                        strcpy(selectionname, name);
                        memcpy(selectionnumber, num, SIZEOFNUMBER);
                        selectiontimer = (double)clock();
                            selection_sort_for_number(selectionnumber, SIZEOFNUMBER);
                        selectiontimer = (double)clock()-selectiontimer;
                            number_printer(selectionnumber, SIZEOFNUMBER, ((double)selectiontimer), sorttype);
                        selectiontimer2 = (double)clock();
                            selection_sort(selectionname, SIZEOFNAME);
                        selectiontimer2 = (double)clock()-selectiontimer2;
                            name_printer(selectionname, SIZEOFNAME, ((double)selectiontimer2), sorttype);
                                                            /////////////////// Bubble Sort
                                            memset(sorttype, 0, sizeof(sorttype));
                                            strcat(sorttype, "Bubble");
                                            char bubblename[SIZEOFNAME], bubblenumber[SIZEOFNUMBER];
                                            strcpy(bubblename, name);
                                            memcpy(bubblenumber, num, SIZEOFNUMBER);
                                            bubbletimer = (double)clock();
                                                bubble_sort_number(bubblenumber, SIZEOFNUMBER);
                                            bubbletimer = (double)clock()-bubbletimer;
                                                number_printer(bubblenumber, SIZEOFNUMBER, ((double)bubbletimer), sorttype);
                                            bubbletimer2 = (double)clock();
                                                bubble_sort_name(bubblename, SIZEOFNAME);
                                            bubbletimer2 = (double)clock()-bubbletimer2;
                                                name_printer(bubblename, SIZEOFNAME, ((double)bubbletimer2), sorttype);
                                                            /////////////////// Merge Sort
                                                                memset(sorttype, 0, sizeof(sorttype));
                                                                strcat(sorttype, "Merge");
                                                                char mergename[SIZEOFNAME], mergenumber[SIZEOFNUMBER];
                                                                strcpy(mergename, name);
                                                                memcpy(mergenumber, num, SIZEOFNUMBER);
                                                                mergetimer = (double)clock();
                                                                    merge_sort(mergenumber, 0, SIZEOFNUMBER - 1);
                                                                mergetimer = (double)clock()-mergetimer;
                                                                    number_printer(mergenumber, SIZEOFNUMBER, ((double)mergetimer), sorttype);
                                                                mergetimer2 = (double)clock();
                                                                    merge_sort(mergename, 0, SIZEOFNAME - 1);
                                                                mergetimer2 = (double)clock()-mergetimer2;
                                                                    name_printer(mergename, SIZEOFNAME, ((double)mergetimer2), sorttype);
                                                            /////////////////// Insertion Sort
                                                                                        memset(sorttype, 0, sizeof(sorttype));
                                                                                        strcat(sorttype, "Insertion");
                                                                                        char insertionname[SIZEOFNAME], insertionnumber[SIZEOFNUMBER];
                                                                                        strcpy(insertionname, name);
                                                                                        memcpy(insertionnumber, num, SIZEOFNUMBER);
                                                                                        invertiontimer = (double)clock();
                                                                                            insertion_sort(insertionnumber, SIZEOFNUMBER);
                                                                                        invertiontimer = (double)clock()-invertiontimer;
                                                                                            number_printer(insertionnumber, SIZEOFNUMBER, ((double)invertiontimer), sorttype);
                                                                                        invertiontimer2 = (double)clock();
                                                                                            insertion_sort(insertionname, SIZEOFNAME);
                                                                                        invertiontimer2 = (double)clock()-invertiontimer2;
                                                                                            name_printer(insertionname, SIZEOFNAME, ((double)invertiontimer2), sorttype);
                                                            /////////////////// Heap Sort
                                                                memset(sorttype, 0, sizeof(sorttype));
                                                                strcat(sorttype, "Heap");
                                                                char heapname[SIZEOFNAME], heapnumber[SIZEOFNUMBER];
                                                                strcpy(heapname, name);
                                                                memcpy(heapnumber, num, SIZEOFNUMBER);
                                                                heaptimer = (double)clock();
                                                                    heap_sort(heapnumber, SIZEOFNUMBER);
                                                                heaptimer = (double)clock()-heaptimer;
                                                                    number_printer(heapnumber, SIZEOFNUMBER, ((double)heaptimer), sorttype);
                                                                heaptimer2 = (double)clock();
                                                                    heap_sort(heapname, SIZEOFNAME);
                                                                heaptimer2 = (double)clock()-heaptimer2;
                                                                    name_printer(heapname, SIZEOFNAME, ((double)heaptimer2), sorttype);
                                                            /////////////////// Quick Sort
                                            memset(sorttype, 0, sizeof(sorttype));
                                            strcat(sorttype, "Quick");
                                            char quickname[SIZEOFNAME], quicknumber[SIZEOFNUMBER];
                                            strcpy(quickname, name);
                                            memcpy(quicknumber, num, SIZEOFNUMBER);
                                            quicktimer = (double)clock();
                                                quick_sort(quicknumber, 0, SIZEOFNUMBER - 1);
                                            quicktimer = (double)clock()-quicktimer;
                                                number_printer(quicknumber, SIZEOFNUMBER, ((double)quicktimer), sorttype);
                                            quicktimer2 = (double)clock();
                                                quick_sort(quickname, 0, SIZEOFNAME - 1);
                                            quicktimer2 = (double)clock()-quicktimer2;
                                                name_printer(quickname, SIZEOFNAME, ((double)quicktimer2), sorttype);
/////////////////// Listing all sorting performance
                performance_list(((double)selectiontimer), ((double)bubbletimer), ((double)mergetimer), ((double)invertiontimer), ((double)heaptimer), ((double)quicktimer), ((double)selectiontimer2), ((double)bubbletimer2), ((double)mergetimer2), ((double)invertiontimer2), ((double)heaptimer2), ((double)quicktimer2));
                printf("\nMahmut Alperen Ruhbas ----- 2018556060\n");
    return 0;
}