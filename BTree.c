/* Program for Binary Tree Creation and Traversals */
#include<stdio.h>
#include<conio.h>
struct BT
{
  int data;
  struct BT *left,*right;
};
typedef struct BT node;
node* insert(node *root,int x)
{
  node *p;
  p=(node *)malloc(sizeof(node));
  p->data=x;
  p->left=NULL;
  p->right=NULL;
  if(root==NULL)
  root=p;
  if(x<root->data)
    root->left=insert(root->left,x);
  if(x>root->data)
    root->right=insert(root->right,x);
  return root;
}
void preorder(node *t)
{
  if (t!=NULL)
  {
    printf("\n%d",t->data);
    preorder(t->left);
    preorder (t->right);
  }
}
void inorder(node *t)
{
  if (t!=NULL)
  {
    inorder(t->left);
    printf("\n%d",t->data);
    inorder (t->right);
  }
}
void postorder(node *t)
{
  if (t!=NULL)
  {
    postorder(t->left);
    postorder (t->right);
    printf("\n%d",t->data);
  }
}
void main()
{
  int op,n;
  node *root;
  clrscr();
  root=(node *)malloc(sizeof(node));
  printf("\nInsert Data For Root: ");
  scanf("%d",&root->data);
  root->right=root->left=NULL;
  do
  {
    printf("\n 1.Insertion");
    printf("\n 2.Preorder");
    printf("\n 3.Inorder");
    printf("\n 4.Postorder");
    printf("\n 5.Quit");
    printf("\n Enter your choice\n");
    scanf("%d",&op);
    switch (op)
    {
      case 1:
        printf("\n Enter the element to insert\n");
        scanf("%d",&n);
        insert(root,n);
      break;
      case 2:
        printf("\n The preorder elements are\n");
        preorder(root);
      break;
      case 3:
        printf("\n The inorder elements are\n");
        inorder(root);
      break;
      case 4:
        printf("\n The postorder elements are\n");
        postorder(root);
      break;
      default:
        exit(0);
    }
  }while(op<4);
  getch();
}
