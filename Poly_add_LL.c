#include<stdio.h>
#include<stdlib.h>
struct term
{
 int coef,exp;
 struct term *link;
};
struct term *head;
struct term* readpoly()
{
 struct term *new,*ptr;
 int i,n,c,e;
 head=NULL;
 printf("Enter the number of terms\n");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  printf("Enter the coefficient of %d term :",i+1);
  scanf("%d",&c);
  printf("Enter the exponent of %d term :",i+1);
  scanf("%d",&e);
  new=(struct term*)malloc(sizeof(struct term));
  new->coef=c;
  new->exp=e;
  if(head==NULL)
  {
   head=new;
   ptr=new;
  }
  else
  {
   ptr->link=new;
   ptr=new;
  }
 }
 return head;
}
struct term* addpoly(struct term *p,struct term *q)
{
 struct term *head1=NULL;
 struct term *new,*ptr1,*ptr2,*ptr3;
 ptr1=p;
 ptr2=q;
 ptr3=head1;
 while(ptr1!=NULL&&ptr2!=NULL)
 {
  new=(struct term*)malloc(sizeof(struct term));
  new->link=NULL;
  if(ptr1->exp==ptr2->exp)
  {
   new->coef=ptr1->coef+ptr2->coef;
   new->exp=ptr1->exp;
   ptr1=ptr1->link;
   ptr2=ptr2->link;
  }
  else if(ptr1->exp>ptr2->exp)
  {
   new->coef=ptr1->coef;
   new->exp=ptr1->exp;
   ptr1=ptr1->link;
  }
  else
  {
   new->coef=ptr2->coef;
   new->exp=ptr1->exp;
   ptr2=ptr2->link;
  }
  if(head1==NULL)
  {
   head1=new;
   ptr3=new;
  }
  else
  {
   ptr3->link=new;
   ptr3=new;
  }
 }
 while(ptr1!=NULL)
 {
  new=(struct term*)malloc(sizeof(struct term));
  new->link=NULL;
  new->coef=ptr1->coef;
  new->exp=ptr1->exp;
  ptr1=ptr1->link;
  ptr3->link=new;
  ptr3=new;
 }
 while(ptr2!=NULL)
 {
  new=(struct term*)malloc(sizeof(struct term));
  new->link=NULL;
  new->coef=ptr2->coef;
  new->exp=ptr2->exp;
  ptr2=ptr2->link;
  ptr3->link=new;
  ptr3=new;
 }
 return head1;
}
void display(struct term *head1)
{
 struct term *ptr;
 if(head1!=NULL)
 {
  printf("Polynomial :");
  ptr=head1;
  while(ptr->link!=NULL)
  {
   printf("%dX^%d+",ptr->coef,ptr->exp);
   ptr=ptr->link;
  }
  if(ptr->exp==0)
   printf("%d ",ptr->coef);
  else if(ptr->exp==1)
   printf("%dX ",ptr->coef);
  else
   printf("%dX^%d",ptr->coef,ptr->exp);
 }
 printf("\n");
}
void main()
{
 struct term *p,*q,*r;
 p=readpoly();
 display(p);
 q=readpoly();
 display(q);
 r=addpoly(p,q);
 printf("Resultant ");
 display(r);
}
















