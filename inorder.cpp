#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;


struct node
{
	int left;
	int right;
	int name;
	int value;
};

vector<node> binary;


void inorder(node current)
{
	if((current.name==-1))    return;	

	if(current.left!=-1)    inorder(binary[current.left]);
	cout<<current.name<<" ";
	if(current.right!=-1)    inorder(binary[current.right]);
}


int main()
{
	// input process ////////////////////////////////////////
	int N;
	cin>>N;

	
	vector<int> sequence_value(N);
	for(int i=0;i<N;i++)
	{
		node temp;
		cin>>temp.left;
		cin>>temp.right;
		temp.name = i;
		binary.push_back(temp);

	}


	inorder(binary[0]);






	return 0;
}




