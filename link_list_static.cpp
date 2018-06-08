#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

// Node of link list;
struct Node
{
	int location;
	int prev;
	int addr;
	int key;
	int next;
};

vector<Node> linklist(100001);


// convert int to string;
string int_to_string(int addr)
{
	string result;
	stringstream ss;
	ss<<addr;
	ss>>result;


	if(result != "-1")
	{
		while(result.length() < 5)    result = "0" + result;
	}

	return result;
}

// print link list;
void print_list(int head)
{
	int	current = head;
	while(current != -1)
	{	
		cout<<int_to_string(linklist[current].addr)<<" "<<linklist[current].key<<" "<<int_to_string(linklist[current].next);
		if(linklist[current].next != -1)    cout<<endl;

		current = linklist[current].next;
	}
}


int main()
{
	int head; // address of the first node;
	cin>>head;
	int N; // total number of nodes;
	cin>>N; 
	int K; // length of the sublist to be reversed;
	cin>>K; 

	vector<Node> save;
	for(int i=0;i<N;i++)
	{
		Node temp;
		cin>>temp.addr;
		cin>>temp.key;
		cin>>temp.next;
		save.push_back(temp);
	}

	// initialize link list;	
	for(int i=0;i<linklist.size();i++)
	{
		linklist[i].addr = -1;
		linklist[i].next = -1;
	}

	// allocate link list nodes;
	for(int i=0;i<N;i++)
	{
		int temp = save[i].addr;
		linklist[temp].addr = save[i].addr;
		linklist[temp].key = save[i].key;
		linklist[temp].next = save[i].next;
	}

	print_list(head);




	return 0;
}



