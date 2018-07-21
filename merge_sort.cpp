/* Iterative C program for merge sort */
#include<iostream>
#include<vector>
using namespace std; 


vector<int> arr;



int min(int x, int y) { return (x<y)? x :y; }
 

void merge(int l, int m, int r)
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
 

void merge_sort()
{ 
   for (int curr_size=1; curr_size<=arr.size()-1; curr_size = 2*curr_size)
   {
       for (int left_start=0; left_start<arr.size()-1; left_start += 2*curr_size)
       {
           int mid = left_start + curr_size - 1;
 
           int right_end = min(left_start + 2*curr_size - 1, arr.size()-1);
 
           merge(left_start, mid, right_end);
       }
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
	arr.resize(6);
	arr[0] = 12;
	arr[1] = 11;
	arr[2] = 13;
	arr[3] = 5;
	arr[4] = 6;
	arr[5] = 7;

    cout<<"Given array is "<<endl;
    printArray();
 
    merge_sort();
 
    cout<<"Sorted array is "<<endl;
    printArray();

    return 0;
}




