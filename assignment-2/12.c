#include <stdio.h>

int revNum(int n){
    int rev = 0;
    while(n){
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}

void displayArr(int arr[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int checkAllDigitsPresent(int test, int data){
    int testArr[7], dataArr[7];
    int i = 0, j = 0;
    while (test) {
        testArr[i++] = test % 10;
        test /= 10;
    }
    while (data) {
        dataArr[j++] = data % 10;
        data /= 10;
    }
    int k = 0;
    while (k < j) {
        int l;
        for (l = 0; l < i; l++){
            if (testArr[l] == dataArr[k]){
                k++;
                break;
            }
        }
        if (l == i)
            return 0;
    }
    return 1;
}
int main(){
    int arr[] = {2,9,6,3,9,8,17,3,4,6,13,5};
    int m = sizeof(arr) / sizeof(int);
    printf("Original Array: ");
    displayArr(arr, m);
    for (int i = 1; i < m; i++){
        int d = arr[i];
        if (d  < arr[i - 1]){
            int rev = revNum(d);
            if (rev > arr[i - 1])
                d = rev;
        }
        while(d < arr[i - 1]){
            d += 10;
        }
        while (!checkAllDigitsPresent(d, arr[i])) {
                d += 10;
        }
        arr[i] = d;
    }
    printf("Modified Array: ");
    displayArr(arr, m);
}