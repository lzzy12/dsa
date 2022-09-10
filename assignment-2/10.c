#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arrSize = 10, subArrSize;
    printf("Enter size of sub arr: ");
    scanf("%d", &subArrSize);
    int *subArr = calloc(subArrSize, sizeof(int));
    printf("Enter %d elements for sub arr: ", subArrSize);
    for (int i = 0; i < subArrSize; i++){
        scanf("%d", subArr + i);
    }
    int left = 0, right = 0;
    int index;
    while(right < arrSize && left < subArrSize){
        if (subArr[left] == arr[right]){
            if (left == 0)
                index = right;
            left++;
        } else{
            left = 0;
        }

        right++;
    }
    printf("left: %d\n", left);
    if (subArrSize == left){
        printf("Sub array found at: %d\n", index);
    } else{
        printf("Sub array not found\n");
    }
}