#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct LinkNode
{
    int data;
    struct LinkNode *next;
} LinkNode;
LinkNode *getLinkNode(int data){
    LinkNode * ref = (LinkNode *) malloc(sizeof(LinkNode));
    if(ref == NULL){
        return NULL;
    }
    ref->data = data;
    ref->next = NULL;
    return ref;
}
typedef struct SingleLL
{
    struct LinkNode *head;
} SingleLL;
SingleLL *getSingleLL(){
    // Create dynamic memory of SingleLL
    SingleLL * ref = (SingleLL *) malloc(sizeof(SingleLL));
    if(ref == NULL){
        // Failed to create memory
        return NULL;
    }
    ref->head = NULL;
    return ref;
}
// Add new Node at end of linked list
void  addNode (SingleLL* ref, int data)
{
    LinkNode *node = getLinkNode(data);
    if (ref->head == NULL)
    {
        ref->head = node;
    }
    else
    {
        LinkNode *temp = ref->head;
        // Find the last node
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        // Append the node at last position
        temp->next = node;
    }
}
// Display linked list element
void  display (SingleLL* ref)
{
    if (ref->head == NULL)
    {
        printf("\n Empty linked list\n");
        return;
    }
    LinkNode *temp = ref->head;
    // iterating linked list elements
    while(temp != NULL)
    {
        if (temp != ref->head)
        {
            printf(" ");
        }
        printf(" %d" , temp->data);
        // Visit to next node
        temp = temp->next;
    }
    printf(" NULL\n");
}
// Swap the given node value
void  swapData (LinkNode *a, LinkNode *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}
// Sort the linked list using selection sort
void  selectionSort (SingleLL* ref)
{
    int count=0;
    LinkNode *auxiliary = ref->head;
    LinkNode *temp = NULL;
    LinkNode *node = NULL;
    // Execute linked list node
    while(auxiliary != NULL)
    {
        node = auxiliary;
        temp = auxiliary->next;
        // Find the minimum node
        while(temp != NULL)
        {
            if (node->data > temp->data)
            {
                node = temp;
            }
            // Visit to next node
            temp = temp->next;
        }
        if (auxiliary->data > node->data)
        {
            // Transfer minimum value to initial position
            // Swap the node value
            count++;
            swapData(auxiliary, node);
        }
        // Visit to next node
        auxiliary = auxiliary->next;
    }
    printf("\nThe number of comparisons made is %d",count);
}

int main()
{
    SingleLL *sll = getSingleLL();
    addNode(sll,rand()%100+1);
    addNode(sll,rand()%100+1);
    addNode(sll,rand()%100+1);
    addNode(sll,rand()%100+1);
    addNode(sll,rand()%100+1);
    printf("\n Before sort \n");
    display(sll);
    // Sort linked list
    selectionSort(sll);
    printf("\n After sort \n");
    display(sll);
	return 0; 
}