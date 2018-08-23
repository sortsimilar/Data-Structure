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

void print_sequence()
{
	for(int i=0;i<sequence.size();i++)
	{
		cout<<sequence[i]<<" ";
	}
	cout<<endl;

}


int main()
{


	int N;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		int temp;
		cin>>temp;
		sequence.push_back(temp);
	}

	insertion_sort();

	print_sequence();



	return 0;
}

/*

10
1 2 3 7 8 5 9 4 6 0

*/


