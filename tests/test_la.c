#include <stdio.h>
#include <math.h>
#include "la_matrix.h"
#include "la_ops.h"
#include "la_solve.h"

static int nearly_equal(double a, double b) {
    return fabs(a - b) < 1e-9;
}

int main(void) {
    Matrix A, B, C, T;

    // Initialize matrices A and B  
    if (la_matrix_init(&A, 2, 2) != LA_OK) return 1;
    if (la_matrix_init(&B, 2, 2) != LA_OK) return 1;

    // Fill matrices A and B
    // A = [1 2; 3 4]
    // B = [10 20; 30 40]
    LA_AT(&A,0,0)=1; LA_AT(&A,0,1)=2;
    LA_AT(&A,1,0)=3; LA_AT(&A,1,1)=4;
   
    LA_AT(&B,0,0)=10; LA_AT(&B,0,1)=20;
    LA_AT(&B,1,0)=30; LA_AT(&B,1,1)=40;

    // Addition test:
    if (la_add(&C, &A, &B) != LA_OK) return 2;
    if (!nearly_equal(LA_AT(&C,1,1), 44)) return 3;

    // Transpose test:
    if (la_transpose(&T, &A) != LA_OK) return 4;
    if (!nearly_equal(LA_AT(&T,0,1), 3)) return 5; // A(1,0) -> T(0,1)

    // Multiplication test:
    // A = [1 2; 3 4]
    // B = [10 20; 30 40]
    // A*B = [70 100; 150 220]
    Matrix M = {0};
    if (la_mul(&M, &A, &B) != LA_OK) return 6;
    if (!nearly_equal(LA_AT(&M,0,0), 70)) return 7;
    if (!nearly_equal(LA_AT(&M,0,1), 100)) return 8;
    if (!nearly_equal(LA_AT(&M,1,0), 150)) return 9;
    if (!nearly_equal(LA_AT(&M,1,1), 220)) return 10;

    // Subtraction test:
    // A - B = [-9 -18; -27 -36]
    Matrix S = {0};
    if (la_sub(&S, &A, &B) != LA_OK) return 11;
    if (!nearly_equal(LA_AT(&S,0,0), -9))  return 12;
    if (!nearly_equal(LA_AT(&S,0,1), -18)) return 13;
    if (!nearly_equal(LA_AT(&S,1,0), -27)) return 14;
    if (!nearly_equal(LA_AT(&S,1,1), -36)) return 15;

    // Determinant test:
    // For A = [[1,2],[3,4]], det = -2.0
    double det = 0.0;
    if (la_det(&det, &A) != LA_OK) return 20;
    if (!nearly_equal(det, -2.0)) return 21;

    // Solve test:  
    // A = [[3,2],[1,2]], b = [[5],[5]]
    Matrix A2 = {0}, b2 = {0}, x = {0};
    if (la_matrix_init(&A2, 2, 2) != LA_OK) return 22;
    if (la_matrix_init(&b2, 2, 1) != LA_OK) return 23;

    LA_AT(&A2,0,0)=3; LA_AT(&A2,0,1)=2;
    LA_AT(&A2,1,0)=1; LA_AT(&A2,1,1)=2;

    LA_AT(&b2,0,0)=5;
    LA_AT(&b2,1,0)=5;

    if (la_solve(&x, &A2, &b2) != LA_OK) return 24;
    if (!nearly_equal(LA_AT(&x,0,0), 0.0)) return 25;
    if (!nearly_equal(LA_AT(&x,1,0), 2.5)) return 26;


    // Free all matrices
    la_matrix_free(&A2);
    la_matrix_free(&b2);
    la_matrix_free(&x);
    la_matrix_free(&S);
    la_matrix_free(&A);
    la_matrix_free(&B);
    la_matrix_free(&C);
    la_matrix_free(&T);
    la_matrix_free(&M);

    printf("test_la: OK\n");
    return 0;
}
