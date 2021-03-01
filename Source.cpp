#include<iostream>
#include<string>
using namespace std;
struct node
{
	int info;
	node *left;
	node *right;
	int height;
};
class avl  // class 
{
private:
	node *temp;
public:
	avl() //constructor
	{
     temp=root=NULL;
	 number = 0;
	}
	node* root;
	int number;

	void to_make_Empty(node *temp)//making array empty one by one 
	{
		if (temp== NULL)
		  return ;  

		to_make_Empty(temp->left);
		to_make_Empty(temp->right);
		delete temp;
	}

	int height(node *temp)
	{
		return (temp == NULL ? -1 : temp->height); 

	}
	node* findMin(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

	    node* findMax(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }


	node *insert(int num, node *temp)
	{
		if (temp == NULL)
		{
			temp = new node;
			temp->info = number;
			temp->height = 0;
			temp->left = NULL;
			temp->right = NULL;
		
		}
		else if (number < temp->info)
		{
			temp->left = insert(num,temp->left);

			if (height(temp->left) - height(temp->right) == 2 )
			{
				if (number < temp->left->info)
				temp= singleRightRotation(temp);

				else

					temp= doubleRightRotation(temp);
			}
		}

		else if (number > temp->info)
		{

			temp->right = insert(number , temp->right);

			if (height(temp->right) - height(temp->left) == 2 )
			{

				if (number > temp->right->info)
               
					temp = singleLeftRotation(temp);

				else
                       
					temp= doubleLeftRotation(temp);

			}
		}


		temp->height = max(height(temp->left) , height(temp->right)) + 1 ;
		return temp;
	}

	node *singleLeftRotation(node *temp)
	{
	
		node *pr =temp->right;
		temp->right=pr->left;
		pr->left = temp;
		temp->height = max(height(temp->left), height(temp->right)) + 1;
		pr->height  = max(height(temp->right), temp->height) +1;
		return pr;
	
	}
	node * singleRightRotation(node *ptr)
	{
		node *temp = ptr->left;
		ptr->left  = temp->right;
		temp->right = ptr;

		ptr->height = max(height(ptr->left), height(ptr->right));
		temp->height= max(height(ptr->left), height(ptr->right));

		return temp;
	}

	node *doubleLeftRotation(node* ptr)//right and left rotation
	{
		ptr->right = singleRightRotation(ptr->right);

		return singleLeftRotation(ptr);
	}


	node *doubleRightRotation(node *ptr) // left and right Rotation
	{

		ptr->left= singleLeftRotation(ptr->left);

		return singleRightRotation(ptr);

	}


	node *remove(int number , node *ptr)
	{
		node *temp;

		if (ptr == NULL) //  Element Not Founded 	
			return NULL;


		else if (number < ptr->info)  //search for element
		
			ptr->left= remove(number , ptr->left);
              
		else if( number > ptr->info ) // search for element 

			ptr->right = remove(number , ptr->left);

		// Now Beneth here Element is founded 

		//Case 1 With 2 child

		else if (ptr-> left != NULL  && ptr-> right != NULL )
		{
			temp= findMin(ptr->right);
			temp->info = ptr-> info;

			ptr->right = remove(ptr->info , ptr->right);
			// upper line is for He took the number into last child and then he will delete it on
			//next function , thats why he is searching again 

		}

		else  // with 0 or 1  Child 
		{
			temp=ptr;
			if (ptr->left == NULL)
			
				ptr = ptr->right;

			else if ( ptr->right == NULL )
				ptr=ptr->left;

			delete temp;
		}
		    if (ptr == NULL)
			return ptr;
	
		ptr->height = max(height(ptr->left) , height(ptr->right)) +1;


	 // if node is Unbalance 

		//case 1 if left node is Deleted , Right Case

		if (height(ptr->left) - height(ptr->right) == 2 );
		{
			//right right case 

			if (height(ptr->left->left) - height(ptr->left->right) == 1 )
			{
				return singleLeftRotation(ptr);

			}
			//right left case 
			else
			{
				return doubleLeftRotation(ptr);
			}
		}

		//case 2 if right node is deleted , Left case 
		
		 if( height(ptr->right) - height(ptr->left) == 2)
		{

			//left left case 

			if (height(ptr->right->right) - height(ptr->right->left) == 1)
			{
				return singleRightRotation(ptr);

			}

			//left right case 

			else
			{
				return doubleRightRotation(ptr);
			}
		}

		 return ptr;

	}



	int getBalance(node *ptr)
	{
		if (ptr == NULL)
		{
			return 0;
		}

		else
		{
			return height(ptr->left) - height(ptr->right);
		}
	}

	void inorder(node *temp)
	{
		if (temp == NULL)
		{
			return ;

		}

		inorder(temp->left);
		cout<<temp->info<<" ";
		inorder(temp->right);

	}

	void insert(int x)
    {
        root = insert(x, root);
    }

    void remove(int x)
    {
        root = remove(x, root);
    }

    void display()
    {
        inorder(root);
        cout << endl;
    }

};
int main()
{
	avl t;

	 t.insert(20);
    t.insert(25);
    t.insert(15);
    t.insert(10);
    t.insert(30);
    t.insert(5);
    t.insert(35);
    t.insert(67);
    t.insert(43);
    t.insert(21);
    t.insert(10);
    t.insert(89);
    t.insert(38);
    t.insert(69);
    t.display();
    t.remove(5);
    t.remove(35);
    t.remove(65);
    t.remove(89);
    t.remove(43);
    t.remove(88);
    t.remove(20);
    t.remove(38);
    t.display();



	system("pause");
	return 0;
}