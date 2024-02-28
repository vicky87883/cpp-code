#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
	int value;
	struct node *link;
};
struct list1{
	int value;
	struct list1 *l1;
};
struct list2{
	int value;
	struct list2 *l2;
};
//struct node *l1,*l2;
void list1()
{
	struct list1 *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	cout<<"Enter the node data";
	cin>>temp->value;
	temp->link=NULL;
	if(l1==NULL)
	l1=temp;
	else
	{
		struct node *p;
		p=l1;
		while(p->link!=NULL)
		{
			p=p->link;
		}
		p->link=temp;
	}
}
void list2()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	cout<<"Enter the node data";
	cin>>temp->value;
	temp->link=NULL;
	if(l2==NULL)
	l2=temp;
	else
	{
		struct node *p;
		p=l2;
		while(p->link!=NULL)
		{
			p=p->link;
		}
		p->link=temp;
	}
}
int len1()
{
	int count=0;
	while(l1!=NULL)
	{
		count++;
		l1=l1->link;
	}
	return count;
	
}
int len2()
{
	int count=0;
	while(l2!=NULL)
	{
		count++;
		l2=l2->link;
	}
	return count;
}
void Return_Node(int data)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
    temp->value=data;
    temp->link=NULL;
    if(root==NULL)
    {
    	root=temp;
	}
	else
	{
		struct node *p;
		while(p->link!=NULL)
		{
			p=p->link;
		}
		p=temp;
	}
}
void Print_Node_Sum()
{
	struct node *temp;
	while(temp!=NULL)
	{
		printf("%d",temp->value);
	}
}
void nodesum()
{
	int i=0;
	while(l1!=NULL&&l2!=NULL)
	{
		Return_Node(l1->value+l2->value);
	}
}
//void nodesum()
//{
//	int arr[10];
//	int i=0;
//	while(l1!=NULL&&l2!=NULL)
//	{
//	arr[i]=l1->value+l2->value;
//	i++;
//	}
//}
int main()
{
	int ch;
	while(1)
	{
	cout<<"Enter the first list data\n";
	cout<<"Enter the second list data\n";
	cout<<"see the sum\n";
	cin>>ch;
	switch(ch)
	{
		case 1:
			list1();
			break;
			case 2:
				list2();
				break;
				case 3:
					nodesum();
					break;
				case 4:
					Print_Node_Sum();
					break;
			
	}
}
}
