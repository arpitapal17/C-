#include <stdio.h>
#include <stdlib.h>
typedef struct polynomial
{
    int coef;
    int expo;
    struct polynomial *next;
}poly;
poly *head = NULL ;

poly *create_poly()
{
    poly *ptr;
    int size;
    printf("enter the number of terms: ");
    scanf("%d", &size);
    if(size == 0)
        return head ;
    for (int i = 0; i < size; i++)
    {
        if (i == 0)
        {
            head = (poly*)malloc(sizeof(poly));
            ptr = head;
        }
        else
        {
            ptr->next = (poly*)malloc(sizeof(poly));
            ptr = ptr->next;
        }
        printf("enter the coefficient of term %d : ",i);
        scanf("%d", &ptr->coef);
        printf("enter the exponent of term %d : ",i);
        scanf("%d", &ptr->expo);
    }
    ptr->next = NULL;
    return (head);
    
}
void Traverse(poly *head){
    poly *ptr ;
    ptr = head ;
    if( head == NULL){
        printf("no polynomial formed");
    }
    else{
        printf("The given polynomial: ");
        while(ptr != NULL){
            printf("%dx^%d + ",ptr->coef,ptr->expo);
            ptr = ptr->next ;
        }
    }
}

int main(){
    head = create_poly();
    Traverse(head);
}