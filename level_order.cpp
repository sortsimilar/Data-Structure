#include<iostream>
#include<vector>
using namespace std;


struct Node
{
	int key;
	int left;
	int right;
};


vector<Node> binary;
vector<int> level_sequence;


void level_order(int root)
{    

	vector<int> q;  
    q.push_back(root);  


    while (!q.empty())
	{
		int current = q[0];
		q.erase(q.begin());		
		level_sequence.push_back(binary[current].key); 

		if(binary[current].left != -1)    q.push_back(binary[current].left);
		if(binary[current].right != -1)    q.push_back(binary[current].right);
    }
	  
} 





int main()
{
	
	int N;
	cin>>N;

	
	// build binary tree;
	vector<bool> hash_table(N, false);

	binary.resize(N);
	for(int i=0;i<N;i++)
	{

		binary[i].key = i;

		cin>>binary[i].left;
		cin>>binary[i].right;
		
		if(binary[i].left != -1)
		{
			hash_table[binary[i].left] = true;
		}



		if(binary[i].right != -1)
		{
			hash_table[binary[i].right] = true;
		}

	}

	// find root of binary tree;
	int root = -1;
	for(int i=0;i<hash_table.size();i++)
	{
		if(hash_table[i]==false)
		{
			root = i;
			break;
		}
	}


	level_order(root);

	for(int i=0;i<level_sequence.size();i++)
	{
		cout<<level_sequence[i]<<" ";
	}


	return 0;
}

/*

9
7 8
-1 -1
-1 -1
-1 -1
0 1
2 3
4 5
-1 -1
-1 -1

*/


