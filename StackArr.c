#include <stdio.h>
#include <stdlib.h>
int top = -1 ;
void push(int stack[] ,int n){
    printf("enter the elements: ");
    while(top != n-1){
        top++;
        scanf("%d",&stack[top]);
    }
}
void display(int stack[]){
    if(top == -1){
        printf("stack is empty");
    }
    else{
        printf("stack:\n");
        while(top != -1){
            printf("%d\n",stack[top]);
            top-- ;
        }
    }
}
void pop(int stack[] , int n){
    int *temp ;
    top = n-1 ;
    printf("how many elements u want to pop: ");
    int k ;
    scanf("%d",&k);
    printf("After popping:\n");
    for(int i = 0 ; i < k ; i++){
        temp = &stack[top];
        top-- ;
        free(temp); 
    }
    display(stack); 
}
int main(){
    printf("enter the number of elements you want to enter: ");
    int n ;
    scanf("%d",&n);
    int *stack = (int*)malloc(n * sizeof(int));
    push(stack , n);
    display(stack);
    pop(stack , n);
}