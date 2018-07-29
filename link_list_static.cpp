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

vector<Node> save;
vector<Node> linklist(100001);
vector<Node> linklist_origin;

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

// create link list;
void create_list(int head)
{
	int	current = head;
	while(current != -1)
	{	
		Node temp;
		temp.addr = linklist[current].addr;
		temp.key = linklist[current].key;
		temp.next = linklist[current].next;
		linklist_origin.push_back(temp);

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

	save.resize(N);
	for(int i=0;i<save.size();i++)
	{
		cin>>save[i].addr;
		cin>>save[i].key;
		cin>>save[i].next;
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

//	print link list;
	create_list(head);
	for(int i=0;i<linklist_origin.size();i++)
	{
		cout<<linklist_origin[i].addr<<" "<<linklist_origin[i].key<<" "<<linklist_origin[i].next<<endl;
	}


	return 0;
}



