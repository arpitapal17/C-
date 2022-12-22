#include<stdio.h>
void merge(int arr[], int lb, int mid, int ub)
{
    int i, j, k;
    int n1 = mid - lb + 1;
    int n2 = ub - mid; 
    int Left[n1], Right[n2];
    for (i = 0; i < n1; i++)
        Left[i] = arr[lb + i];
    for (j = 0; j < n2; j++)
        Right[j] = arr[mid + 1 + j]; 
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = lb; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (Left[i] <= Right[j]) {
            arr[k] = Left[i];
            i++;
        }
        else {
            arr[k] = Right[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = Left[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = Right[j];
        j++;
        k++;
    }
}
void mergeSort(int a[] , int lb , int ub){
    if(lb < ub){
        int mid = (lb + ub)/2 ;
        mergeSort(a , lb , mid);
        mergeSort(a , mid+1 , ub);
        merge(a , lb , mid , ub);
    }
}
int main(){
    int n ;
    printf("enter the size of array: ");
    scanf("%d",&n);
    int a[n];
    printf("unsorted array: ");
    for(int i = 0 ; i < n ; i++){
        printf("  %d",a[i]=rand()%100);
    }
    printf("\n");
    mergeSort(a, 0 , n-1);
    printf("sorted array: ");
    for(int i = 0 ; i < n ; i++){
        printf("  %d",a[i]);
    }
    return 0 ;
}