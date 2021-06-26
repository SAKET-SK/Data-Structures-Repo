/* De Queue */
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
  if((q->r+1)%MAX==q->f)
    return 1;
  else
    return 0;
}
void insertR(struct queue *q,int x)
{
  if(q->r==-1)
  {
    q->f=q->r=0;
  }
  else
  {
    q->r=(q->r+1)%MAX;
  }
  q->a[q->r]=x;
}
void insertF(struct queue *q,int x)
{
  if(q->r==-1)
  {
    q->f=q->r=0;
  }
  else
  {
    q->f=(q->f-1+MAX)%MAX;
  }
  q->a[q->f]=x;
}
int deleteR(struct queue *q)
{
  int x;
  x=q->a[q->r];
  if(q->f==q->r)
  {
    q->f=q->r=-1;
  }
  else
  {
    q->r=(q->r-1+MAX)%MAX;
  }
  return x;
}
int deqleteF(struct queue *q)
{
  int x;
  x=q->a[q->f];
  if(q->f==q->r)
  {
    q->f=q->r=-1;
  }
  else
  {
    q->f=(q->f+1)%MAX;
  }
  return x;
}
void print(struct queue *q)
{
  int i=q->f;
  printf("\n");
  while(i!=q->r)
  {
    printf("%d\t",q->a[i]);
    i=(i+1)%MAX;
  }
  printf("\t%d",q->a[q->r]);
}
void main()
{
  struct queue q;
  int x,op;
  clrscr();
  init(&q);
  printf("\n1.InsertR\n2.InsertF\n3.DeleteR\n4.DeleteF\n5.Print\n6.Quit");
  do
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
          insertR(&q,x);
        }
      break;
      case 2:
        if(isfull(&q))
          printf("\nOverflow");
        else
        {
          printf("\nEnter value: ");
          scanf("%d",&x);
          insertF(&q,x);
        }
      break;
      case 3:
        if(isempty(&q))
          printf("\nUnderflow");
        else
        {
          x=deleteR(&q);
          printf("\nDeleted Value=%d",x);
        }
      break;
      case 4:
      if(isempty(&q))
        printf("\nUnderflow");
      else
      {
        x=deleteF(&q);
        printf("\nDeleted Value=%d",x);
      }
      break;
      case 5:
        print(&q);
      break;
    }
  }while(op!=6);
  getch();
}
