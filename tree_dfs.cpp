#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

struct Node
{
	int key;
	vector<int> child;

};


vector<Node> tree;


void tree_dfs(int current)
{
	cout<<tree[current].key<<" ";

	for(int i=0;i<tree[current].child.size();i++) // childs 存放指向其每個子結點的指標
	{ 
		tree_dfs(tree[current].child[i]);   
    }	
}



int main()
{
	int N; // total number of the nodes in the tree;
	cin>>N;
	

	// initialize tree node;
	for(int i=0;i<N;i++)
	{
		Node temp;
		temp.key = i;

		tree.push_back(temp);
	}


	for(int i=0;i<N;i++)
	{
		int K;
		cin>>K;
		
		if(K != 0)
		{
			for(int j=0;j<K;j++)
			{
				int temp_j;
				cin>>temp_j;
				tree[i].child.push_back(temp_j);
			}
		}
		else
		{
			int temp;
			cin>>temp;
		}
	}


	tree_dfs(0);


	return 0;
}


/*

10
3 2 3 5
1 9
1 4
1 7
0 7
2 6 1
1 8
0 9
0 4
0 3

*/


