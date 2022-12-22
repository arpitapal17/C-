#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct  node *lc;
    struct  node *rc;    
}tree;
tree* newNode(int data)
{
    struct node* node
        = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->lc = NULL;
    node->rc = NULL; 
    return (node);
}
void Preorder(tree* node){
    if (node == NULL)
        return;
    printf("%d ", node->data);
    Preorder(node->lc);
    Preorder(node->rc);
}
void Postorder(tree* node){
    if (node == NULL)
        return;
    Postorder(node->lc);
    Postorder(node->rc);    
    printf("%d ", node->data);
}
void Inorder(tree* node)
{
    if (node == NULL)
        return;
    Inorder(node->lc);
    printf("%d ", node->data);
    Inorder(node->rc);
}
int main(){
    
    tree *root = newNode(1);
    root->lc = newNode(2);
    root->rc = newNode(3);
    root->lc->lc = newNode(4);
    root->lc->rc = newNode(5);
    printf("MENU:\n");
    printf("1.Preorder\n");
    printf("2.Inorder\n");
    printf("3.Postorder\n");
    int ch;
    printf("enter your choice: ");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1: printf("\nPreorder traversal of binary tree is \n");
            Preorder(root);
            break;
    case 2: printf("\nInorder traversal of binary tree is \n");
            Inorder(root);
            break;
    case 3: printf("\nPostorder traversal of binary tree is \n");
            Postorder(root);
            break;
    default: printf("Invalid choice");
    }
    return 0 ;
 
}
 
