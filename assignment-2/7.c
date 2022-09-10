#include <stdio.h>

void rightRotate(int arr[], int l, int r){
    int temp = arr[r];
    for (int i = r; i > l; i--){
        arr[i ] = arr[i - 1];
    }
    arr[l] = temp;
}

void displayArr(int arr[], int n){
    for (int i =0; i < n; i++)
        printf("%d, ", arr[i]);
    printf("\n");
}

int main(){
    int arr[] = {2,9,6,3,5,8,11,3,6,7,13,5};
    int shifting;
    printf("Enter shifting value: ");
    scanf("%d", &shifting);
    if (shifting <= 0)
        return 0;
    while(shifting--){
        rightRotate(arr, 4, 9);
    }
    displayArr(arr, sizeof(arr) / sizeof(int));
}