#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<list>
#include "mysql.h"
struct list1{
	int data;
	struct list1 *next;
};
struct list2
{
	int data;
	struct list2 *next;
};
struct node {
	int data;
	struct node *next;
};
struct list1 *l1=NULL;
struct list2 *l2=NULL;
struct node *root=NULL;
int append_list1(void)
{
	struct list1 *temp;
	temp=(struct list1*)malloc(sizeof(struct list1));
	printf("Enter the Node Data");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if(l1==NULL)
		l1=temp;
	else
	{
		struct list1 *p;
		p=l1;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p=temp;
	}
	return temp->data;
}
int append_list2(void)
{
	struct list2 *temp;
	temp=(struct list2*)malloc(sizeof(struct list2));
	printf("Enter the Node Data");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if(l2==NULL)
		l2=temp;
	else
	{
		struct list2 *p;
		p=l2;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p=temp;
	}
	return temp->data;
}
int Addition_Of_List()
{
	struct node *temp;
	int count=0;
	temp=(struct node*)malloc(sizeof(struct node));
//	temp->data=l1->data+l2->data;
     while(l1!=NULL&&l2!=NULL)
     {
     	l1=l1->next;
     	l2=l2->next;
	 }
	return count;
}
int main()
{
	int ch,val;
	while(1)
	{
		printf("\n1. Insertion in List1\n");
		printf("\n2. Insertion in List2\n");
		printf("\n3. Traversing\n");
		printf("\n4. Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				val=append_list1();
				printf("%d is inserted in the list1",val);
				break;
				case 2:
					val=append_list2();
					printf("%d is inserted in the list2",val);
					break;
					case 3:
						val=Addition_Of_List();
						printf("%d nodes are added...",val);
						break;
						case 4:
							exit(0);
						
		}
	}
	
}
