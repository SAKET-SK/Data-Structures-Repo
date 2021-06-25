#include<stdio.h>
#include<conio.h>
#define MAX 5
struct stack
{
  int ary[MAX];
  int top;
};
void init(struct stack *s)
{
  s->top=-1;
}
int isempty(struct stack *s)
{
  if(s->top==-1)
    return 1;
  else
    return 0;
}
int isfull(struct stack *s)
{
  if(s->top==MAX-1)
    return 1;
  else
  return 0;
}
void push(struct stack *s,int x)
{
  s->top=s->top+1;
  s->ary[s->top]=x;
}
int pop(struct stack *s)
{
  int x;
  x=s->ary[s->top];
  s->top=s->top-1;
  return x;
}
void print(struct stack *s)
{
  int i;
  printf("\n");
  for(i=s->top;i>=0;i--)
  printf("%d ",s->ary[i]);
}
void main()
{
  struct stack s;
  int x, op;
  init(&s);
  clrscr();
  do
  {
    printf("\n1. Push\n2. Pop\n3. Print\n4. Quit");
    printf("\nEnter your choice: ");
    scanf("%d",&op);
    switch(op)
    {
      case 1:
        printf("Enter a number: ");
        scanf("%d",&x);
        if(isfull(&s))
          printf("Overflow");
        else
          push(&s,x);
        break;
      case 2:
        if (isempty(&s))
          printf("Underflow");
        else
          x = pop(&s);
          printf("\nPopped value = %d",x);
          break;
      case 3:
          print(&s);
          break;
    }
  }while(op != 4);
}
