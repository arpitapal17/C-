#include <stdio.h>
void swap(int *a , int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSort(int a[] , int n){
    for(int i = 0 ; i < n ; i++){
        int min = i;
        for(int j = i+1 ; j < n ; j++){
            if(a[j] < a[min])
                min = j ;
        }
        if(min != i)
            swap(&a[i] , &a[min]);
    }
}
int main(){
    int n ;
    printf("enter the size of array: ");
    scanf("%d",&n);
    int a[n];
    printf("enter %d elements: ",n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&a[i]);
    }
    printf("unsorted array: ");
    for(int i = 0 ; i < n ; i++){
        printf("  %d",a[i]);
    }
    printf("\n");
    selectionSort(a,n);
    printf("sorted array: ");
    for(int i = 0 ; i < n ; i++){
        printf("  %d",a[i]);
    }
    return 0 ;
}