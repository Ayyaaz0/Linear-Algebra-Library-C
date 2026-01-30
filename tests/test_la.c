#include <stdio.h>
#include <math.h>
#include "la_matrix.h"
#include "la_ops.h"

static int nearly_equal(double a, double b) {
    return fabs(a - b) < 1e-9;
}

int main(void) {
    Matrix A, B, C, T;

    if (la_matrix_init(&A, 2, 2) != LA_OK) return 1;
    if (la_matrix_init(&B, 2, 2) != LA_OK) return 1;

    LA_AT(&A,0,0)=1; LA_AT(&A,0,1)=2;
    LA_AT(&A,1,0)=3; LA_AT(&A,1,1)=4;

    LA_AT(&B,0,0)=10; LA_AT(&B,0,1)=20;
    LA_AT(&B,1,0)=30; LA_AT(&B,1,1)=40;

    if (la_add(&C, &A, &B) != LA_OK) return 2;

    if (!nearly_equal(LA_AT(&C,1,1), 44)) return 3;

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


    la_matrix_free(&A);
    la_matrix_free(&B);
    la_matrix_free(&C);
    la_matrix_free(&T);
    la_matrix_free(&M);

    printf("test_la: OK\n");
    return 0;
}
