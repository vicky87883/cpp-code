#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
	int data;
	struct node *link;
};
struct node *root=NULL;
void insertion()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	cout<<"Enter the node data\n";
	cin>>temp->data;
	temp->link=NULL;
	if(root==NULL)
	root=temp;
	else
	{
		struct node *p=root;
		while(p->link!=NULL)
		{
			p=p->link;
		}
		p->link=temp;
	}
}
void deletion()
{
	int loc,i=1,j=1;
	struct node *p,*q;
	p=root;
	q=root;
	cout<<"Enter the location\n";
	cin>>loc;
	while(i<loc)
	{
		p=p->link;
		i++;
	}
	while(j<loc-1)
	{
		q=q->link;
		j++;
	}
	q->link=p->link;
	p->link=NULL;
	cout<<"After deletion\n";
	while(p!=NULL)
	{
		cout<<p->data;
		p=p->link;
	}
}
void display()
{
	struct node *temp=root;
	cout<<"data is\n";
	while(temp!=NULL)
	{
		cout<<"|"<<temp->data<<"|->";
		temp=temp->link;
	}
}
int main()
{
	int ch;
	while(1)
	{
		cout<<"1. Insertion\n";
		cout<<"2. Deletion\n";
		cout<<"3. Display\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				insertion();
				break;
				case 2:
					deletion();
					break;
					case 3:
						display();
						break;
					case 4:
						exit(0);
		}
		
	}
}
