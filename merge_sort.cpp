/* Iterative C program for merge sort */
#include<iostream>
#include<vector>
using namespace std; 


void merge(int arr[], int l, int m, int r);
int min(int x, int y) { return (x<y)? x :y; }
 
 
/* Iterative mergesort function to sort arr[0...n-1] */
void mergeSort(int arr[], int n)
{ 
   for (int curr_size=1; curr_size<=n-1; curr_size = 2*curr_size)
   {
       for (int left_start=0; left_start<n-1; left_start += 2*curr_size)
       {
           int mid = left_start + curr_size - 1;
 
           int right_end = min(left_start + 2*curr_size - 1, n-1);
 
           merge(arr, left_start, mid, right_end);
       }
   }
}

 
/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    int L[n1];
	int R[n2];
 
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
 
/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
	{
        cout<<A[i]<<" ";
	}
    cout<<endl;
}
 


int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    cout<<"Given array is "<<endl;
    printArray(arr, n);
 
    mergeSort(arr, n);
 
    cout<<"Sorted array is "<<endl;
    printArray(arr, n);

    return 0;
}




