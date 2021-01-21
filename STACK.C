#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void display();
void search();
struct node
{
 int data;
 struct node *next;
};
 struct node *head;

void main()
{
 int c;
 clrscr();
 do
 {
  printf("\n\n1.Push\n2.Pop\n3.Display\n4.Search\n5.Exit\n\n");
  scanf("%d",&c);
  switch(c)
  {
   case 1:push();
   break;
   case 2:pop();
   break;
   case 3:display();
   break;
   case 4:search();
   break;
   case 5:exit(0);
   break;
   default:printf("Wrong Input");
   break;
  }
  }while(c!=5);
  getch();
}

void push()
{
 struct node *newnode;
 newnode=(struct node*)malloc(sizeof(struct node));
 printf("Enter the data:");
 scanf("%d",&newnode->data);
 if(head==NULL)
 {
  head=newnode;
  }
 else
 {
  newnode->next=head;
  head=newnode;
 }
}

void pop()
{
 struct node *newnode;
 if(head==NULL)
 {
  printf("Stack is Empty\n\n");
  }
 else
 {
  newnode=head;
  head=head->next;
  printf("%d poped\n\n",newnode->data);
  free(newnode);
  }
}

void display()
{
 struct node *temp;
 temp=head;
 if(temp==NULL)
   printf("Stack is empty\n\n");
 else
 {
  while(temp!=NULL)
  {
   printf("%d\t",temp->data);
   temp=temp->next;
   }
  }
  return;
}

void search()
{
 struct node *temp;
 int s,i=1,p;
 temp=head;
 if(head==NULL)
   printf("Stack is empty\n\n");
 else
 {
   printf("Enter the data to be searched:");
   scanf("%d",&s);
   while(temp!=NULL)
   {
    if(temp->data==s)
    {
    p=0;
    printf("%d found at %d position:",temp->data,i);
    break;
    }
    else
    {
    temp=temp->next;
    i++;
    p=1;
    }
   }
   if(p==1)
   {
    printf("Element not found\n\n");
  }
  return;
}
}