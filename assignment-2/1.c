#include <stdio.h>
#include <stdlib.h>

#define default_size 10
typedef struct {
    int *arr;
    int size;
    int maxSize;
} arrayList;

void init(arrayList *list){
    list->arr = malloc(sizeof(int) * default_size);
    list->size = 0;
    list->maxSize = default_size;
}
int insert(arrayList *list, int data, int n){
    if (n < 0)
        return -2;
    if (list->size == list->maxSize){
        int *ptr;
        ptr = realloc(list->arr, sizeof(int) * (list->size * 2));
        if (ptr){
            list->arr = ptr;
            list->maxSize *= 2;
            printf("Max size changed to: %d\n", list->maxSize);
        } else{
            return -1;
        }
    }
    
    if (n < list->size){
        for (int j = list->size; j > n; j--){
            list->arr[j] = list->arr[j - 1];
        }
        list->arr[n] = data;
    } else{
        list->arr[list->size] = data;
    }
    list->size++;

    return 0;
}

int push(arrayList *list, int data){
    insert(list, data, list->size);
}

int delete(arrayList *list, int data){
    int i;
    int r;
    for (i = 0; i < list->size; i++){
        if (list->arr[i] == data){
            r = list->arr[i];
            for (int j = i; j < list->size - 1; j++){
                list->arr[j] = list->arr[j + 1];
            }
            list->size--;
            break;
        }
    }
    return r;
}
void displayList(arrayList list){
    for (int i = 0; i < list.size; i++){
        printf("%d, ", list.arr[i]);
    }
    printf("\n");
}
int main(){
    arrayList list;
    int del;
    init(&list);
    push(&list, 5);
    push(&list, 10);
    push(&list, 18);
    insert(&list, 9, 1);
    push(&list, 18);
    displayList(list);
    del = delete(&list, 5);
    printf("After deleting: %d\n", del);
    displayList(list);
    del = delete(&list, 10);
    printf("After deleting: %d\n", del);
    displayList(list);
    del = delete(&list, -1);
    displayList(list);
}