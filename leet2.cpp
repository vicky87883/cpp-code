//Program for Single linked list implementation
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node* link;
};
struct list1{
	int data;
	struct list1* link;
};
struct list2{
	int data;
	struct list2* link;
};
struct list1 *l1=NULL;
struct list2 *l2=NULL;
struct list3 *l3=NULL;
struct node* root;
int len;
void Add_BOTH_List_Data()
{
	struct list1 *temp;
	struct list2 *rand;
	temp=(struct list1 *)malloc(sizeof(struct list1));
	rand=(struct list2 *)malloc(sizeof(struct list2));
	printf("Enter the List1 Data\n");
	scanf("%d",&temp->data);
	printf("Enter the List2 Data\n");
	scanf("%d",&rand->data);
	temp->link=NULL;
	rand->link=NULL;
	if(l1==NULL)
	l1=temp;
	else
	{
		struct list1 *p;
		p=l1;
		while(p->link!=NULL)
		{
			p=p->link;
		}
		p->link=temp;
	}
	if(l2==NULL)
	l2=rand;
		else
	{
		struct list2 *q=l2;
		while(q->link!=NULL)
		{
			q=q->link;
		}
		q->link=rand;
	}
}
void append()
{

	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("Enter the node data->");
	scanf("%d",&temp->data);
	temp->link = NULL;
	if(root==NULL)	
	{
		root = temp;
	}
	else
	{
		struct node *p;
		p=root;
		while(p->link!=NULL)
		{
			p=p->link;
		}
		p->link=temp;
	}
}
int length()
{
	int count=0;
	struct node* temp;
	temp = root;
	while(temp!=NULL)
	{
	  count++;	
	  temp = temp->link;
	}
	return count;
}
void display()
{
	struct node *temp;
	temp = root;
	if(temp==NULL)
	{
		printf("List is Empty");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->link;
		}
		printf("\n\n");
	}
}
void deletefun()
{
	struct node *temp;
	int loc;
	printf("Enter Location to Delete\n");
	scanf("%d",&loc);
	if(loc>length())
	{
		printf("Invalid Location\n");
	}
	else if(loc==1)
	{
		temp=root;
		root=temp->link;
		temp->link=NULL;
		free(temp);
	}
	else
	{
		int i=1;
		struct node *p,*q;
		p=root;
		while(i<loc-1){
			p=p->link;
			i++;
		}
		q=p->link;
		p->link=q->link;
		q->link=NULL;
		free(q);
	}
	printf("Your %d has been deleted",loc);
}
void addatbegin()
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("Enter the Element\n");
	scanf("%d",&temp->data);
	temp->link=root;
	root=temp;
	printf("Node data Inserted Successfully\n");
}
void addafter()
{
	struct node *temp,*p=root;
	int i=1,loc;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("Enter the location to add after\n");
	scanf("%d",&loc);
	printf("Enter the Element\n");
	scanf("%d",&temp->data);
	temp->link=NULL;
	while(i<loc)
	{
		p=p->link;
		i++;
	}
	temp->link=p->link;
	p->link=temp;
	printf("Connection Successful");
}
void SEARCH_ELE()
{
	struct node* temp=root;
	int element,count=0;
	printf("Enter the element for searching\n");
	scanf("%d",&element);
	while(temp!=NULL)
	{
		if(element==temp->data)
		{
			count++;
		}
		temp=temp->link;
	}
	if(count==1)
	printf("Successful search\n");
	else
	printf("Unsuccessful search.\n");
}
void reverseLLPrint(struct node *temp) {
    if (temp != NULL) {
        reverseLLPrint(temp->link);
        printf("%d", temp->data);
    }
}
void Disp_Both_List()
{
	struct list1 *temp=l1;
	struct list2 *rand=l2;
	while(temp!=NULL&&rand!=NULL)
	{
		printf("|%d %d|->\n",temp->data,rand->data);
		temp=temp->link;
		rand=rand->link;
	}
}
void return_addition(int data)
{
	printf("%d->",data);
}
void Sum_Two_Lists()
{
	struct list1 *temp=l1;
	struct list2 *rand=l2;
	while(temp!=NULL&&rand!=NULL)
	{
		return_addition(temp->data+rand->data);
		temp=temp->link;
		rand=rand->link;
	}
}
//Remove the Last element from linked list
void remove_end_node()
{
	int key=1;
//	struct node* temp=root;
	while(key<length())
	{
		printf("%d",root->data);
		root=root->link;
	}
	printf("%d",root->data);
}
int main()
{
	while(1)
	{
		int ch;
		printf("\nSingle Linked List Operations\n");
		printf("1. Append\n");
//		printf("3. Add at After\n");
		printf("2. Length\n");
		printf("3. Display\n");
		printf("4. Delete \n");
		printf("5. Add at Begin\n");
		printf("6. Add after\n");
		printf("7. Reverse Order\n");
		printf("8. Searching\n");
		printf("\n----------------------------------------------------\n");
		printf("9. Two List Insertion\n");
		printf("10. Display two list\n");
		printf("11. Addition_List_data\n");
		printf("12. Remove_End_Node\n");
		
//		printf("11. Quit \n");
		printf("Enter Your Choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				append();
				break;
				case 2:
					len = length();
					printf("List Size is: %d\n",len);
					break;
					case 3:
						display();
						break;
						case 4:
							deletefun();
							break;
							case 5:
								addatbegin();
								break;
								case 6:
									addafter();
									break;
									case 7:
										reverseLLPrint(root);
										break;
										case 8:
											SEARCH_ELE();
											break;
											case 9:
												Add_BOTH_List_Data();
												break;
												case 10:
													Disp_Both_List();
													break;
													case 11:
														Sum_Two_Lists();
														break;
														case 12:
															remove_end_node();
															break;
//								case 10:
//									exit(0);
//									default:
//										printf("Invalid Choice");
		}
		
	}
}

