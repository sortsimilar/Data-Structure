// inorder traversal for complete binary tree;
#include<iostream>
#include<vector>
using namespace std;


vector<int> binary;


void inorder(int current)
{
	if(current <= binary.size()-1)	
	{
		inorder(2*current+1);		
		inorder(2*current+2);
		cout<<binary[current]<<" ";
	}
}


int main()
{
	
	binary.push_back(8);
	binary.push_back(38);
	binary.push_back(25);
	binary.push_back(58);
	binary.push_back(52);
	binary.push_back(82);
	binary.push_back(70);
	binary.push_back(60);

	inorder(0);



	return 0;
}




