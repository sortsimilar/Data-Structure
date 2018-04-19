// Reference: https://www.codementor.io/codementorteam/a-comprehensive-guide-to-implementation-of-singly-linked-list-using-c_plus_plus-ondlm5azr

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
	Node * head, *tail; //tail help us add element at last;
	List()
	{
		head = NULL;
		tail = NULL;
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

	// insert a new node at last;
	void insert_last(int value)
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
		tail = temp->next;
	}

	// delete at certain position;
	void delete_position(int position)
	{
		Node *temp = new Node;
		Node *node_deleted = new Node;
		temp = head;
		for (int i = 1;i < position;i++)
		{
			temp = temp->next;
		}
		node_deleted = temp->next;
		temp->next = temp->next->next;
		delete node_deleted;
	}
};



int main()
{
	List test;
	test.insert_last(20);
	test.insert_last(30);
	test.insert_last(40);
//	test.insert_start(10); // test insert at start;
//	test.insert_position(1, 35); // insert at certain position;
//	test.delete_first(); // delete first element; 
//	test.delete_last(); // delete last element;
	test.delete_position(1);

	test.print_list();


	system("pause");
	return 0;
}