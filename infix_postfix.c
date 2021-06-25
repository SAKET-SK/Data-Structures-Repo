#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#define MAX 50
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
int tp(struct stack *s)
{
  return (s->ary[s->top]);
}
int precedence(char x)
{
  if(x=='(') return 0;
  if(x=='+' || x=='-') return 1;
  if(x=='*' || x=='/' || x=='%') return 2;
  return 3;
}
void infixtopostfix(char infix[],char postfix[])
{
  struct stack s;
  char x;
  int i,j;
  char token;
  init(&s);
  j=0;
for(i=0;infix[i]!='\0';i++)
{
  token=infix[i];
  if(isalnum(token))
    postfix[j++]=token;
  else
    if(token=='(')
      push(&s,'(');
    else
      if(token==')')
        while((x=pop(&s))!='(')
          postfix[j++]=x;
      else
      {
        while(precedence(token)<=precedence(tp(&s))&&!isempty(&s))
        { x=pop(&s);
        postfix[j++]=x;
        }
        push(&s,token);
      }
    }
  while(!isempty(&s))
  {
    x=pop(&s);
    postfix[j++]=x;
  }
  postfix[j]='\0';
}
void main()
{
  char infix[30],postfix[30];
  clrscr();
  printf("\nEnter an inix expression: ");
  gets(infix);
  infixtopostfix(infix,postfix);
  printf("\nPostfix: %s ",postfix);
  getch();
}
