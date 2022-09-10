#include <stdio.h>

#define size 4

int summationSqMatrix(int c, int i, int j, int mat[][size]){
    int sum = 0;
    for (int k = 0; k < c; k++){
        for (int l = 0; l < c; l++){
            sum += mat[k + i][l + j];
        }
    }
    return sum;
}
void displaySqMatrix(int c, int i, int j, int mat[][size]){
    for (int k = 0; k < c; k++){
        for (int l = 0; l < c; l++){
            printf("%d\t", mat[k + i][l + j]);
        }
        printf("\n");
    }
}

int main(){
    int arr[size][size] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8}, 
        {9, 10, 11, 12},
    };
    int target;
    printf("Enter target: ");
    scanf("%d", &target);
    for (int c = 1; c < size; c++){
        for (int i = 0; i < size - c; i++){
            for (int j = 0; j < size - c; j++){
                int sum = summationSqMatrix(c, i, j, arr);
                if (sum == target)
                {
                    printf("Found sum = %d matched target = %d at arr[%d][%d], size = %d\n", sum, target, i, j, c);
                    displaySqMatrix(c, i, j, arr);
                    return 0;
                }
                
            }

        }
    }

}