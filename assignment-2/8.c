#include <stdio.h>
void moveCircular(int m, int n, int init, int mat[m][n]){
    int i, j;
    int temp = mat[init][init];
    for (i = init; i < m - 1 - init; i++){
        mat[i][init] = mat[i + 1][init];
    }
    for (j = init; j < n - 1 - init; j++){
        mat[i][j] = mat[i][j + 1];
    }
    for (; i > init; i--){
        mat[i][j] = mat[i - 1][j];
    }
    for (; j > init + 1; j--){
        mat[i][j] = mat[i][j - 1];
    }
    mat[init][init + 1] = temp;
}

void display2DArray(int mat[][5]){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int n;
    printf("Enter number of circular steps: ");
    scanf("%d", &n);
    const int size = 5;
    int mat[size][size];
    int c = 1;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            mat[i][j] = c++;
        }
    }
    display2DArray(mat);
    while(n--){
        int i = 0;
        while(i < size / 2){
            moveCircular(size, size, i++, mat);
        }
        
    }
    printf("\nAfter circular movement: \n");
    display2DArray(mat);
}