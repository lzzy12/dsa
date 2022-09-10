#include <stdio.h>

int main(){
    int arr[] = {2,9,10,12,22,8,17,3,6,4,13,5};
    int n = sizeof(arr) / sizeof(int);
    for (int i = 0; i < n - 1; i++){
        int sum = arr[i];
        for (int j = i + 1; j < n; j++){
            if (sum == arr[j])
            {
                printf("Sum found: %d\n", arr[j]);
                return 0;
            }
            if (arr[j] >= arr[j - 1]){
                sum += arr[j];
            } else{
                break;
            }
        }
        
    }
    printf("Not found\n");
}