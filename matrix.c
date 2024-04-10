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

    // 입력받은 행과 열이 비정상이면 경고문 출력
    if (row <= 0 || column <= 0) {
        printf("행과 열은 0보다 커야합니다.\n");
        return 0;
    }

    /** 2. 행렬 A, B를 동적할당 **/
    int **A; //이중포인터 변수 A 선언
    int **B; //이중포인터 변수 B 선언

    // 배열의 주소를 받을 포인터 사이즈 x 행렬의 행의 공간을 동적할당했다. 
    A = (int **)malloc(sizeof(int *) * row); 
    B = (int **)malloc(sizeof(int *) * row); 

    // 배열의 값이 저장될 int 사이즈 x 행렬의 열의 공간을 동적할당했다.
    for (int i = 0; i < row; i++) { 
        A[i] = (int *)malloc(sizeof(int) * column); 
        B[i] = (int *)malloc(sizeof(int) * column); 
    }
    
    // 동적할당이 제대로 이루어지지 않았다면 경고문 출력
    if (A == NULL || B == NULL) {
        printf("메모리 할당에 실패했습니다.\n");
        return 0;
    }

    /** 3. random 값으로 행렬 초기화 **/
    srand(time(NULL));
    
    // rand 함수를 사용하여 0~99 사이의 값을 할당했다.
    for (int i = 0; i < row; i++){ // 행 만큼 반복
        for (int j = 0; j < column; j++) { // 열 만큼 반복
            A[i][j] = rand() % 100;
            B[i][j] = rand() % 100;
        }
    }
    
    printf("\nA 행렬\n");
    print_matrix(row, column, A); // 행렬 A 출력
    printf("B 행렬\n");
    print_matrix(row, column, B); // 행렬 B 출력

    printf("A + B 행렬\n");
    print_matrix(row, column, addition_matrix(row, column, A, B)); // A+B 행렬 출력
    printf("A - B 행렬\n");
    print_matrix(row, column, subtract_matrix(row, column, A, B)); // A-B 행렬 출력
    printf("A 전치행렬\n");
    print_matrix(row, column, transpose_matrix(row, column, A)); // A의 전치행렬 출력
    printf("A * B 행렬\n");
    print_matrix(row, column, multiply_matrix(row, column, A, B)); // A*B 행렬 출력
    
    // 동적할당 해제
    free_matrix(row, addition_matrix(row, column, A, B));
    free_matrix(row, subtract_matrix(row, column, A, B));
    free_matrix(column, transpose_matrix(row, column, A));
    free_matrix(row, multiply_matrix(row, column, A, B));
    free_matrix(row, A); 
    free_matrix(row, B);
}


/** 4. Print Matrix 함수 구현 **/
void print_matrix(int x, int y, int** A){
        for (int i = 0; i < x; i++) { // 행 만큼 반복
            for (int j = 0; j < y; j++) { // 열 만큼 반복
                printf("%d ", A[i][j]); // 행렬의 값 출력
            }
            printf("\n");
        }
        printf("\n");
    
    
}

/** 5. Add Matrix 함수 구현 **/
int** addition_matrix(int x, int y, int** A, int** B){
    
    // 이중포인터 변수 선언과 동시에 각 배열의 주소를 받을 포인터 사이즈 x 행의 공간을 동적할당
    int **result = (int **)malloc(sizeof(int *) * x); 
    // 배열의 값이 저장될 int 사이즈 x 행렬의 열의 공간을 동적할당
    for (int i = 0; i < x; i++) { 
        result[i] = (int *)malloc(sizeof(int) * y); 
    }
    
    // 동적할당이 제대로 이루어지지 않았다면 경고문 출력
    if (result == NULL) {
        printf("메모리 할당에 실패했습니다.\n");
        return NULL;
    }

    for (int i = 0; i < x; i++) { // 행 만큼 반복
        for (int j = 0; j < y; j++) { // 열 만큼 반복
            result[i][j] = A[i][j]+B[i][j]; // 각 성분을 더한 값을 저장
        }
    }
    return result;

}

/** 6. Subtract Matrix 함수 구현 **/
int** subtract_matrix(int x, int y, int** A, int** B){
        
    // 이중포인터 변수 선언과 동시에 각 배열의 주소를 받을 포인터 사이즈 x 행의 공간을 동적할당
    int **result = (int **)malloc(sizeof(int *) * x); 
    // 배열의 값이 저장될 int 사이즈 x 행렬의 열의 공간을 동적할당
    for (int i = 0; i < x; i++) { 
        result[i] = (int *)malloc(sizeof(int) * y); 
    }
        
    // 동적할당이 제대로 이루어지지 않았다면 경고문 출력
    if (result == NULL) {
        printf("메모리 할당에 실패했습니다.\n");
        return NULL;
    }
    
    for (int i = 0; i < x; i++) { // 행 만큼 반복
        for (int j = 0; j < y; j++) { // 열 만큼 반복
            result[i][j] = A[i][j]-B[i][j]; // 각 성분을 뺀 값을 저장
        }
    }
    return result;
    
}

/** 7. Transpose Matrix_a 함수 구현 **/
int** transpose_matrix(int x, int y, int** A){
    // 이중포인터 변수 선언과 동시에 각 배열의 주소를 받을 포인터 사이즈 x 열의 공간을 동적할당
    int **result = (int **)malloc(sizeof(int *) * y); 
    // 배열의 값이 저장될 int 사이즈 x 행렬의 행의 공간을 동적할당
    for (int i = 0; i < y; i++) { 
        result[i] = (int *)malloc(sizeof(int) * x); 
    }

    // 동적할당이 제대로 이루어지지 않았다면 경고문 출력
    if (result == NULL) {
        printf("메모리 할당에 실패했습니다.\n");
        return NULL;
    }

    for (int i = 0; i < y; i++) { // 열 만큼 반복
        for (int j = 0; j < x; j++) { // 행 만큼 반복
            result[i][j] = A[j][i]; // A의 행과 열을 바꾼 값을 저장
        }
    }
    return result;

}

/** 8. Multiply Matrix 함수 구현 **/
int** multiply_matrix(int x, int y, int** A, int** B){
    // 이중포인터 변수 선언과 동시에 각 배열의 주소를 받을 포인터 사이즈 x 행의 공간을 동적할당
    int **result = (int **)malloc(sizeof(int *) * x); 
    // 배열의 값이 저장될 int 사이즈 x 행렬의 열의 공간을 동적할당
    for (int i = 0; i < x; i++) { 
        result[i] = (int *)malloc(sizeof(int) * y); 
    }

    // 동적할당이 제대로 이루어지지 않았다면 경고문 출력
    if (result == NULL) {
        printf("메모리 할당에 실패했습니다.\n");
        return NULL;
    }

    for (int i = 0; i < x; i++) { // 행 만큼 반복
        for (int j = 0; j < y; j++) { // 열 만큼 반복
            result[i][j] = A[i][j]*B[i][j]; // 각 성분을 곱한 값을 저장
        }
    }
    return result;

}

/** 9. 할당했던 메모리 해제 함수 구현 **/
void free_matrix(int x, int** A){
    for (int i = 0; i < x; i++) { // 배열의 값이 저장된 공간을 해제
        free(A[i]);
    }
    free(A); // 배열의 주소를 받은 공간을 해제
}