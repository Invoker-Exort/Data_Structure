
#include<iostream>
#include<string>

using namespace std;

struct node
{
	int info;
	node *left;
	node *right;
	

};

class Tree

{
private:
	node *temp;
	int counter;
public:
		node *root;
		int number;
	Tree()
	{    temp=root=NULL;
	     counter=0;
		
	}

	void insert_in_order(node *temp) // left , root , right
	{
		if (root==NULL)
		{
			temp=new node;
			counter++;
			temp->info=number;
			temp->left=NULL;
			temp->right=NULL;
			root=temp;
			return;
		}

		if (temp->info == number)
		{
			cout<<"Entered Number is already present in Tree  "<<endl;
		return;
		}

		if (temp->info > number)
		{
			if (temp->left != NULL)
			{   counter++;
				insert_in_order(temp->left);
             return;
			}

			else
			{  counter++;
				temp->left=new node;
				temp->left->info=number;
				temp->left->left=NULL;
				temp->left->right=NULL;
				return;
			}
		}

		if (temp->info < number)
		{
			if (temp->right != NULL)

			{counter++;
				insert_in_order(temp->right);
			return;

			}
			else
			{counter++;
				temp->right=new node;
				temp->right->info=number;
				temp->right->right=NULL;
				temp->right->left=NULL;
				return;
			}



		}

	}

	void search_inorder(node *temp)
	{
		if (root== NULL)
		{cout<<"tree is empty "<<endl; 

		return;	
		}
		if (temp->left != NULL)            // left 
		{
			search_inorder(temp->left);
		}
		cout<<temp->info<<" ";                // root 

		if (temp->right != NULL)                // right
		{
			search_inorder(temp->right);
		}
		return;
	}
	void option()
	{
cout<<"\n\n ************** Select Option *****************.\n";
 cout<<"\n Enter any of choices.\n";
 cout<<"\n 1 : Adding (inserting) node in BST.\n";
 cout<<"\n 2 : Print the whole BST .\n";
 cout<<"\n 3 : Post Search .\n";
 cout<<"\n 4 : delete  .\n";
 cout<<"\n 5 : 1st 2nd 3rd Largest Nodes  .\n";
 cout<<"\n 6 : Print B/w Two Nodes  .\n";
 cout<<"\n 7 : Quitting the Program.\n";
 cout<<"\n ********************************************.\n";
 cout<<endl;
}//--------------------------------------------------------------

	struct node * minValueNode(struct node* node)  // to get the most successor
{ 
    struct node* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 

