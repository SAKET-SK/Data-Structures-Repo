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
  return 0;
}
int isfull(struct queue *q)
{
  if((q->r+1)%MAX==q->f)
    return 1;
  else
    return 0;
}
void insert(struct queue *q,int x)
{
  if(q->r==-1)
  {
    q->f=q->r=0;
    q->a[q->r]=x;
  }
  else
  {
    i=q->r;
    while(x>q->aa[i])
    {
      q->a[(i+1)%MAX]=q->a[i];
      i=(i-1+MAX)%MAX;
      if((i+1)%MAX==q->f;
        break;
    }
    i=(i+1)%MAX;
    q->a[i]=x;
    q->r=(q->r+1)%MAX;
  }
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
  printf("\n1.Insert\n2.Delete\n3.Print\n4.Quit");
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
     break;
     case 3:
      print(&q);
    break;
  }
  }while(op!=4);
  getch();
}
