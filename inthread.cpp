#include<iostream>
using namespace std;


struct ThreadNode
{
	int key;
	ThreadNode *left;
	ThreadNode *right;
	bool tag_left;
	bool tag_right;
};


void in_order(ThreadNode *node)
{
	if(node != NULL)
	{
		in_order(node->left);
		cout<<node->key<<" ";
		in_order(node->right);
	}
}




int main()
{
	ThreadNode *root = new ThreadNode;

	root->key = 1;
	root->left = new ThreadNode;
	root->right = new ThreadNode;
	
	root->left->key = 2;
	root->left->left = NULL;
	root->right->right = NULL;

	root->right->key = 3;
	root->right->left = new ThreadNode;
	root->right->right = new ThreadNode;

	root->right->left->key = 4;	
	root->right->left->left = NULL;
	root->right->left->right = NULL;

	root->right->right->key = 5;
	root->right->right->left = NULL;
	root->right->right->right = NULL;



	in_order(root);














	return 0;
}





