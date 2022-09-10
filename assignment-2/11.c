#include <stdio.h>
#include <stdlib.h>
int main(){
    int set1[5] = {1, 2, 2, 3, 4, 5}, set2[5] = {4, 5, 6, 7, 1};
    int set1Size = 5; int set2Size = 5;
    printf("Enter %d numbers for set1: ", set1Size);
    for (int i = 0; i < set2Size; i++){
        scanf("%d", set1 + i);
    }
    printf("Enter %d numbers for set2: ", set2Size);
    for (int i = 0; i < set2Size; i++){
        scanf("%d", set2 + i);
    }
    int largest = set1[0];
    for (int i = 0; i < 5; i++){
        if (largest < set1[i])
            largest = set1[i];
    }
    int *hashMap = calloc(largest, sizeof(int));
    for (int i = 0; i < set1Size; i++){
        hashMap[set1[i]]++;
    }
    printf("Intersection of 2 sets are: ");
    for (int i = 0; i < set2Size; i++){
        if (set2[i] <= largest && hashMap[set2[i]] > 0){
            printf("%d, ", set2[i]);
        }
    }
    printf("\n");
}