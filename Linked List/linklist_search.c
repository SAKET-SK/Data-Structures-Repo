#include<stdio.h>
struct linked_list
{
  int data;
  struct linked_list *next;
};
typedef struct linked_list node;
void search(node *p,int x)
{
  while(p!=NULL)
  {
    if(p->data==x)
    {
      printf("Data found at location %u",p);
      getch();
      exit(0);
    }
    p=p->next;
  }
  printf("Data not present");
}
void main()
{ 
  node *head,*p;
  int x,n,i;
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
  printf("Enter the element to search: ");
  scanf("%d",&x);
  search(head,x);
  getch();
}
