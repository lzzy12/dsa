#include <stdio.h>
#include <stdlib.h>

int removeRepeated(int arr[], int n){
    int largest = arr[0];
    for (int i = 1; i < n; i++){
        if (largest < arr[i])
            largest = arr[i];
    }
    int *hashMap = calloc(largest, sizeof(int));
    for (int i = 0; i < n; i++){
        hashMap[arr[i]]++;
    }
    n = 0;
    for (int i = 0; i < largest; i++){
        if (hashMap[i] >= 1){
            arr[n++] = i;
        }
    }
    return n;
}
void displayArr(int arr[], int n){
    for (int i =0; i < n; i++)
        printf("%d, ", arr[i]);
    printf("\n");
}
int main(){
    int arr[] = {1, 2, 2, 5, 1, 3, 8, 7, 8};
    int size = sizeof(arr) / sizeof(int);
    displayArr(arr,size);
    size = removeRepeated(arr, size);
    displayArr(arr, size);
}