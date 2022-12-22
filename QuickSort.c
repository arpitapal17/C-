#include<stdio.h>
#include<stdlib.h>
void swap(int *a , int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int *a,int first,int last){
   int i, j, pivot, temp;
      pivot = a[first];
      i=first;
      j=last;
      while(i<j){
         while(a[i]<=pivot&&i<last)
         i++;
         while(a[j]>pivot)
         j--;
         if(i<j){
            swap(&a[i],&a[j]);
         }
      }
      swap(&a[first] , &a[j]);
      return j;
}
void quickSort(int *a , int start , int end){
    if(start < end){
        int k = partition(a,start,end);
        quickSort(a,start,k-1);
        quickSort(a,k+1,end);
    }
}
int main(){
    int n ;
    printf("enter the size of array: ");
    scanf("%d",&n);
    int *a = (int *)malloc( n * sizeof(int));
    printf("unsorted array: ");
    for(int i = 0 ; i < n ; i++){
        printf("  %d",a[i] = rand()%100);
    }
    printf("\n");
    quickSort(a, 0 , n-1);
    int k;
    printf("enter k: ");
    scanf("%d",&k);
    printf("kth smallest element = %d",a[k]);
    return 0 ;
}