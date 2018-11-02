#include<iostream>
#include<vector>
using namespace std;


vector<int> arr(11);

int binary_search(int key)
{
	int low = 0;
	int high = arr.size()-1;
	int mid;

	while(low<=high)
	{
		mid = (low+high) / 2;
		if(arr[mid]==key)    return mid;
		else if(arr[mid]>key)    high = mid - 1;
		else    low = mid + 1;
	}
	
	
	return -1;
}



int main()
{
	arr[0] = 7; arr[1] = 10; arr[2] = 13; arr[3] = 16; arr[4] = 19; arr[5] = 29; 
	arr[6] = 32; arr[7] = 33; arr[8] = 37; arr[9] = 41; arr[10] = 43;

	cout<<binary_search(32)<<endl;
	cout<<binary_search(30)<<endl;
	
	
	
	return 0;	
}




