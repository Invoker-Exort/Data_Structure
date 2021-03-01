#include <iostream>
#include <string>
using namespace std;


struct node1
{
	string data;
	node1* next;
};


struct node
{
	string data;
	node1* next;
	node* bottom;
};



class graph
{
public:
	node* head;
	node* temp;
	node* temp1;
	node* temp2;
	node1* temp3;

	graph()
	{
		head = temp = temp2 = temp1 = NULL;
		temp3 = NULL;
	}

	void list(string x)
	{
		if (head == NULL)
		{
			head = new node;
			head->data = x;
			head->next = NULL;
			head->bottom = NULL;
			return;
		}
		else
		{
			temp = head;
			while (temp != NULL)
			{
				if (temp->bottom == NULL)
				{
					temp1 = new node;
					temp1->data = x;
					temp1->next = NULL;
					temp1->bottom = NULL;
					temp->bottom = temp1;
					return;
				}
				temp = temp->bottom;
			}

			

		}
	}

	void link(string x, string y)
	{
		
		if (head == NULL)
		{
			cout << "Empty graph" << endl;
			return;
		}
		else
			{

			temp = head;
		while (temp != NULL)
		{
			if (x == temp->data)
			{
				temp1 = head;
				while (temp1 != NULL)
				{
					if (y == temp1->data)
					{
						if (temp->next == NULL)
						{


							temp3 = new node1;
							temp3->data = y;
							temp->next = temp3;
							temp3->next = NULL;
							return;
						}
						else
						{
							while (temp->next != NULL)
							{
								if (temp->next->next== NULL)
								{

									temp3 = new node1;
									temp3->data = y;
									temp3->next = NULL;
									temp->next->next= temp3;
									return;
								}
								temp->next = temp->next->next;
							}
						}
					}
					temp1 = temp1->bottom;
				}
			}
			temp = temp->bottom;
		}
	}
	}



	void print()
	{
		
		node1* tempp;

		if (head == NULL)
		{
			cout << "EMPTY" << endl;
		}
		else
		{
			temp = head;
			while (temp != NULL)
			{
				cout << temp->data << " -> ";
				if (temp->next != NULL)
				{
					tempp = temp->next;

					while (tempp != NULL)
					{
						cout << tempp->data << " -> ";
						tempp = tempp->next;
					}

				}
				cout << endl;
				temp = temp->bottom;
			}
		}
	}
};

int main()
{
	graph A;
	A.list("A");
	A.list("B");
	A.list("C");
	A.list("D");
	A.link("A", "B");
	A.link("A", "C");
	A.link("B", "D");
	A.link("C", "D");

	cout << endl;

	A.print();
	system("pause");
	return 0;
}
