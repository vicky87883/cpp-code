#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct ListNode {
      int val;
      struct ListNode *next;
  };
  struct ListNode *l1;
  struct ListNode *l2;
  void append1()
  {
  	struct ListNode *temp;
  	temp = (struct ListNode*)malloc(sizeof(struct ListNode));
  	printf("Enter the first list data");
  	scanf("%d",&temp->val);
  	temp->next=NULL;
  	if(l1==NULL)
  	{
  	l1=temp;	
	}
	else
	{
		struct ListNode *p;
		p=l1;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=temp;
	}
  }
  void append2()
  {
  	struct ListNode *temp;
  	temp = (struct ListNode*)malloc(sizeof(struct ListNode));
  	printf("Enter the Second List Data..");
  	scanf("%d",&temp->val);
  	temp->next=NULL;
  	if(l2==NULL)
  	l2=temp;
  	else
  	{
  		struct ListNode *p;
  		p=l2;
  		while(p->next!=NULL)
  		{
  			p=p->next;
		}
		p->next=temp;
	}
  }
  void displayboth()
  {
  	struct ListNode *temp1,*temp2;
  	temp1=l1;
  	temp2 = l2;
     printf("Here the both lists are \n");
     while(temp1!=NULL)
     {
     	printf("%d",temp1->val);
     	temp1=temp1->next;
	 }
	 while(temp2!=NULL)
	 {
	 	printf("%d",temp2->val);
	 	temp2=temp2->next;
	 }
  }
  void addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *sum;
    sum=(struct ListNode *)malloc(sizeof(struct ListNode));
while(l1!=NULL&&l2!=NULL)
{
sum->val = l1->val+l2->val;
l1=l1->next;
l2=l2->next;
sum=sum->next;
}
}

 int main()
 {
 	while(1)
 	{
 		int ch;
 	printf("Press 1 for first list data\n")	;
 	printf("Press 2 for second list data\n");
 	printf("Press 3 for display both list data\n");
 	printf("press 4 for sum of element of linked list");
 	printf("Exit from the program\n");
 	scanf("%d",&ch);
 	switch(ch)
 	{
 	case 1:
append1();
break;
case 2:
append2();
break;
case 3:
	displayboth();
	break;
	case 4:
		addTwoNumbers(l1,l2);
		break;
case 5:
exit(0);
	}
	}
 }
