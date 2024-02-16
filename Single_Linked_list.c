#include<stdio.h>
#include<stdlib.h>
void dele_poss();
struct node
{
    int data;
    struct node *link;
};
struct node *head,*new,*ptr,*temp,*ptr1;
int pos,i;
void main()
{
    int choice,op;
    do
    {
        printf("Enter your choice : \n");
        printf("1--insertion at beginning\t2--insertion at end\t3--insertion at particular position\n4--deletion from beginning\t5--deletion from end\t6--deletion from a particular   position\n7--Display Current Linked List\n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:insert_beg();
                   break;
            case 2:insert_end();
                   break;
            case 3:insert_pos();
                   break;
            case 4:dele_beg();
                   break;
            case 5:dele_end();
                   break;
            case 6:dele_pos();
                   break;
            case 7:display();
                   break;
            default:
                    break;
            
        }
        printf("Enter 1 to continue\n");
	    scanf("%d",&op);
	}while(op==1);
}



void insert()
{
    int item;
    new=(struct node *)malloc(sizeof(struct node));
    printf("Enter the value to be inserted\n");
    scanf("%d",&item);
    new->data=item;
    new->link=NULL;
}
void insert_beg()
{
    insert();
    if(head==NULL)
    {
        head=new;
    }
    else
    {
        new->link=head;
        head=new;
    }
}
void insert_end()
{
    insert();
    if(head==NULL)
    {
        head=new;
    }
    else
    {
        ptr=head;
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=new;
    }
}
void insert_pos()
{
    printf("Enter the position to be inserted :\n");
    scanf("%d",&pos);
    if(pos==1)
    {
        insert_beg();
    }
    else
    {
        insert();
        for(i=1;i<pos-1;i++)
        {
            ptr=ptr->link;
        }
        new->link=ptr->link;
        ptr->link=new;
        free(ptr);
    }
}
void dele_beg()
{
    if (head==NULL)
    {
        printf("Linked List is Empty,Deletion not possible\n");
    }
    else
    {
        if (head->link==NULL)
        {
            temp=head;
            printf("The Deleted item is %d\n",temp->data);
            head=NULL;
        }
        else
        {
            temp=head;
            printf("The Deleted item is %d\n",temp->data);
            head=temp->link;
            free(temp);
        }
    }
}
void dele_pos()
{
    printf("Enter the position at which element should be deleted :\n");
    scanf("%d",&pos);
    ptr = head; 
    int i;
    if (pos == 1) 
    {
        printf("\nElement deleted is : %d\n", ptr->data);
        head = head->link;
        ptr->link = NULL;
        free(ptr); 
    }
    else {
        for (i = 1; i < pos - 1; i++) 
        {
            ptr = ptr->link;
        }
        temp= ptr->link;
        ptr->link = ptr->link->link;
        printf("\nThw deleted item is %d\n", temp->data);
        temp->link = NULL;
        free(temp); 
    }
}
void dele_end()
{
    if(head==NULL)
    {
        printf("Linked List is Empty,Deletion not possible\n");
    }
    else
    {
        if (head->link==NULL)
        {
            temp=head;
            printf("The Deleted item is %d\n",temp->data);
            head=NULL;
        }
        else
        {
            ptr=head;
            while(ptr->link!=NULL)
            {
                ptr1=ptr;
                ptr=ptr->link;
            }
            temp=ptr;
            printf("The Deleted item is %d\n",temp->data);
            ptr1->link=NULL;
            free(temp);
        }
    }
}
void display()
{
    if(head==NULL)
    {
        printf("Linked List is Empty\n");
    }
    else
    {
        ptr=head;
        while(ptr->link!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->link;
        }
        printf("%d",ptr->data);
        printf("\n");
    }
}