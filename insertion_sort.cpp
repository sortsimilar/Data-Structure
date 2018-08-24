#include<iostream>
#include<vector>
using namespace std;

vector<int> sequence;


void insertion_sort()
{
    for(int i=1;i<sequence.size();i++)
	{
        int key = sequence[i];

        int j;
        for(j=i-1;j>=0 && key<sequence[j];j--)
		{
			sequence[j+1] = sequence[j];
		}

        sequence[j+1]=key;
    }
}



int main()
{


	int N;
	cin>>N;
	sequence.resize(N);
	for(int i=0;i<sequence.size();i++)
	{
		cin>>sequence[i];
	}

	insertion_sort();

	for(int i=0;i<sequence.size();i++)
	{
		cout<<sequence[i]<<" ";
	}



	return 0;
}

/*

10
1 2 3 7 8 5 9 4 6 0

*/


