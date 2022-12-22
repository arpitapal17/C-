#include <stdio.h>
#include <stdlib.h>
typedef struct  node
{
    int data ;
    struct  node *prev;
    struct node *next ;    
}node;
node *head = NULL;
node *create_list(){
    node *newnode , *temp;
    int size;
    printf("enter the number of elements you want to enter: ");
    scanf("%d", &size);
    if(size == 0){
        return head ;
    }
    else{
        printf("enter the elements: ");
        for (int i = 0; i < size; i++)
        {
            if (i == 0)
            {
                head = (node *)malloc(sizeof(node));
                temp = head ;
            }
            else
            {
                newnode = (node *)malloc(sizeof(node));
                newnode->prev = temp;
                temp->next = newnode;
                temp = newnode ;
            }
            scanf("%d",&temp->data);   
        }
        newnode->next = head ;
        head->prev = newnode ;
        return (head);
    }
}
void Traverse(node *head){
    node *ptr = head ;
    if(head == NULL){
        printf("list is empty");
    }
    while( ptr->next != head){
        printf("%d  ",ptr->data);
        ptr = ptr->next ;
    }
    printf("%d",ptr->data);
    printf("\n");
}

int main()
{
    head = create_list();
    Traverse(head);
    insert_at_begining(head);
}    