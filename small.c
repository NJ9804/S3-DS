//To delte the smallest node from sll
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
}*new,*head,*ptr1,*ptr,*head1,*ptr3;
void insert();
void create_sll();
void del_sll(struct node *head1);
int item,small,ch;
void insert()
{
    new=(struct node*)malloc(sizeof(struct node));
    printf("Enter the item to be inserted\n");
    scanf("%d",&item);
    new->data=item;
    new->link=NULL;
}
void create_sll()
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
void del_sll(struct node *head1)
{
    head = head1;
    small = head->data;
    ptr = head->link;
    ptr1 = head;

    // Find the smallest element and its previous node
    while (ptr != NULL)
    {
        if (small > ptr->data)
        {
            small = ptr->data;
            ptr1 = ptr;
        }
        ptr = ptr->link;
    }

    // If the smallest element is the head
    if (ptr1 == head)
    {
        head = head->link;
        printf("\n%d is the lowest node\n", ptr1->data);
        free(ptr1);
        return;
    }

    // Find the node before the smallest element
    ptr = head;
    while (ptr->link != ptr1)
    {
        ptr = ptr->link;
    }

    // Adjust the links to remove the smallest element
    ptr->link = ptr1->link;
    printf("\n%d is the lowest node\n", ptr1->data);
    free(ptr1);
}
void main()
{
     printf("To create sll\n");
    do
    {
        create_sll();
        printf("Do you want another node?(1--yes)\n");
        scanf(" %d",&ch);

    } while (ch==1);
    printf("The current sll is : \n");
    for(ptr=head;ptr->link!=NULL;ptr=ptr->link)
    {
        printf("%d\t",ptr->data);
    }
    printf("%d\t",ptr->data);
    del_sll(head);
    printf("The modified array is: \n");
    for(ptr=head;ptr->link!=NULL;ptr=ptr->link)
    {
        printf("%d\t",ptr->data);
    }
    printf("%d\t",ptr->data);
}