#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	int height;
};
int max(int a, int b);
int c=0;
int height(struct Node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}
int max(int a, int b)
{
	return (a > b)? a : b;
}
struct Node * minValueNode(struct Node* node)
{
	struct Node* current = node;
	while (current->left != NULL)
		current = current->left;

	return current;
}
struct Node* newNode(int key)
{
	struct Node* node = malloc(sizeof(struct Node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return(node);
}
struct Node *rightRotate(struct Node *y)
{
	struct Node *x = y->left;
	struct Node *T2 = x->right;
	x->right = y;
	y->left = T2;
	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;
	return x;
}
struct Node *leftRotate(struct Node *x)
{
	struct Node *y = x->right;
	struct Node *T2 = y->left;
	y->left = x;
	x->right = T2;
	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;
	return y;
}
int getBalance(struct Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}
struct Node* insert(struct Node* node, int key)
{

	if (node == NULL)
		return(newNode(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else
		return node;
	node->height = 1 + max(height(node->left),
						height(node->right));
	int balance = getBalance(node);
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	return node;
}
void preOrder(struct Node *root)
{
	if(root != NULL)
	{
		printf("%d ", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}
void printPostorder(struct Node* node)
{
	if (node == NULL)
		return;
	printPostorder(node->left);
	printPostorder(node->right);
	printf("%d ", node->key);
}
void printInorder(struct Node* node)
{
	if (node == NULL)
		return;
	printInorder( node->left);
	printf("%d ",node->key);
	printInorder(node->right);
}
int find(struct Node* node,int x)
{
   if(node!=NULL)
   {
       if(node->key==x)
        return 1;
       int left=find(node->left,x);
       if(left==1)
        return 1;
       int right=find(node->right,x);
       if(right==1)
        return 1;
   }
   return 0;
}
void main()
{
struct Node *root = NULL;
int d,n;
while(1)
{
    printf("\n\t\tMenu\n\n1.Insert\n2.Find\n3.Preorder Traversal\n4.Inorder Traversal\n5.Postorder Traversal\n6.Exit\nEnter your choice:");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
            {
           printf("Enter the element:");
            scanf("%d",&d);
            root=insert(root,d);
            break;
            }
        case 2:
            {
            printf("Enter the element:");
            scanf("%d",&d);
            c=find(root,d);
            if(c==0)
                printf("Element Not Found");
            else
            {
                printf("Element Found");
            }

            break;
            }
        case 3:
            {
            printf("\nPreorder traversal of the constructed AVL tree is : ");
            preOrder(root);
            break;
            }
        case 4:
            printf("\nInorder traversal of the constructed AVL tree is : ");
            printInorder(root);
            break;
        case 5:
            printf("\nPostorder traversal of the constructed AVL tree is : ");
            printPostorder(root);
            break;
        case 6:
            exit(0);
    }
}
}
