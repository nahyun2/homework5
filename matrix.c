#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_matrix(int x, int y, int** A); // 행렬 출력
int** addition_matrix(int x, int y, int** A, int** B); // A+B
int** subtract_matrix(int x, int y, int** A, int** B); // A-B
int** transpose_matrix(int x, int y, int** A); // A의 전치행렬 T
int** multiply_matrix(int x, int y, int** A, int** B); // A*B
void free_matrix(int x, int** A); // 동적할당 해제

int main() {
    printf("[-----[최나현] [2023041039]-----]\n\n");

    /** 1. 행렬의 크기를 입력 **/
    int row, column;

    // scanf 함수를 사용하여 행렬의 행과 열을 입력받았다.
    printf("행렬의 행 : ");
    scanf("%d", &row);
    printf("행렬의 열 : ");
    scanf("%d", &column);

    /** 2. 행렬 A, B를 동적할당 **/
    int **A;
    int **B;

    //행렬의 행을 동적할당했다.
    A = (int **)malloc(sizeof(int *) * row); 
    B = (int **)malloc(sizeof(int *) * row); 

    // 행렬의 열을 동적할당했다.
    
    for (int i = 0; i < row; i++) { 
        A[i] = (int *)malloc(sizeof(int) * column); 
        B[i] = (int *)malloc(sizeof(int) * column); 
    }

    /** 3. random 값으로 행렬 초기화 **/
    srand(time(NULL));
    
    // rand 함수를 사용하여 0~99 사이의 값을 할당했다.
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++) {
            A[i][j] = rand() % 100;
            B[i][j] = rand() % 100;
        }
    }
    printf("\nA 행렬\n");
    print_matrix(row, column, A); // 행렬 A 출력
    printf("B 행렬\n");
    print_matrix(row, column, B); // 행렬 B 출력

    printf("A + B 행렬\n");
    print_matrix(row, column, addition_matrix(row, column, A, B));
    printf("A - B 행렬\n");
    print_matrix(row, column, subtract_matrix(row, column, A, B));
    printf("A 전치행렬\n");
    print_matrix(row, column, transpose_matrix(row, column, A));
    printf("A * B 행렬\n");
    print_matrix(row, column, multiply_matrix(row, column, A, B));
    
    
    free_matrix(row, A);
    free_matrix(row, B);

    free_matrix(row, addition_matrix(row, column, A, B));
    free_matrix(row, subtract_matrix(row, column, A, B));
    free_matrix(column, transpose_matrix(row, column, A));
    free_matrix(row, multiply_matrix(row, column, A, B));
}


/** 4. Print Matrix 함수 구현 **/
void print_matrix(int x, int y, int** A){
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                printf("%d ", A[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    
    
}

/** 5. Add Matrix 함수 구현 **/
int** addition_matrix(int x, int y, int** A, int** B){
    
    int **result;
    result = (int **)malloc(sizeof(int *) * x); 
    for (int i = 0; i < x; i++) { 
        result[i] = (int *)malloc(sizeof(int) * y); 
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            result[i][j] = A[i][j]+B[i][j];
        }
    }
    return result;

}

/** 6. Subtract Matrix 함수 구현 **/
int** subtract_matrix(int x, int y, int** A, int** B){
        
        int **result;
        result = (int **)malloc(sizeof(int *) * x); 
        for (int i = 0; i < x; i++) { 
            result[i] = (int *)malloc(sizeof(int) * y); 
        }
    
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                result[i][j] = A[i][j]-B[i][j];
            }
        }
        return result;
    
}

/** 7. Transpose Matrix_a 함수 구현 **/
int** transpose_matrix(int x, int y, int** A){
    int **result;
    result = (int **)malloc(sizeof(int *) * y); 
    for (int i = 0; i < y; i++) { 
        result[i] = (int *)malloc(sizeof(int) * x); 
    }

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            result[i][j] = A[j][i];
        }
    }
    return result;

}

/** 8. Multiply Matrix 함수 구현 **/
int** multiply_matrix(int x, int y, int** A, int** B){
    int **result;
    result = (int **)malloc(sizeof(int *) * x); 
    for (int i = 0; i < x; i++) { 
        result[i] = (int *)malloc(sizeof(int) * y); 
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            result[i][j] = A[i][j]*B[i][j];
        }
    }
    return result;

}

/** 9. 할당했던 메모리 해제 함수 구현 **/
void free_matrix(int x, int** A){
    for (int i = 0; i < x; i++) {
        free(A[i]);
    }
    free(A);
}