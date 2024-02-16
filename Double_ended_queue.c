#include<stdio.h>						
#include<stdlib.h>							
# define MAX_SIZE 3									
int front=-1,rear=-1,item,ch,del_item,op,i,temp,fpos,rear_pos;
int Q[MAX_SIZE];
void enqueuefront();
void enqueuerear();
void dequeuefront();
void dequeuerear();
void Display();
void main()
{
do{
    printf("1--enqueuerear\t\t2--enqueuefront\t\t3--dequeuefront\t\t4--dequeuerear\t\t5--Display\n");
    printf("Enter your choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: enqueuerear();
                break;
        case 2: enqueuefront();
                break;
        case 3: dequeuefront();
                break;
        case 4 : dequeuerear();
                break;
        case 5 : Display();
                break;
        default: printf("INVALID CHOICE\n");
    }
    printf("\n");
    printf("DO YOU WANT TO CONTINUE?(1--YES)\n");
    scanf("%d",&op);
 }while(op==1);
}
void enqueuerear()
{
    printf("Enter the item to be inserted\n");
    scanf("%d",&item);
    if(front==(rear+1)%MAX_SIZE)
    {
        printf("QUEUE IS FULL\nInsertion not possible\n");
    }
    else if(front==-1)
    {
        front=0;
        rear=0;
        Q[rear]=item;
    }
    else
    {
        rear=(rear+1)%MAX_SIZE;
        Q[rear]=item;
    }
}
void dequeuefront()
{
    if(front==-1)
    {
        printf("QUEUE IS EMPTY\nDeletion not possible\n");
    }
    else
    {
        del_item=Q[front];  
        printf("%d is the deleted item\n",del_item);
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {   
            front=(front+1)%MAX_SIZE;
        }
    }
}
void enqueuefront()
{
    printf("Enter the item to be inserted\n");
    scanf("%d",&item);
    if(front==-1)
    {
        front=0;
        rear=0;
        Q[front]=item;
    }
    else
    {  
        if(front==0)
        {
            temp=MAX_SIZE-1;
        }
        else
        {
            temp=front-1;
        }
        if(temp==rear)
        {
             printf("QUEUE IS FULL\n");
        }
         else
        {
            front=temp;
            Q[front]=item;
        }
    }

}
void dequeuerear()
{
    if(rear==-1)
    {
        printf("QUEUE IS EMPTY\nDeletion not possible\n");
    }
    else
    {
        del_item=Q[rear];
        printf("%d is the deleted item",Q[rear]);
        if(rear==front)
        {
            rear=-1;
            front=-1;
        }
        else if(rear==0)
        {
            rear=MAX_SIZE-1;
        }
        else
        {
            rear=rear-1;
        }
    }
}


void Display()
{
    fpos = front;
    rear_pos = rear;
    if(front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements :\n");
    if( fpos <= rear_pos )
    {
        while(fpos <= rear_pos)
        {
            printf("Q[%d]=%d ",fpos,Q[fpos]);
            fpos++;
        }
    }
    else
    {
        while(fpos <= MAX_SIZE-1)
        {
            printf("Q[%d]=%d ",fpos,Q[fpos]);
            fpos=fpos+1;
        }
        fpos = 0;
        while(fpos <= rear_pos)
        {
            printf("Q[%d]=%d ",fpos,Q[fpos]);
            fpos++;
        }
    }
    printf("\n");
