/* Iterative C program for merge sort */
#include<iostream>
#include<vector>
using namespace std; 


vector<int> arr;

int get_min(int x, int y) { return (x<y)? x :y; }
 
// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
	/* create temp arrays */
	int L[n1];
	int R[n2];
 
	/* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)	L[i] = arr[l + i];
    for (j = 0; j < n2; j++)	R[j] = arr[m + 1+ j];
 

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
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
 
    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 

void merge_sort()
{ 
   for (int curr_size=1; curr_size<=arr.size()-1; curr_size = 2*curr_size)
   {
       for (int left_start=0; left_start<arr.size()-1; left_start += 2*curr_size)
       {
           int mid = left_start + curr_size - 1;
 
           int right_end = get_min(left_start + 2*curr_size - 1, arr.size()-1);
 
           merge(left_start, mid, right_end);
       }
   }
}


void merge_one_more()
{ 
	int curr_size = 2;
	for (int left_start=0; left_start<arr.size()-1; left_start += 2*curr_size)
	{
	   int mid = left_start + curr_size - 1;

	   int right_end = get_min(left_start + 2*curr_size - 1, arr.size()-1);

	   merge(left_start, mid, right_end);
	}
}




/* Function to print an array */
void printArray()
{
    int i;
    for (i=0;i<arr.size();i++)
	{
        cout<<arr[i]<<" ";
	}
    cout<<endl;
}
 


int main()
{ 
	arr.resize(10);
	arr[0] = 1;
	arr[1] = 3;
	arr[2] = 2;
	arr[3] = 8;
	arr[4] = 5;
	arr[5] = 7;
	arr[6] = 4;
	arr[7] = 9;
	arr[8] = 0;
	arr[9] = 6;

    cout<<"Given array is "<<endl;
    printArray();
 
//    merge_sort();

	merge_one_more();
 
    cout<<"Sorted array is "<<endl;
    printArray();

    return 0;
}

/*
10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6
*/
