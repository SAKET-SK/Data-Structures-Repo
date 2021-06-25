#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#define MAX 50
#define OPERAND 10
#define OPERATOR 20
#define LEFTPARA 30
#define RIGHTPARA 40
struct stack
{
  char ary[MAX];
  int top;
};
void init(struct stack *s)
{
  s->top=-1;
}
void push(struct stack *s,int x)
{
  s->top=s->top+1;
  s->ary[s->top]=x;
}
char pop(struct stack *s)
{
  int x;
  x=s->ary[s->top];
  s->top=s->top-1;
  return x;
}
int getprec(char c)
{
  switch(c)
  { 
    case ')':
      return 0;
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
    case '%':
      return 2;
    case '^':
      return 3;
  }
}
int gettype(char c)
{
  switch(c)
{ 
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    case '^':
      return OPERATOR;
    case '(':
      return LEFTPARA;
    case ')':
      return RIGHTPARA;
    default:
      return OPERAND;
  }
}
void main()
{
  struct stack s;
  char inf[MAX],pre[MAX],ch;
  int l,i,pr,k=0;
  fflush(stdin);
  clrscr();
  init(&s);
  printf("\nEnter infix expression: ");
  gets(inf);
  l=strlen(inf);
  for(i=l-1;i>=0;i--)
  {
    switch(gettype(inf[i]))
    {
      case OPERAND:
        pre[k++]=inf[i];
      break;
      case OPERATOR:
        pr=getprec(inf[i]);
        while(pr<getprec(s.ary[s.top])&&s.top!=-1)
          pre[k++]=pop(&s);
          push(&s,inf[i]);
        break;
      case RIGHTPARA:
        push(&s,inf[i]);
      break;
      case LEFTPARA:
        while((ch=pop(&s))!=')')
          pre[k++]=ch;
      }
  }
  while(s.top!=-1)
  pre[k++]=pop(&s);
  pre[k]='\0';
  strrev(pre);
  puts(pre);
  getch();
}
