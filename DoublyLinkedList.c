#include <stdio.h>
#include <stdlib.h>
typedef struct  node
{
    int data ;
    struct  node *prev;
    struct node *next ;    
}node;
node *create_list(){
    node *newnode , *head ,*temp;
    int size;
    head = NULL ;
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
        newnode->next = NULL ;
        head->prev = NULL ;
        return (head);
    }
}
void TraverseForward(node *head){
    node *ptr = head ;
    if(head == NULL){
        printf("list is empty");
    }
    while( ptr != NULL){
        printf("%d  ",ptr->data);
        ptr = ptr->next ;
    }
    printf("\n");
}
void TraverseBackward(node *head){
    node *ptr = head , *last;
    while( ptr != NULL){
        last = ptr ;
        ptr = ptr->next ;
    }
    while (last != NULL)
    {
        printf("%d  ",last->data);
        last = last->prev ;
    }
    printf("\n");
    
}
void inserAtBeginning(node *head){
    node *startNode = (node*)malloc(sizeof(node));
    printf("\nenter the element to be entered at begining: ");
    scanf("%d", &startNode->data);
    startNode->next = head;
    head->prev = startNode ;
    head = startNode ;
    head->prev = NULL ;
    printf("The modified doubly linked list: ");
    TraverseForward(head);
}
void insertAtlast(node *head){
    node *last_node , *temp;
    last_node = (struct node *)malloc(sizeof(struct node));
    printf("\nenter the element to be entered at last: ");
    scanf("%d", &last_node->data);
    temp = head ;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = last_node ;
    last_node->prev = temp ;
    last_node->next = NULL ;
    printf("The modified doubly linked list: ");
    TraverseForward(head);
    
}
void insertAtSpecificPosition(node *head){
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
        new_node->next = temp->next;
        temp->next->prev = new_node ;
        new_node->prev = temp ;
        temp->next = new_node ;
        printf("The modified doubly linked list: ");
        TraverseForward(head);
    }
    else{
        printf("location not found");
    }
}
void deleteAtFirst(node *head){
    node *first_node;
    first_node = head ;
    head = first_node->next;
    head->prev = NULL ;
    free(first_node);
    printf("The modified doubly linked list: ");
    TraverseForward(head);
}
void deleteAtLast(node *head){
    node *temp , *last_node ;
    last_node = head ;
    while(last_node->next != NULL){
        temp = last_node ;
        last_node = last_node->next ;
    }
    temp->next = NULL ;
    free(last_node);
    printf("The modified doubly linked list: ");
    TraverseForward(head);
}  
void deleteAtSpecificPosition(node *head){
    node *temp , *ptr ;
    int position ;
    printf("enter the position of the element you want to delete: ");
    scanf("%d",&position);
    temp = head ;
    for(int i = 1 ; i < position  ; i++){
        ptr = temp ;
        temp = temp->next ;
    }
    if(temp != NULL){
        ptr->next = temp->next ;
        temp->next->prev = ptr ;
        free(temp);
        printf("The modified doubly linked list: ");
        TraverseForward(head);
    }
    else{
        printf("location not found");
    }
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
void searchElement(node *head){
    node *ptr ;
    ptr = head ;
    int n;
    printf("enter the element you want to search: ");
    scanf("%d",&n);
    int i = 0;
    while(ptr != NULL){
        i++;
        if(ptr->data == n){
            printf("element found at %d\n", i);
            break;
        }
        ptr = ptr->next ;
    }
    if(ptr == NULL){
        printf("element not found");
    }
}
void checkIfListisEmpty(node *head){
    if(head == NULL){
        printf("list is empty");
    }
    while( head != NULL){
        printf("list is not empty");
    }
}
void reverse(node * head)
{
    node* temp = NULL;
    node* current = head;
 
    /* swap next and prev for all nodes of
      doubly linked list */
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
 
    /* Before changing head, check for the cases like empty
       list and list with only one node */
    if (temp != NULL)
        head = temp->prev;

    TraverseForward(head);    
}
void sort(node *head)
{
    node* current = head;
	node* index = NULL;
    while (current != NULL) 
    {
			index = current->next;
			// Traverse the LL nestedly
			// and find the minimum
			// element
			while (index != NULL) 
			{

				// Swap with it the value
				// at current
				if (current->data > index->data) {
					int temp = current->data;
					current->data = index->data;
					index->data = temp;
				}
				index = index->next;
			}
			// Update the current
			current = current->next;
	}
    printf("Sorted Linked List: ");
    TraverseForward(head);
}
void duplicate_remove(node *head)
{
    sort(head);
    node* temp = head , *ptr;
    while(temp->next!=NULL)
    {
        if(temp->data==temp->next->data)
        {
            ptr = temp->next ;
            temp->next=temp->next->next;
            free(ptr);
        }
        else
            temp = temp->next;
    }
    printf("Modified linked list: ");
    TraverseForward(head);
}
int main()
{
    node *head;
    head = create_list();
    printf("Given Linked List : ");
    printf("Menu:\n");
    printf("1. Traverse the list forward\n");
    printf("2. Traverse the list backward\n");
    printf("3. Check if the list is empty\n");
    printf("4. Insert a node at beginning\n");
    printf("5. Insert a node at last\n");
    printf("6. Insert a node at a specific location\n");
    printf("7. Delete a node at beginning\n");
    printf("8. Delete a node at last\n");
    printf("9. Delete a node at a specific location\n");
    printf("10. Delete a node for the given key\n");
    printf("11. Count the total number of nodes\n");
    printf("12. Search for an element in the linked list\n");
    printf("13. Reverse the sequence of linked list.\n");
    printf("14. Sort the elements\n");
    printf("15. Remove duplicate elements\n");
    int choice ;
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch (choice)
    {
        case 1 : TraverseForward(head);
            break;
        case 2 : TraverseBackward(head);
            break;
        case 3 : checkIfListisEmpty(head);
            break;
        case 4 : inserAtBeginning(head);
            break;
        case 5 : insertAtlast(head);
            break;
        case 6 : insertAtSpecificPosition(head);
            break;
        case 7 : deleteAtFirst(head);
            break;
        case 8 : deleteAtLast(head);
            break;
        case 9 : deleteAtSpecificPosition(head);
            break;
        case 10 : deleteAtSpecificPosition(head);
            break;
        case 11 : count_total_number_of_nodes(head);
            break;
        case 12 : searchElement(head);
            break; 
        case 13 : reverse(head);  
            break;
        case 14 : sort(head);
            break;
        case 15 : duplicate_remove(head);
            break;                                    
        default:
            printf("wrong choice");
    }
    return 0 ;
}
