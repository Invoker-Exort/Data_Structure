#include <iostream> 
#include<string>

using namespace std; 

struct node
{
	string data;
	node* next;
	node *prev;
	
};

class LinkedList
{
	
	private:
    node *head;
    node *tail;

    
public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void createNode(string value)
    {
		 node *temp = new node;
		 node *s    = new node;

        temp->data = value;
        temp->next = NULL;
		

        if (head == NULL)
        {
			temp->prev=NULL;
             head = temp;
          
           
        }
        else
        {   
              s = head;
        while (s->next != NULL)
            s = s->next;
        s->next = temp;
        temp->prev = s;
        }
		
    }


    void printList() 
	{
        node * current = head;

		if (head == NULL)
		{
			cout<<"List is Empty,nothing to Display "<<endl;
			return;
		}

        while (current != NULL) {
            cout << current->data <<" <-> ";
            current = current->next;
        
        }
cout<<endl;
    }

	void Reverse()                   //Reverse of Double link list

	{
		 node *p1,*p2;

		p1 = head;
    p2 = p1->next;
    p1->next = NULL;
    p1->prev = p2;

    while (p2 != NULL)
    {
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev; 
    }
    head = p1;

	}

	void  count()                     //count number of Nodes
{ 	
     node *q = head;

    int cnt = 0;
    while (q != NULL)
    {
        q = q->next;
        cnt++;
    }
    cout<<"Number of elements in double link list are : "<<cnt<<endl;
	cout<<endl;
	cout<<"that are : ";
}

                                 //inserting new Node at the head
    void pushNode(string value)
	
{
	if (head ==NULL)
	{
		cout<<"First Creat list  : "<<endl;
		return;
	}

    node * new_node;

    new_node = new node;

	new_node->prev=NULL;
    new_node->data = value;
    new_node->next = head;
	head->prev=new_node;

    head = new_node;
}
    
                                                 // Inserting Node at a particular location    
void insertNodeAtPosition(string pos, string value)
{
  
	if (head ==NULL)
	{
		cout<<"First Creat list  : "<<endl;
		return;
	}
	 node *pre = new node;
      node *post = new node;
      node *temp = new node;

	  post= head;
      post = temp;
 
	  while (post->data != pos)
	  {
		  post=post->next;
	  }
	  cout<<value<<"<->"<<endl;
	 
	  

}


                                     //Deleting first item of the list
string pop() 
{
  
    string retval = NULL;
    node * next_node = NULL;
    next_node = head->next;
    retval = head->data;
    delete head;
    head = next_node;

    return retval;

}    

                                                //deleting last item
string removeLast() {
    string retval = NULL;
 
    if (head->next == NULL) {
        retval = head->data;
        delete head;
        return retval;
    }

    
    node * current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

 
    retval = current->next->data;
    delete current->next;
    current->next = NULL;
    return retval;
}


                                    //removing at a specific Position
string removeByIndex(string n)
{
    
    string retval = NULL;
    node   *current = head;
    node * temp_node = NULL;

    if ( head == NULL)
	{
    	cout<<"Head Element"<<endl;
        return 0;
    }

	for (string i = head->data; i < n; i=current->next->data) {
        if (current->next == NULL) {
            return NULL;
        }
        current = current->next;
    }

    temp_node = current->next;
    retval = temp_node->data;
    current->next = temp_node->next;
    delete temp_node;

    return retval;

}

};



int main() 
{ 
   LinkedList L;
  
    L.createNode("Jony Sins");
   L.createNode("Jackline");
   L.createNode("Disha Patni");
   L.createNode("Mia Khilifa ");
   cout<<"...................................................."<<endl;
   cout<<" --Double Link List                        = ";

   L.printList();

   cout<<endl;

	cout<<"--Reverse of List   Double link list        = ";
   L.Reverse();


	L.printList();

	cout<<".................................................."<<endl;
	
	L.count();

	L.printList();
cout<<endl;
	
   cout<<"--Pushed in Double link list  ";
  L.pushNode("khan");
  cout<<endl;
   L.createNode("Alia");
   cout<<endl;

   L.pushNode("Sara");
   L.printList();   
 cout<<endl;
 cout<<endl;

  cout<<"--Insert  Node in Double link  at position        ";
  //  L.insertNodeAtPosition ("Alia","Disha Patni");
  // L.printList();

   cout<<endl;
   cout<<endl;
  //cout<<"--popped value  in double link list               = "<<L.pop()<<endl;
  cout<<endl;
   L.printList(); 
  
   cout<<endl;
   cout<<endl;
   cout<<"--Remove last node in double link list            = "<<L.removeLast()<<endl;
   cout<<endl;
   L.printList(); 
   
   
   cout<<endl;
   cout<<endl;
   cout<<"--Remove At a position     = "<<L.removeByIndex("khan")<<endl;
  cout<<endl;
   L.printList(); 
  
   cout<<endl<<endl;


	system("pause");
    return 0; 
}  