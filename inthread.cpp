#include<iostream>
using namespace std;


struct ThreadNode
{
	int key;
	ThreadNode *left;
	ThreadNode *right;
	bool left_tag;
	bool right_tag;
};

// in order traversal;
void in_order(ThreadNode *node)
{
	if(node != NULL)
	{
		in_order(node->left);
		cout<<node->key<<" ";
		in_order(node->right);
	}
}


void in_thread(ThreadNode *node, ThreadNode *pre)
{
	if(node != NULL)
	{
//		cout<<node->key<<" ";

		in_thread(node->left, pre);
		if(node->left == NULL)
		{
			node->left = pre;
			node->left_tag = true;
		}

		if(pre!=NULL && pre->right==NULL)
		{
			pre->right = node;
			pre->right_tag = true;
		}

		pre = node;
		in_thread(node->right, pre);
	}
}


void create_in_thread(ThreadNode *node)
{
	ThreadNode *pre = NULL;
	if(node != NULL)
	{
		in_thread(node, pre);
		pre->right = NULL;
		pre->right_tag = true;
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



//	in_order(root);


//	cout<<root->right->left->left_tag;

	in_thread(root, NULL);

	cout<<root->right->right->left->key;









	return 0;
}





