#include <stdio.h>
#include <stdlib.h>

void reverseEvenOdd(int arr[], int n, int startIndex){
    if (n % 2 == 0)
        startIndex = 0;
    else
        startIndex = 1;
    for (int i = startIndex; i < n / 2; i += 2) {
        int t = arr[n - 1 - i];
        arr[n - 1 - i] = arr[i];
        arr[i] = t;
    }
}
int main() {
    int n, s;
    printf("\nEnter the size of array: ");
    scanf("%d", &n);
    int *arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10;
    }
    reverseEvenOdd(arr, n, s);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}