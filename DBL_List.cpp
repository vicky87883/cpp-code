#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *root=NULL;
void Insertion_DBL(){
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	cout<<"Enter the data\n";
	cin>>temp->data;
	temp->left=NULL;
	temp->right=NULL;
	if(root==NULL)
	root=temp;
	else
	{
		struct node *p=root;
		while(p->right!=NULL)
		{
			p=p->right;
		}
		p->right=temp;
		temp->left=p;
	}
}
void Display_DBL()
{
	struct node *temp=root;
	while(temp!=NULL)
	{
		cout<<"|"<<temp->data<<"|->";
		temp=temp->right;
	}
}
void Deletion_DBL()
{
	int loc;
	int i=1,j=1;
	struct node *p,*q;
	p=root;
	q=root;
	cout<<"Enter the location\n";
	cin>>loc;
	while(i<loc)
	{
		p=p->right;
		i++;
	}
	while(j<loc-1)
	{
		q=q->right;
		j++;
	}
	q->right=p->right;
	p->right->left=q;
	p->left=NULL;
	p->right=NULL;
}
int main()
{
	int ch;
while(1)	
{
	cout<<"Insertion\n";
	cout<<"Display\n";
	cout<<"Deletion\n";
	cin>>ch;
	switch(ch)
	{
		case 1:
			Insertion_DBL();
			break;
			case 3:
				Deletion_DBL();
				break;
				case 2:
					Display_DBL();
					break;
					case 4:
						exit(0);
						default:
							cout<<"nothing here to display\n";
	}
}
}
