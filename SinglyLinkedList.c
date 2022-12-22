#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
node *create_list()
{
    node *ptr, *head;
    int size;
    printf("enter the number of elements you want to enter: ");
    scanf("%d", &size);
    printf("enter the elements: ");
    for (int i = 0; i < size; i++)
    {
        if (i == 0)
        {
            head = (node *)malloc(sizeof(node));
            ptr = head;
        }
        else
        {
            ptr->next = (node *)malloc(sizeof(node));
            ptr = ptr->next;
        }
        scanf("%d", &ptr->data);
    }
    ptr->next = NULL;
    return (head);
}
void traverse(node *head)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
}
void insert_at_begining(node *head)
{
    node *start_node;
    start_node = (node *)malloc(sizeof(node));
    printf("\nenter the element to be entered at begining: ");
    scanf("%d", &start_node->data);
    start_node->next = head;
    head = start_node;
    printf("the modified link list: ");
    traverse(head);
}
void insert_at_last(node *head)
{
    node *last_node , *temp;
    last_node = (struct node *)malloc(sizeof(struct node));
    printf("\nenter the element to be entered at last: ");
    scanf("%d", &last_node->data);
        temp = head ;
        while(temp->next != NULL){
            temp = temp->next;
        }
    temp->next = last_node; 
    last_node->next = NULL;
    printf("the modified link list: ");
    traverse(head);
}        
void insert_at_specific_position(node *head){
    node *new_node ,*temp;
    int position ;
    printf("\nenter the position you want to enter: ");
    scanf("%d",&position);
    new_node = (node*)malloc(sizeof(node));
    printf("enter the element you want to enter at %d: ",position);
    scanf("%d",&new_node->data);
    temp = head ;
    for(int i = 1 ; i < position-1 ; i++){
        temp = temp->next ;
    }
    if(temp->next != NULL){
        new_node->next= temp->next;
        temp->next = new_node; 
        printf("the modified link list: ");
        traverse(head);
    }
    else{
        printf("location not found\n");
    }
}
void insert_after_an_element(node *head){
    node *ptr = head , *newNode ;
    printf("Enter the element after which u want to insert: ");
    int n ;
    scanf("%d",&n);
    newNode = (node *)malloc(sizeof(node));
    printf("enter the element u want to insert after %d: ",n);
    scanf("%d",&newNode->data);
    while(ptr->data != n){
        ptr = ptr->next ;
    }
    newNode->next = ptr->next ;
    ptr->next = newNode;
    printf("modified Linked list:");
    traverse(head);
}
void insert_before_an_element(node *head){
    node *prev, *temp = head , *newNode;
    printf("enter the element before which u want to enter : ");
    int n ;
    scanf("%d",&n);
    printf("Enter the element u want to insert: ");
    newNode = (node*)malloc(sizeof(node));
    scanf("%d",&newNode->data);
    while(temp->data != n){
        prev = temp;
        temp = temp->next ;
    }
    newNode->next = temp ;
    prev->next = newNode ;
    printf("modified Linked list: ");
    traverse(head);
}
void delete_first_node(node *head){
    node *first_node;
    first_node = head ;
    head = first_node->next ;
    free(first_node);
    printf("the modified link list: ");
    traverse(head);
}
void delete_last_node(node *head){
    node *temp ,*prev ;
    temp = head ;
    while(temp->next != NULL){
        prev = temp ;
        temp = temp->next;
    }
    free(temp);
    prev->next = NULL ;
    printf("the modified link list: ");
    traverse(head);
}
void delete_at_specific_position(node *head){
    node *temp , *prev;
    int position ;
    printf("enter the position of the element you want to delete: ");
    scanf("%d",&position);
    temp = head ;
    for(int i = 1 ; i < position ; i++){
        prev = temp ;
        temp = temp->next ;
    }
    if(temp != NULL){
        prev->next = temp->next ;
        free(temp);
        printf("the modified link list: ");
        traverse(head);
    }
    else{
        printf("location not found");
    }
}
void delete_after_an_element(node *head){
    node *ptr = head , *temp;
    printf("Enter the element after which u want to delete: ");
    int n ;
    scanf("%d",&n);
    while(ptr->data != n){
        ptr = ptr->next ;
        temp = ptr->next ;
    }
    ptr->next = temp->next ;
    free(temp);
    printf("modified Linked list: ");
    traverse(head);
} 
void delete_before_an_element(node *head){
    node *temp = head , *prev;
    printf("enter the element before which u want to delete: ");
    int n;
    scanf("%d",&n);
    while(temp->next->data != n){
        prev = temp ;
        temp = temp->next ;
    }
    prev->next = temp->next ;
    free(temp);
    printf("Modified Linked list: ");
    traverse(head);
}   
void count_total_number_of_nodes(node *head){
    int count = 0 ;
    while (head != NULL)
    {
        count++ ;
        head = head->next;
    }
    printf("\ntotal number of nodes : %d",count);
}
void maximum(node *head)
{
    int max = head->data ;
    while( head != NULL)
    {
        if(head->data > max)
           max = head->data;
        head = head->next;
    }
    printf("\nThe maximum element of the linked list is: %d ",max);
}
void minimum(node *head)
{
    int min = head->data ;
    while( head != NULL)
    {
        if(head->data < min)
           min = head->data;
        head = head->next;
    }
    printf("\nThe minimum element of the linked list is: %d ",min);
}
void reverse(node *head)
{
    node* prev = NULL;
    node* current = head;
    node* next = NULL;
    while (current != NULL) {
        // Store next
        next = current->next;
 
        // Reverse current node's pointer
        current->next = prev;
 
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    head = prev;
    printf("reverse linked list: ");
    traverse(head);
}
 
int main()
{
    node *head;
    head = create_list();
    printf("Link list : ");
    traverse(head);
    // printf("\n\nMenu:\n");
    // printf("1. insert a node at begining\n");
    // printf("2. insert a node at last\n");
    // printf("3. insert at a specific position\n");
    // printf("4. insert node after an element\n");
    // printf("5. delete first node\n");
    // printf("6. delete last node\n");
    // printf("7. delete node at specific position\n");
    // printf("8. delete after a element\n");
    // printf("9. count the total number of nodes\n");
    // printf("10. get the maximum value from link list\n");
    // printf("11. get the minimum value from link list\n");
    // printf("12. Reverse linked list");
    // int choice ;
    // printf("\nenter your choice: ");
    // scanf("%d",&choice);
    // switch (choice)
    // {
    // case 1 : insert_at_begining(head);
    //     break;
    // case 2 : insert_at_last(head);
    //     break;
    // case 3 : insert_at_specific_position(head);
    //     break; 
    // case 4 : insert_after_an_element(head);
    //     break;
    // case 5 : delete_first_node(head);    
    //     break;  
    // case 6 : delete_last_node(head);
    //     break;
    // case 7 : delete_at_specific_position(head);
    //     break; 
    // case 8 : delete_after_an_element(head);
    //     break;    
    // case 9 : count_total_number_of_nodes(head);
    //     break;     
    //case 10 : maximum(head);
    //     break;
    // case 11 : minimum(head);
    //     break; 
    // case 12 : reverse(head); 
    //     break;                 
    // default:
    //     printf("wrong choice");
    // } 
    //insert_before_an_element(head);
    //delete_before_an_element(head);
    return 0;
}