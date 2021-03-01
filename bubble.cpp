  
#include<iostream> 
#include<string>
using namespace std; 
  
/* structure for a node */
struct Node  
{ 
    int data; 
    struct Node* next; 
} Node; 
  
/*Function to swap the nodes */
struct Node* swap(struct Node* ptr1, struct Node* ptr2) 
{ 
    struct Node* tmp = ptr2->next; 
    ptr2->next = ptr1; 
    ptr1->next = tmp; 
    return ptr2; 
} 
  
/* Function to sort the list */
int bubbleSort(struct Node** head, int count) 
{ 
    struct Node** h; 
    int i, j, swapped; 
  
    for (i = 0; i <= count; i++) 
    { 
  
        h = head; 
        swapped = 0; 
  
        for (j = 0; j < count - i - 1; j++)  
        { 
  
            struct Node* p1 = *h; 
            struct Node* p2 = p1->next; 
  
            if (p1->data > p2->data) 
            { 
  
                /* update the link after swapping */
                *h = swap(p1, p2); 
                swapped = 1; 
            } 
  
            h = &(*h)->next; 
        } 
  
        /* break if the loop ended without any swap */
        if (swapped == 0) 
            break; 
    } 
	return 0;
} 
  
/* Function to print the list */
void printList(struct Node* n) 
{ 
    while (n != NULL) 
    { 
        cout << n->data << " -> "; 
        n = n->next; 
    } 
    cout << endl; 
} 
  
/* Function to insert a struct Node 
at the beginning of a linked list */
void insertAtTheBegin(struct Node** start_ref, int data) 
{ 
    struct Node* ptr1 
        = (struct Node*)malloc(sizeof(struct Node)); 
  
    ptr1->data = data; 
    ptr1->next = *start_ref; 
    *start_ref = ptr1; 
} 
  
// Driver Code 
int main() 
{ 
	int s= 0;
	
    int *arr;
	arr = new int[]; // dynamic

	cout<<"Enter Size of Array : ";
	cin>>s;

	
	for (int p = 0; p < s; p++)
	{cout<<"Enter data in Array ["<<p<<"] : ";
		cin>>arr[p];
	}

    int list_size, i; 
  
    /* start with empty linked list */
    struct Node* start = NULL; 
     list_size = sizeof(arr) / sizeof(arr[0]); 
  
    /* Create linked list from the array arr[] */
    for (i = 0; i < list_size; i++) 
        insertAtTheBegin(&start, arr[i]); 
  
    /* print list before sorting */
    cout <<"Linked list before sorting\n"; 
    printList(start); 
  
    /* sort the linked list */
    cout<<bubbleSort(&start, list_size); 
  
    /* print list after sorting */
    cout<<"Linked list after sorting\n"; 
    printList(start); 
   
	cout<<endl;
	system("pause");
    return 0; 
} 
  