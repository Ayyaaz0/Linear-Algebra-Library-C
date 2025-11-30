#include <stdio.h>
#include "input.h"
#include "linalg.h"

static void input_matrix(Matrix *m);
static void print_matrix(const Matrix *m);

void linalg_add_n(void) {
    int count = get_int_in_range("How many matrices do you want to add? (2-10)", 2, 10);
    
    Matrix sum, M;
    sum.rows = get_int_in_range("Rows (1-10):  ", 1, MAX);
    sum.cols = get_int_in_range("Cols (1-10):  ", 1, MAX);
    
    // Set the sum matrix to all zeroes
    for (int i = 0; i < sum.rows; i++) {
        for (int j = 0; j < sum.cols; j++) {
            sum.data[i][j] = 0.0;
        }
    }
    // Read matrices and accumlate
    for (int k = 1; k <= count; k++) {
        printf("\n===== MATRX %d =====\n", k);
        M.rows = sum.rows;
        M.cols = sum.cols;
        input_matrix(&M);

        // S = S + M
        for (int i = 0; i < sum.rows; i++) {
            for (int j = 0; j < sum.cols; j++) {
                sum.data[i][j] += M.data[i][j];
            }
        }
    }
    printf("\nResult of adding %d matrices:\n", count);
    print_matrix(&sum);
}

//--------------------- Helper Functions -----------------------
/*
A general matrice's element is defined as a_ij (reference guide)
        a11 a12 a13 a14 ...a1j
        a21 a22 a23 a24 ...a2j
        a31 a32 a33 a34 ...a3j
        .    .   .   .
        .    .   .   .
        ai1 ai2 ai3 ai4
*/
static void input_matrix(Matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        printf("Rows %d (%d values):\n", i, m->cols);
        for (int j = 0; j < m->cols; j++) {
            char prompt[PROMPT_LEN];
            snprintf(prompt, sizeof(prompt), "  a[%d][%d] = ", i, j);
            m->data[i][j] = get_double(prompt);
        }
    }
}

static void print_matrix(const Matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%8.2f ", m->data[i][j]);
        }
        printf("\n");
    }
}



