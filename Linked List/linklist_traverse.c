#include<stdio.h>
struct linked_list
{
  int data;
  struct linked_list *next;
};
typedef struct linked_list node;
void print(node *p)
{
  printf("Printing a linked list: ");
  while(p!=NULL)
  {
    printf("%d\t",p->data);
    p=p->next;
  }
}
void main()
{
  node *head,*p;
  int n,i;
  clrscr();
  printf("Enter number of nodes: ");
  scanf("%d",&n);
  head=(node*)malloc(sizeof(node));
  scanf("%d",&head->data);
  head->next=NULL;
  p=head;
  for(i=1;i<=n-1;i++)
  {
    p->next=(node*)malloc(sizeof(node));
    p=p->next;
    scanf("%d",&p->data);
    p->next=NULL;
  }
  print(head);
  getch();
}
