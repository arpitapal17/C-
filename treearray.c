#include <stdio.h>
#include <math.h>
int bt[100];
void create(int i){
    int x , r ;
    printf("\nEnter root element: ");
    scanf("%d",&x);
    bt[0] = x;
    for(r = 0 ; r < i ; ++r){
        printf("Enter data of left child: ");
        scanf("%d",&x);
        bt[2*r+1] = x;
        printf("Enter data of right child: ");
        scanf("%d",&x);
        bt[2*r+2] = x;
    }
}
void display(int i){
    int r;
    for(r = 0 ; r < i ; ++r){
        if(r == 0){
            printf("\nroot element = %d",bt[r]);
        }
        printf("\nLeft Child = %d",bt[2*r+1]);
        printf("\nRight Child = %d",bt[2*r+2]);
    }
}
int main(){
    int h , l ,i ;
    printf("enter height of the tree: ");
    scanf("%d",&h);
    l = pow(2,h);
    i = l - 1;
    printf("number of leaf nodes = %d",l);
    printf("\nnumber of internal nodes = %d",i);
    create(i);
    display(i);
    return 0 ;
}