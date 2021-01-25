#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
int count=0,i=1;
struct node
{
 struct node *left;
 int data;
 struct node *right;
 };
 struct node *head=NULL;
 struct node *GetNode();
 void display();
 void insertLast();
 void insertFirst();
 void insertPos();
 void deleteFirst();
 void deleteLast();
 void deletePos();
 void search();
 void main()
 {
  int opt=0;
  clrscr();
  while(opt!=9)
  {
  printf("\n\nMenu\n1.InsertFirst\n2.InsertLast\n3.Insert at Position\n4.DeleteFirst\n5.DeleteLast\n6.Delete at position\n7.Search\n8.Display\n9.Exit\n\nEnter your Choice:");
  scanf("%d",&opt);
  switch(opt)
  {
   case 1:insertFirst();
   count++;
   break;
   case 2:insertLast();
   break;
   case 3:insertPos();
   break;
   case 4:deleteFirst();
   break;
   case 5:deleteLast();
   break;
   case 6:deletePos();
   break;
   case 7:search();
   break;
   case 8:display();
   break;
   default:exit(0);
	   printf("Wrong Input");
   break;
   }
   }
   getch();
}

void display()
{
 struct node *ptr=head;
 if(head==NULL)
 {
  printf("List is Empty");
  return;
  }
  printf("Elements are:\n");
  while(ptr!=NULL)
  {
   printf("%d\t",ptr->data);
   ptr=ptr->right;
   }
}
struct node *GetNode()
{
 int x;
 struct node *ne=(struct node *)malloc(sizeof(struct node));
 if(ne==NULL)
  printf("Insufficient Memory\n");
  else
  {
    printf("Enter the value to insert");
    scanf("%d",&x);
    ne->left=NULL;
    ne->right=NULL;
    ne->data=x;
    }
    return ne;
}

void insertFirst()
{
 struct node *ne;
 ne=GetNode();
 if(ne==NULL)
   return;
 if(head==NULL)
  head=ne;
 else
 {
  head->left=ne;
  ne->right=head;
  head=ne;
  }
  display();
}

void insertLast()
{
 struct node *ne,*ptr;
 ne=GetNode();
 if(ne==NULL)
  return;
 if(head==NULL)
  head=ne;
 else
 {
  ptr=head;
  while(ptr->right!=NULL)
  {
   ptr=ptr->right;
   }
   ptr->right=ne;
   ne->left=ptr;
   }
   display();
}

void insertPos()
{
 int value;
 struct node *ne,*ptr,*ptr1;
 ne=GetNode();
 if(ne==NULL)
  return;
 if(head==NULL)
 {
   printf("List is Empty so the node is inserted as the first node");
   head=ne;
   return;
  }
  printf("Enter the key value after which the node has to be inserted\n");
  scanf("%d",&value);
  ptr=head;
  while(ptr->right!=NULL && ptr->data!=value)
  {
   ptr=ptr->right;
   }
  if(ptr->right==NULL)
  {
   ptr->right=ne;
   ne->left=ptr;
   printf("\n Node is inserted at last position");
   }
  else
  {
   ptr1=ptr->right;
   ne->right=ptr1;
   ne->left=ptr;
   ptr->right=ne;
   ptr1->left=ne;
   }
   printf("\nElement is inserted\n");
   display();
}

void deleteFirst()
{
  struct node *ptr;
  if(head==NULL)
  {
   printf("List is empty\n");
   return;
   }
  ptr=head;
  head=head->right;
  if(head!=NULL)
    head->left=NULL;
    free(ptr);
    display();
}

void deleteLast()
{
 struct node *ptr,*prev;
 if(head==NULL)
 {
  printf("\nList is empty\n");
  return;
  }
  if(head->right==NULL)
  {
    free(head);
    head=NULL;
    }
    ptr=head->right;
    while(ptr->right!=NULL)
    {
     ptr=ptr->right;
     }
     prev=ptr->left;
     prev->right=NULL;
     free(ptr);
     display();
}

void deletePos()
{
 struct node *prev,*next,*temp;
 int x;
 printf("Enter the position to be deleted");
  scanf("%d",&x);
 if(head==NULL)
 {
  printf("\nList is empty");
  return;
  }
  else if(x==count)
  deleteLast();
  else if(x==1)
  deleteFirst();
  else
  {
   temp=head;
   while(i<x)
   {
   temp=temp->right;
    i++;
   }
   temp->left->right=temp->right;
   temp->right->left=temp->left;
   free(temp);
}
}
void search()
{
 struct node *ptr;
 int x;
 if(head==NULL)
 {
  printf("\nList is empty");
  return;
  }
  printf("Enter the element to search:");
  scanf("%d",&x);
  ptr=head;
  while(ptr!=NULL)
  {
   if(ptr->data==x)
   {
     printf("\nElement %d at %d position",ptr->data,i);
     break;
     }
     ptr=ptr->right;
     i++;
   }
    if(ptr==NULL)
      printf("\nElement not in the list\n");
}