 void search_post_order(node *temp)
 {

	 cout<<temp->info<<"  ";    // root

	 if (temp->left != NULL)       //left
	 {
		 search_post_order(temp->left);
	 }

	 if (temp->right != NULL)      //right 
	 {
		
		 search_post_order(temp->right);
	 }
	 return;

 }
 void deleteo(node *temp, int key) 
	 // case1 when left and right is Null, case2  when 1leaf is NULL ,case3  when both leaf is presen
 {
	 if (key == root->info) //in root
	 {
		 delete root;
		 cout<<"Tree is Finished "<<endl;
		 return;
	 }

	 if (temp->left->info == key) 
	 {

		 if (temp->left->left == NULL && temp->left->right == NULL) //case 1 both NULL
		 {  counter--;
			 delete temp->left;
			 temp->left=NULL;
			 return;
		 }
		 if (temp->left->left == NULL && temp->left->right != NULL)  // case 2 left size nUll only of left node
		 {
			 node *temp1;

			 temp1=temp->left;

			 temp->left=temp->left->right;
			  counter--;
			 delete temp1;
			 return;
		 }

		  if (temp->left->left != NULL && temp->left->right == NULL)  //case 2  right size nUll only of left node
		 {
			 node *temp1;

			 temp1=temp->left;

			 temp->left=temp->left->left;
			  counter--;
			 delete temp1;
			 return;
		 }

		   if (temp->left->left != NULL && temp->left->right != NULL)  //case 3 both are not NULL
			   // temp successor
	 {

		  node *temp1;
		  node *temp2;

		temp1=temp->left;
		temp2=temp->left;

		  while (temp1->right->right != NULL)
		  {
			  temp1=temp->right;
		  }

		  temp->left=temp1->right;
		   counter--;
		  delete temp2;
		  temp1->right =NULL;

			 return;
		 }



	 }

	 if (temp->right->info == key) 
	 {

		  if (temp->right->left == NULL && temp->right->right == NULL) // case 1 both NULL
		 {    counter--;
			 delete temp->right;
			 temp->right=NULL;
			 return;
		 }

		   if (temp->right->left == NULL && temp->right->right != NULL)  //case 2 left side nUll only of  right node
		 {
			 node *temp1;

			 temp1=temp->right;

			 temp->right=temp->right->right;
			  counter--;
			 delete temp1;
			 return;

		 }
		     if (temp->right->left != NULL && temp->right->right == NULL)  //case 2 right side nUll only of  right node
		 {
			 node *temp1;

			 temp1=temp->right;

			 temp->right=temp->right->left;
			  counter--;
			 delete temp1;

			 return;
		 }

			   if (temp->right->left != NULL && temp->right->right != NULL)  //case 3 both are not NULL

	 {
		  node *temp1;
		  node *temp2;

		temp1=temp->right;
		temp2=temp->right;

		  while (temp1->right->right != NULL)
		  {
			  temp1=temp->right;
		  }

		  temp->right=temp1->right;
		   counter--;
		  delete temp2;
		  temp1->right =NULL;

			 return;
		 }

	 }


	 if (temp->info > key )
	 {
		 deleteo(temp->left, key);
		 return;
	 }

	 if (temp->info < key)
	 {
		 deleteo(temp->right,key);
		 return;
	 }	 
 }
  
