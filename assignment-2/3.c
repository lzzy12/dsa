#include <stdio.h>
#include <stdlib.h>

#define default_size 10
typedef struct {
    int *arr;
    int size;
    int maxSize;
} arrayList;

void init(arrayList *list){
    list->arr = (int *)malloc(sizeof(int) * default_size);
    list->size = 0;
    list->maxSize = default_size;
}
int insert(arrayList *list, int data[], int dataSize, int n){
    if (n > list->size)
        n = list->size;
    if (list->size + dataSize + 1 > list->maxSize){
        list->maxSize = ((list->maxSize * 2) + dataSize); // Double the size and guarantee that data can fit however long it is;
        list->arr = realloc(list->arr, sizeof(int) * (list->maxSize));
    }
    int i = list->size - 1;
    while(i >= n){
        list->arr[i + dataSize] = list->arr[i];
        i--;
    }
    i = 0;
    while(i < dataSize){
        list->arr[i + n] = data[i];
        i++;
    }
    list->size += dataSize;
    return 0;
}

void displayList(arrayList list){
    for (int i = 0; i < list.size; i++){
        printf("%d, ", list.arr[i]);
    }
    printf("\n");
}
int main(){
    arrayList list;
    int dataArr[] = {1,2,3,4,5,6,7,8,9};
    int m = sizeof(dataArr) / sizeof(int);
    int arr[] = {15,17,19};
    int n = sizeof(arr) / sizeof(int);
    init(&list);
    insert(&list, dataArr, m, 0);
    displayList(list);
    insert(&list, arr, n, m);
    displayList(list);
}