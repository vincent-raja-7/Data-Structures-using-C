#include <stdio.h>
#include <stdlib.h>
struct node
{
    int x;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;
struct node *create(int d)
{
     struct node *temp = malloc(sizeof(struct node));
     temp->x = d;
     temp->left = temp->right = NULL;
     return temp;
}
void inorder(struct node *root)
{
       if (root != NULL)
        {
            inorder(root->left);
            printf("%d ",root->x);
            inorder(root->right);
        }
}
struct node* insert(struct node* ptr, int d)
{
       if (ptr == NULL)
           return create(d);
       if (d < ptr->x)
           ptr->left = insert(ptr->left,d);
       else
           ptr->right = insert(ptr->right, d);
       return ptr;
}
int minValue(struct node* node)
{
       struct node* ptr = node;
       while (ptr->left != NULL)
           ptr = ptr->left;
       return ptr->x;
}
int maxValue(struct node* node)
{
       struct node* ptr = node;
       while (ptr->right != NULL)
           ptr = ptr->right;
       return ptr->x;
}
struct node* dele(struct node* root, int d)
{
     struct node *temp;
     if (root == NULL)
         return root;
     if (d < root->x)
        root->left = dele(root->left, d);
    else if (d > root->x)
        root->right = dele(root->right,d);
    else
   {
       if(root->left == NULL)
         {
            temp = root->right;
            free(root);
            return temp;
         }
      else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }
      temp = minValue(root->right);
      root->x = temp->x;
      root->right = dele(root->right, temp->x);
   }
return root;
}
struct node* display(struct node* ptr)
{
  display(ptr->left);
  printf("%d \n",ptr->x);
  display(ptr->right);
}
struct node* delemin(struct node* ptr)
{
   int m=minValue(root);
   dele(root,m);
}
struct node* delemax(struct node* ptr)
{
   int m=maxValue(root);
   dele(root,m);
}
void main()
{
int data,n;
while(1)
{
    printf("\n\t\tMenu\n\n1.Insert\n2.Delete\n3.Display\n4.Find Min\n5.Find Max\n6.Exit\nEnter your choice:");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
            {
            printf("Enter The Data : ");
            scanf("%d",&data);
            root = insert(root, data);
            break;
            }
        case 2:
            {
            printf("Enter The Data : ");
            scanf("%d",&data);
            root = dele(root,data);
            break;
            }
        case 3:
            {
            printf("Inorder traversal of the given tree \n");
            inorder(root);
            break;
            }
        case 4:
            printf("%d",minValue(root));
            break;
        case 5:
            printf("%d",maxValue(root));
            break;
        case 6:
            exit(0);
    }
   }
}
