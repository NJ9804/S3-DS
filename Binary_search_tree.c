#include<stdio.h>				
#include<stdlib.h>					
struct node
{
    struct node *lptr,*rptr;
    int data;
}*root,*new1,*parent;
void insert(int val)
{
    struct node *ptr;
    new1=(struct node*)malloc(sizeof(struct node));
    new1->data=val;
    new1->rptr=new1->lptr=NULL;
    if(root==NULL)
   	 root=new1;
    else
    {
   	 ptr=root;
   	 while(ptr!=NULL)
   	 {
   		 parent=ptr;
   		 if(ptr->data>val)
   			 ptr=ptr->lptr;
   		 else
   			 ptr=ptr->rptr;
   	 }
   	 if(parent->data>val)
   		 parent->lptr=new1;
   	 else
   		 parent->rptr=new1;
    }
}
struct node* insuc(struct node *ptr)
{
    ptr=ptr->rptr;
    while(ptr->lptr!=NULL)
   	 ptr=ptr->lptr;
    return ptr;
}
void delete1(int val)
{
    struct node *insucces,*ptr;
    int succes;
    ptr=root;
    while(ptr!=NULL)
    {
   	 if(ptr->data==val)
   		 break;
   	 else
   	 {
   		 parent=ptr;
   		 if(ptr->data>val)
   			 ptr=ptr->lptr;
   		 else
   			 ptr=ptr->rptr;
   	 }
    }    
    if(ptr==NULL)
   	 printf("Element not found deletion not possible \n");
    else
    {
   	 if(ptr->lptr==NULL&&ptr->rptr==NULL)
   	 {    
   		 if(ptr==root)
   			 root=NULL;
   		 else if(parent->lptr==ptr)
   			 parent->lptr=NULL;
   		 else
   			 parent->rptr=NULL;
   	 }
   	 else if(ptr->rptr==NULL)
   	 {
   		 if(ptr==root)
   			 root=ptr->lptr;
   		 else if(parent->lptr==ptr)
   			 parent->lptr=ptr->lptr;
   		 else
   			 parent->rptr=ptr->lptr;
   	 }
   	 else if(ptr->lptr==NULL)
   	 {
   		 if(ptr==root)
   			 root=ptr->rptr;
   		 else if(parent->lptr==ptr)
   			 parent->lptr=ptr->rptr;
   		 else
   			 parent->rptr=ptr->rptr;
   	 }
   	 else
   	 {
   		 insucces=insuc(ptr);
   		 succes=insucces->data;
   		 delete1(insucces->data);
   		 ptr->data=insucces->data;
   	 }
    }
}
void preorder(struct node *ptr)
{
    if(ptr==NULL)
   	 return;
    else
    {
   	 printf("%d ",ptr->data);
   	 preorder(ptr->lptr);
   	 preorder(ptr->rptr);
    }
}
void inorder(struct node *ptr)
{
    if(ptr==NULL)
   	 return;
    else
    {
   	 inorder(ptr->lptr);
   	 printf("%d ",ptr->data);
   	 inorder(ptr->rptr);
    }
}
void postorder(struct node *ptr)
{
    if(ptr==NULL)
   	 return;
    else
    {
   	 postorder(ptr->lptr);
   	 postorder(ptr->rptr);
   	 printf("%d ",ptr->data);
    }
}
struct node* search(int val)
{
    struct node *ptr;
    ptr=root;
    while(ptr!=NULL)
    {
   	 if(ptr->data==val)
   	 {
   		 printf("%d is found\n",val);
   		 break;
   	 }
   	 else if(ptr->data>val)
   		 ptr=ptr->lptr;
   	 else
   		 ptr=ptr->rptr;
    }
    if(ptr==NULL)
   	 printf("%d was not found\n",val);
}
void display()
{
    if(root==NULL)
   	 printf("Tree is empty\n");
    else
    {
       	printf("Preorder representation of tree : ");
       	preorder(root);
       	printf("\n");
       	printf("Inorder representation of tree : ");
       	inorder(root);
       	printf("\n");
       	printf("Postorder representation of tree : ");
       	postorder(root);
       	printf("\n");
     }
}
void main()
{
    int ch,val;
    do
    {
   	 printf("Enter 1:Insert 2:Delete 3:Search 4:Display 5:Exit\n");
   	 scanf("%d",&ch);
   	 switch(ch)
   	 {
   		 case 1:printf("Enter the value to insert :");
   		    	scanf("%d",&val);
   		    	insert(val);
   		    	break;
   		 case 2:printf("Enter the value of node to delete : ");
   		    	scanf("%d",&val);
   		    	delete1(val);
   		    	break;
   		 case 3:printf("Enter the value of node to search : ");
   		    	scanf("%d",&val);
   		    	search(val);
   		    	break;
   		 case 4:display();
   		    	break;
   		 case 5:break;
   		 default:printf("Invalid input\n");
   	 }
    }while(ch<5);
}
