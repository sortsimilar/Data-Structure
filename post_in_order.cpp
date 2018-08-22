#include<iostream>  
#include<vector>  
using namespace std;  
      
struct Node
{  
    int key;  
    Node* left;  
    Node* right;  
};  

vector<int> post_order;
vector<int> in_order;

vector<int> level_sequence;  
    
Node* build_tree(int inStart, int inEnd, int postStart, int postEnd)
{  
    if (postStart>postEnd || inStart>inEnd)
	{  
        return NULL;  
    }  
  
    Node* root = new Node;  
     
    int position;  
    for (int i = inStart; i <= inEnd; i++)
	{  
        if (in_order[i] == post_order[postEnd])
		{
			position = i;
            break;  
        }  
      
    }  

    root->key = post_order[postEnd];  
    root->left = build_tree(inStart , position-1, postStart, postStart-inStart+position-1);   
    root->right = build_tree(position+1, inEnd, postStart-inStart+position, postEnd-1);

    return root;  
}  
      
       
void level_order(Node* root)
{  
	vector<Node*> q;  
    q.push_back(root);  


    while (!q.empty())
	{
		Node* current = q[0];
		q.erase(q.begin());
		
		level_sequence.push_back(current->key); 
  
        if (current->left != NULL)    q.push_back(current->left);   
        if (current->right != NULL)   q.push_back(current->right);  

    }
	  
    return ;  
}  
      
int main()
{  
	int N;
	cin>>N;  

    post_order.resize(N);
    for (int i = 0; i<post_order.size(); i++)
	{
		cin>>post_order[i];
    }  
    	
	in_order.resize(N);  
    for (int i = 0; i<N; i++)
	{  
		cin>>in_order[i];
    }  

 
    Node* root = build_tree(0, N-1, 0, N-1);  

    level_order(root);  

	for(int i=0;i<level_sequence.size();i++)
	{
		cout<<level_sequence[i];
		if(i!=level_sequence.size()-1)    cout<<" ";
	}
  
    return 0;  
}  

/*

6
3 4 2 6 5 1
3 2 4 1 6 5


*/
