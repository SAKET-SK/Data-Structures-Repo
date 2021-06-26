/* Linear Queue */
#include<stdio.h>
#include<conio.h>
#define MAX 5
struct queue
{
  int a[MAX];
  int f,r;
};
void init(struct queue *q)
{
  q->f=q->r=-1;
}
int isempty(struct queue *q)
{
  if(q->r==-1)
    return 1;
  else
    return 0;
}
int isfull(struct queue *q)
{
  if(q->r==MAX-1)
    return 1;
  else
    return 0;
}
void insert(struct queue *q,int x)
{
  if(q->r==-1)
  {
    q->f=q->r=0;
  }
  else
  {
    q->r=q->r+1;
  }
  q->a[q->r]=x;
}
int delete(struct queue *q)
{
  int x;
  x=q->a[q->f];
  if(q->f==q->r)
  {
    q->f=q->r=-1;
  }
  else
  {
    q->f=q->f+1;
  }
  return x;
}
void print(struct queue *q)
{
  int i;
  printf("\n");
  for(i=q->f;i<=q->r;i++)
  printf("%d\t",q->a[i]);
}
void main()
{
  struct queue q;
  int x,op;
  clrscr();
  init(&q);
  printf("1.Insert\n2.Delete\n3.Print\n4.Quit");
  {
    printf("\nEnter choice: ");
    scanf("%d",&op);
    switch(op)
    {
      case 1:
        if(isfull(&q))
          printf("\nOverflow");
        else
        {
          printf("\nEnter value: ");
          scanf("%d",&x);
          insert(&q,x);
        }
       break;
       case 2:
        if(isempty(&q))
          printf("\nUnderflow");
        else
        {
          x=delete(&q);
          printf("\nDeleted Value=%d",x);
        }
       break;
       case 3:
        print(&q);
       break;
    }
}while(op!=4);
getch();
}