 void largest_value(node *temp)
 {
	 if (root == NULL)
	 {cout<<"tree is Empty "<<endl;
	 return;
	 }
	 if ( counter < 3)
	 { cout<<endl;
		 cout<<"Number of Node is tree are less the 3, couldnt find Three Largests"<<endl; 
		 return;
	 }

	 if (root->right == NULL && root->left != NULL)  //if only Left BSt is present
	 {
		 cout<<"1st Largest (root) : "<<root->info<<endl;

		 if (root->left->right == NULL)
		 {
			  cout<<"2nd Largest  : "<<root->left->info<<endl;
			  cout<<"3rd Largest  : "<<root->left->left->info<<endl;
              return;		
		 }

		 if (root->left->right != NULL)
		 { 
			 temp = root->left;

			 while (temp->right->right != NULL)
			 {
				 temp=temp->right;
			 }
			 cout<<"2nd Largest  : "<<temp->right->info<<endl;
			 cout<<"3rd Largest  : "<<temp->info<<endl;
			 return;
		 }

		
		
	 }
	 // now when right sub tree is present,from root

	 if (temp->right != NULL)   //root  (tringle of 3 node)
	 {//case 4 
		 if (temp->right->right == NULL && temp->right->left == NULL)
		 {
		 cout<<" 1st Largest       : "<<temp->right->info<<endl;
		 cout<<" 2nd Largest (root) : "<<temp->info<<endl;
		 cout<<" 3rd Largest       : "<<temp->left->info<<endl;
		 return;
		 }
	 }

	 if (temp->right != NULL)  //right Subtree 
	 {

		 while (temp->right->right->right != NULL)
		 {
			 temp=temp->right;  // reached to the largest with 3 step back
		 } 

		//case 1 right line ,no left node present 
		 if (temp->right->right->left == NULL && temp->right->left == NULL) 
		 {
		  cout<<"1st largest : "<<temp->right->right->info<<endl;
		  cout<<"2nd Largest : "<<temp->right->info<<endl;
		  cout<<"3rd Largest : "<<temp->info<<endl;
		  return;
		 }
		 //case 2  Second largest left is not empty 1 st largest left is empty
		 if (temp->right->right->left == NULL  && temp->right->left != NULL)
		 {
			  cout<<"1st largest : "<<temp->right->right->info<<endl;
			  node *temp1;

			  temp1=temp->right->left;

			  if (temp1->right == NULL)
			  {
		     cout<<"2nd Largest : "<<temp->right->info<<endl;
		      cout<<"3rd Largest : "<<temp1->info<<endl;
			  return;
                   }
			  if (temp1->right != NULL)
			  {

				  while (temp1->right != NULL)
				  {
					  temp1=temp1->right;
				  }
               cout<<"2nd Largest : "<<temp->right->info<<endl;
		       cout<<"3rd Largest : "<<temp1->info<<endl;
			   return;

			  }
		 }//case2 end

		

		 if (temp->right->right->left != NULL )//case 3 largest left is not empty
		 {
			 cout<<"1st largest : "<<temp->right->right->info<<endl;
			 node *temp1;
			 temp1=temp->right->right->left;

			 if (temp1->right == NULL && temp1->left == NULL )
			 {
				 cout<<"2nd Largest : "<<temp1->info<<endl;
		       cout<<"3rd Largest : "<<temp->right->info<<endl;
			   return;
			 }

			  if (temp1->right == NULL && temp1->left != NULL )
			 { node *temp2;
				 cout<<"1st largest : "<<temp->right->right->info<<endl;
				 cout<<"2nd Largest : "<<temp1->info<<endl;
				 temp2=temp1->left->right;

				 if (temp1->left->right != NULL)
				 {
					 while ( temp2->right != NULL)
					 {
						 temp2=temp2->right;
					 }
				cout<<"3rd Largest : "<<temp2->info<<endl;
				return;

				 }
				 else
				 {
					cout<<"3rd Largest : "<<temp1->left->info<<endl;
					return;
				 }

			   
			 }


			 if (temp1->right != NULL)
			 {
				 while (temp1->right->right != NULL)
				 {
					 temp1=temp1->right;
				 }
			   cout<<"2nd Largest : "<<temp1->right->info<<endl;
		       cout<<"3rd Largest : "<<temp1->info<<endl;
			   return;

			 }

		 }//case 3 end



		 
	 }//right subtree isses bracess

 }

 void special_element_print(node *temp,int num1 , int num2 )
 {
	 //reach upto num1 then back traverse using print funciton and break point num2




	 if (temp->info > num1)
	 {
		 special_element_print(temp->left,num1,num2);
		 return;
	 }
	 if (temp->info < num1)
	 {
		  special_element_print(temp->right,num1,num2);
		 return;

	 }
 }
};

int main()
{
	Tree t;
	int l=0,n1=0,n2=0;

int ch;

while(7)
{
	t.option();
	cout<<"Enter Option : ";
	cin>>ch;

	switch(ch)
	{

	case 1 :
		cout<<"Enter Value which you want to Add in tree :";
		cin>>t.number;
		t.insert_in_order(t.root);
		break;
	
	case 2 :
		cout<<endl;
			cout<<"In order Tree Data : ";
			t.search_inorder(t.root);
			cout<<endl;
			break;
		
	case 3:
		
		cout<<" You want to post order in Tree : ";
	
		t.search_post_order(t.root);
		cout<<endl;
			break;
	case 4:

		cout<<"Which Node you wana to delete : ";
		cin>>t.number;
		t.deleteo(t.root,t.number);
		cout<<endl;

		break;
	case 5:	
		cout<<endl;
		t.largest_value(t.root);
		cout<<endl;
		break;

	case 6:
		cout<<"Enter two Number to Print Element Between them : ";
		cin>>n1;
		cin>>n2;
		t.special_element_print(t.root,n1,n2);
		cout<<endl;
		break;
	case 7:
		
			exit(0);
			break;
		
	
	}

}
	cout<<endl<<endl;
	system("pause");
	return 0;
}