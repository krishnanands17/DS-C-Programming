#include<conio.h>
#include<stdio.h>
#define sz 3
int front=-1,rear=-1;
void insert();
void delet();
void display();
void search();
void main()
{
 int q[20],choice;
 clrscr();
 while(1)
 {
  printf("\nYour Choices are........\n");
  printf("1.INSERT\n2.DELETE\n3.SEARCH\n4.DISPLAY\n5.EXIT\n");
  printf("Enter your choice:\n");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:insert(q);
	   break;
    case 2:delet(q);
	   break;
    case 3:search(q);
	   break;
    case 4:display(q);
	   break;
    case 5:printf("wrong choice:");
	   exit(0);
    }
   }
}
void insert(int *q)
{
 if(front==(rear+1)%sz)
 {
  printf("\nQueue is full");
  return;
  }
  if(front==-1)
    front=0;
    rear=(rear+1)%sz;
    printf("Enter the element to be insert:\n");
    scanf("%d",&q[rear]);
}

void delet(int *q)
{
 if(front==-1)
 {
  printf("\nQueue is empty\n");
  return;
  }
  printf("\nDeleted element %d\n",q[front]);
  if(front==rear)
    front=rear=-1;
    else
    front=(front+1)%sz;
    return;
}
void search(int *q)
{
 int x,f,pos;
 if(front==-1)
 {
  printf("\nQueue is empty\n");
  return;
  }
  printf("Enter the element to be searched\n");
  scanf("%d",&x);
  f=front;
  pos=1;
  while(1)
  {
    if(q[f]==x)
    {
     printf("\nElement found at location%d\n",pos);
     break;
     }
     if(f==rear)
     {
     printf("\nElement found not found\n");
     break;
     }
     f=(f+1)%sz;
     pos=pos+1;
  }
}
void display(int *q)
{
 int f;
 if(front==-1)
 {
 printf("Queue is empty\n");
 return;
 }
 f=front;
 while(1)
 {
  printf("%d",q[f]);
  if(f==rear)
    break;
  f=(f+1)%sz;
  }
}





