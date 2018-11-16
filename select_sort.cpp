#include<iostream>
#include<vector>
using namespace std;


vector<int> sequence (6);


void select_sort()
{
	for(int i=0;i<sequence.size()-1;i++)
	{
		int min_index = i;
		for(int j=i+1;j<sequence.size();j++)
		{
			if(sequence[j] < sequence[min_index])
			{
				min_index = j;
			}
		}
		
		// swap min index with ith element;
		if(min_index != i)
		{
			int temp = sequence[min_index];
			sequence[min_index] = sequence[i];
			sequence[i] = temp;
		}
		
	}

}




int main()
{

	sequence[0] = 1; sequence[1] = 6;
	sequence[2] = 2; sequence[3] = 5;
	sequence[4] = 3; sequence[5] = 4;

	select_sort();

	for(int i=0;i<sequence.size();i++)
	{
		cout<<sequence[i]<<" ";
	}
	cout<<endl;



	return 0;
}	

