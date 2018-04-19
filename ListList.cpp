#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

class List
{
	
public:
	Node * head, *tail;
	List()
	{
		head = NULL;
		tail = NULL;
	}

	// add a new node to list;
	void add_node(int value)
	{
		Node *temp = new Node;
		temp->data = value;
		temp->next = NULL;


		if (head == NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
	}

	// print all node in list;
	void print_list()
	{
		Node *temp;
		temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " " << temp << endl;
			temp = temp->next;
		}
	}

	// insert value at start
	void insert_start(int value)
	{
		Node *temp = new Node;
		temp->data = value;
		temp->next = NULL;

		temp->next = head;
		head = temp;

	}

	// insert value at certain position;
	void insert_position(int position, int value)
	{
		Node *temp = new Node;
		temp->data = value;
		temp->next = NULL;

		Node *previous_node = head;

		for (int i = 1;i < position;i++)
		{
			previous_node = previous_node->next;
		}

		temp->next = previous_node->next;
		previous_node->next = temp;
	}

	// delete first element;
	void delete_first()
	{
		Node *temp = new Node;
		temp = head;
		head = head->next;
		delete temp;
	}

	// delete last element;
	void delete_last()
	{
		Node *temp = new Node;
		temp = head;
		while (temp->next->next != NULL)
		{
			temp = temp->next;
		}
		delete temp->next;
		temp->next = NULL;
	}
};



int main()
{
	List test;
	test.add_node(20);
	test.add_node(30);
	test.add_node(40);
//	test.insert_start(10); // test insert at start;
//	test.insert_position(1, 35); // insert at certain position;
//	test.delete_first(); // delete first element; 
	test.delete_last(); // delete last element;

	test.print_list();


	system("pause");
	return 0;
}