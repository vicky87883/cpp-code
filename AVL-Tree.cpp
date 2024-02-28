#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
	int key;
	struct node *left;
	struct node *right;
	int height;
};
//A utility function to get maximum of two integers
int max(int a,int b);
//A utility function to get height of the tree
int height(struct node *node)
{
	if(node==NULL)
	return 0;
	return node->height;
}
//A utility function to get maximum of two integers
int max(int a,int b)
{
	return (a>b)?a:b;
}
/*Helper function that allocates a new
node with the given key and Null left and right pointers.*/

struct node* newNode(int key)
{
	struct node *node;
	node=(struct node*)malloc(sizeof(struct node));
	node->key=key;
	node->left=NULL;
	node->right=NULL;
	node->height=1;// new node is initially added at left
	return (node);
}

//A utility function to right rotate subtree rooted with y
//See the diagram given above.
struct node *rightRotate(struct node *y)
{
	struct node *x=y->left;
	struct node *T2 = x->right;
//	perform rotation
x->right=y;
y->left=T2;
// Update heights
y->height = max(height(y->left),height(y->right))+1;
x->height = max(height(x->left),height(x->right))+1;
// Return new root
return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct node *leftRotate(struct node *x)
{
	struct node *y=x->right;
	struct node *T2=y->left;
//	Perform rotation
    y->left=x;
    x->right=T2;
//    Update heights
x->height=max(height(x->left),height(x->right))+1;
y->height=max(height(y->left),height(y->right))+1;

// Return new root
return y;
}
// Get balance factor of node N
int getBalance(struct node *node)
{
	if(node==NULL)
	return 0;
	return height(node->left)-height(node->right);
}

struct node* insert(struct node* node,int key)
{
	/*1. perform the normal BST rotation */
	if(node==NULL)
	return(newNode(key));
	
	if(key<node->key)
	node->left=insert(node->left,key);
	else
	node->right=insert(node->right,key);
	
//	2. Update height of this ancestor node 
node->height=max(height(node->left),height(node->right))+1;
/*3. Get the balance factor of this ancestor node to check whether this node became unbalanced*/
int balance=getBalance(node);

// if this node becomes unbalanced, then there are 4 cases 

// Left Left Case
if(balance>1 && key<node->left->key)
return rightRotate(node);

// Right Right Case
if(balance<-1&&key>node->right->key)
return leftRotate(node);

// Left Right Case
if(balance>1 && key>node->left->key)
{
	node->left=leftRotate(node->left);
	return rightRotate(node);
}
// Right Left Case
if(balance<-1 && key<node->right->key)
{
	node->right=rightRotate(node->right);
	return leftRotate(node);
}
/*return the (unchanged) node pointer */
return node;
}

// A utility function to print preorder traversal of the tree.
// The function also prints height of every node
void preOrder(struct node *root)
{
	if(root!=NULL)
	{
	cout<<"->"<<root->key;
	preOrder(root->left);
	preOrder(root->right);	
	}
}
void postOrder(struct node *root)
{
	if(root!=NULL)
	{
	postOrder(root->left);
	postOrder(root->right);	
	cout<<"->"<<root->key;
	}
}
void inOrder(struct node *root)
{
	if(root!=NULL)
	{
		inOrder(root->left);
		cout<<"->"<<root->key;
		inOrder(root->right);
	}
}
// Iterative approach function without recursion
void inOrder_Wout_Recursion(struct node* y)
{
	struct node *curr,*pre;
	if(y==NULL)
	return;
	curr=y;
	while(curr)
	{
		if(curr->left==NULL)
		{
			cout<<curr->key<<" ";
			curr=curr->right;
		}
		else
		{
//			Find the inorder predecessor of current 
         pre = curr->left;
         while(pre->right!=NULL&&pre->right!=curr)
         	pre=pre->right;
//         	Make current as the right child of its
//            Inorder predecessor
            if(pre->right==NULL)
            {
            	pre->right=curr;
            	curr=curr->left;
			}
//			Revert the changes made in the 'if' part to
// restore the original tree i.e., fix the right
// child of predecessor
else
{
	pre->right=NULL;
	cout<<curr->key<<" ";
	curr=curr->right;
}
		 }
		}
}
/*Driver program to test above function */
int main()
{
	struct node *root=NULL;
	/*Construct tree given in the above figure */
	int ch,value;
	while(1)
	{
		cout<<"\n1. Insertion\n";
		cout<<"\n2. Preorder\n";
		cout<<"\n3. PostOrder\n";
		cout<<"\n4. Inorder\n";
		cout<<"\n5. Inorder without recursion";
		cout<<"\n6. Exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"enter the value";
				cin>>value;
				root=insert(root,value);
				break;
				case 2:
					preOrder(root);break;
				case 3:
					postOrder(root);break;
					case 4:
						inOrder(root);break;
						case 5:
							inOrder_Wout_Recursion(root);break;
					case 6:
						exit(0);
						default:
							cout<<"Defaulter";
		}
	}
}










