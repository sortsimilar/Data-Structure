#include<iostream>
#include<vector>
using namespace std;


struct Node
{
	int left;
	int right;
	int name;
};


vector<int> pre_order;
vector<int> in_order;
vector<int> post_order;
vector<Node> binary;

int build_tree(int inStart, int inEnd, int preStart, int preEnd)
{
	if (preStart > preEnd || inStart > inEnd)
	{
		return -1;
	}

	int root = pre_order[preStart];

	int k = 0;
	for (int i = 0; i < in_order.size(); i++) 
	{
		if (in_order[i] == root) 
		{
			k = i;
			break;
		}
	}


	binary[root].left = build_tree(inStart, k-1, preStart+1, preStart+k-inStart);
	// Becuase k is not the length, it it need to -(inStart+1) to get the length
	binary[root].right = build_tree(k+1, inEnd, preStart+(k-inStart)+1, preEnd);
	// postStart+k-inStart = postStart+k-(inStart+1) +1

	post_order.push_back(root+1);

	return root;
}



int main()
{
// input process ////////////////////////////////////////
	int N;
	cin>>N;


	for(int i=0;i<N;i++)
	{
		int temp;
		cin>>temp;
		pre_order.push_back(temp-1);
	}

	for(int i=0;i<N;i++)
	{
		int temp;
		cin>>temp;
		in_order.push_back(temp-1);
	}

// initialize binary tree;
	for(int i=0;i<N;i++)
	{
		Node temp;
		temp.name = i;
		binary.push_back(temp);
	}

/*
	for(int i=0;i<N;i++)    cout<<pre_order[i]<<" ";
	cout<<endl;
	for(int i=0;i<N;i++)    cout<<in_order[i]<<" ";
	cout<<endl;
*/


	build_tree(0, N-1, 0, N-1);

/*
	for(int i=0;i<N;i++)
	{
		cout<<binary[i].name<<" "<<binary[i].left<<" "<<binary[i].right<<endl;
	}
*/

	for(int i=0;i<N;i++)
	{
		cout<<post_order[i]<<" ";
	}


	return 0;
}

/*
7
4 1 3 2 6 5 7
1 2 3 4 5 6 7
*/







