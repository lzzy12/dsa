#include <stdio.h>
int deleteAllEven(int nums[], int size) {
        int count = 0;
        for (int i = 0; i < size; i++){
            if ( nums[i] % 2 != 0){
                nums[count] = nums[i];
                count++;
            }
                
        }
        return count;
}
void displayArr(int arr[], int n){
    for (int i =0; i < n; i++)
        printf("%d, ", arr[i]);
    printf("\n");
}
int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;
    displayArr(arr, size);
    size = deleteAllEven(arr, size);
    displayArr(arr, size);
}