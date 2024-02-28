// C++ program for Inorder Morris Traversal
#include<bits/stdc++.h>
using namespace std;
// A binary tree tNode has data, a pointer to left child
struct node{
	int data;
	struct node *left;
	struct node *right;
};
// Function to traverse the binary tree
// without recursion and without stack
struct node *root=NULL;
void inOrder(struct node* root)
{
	struct node *curr,*pre;
	if(root==NULL)
	return;
	curr=root;
	while(curr!=NULL)
	{
		if(curr->left==NULL)
		{
			cout<<curr->data<<" ";
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
	cout<<curr->data<<" ";
	curr=curr->right;
}
		 }
		}
}
struct node* newNode(int data)
{
	struct node *temp = new node;
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return(temp);
}
int main()
{
//	struct node *root = newNode(1);
//	root->left=newNode(2);
//	root->right=newNode(3);
//	root->left->left=newNode(4);
//	root->left->right=newNode(5);
//	inOrder(root);
int ch,value;
struct node *root;
while(1)
{
	cout<<"Insertion\n";
	cout<<"Traversing\n";
	cin>>ch;
	switch(ch)
	{
		case 1:
			cout<<"Enter the value\n";
			cin>>value;
			newNode(value);
			break;
			case 2:
				inOrder(root);
				break;
	}
}
}

