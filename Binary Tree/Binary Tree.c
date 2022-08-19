#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
struct node *create()
{
    struct node *p;
    int x;
    printf("Enter data(-1 for NULL):");
    scanf("%d",&x);

    if(x==-1)
	return NULL;

    p=malloc(sizeof(struct node));
    p->data=x;
    printf("Enter left child of %d:\n",x);
    p->left=create();
    printf("Enter right child of %d:\n",x);
    p->right=create();
    return p;
}
void printPostorder(struct node* node)
{
	if (node == NULL)
		return;
	printPostorder(node->left);
	printPostorder(node->right);
	printf("%d ", node->data);
}
void printInorder(struct node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
}
void printPreorder(struct node* node)
{
	if (node == NULL)
		return;
	printf("%d ", node->data);
	printPreorder(node->left);
	printPreorder(node->right);
}
void main()
{
	struct node *root = create();
	printf("\nPreorder Traversal Of Binary Tree is \n");
	printPreorder(root);
    printf("\nInorder Traversal Of Binary tree is \n");
	printInorder(root);
    printf("\nPostorder Traversal Of Binary tree is \n");
	printPostorder(root);
}
