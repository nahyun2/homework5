#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_matrix(int x, int y, int** A); // ��� ���
int** addition_matrix(int x, int y, int** A, int** B); // A+B
int** subtract_matrix(int x, int y, int** A, int** B); // A-B
int** transpose_matrix(int x, int y, int** A); // A�� ��ġ��� T
int** multiply_matrix(int x, int y, int** A, int** B); // A*B
void free_matrix(int x, int** A); // �����Ҵ� ����

int main() {
    printf("[-----[�ֳ���] [2023041039]-----]\n\n");

    /** 1. ����� ũ�⸦ �Է� **/
    int row, column;

    // scanf �Լ��� ����Ͽ� ����� ��� ���� �Է¹޾Ҵ�.
    printf("����� �� : ");
    scanf("%d", &row);
    printf("����� �� : ");
    scanf("%d", &column);

    /** 2. ��� A, B�� �����Ҵ� **/
    int **A;
    int **B;

    //����� ���� �����Ҵ��ߴ�.
    A = (int **)malloc(sizeof(int *) * row); 
    B = (int **)malloc(sizeof(int *) * row); 

    // ����� ���� �����Ҵ��ߴ�.
    
    for (int i = 0; i < row; i++) { 
        A[i] = (int *)malloc(sizeof(int) * column); 
        B[i] = (int *)malloc(sizeof(int) * column); 
    }

    /** 3. random ������ ��� �ʱ�ȭ **/
    srand(time(NULL));
    
    // rand �Լ��� ����Ͽ� 0~99 ������ ���� �Ҵ��ߴ�.
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++) {
            A[i][j] = rand() % 100;
            B[i][j] = rand() % 100;
        }
    }
    printf("\nA ���\n");
    print_matrix(row, column, A); // ��� A ���
    printf("B ���\n");
    print_matrix(row, column, B); // ��� B ���

    printf("A + B ���\n");
    print_matrix(row, column, addition_matrix(row, column, A, B));
    printf("A - B ���\n");
    print_matrix(row, column, subtract_matrix(row, column, A, B));
    printf("A ��ġ���\n");
    print_matrix(row, column, transpose_matrix(row, column, A));
    printf("A * B ���\n");
    print_matrix(row, column, multiply_matrix(row, column, A, B));
    
    
    free_matrix(row, A);
    free_matrix(row, B);

    free_matrix(row, addition_matrix(row, column, A, B));
    free_matrix(row, subtract_matrix(row, column, A, B));
    free_matrix(column, transpose_matrix(row, column, A));
    free_matrix(row, multiply_matrix(row, column, A, B));
}


/** 4. Print Matrix �Լ� ���� **/
void print_matrix(int x, int y, int** A){
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                printf("%d ", A[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    
    
}

/** 5. Add Matrix �Լ� ���� **/
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

/** 6. Subtract Matrix �Լ� ���� **/
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

/** 7. Transpose Matrix_a �Լ� ���� **/
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

/** 8. Multiply Matrix �Լ� ���� **/
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

/** 9. �Ҵ��ߴ� �޸� ���� �Լ� ���� **/
void free_matrix(int x, int** A){
    for (int i = 0; i < x; i++) {
        free(A[i]);
    }
    free(A);
}