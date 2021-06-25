#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#define MAX 50
#define OPERAND 10
#define OPERATOR 20
struct stack
{
  int ary[MAX];
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
int pop(struct stack *s)
{
  int x;
  x=s->ary[s->top];
  s->top=s->top-1;
  return x;
}
int eval(char op,int num1,int num2)
{
  int res;
  switch(op)
  {
    case '+':
      res=num1+num2;
    break;
    case '-':
      res=num1-num2;
    break;
    case '*':
      res=num1*num2;
    break;
    case '/':
      res=num1/num2;
    break;
    case '%':
      res=num1%num2;
    break;
    case '^':
      res=pow(num1,num2);
    break;
  }
  return res;
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
    default:
    return OPERAND;
  }
}
void main()
{
  struct stack s;
  char pos[30];
  int num1,num2,item,i;
  fflush(stdin);
  clrscr();
  init(&s);
  printf("\nEnter postfix expression: ");
  gets(pos);
for(i=0;pos[i]!='\0';i++)
{
  if(pos[i]==' '||pos[i]=='\t')
  continue;
  switch(gettype(pos[i]))
  {
    case OPERAND:
      item=pos[i]-'0';
      push(&s,item);
    break;
    case OPERATOR:
      num1=pop(&s);
      num2=pop(&s);
      push(&s,eval(pos[i],num2,num1));
    break;
  }
}
printf("Answer = %d",s.ary[0]);
getch();
}
