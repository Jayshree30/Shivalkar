#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *prev;
	int data;
	struct node *next;

};
struct node* createNode(int);
void addFirst(struct node **, int);
void display(struct node *);
void insertAtPos(struct node **, int, int);
void delFirst(struct node**);
void delAtPos(struct node**,int);
void addLast(struct node **, int);
int main()
{
	struct node *head=NULL;
	int choice, input, pos;
	while(1)
	{
		printf("enter 1-->add first 2-->display 3-->insert at position\n");
		printf("enter 4-->delete first 5-->delete at position 6-->add last \n");
		printf("enter 7-->del last \n");
		printf("Enter your choice::\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1://add first
				printf("enter data val\n");
				scanf("%d", &input);
				addFirst(&head, input);
				break;

			case 2://display
				printf("***list item***\n");
				display(head);
				break;

			case 3://insert at position
				printf("enter data val\n");
				scanf("%d", &input);
				printf("enter data pos\n");
				scanf("%d", &pos);
		   		insertAtPos(&head, input, pos);
				break;
		
			case 4://delfirst
				display(head);
			 	delFirst(&head);
				display(head);
				break;

			case 5://delAtPos
				printf("enter data pos\n");
				scanf("%d",&pos);
				display(head);
				delAtPos(&head,pos);
				display(head);
				break;	
	
			case 6://add last
				printf("enter data val\n");
				scanf("%d", &input);
				addLast(&head, input);
				break;
			
			case 7://del last
				display(head);
			        delLast(&head);
			        display(head);

		}
	}
	
	return 0;
}
void delLast(struct node **ptr)
{	

	int i=1;
	if(*ptr==NULL)
	{
	printf("linklist is empty\n");
		return;
	}
	else{

		struct node *temp,*follow;
		temp=*ptr;
		while(temp->next!=NULL)
		{
			follow=temp;
			temp=temp->next;
				
		}
		follow->next=NULL;
		printf("data %d is deleted from linklist\n",temp->data);
		free(temp);
		temp=NULL;
	
	}
	return;
	

}
void addLast(struct node **ptr, int data)
{

	struct node *temp;
	temp=*ptr;
	struct node *newnode;
	if(temp==NULL)
	{
		addFirst(ptr, data);
		return ;
        }
	else{
	newnode=createNode(data);

	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newnode;
	newnode->prev=temp;
	return;
	}

}
void delAtPos(struct node **ptr ,int pos)
{
	int i;
	struct node *temp='NULL', *temp1='NULL';
	if(*ptr=='NULL')
	{
		printf("linklist is empty\n");
		return;
	}
	else
	{
		temp=*ptr;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->next;
			
		}
		temp1=temp->next;
		temp1->next->prev=temp;
		temp->next=temp1->next;
		printf("data %d is deleted from linklist\n",temp1->data);
		free(temp1);
		temp1='NULL';	
	}
		return;
}	


void delFirst(struct node **ptr)
{
	if(*ptr==NULL)
	{
	printf("linklist is empty\n");
		return;
	}
	else{
	struct node *temp;
	temp=*ptr;
	*ptr=(*ptr)->next;
	
	printf("data %d is deleted from linklist\n",temp->data);
	free(temp);
	temp=NULL;
	(*ptr)->prev=NULL;
	}


}
void insertAtPos(struct node **ptr, int input, int pos)
{
	struct node *trav='NULL',*newnode='NULL';
	int i=0;
	if(*ptr=='NULL'||pos ==1)
	{
		addFirst(*ptr,input);
	}
	else
	{
		newnode=createNode(input);
		trav=*ptr;
		for(i=1;i<pos-1;i++)
		{
			trav=trav->next;
		}
		newnode->prev=trav;
		newnode->next=trav->next;
		trav->next->prev=newnode;
		trav->next=newnode;
	}
	return;

}
void addFirst(struct node **ptr, int data)
{
	struct node *newnode=NULL;
	newnode=createNode(data);
	if(*ptr==NULL)
	{
		*ptr=newnode;
	}
	else
	{
		newnode->next=*ptr;
		*ptr=newnode;
		newnode->prev='NULL';
	}
	return;
}
void display(struct node *ptr)
{
	while(ptr!=NULL)
	{
		printf("-->%d", ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
	
	return;
}
struct node* createNode(int data)
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=data;
	return newnode;
}






