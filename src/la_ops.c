#include "la_ops.h"

la_status la_add(Matrix *out, const Matrix *a, const Matrix *b) {
    if (!out || !a || !b) return LA_ERR_DIM;
    if (!a->data || !b->data) return LA_ERR_DIM;
    if (out->data != NULL) return LA_ERR_DIM;
    if (a->rows != b->rows || a->cols != b->cols) return LA_ERR_DIM;

    la_status st = la_matrix_init(out, a->rows, a->cols);
    if (st != LA_OK) return st;

    for (size_t i = 0; i < a->rows; i++) {
        for (size_t j = 0; j < a->cols; j++) {
            LA_AT(out, i, j) = LA_AT(a, i, j) + LA_AT(b, i, j);
        }
    }
    return LA_OK;
}

la_status la_sub(Matrix *out, const Matrix *a, const Matrix *b) {
    if (!out || !a || !b) return LA_ERR_DIM;
    if (!a->data || !b->data) return LA_ERR_DIM;
    if (out->data != NULL) return LA_ERR_DIM;
    if (a->rows != b->rows || a->cols != b->cols) return LA_ERR_DIM;

    la_status st = la_matrix_init(out, a->rows, a->cols);
    if (st != LA_OK) return st;

    for (size_t i = 0; i < a->rows; i++) {
        for (size_t j = 0; j < a->cols; j++) {
            LA_AT(out, i, j) = LA_AT(a, i, j) - LA_AT(b, i, j);
        }
    }
    return LA_OK;
}

la_status la_transpose(Matrix *out, const Matrix *a) {
    if (!out || !a) return LA_ERR_DIM;
    if (!a->data) return LA_ERR_DIM;
    if (out->data != NULL) return LA_ERR_DIM;

    la_status st = la_matrix_init(out, a->cols, a->rows);
    if (st != LA_OK) return st;

    for (size_t i = 0; i < a->rows; i++) {
        for (size_t j = 0; j < a->cols; j++) {
            LA_AT(out, j, i) = LA_AT(a, i, j);
        }
    }
    return LA_OK;
}

la_status la_mul(Matrix *out, const Matrix *a, const Matrix *b) {
    if (!out || !a || !b) return LA_ERR_DIM;
    if (!a->data || !b->data) return LA_ERR_DIM;
    if (out->data != NULL) return LA_ERR_DIM;
    if (a->cols != b->rows) return LA_ERR_DIM;

    la_status st = la_matrix_init(out, a->rows, b->cols);
    if (st != LA_OK) return st;

    for (size_t i = 0; i < out->rows; i++) {
        for (size_t j = 0; j < out->cols; j++) {
            double sum = 0.0;
            for (size_t k = 0; k < a->cols; k++) {
                sum += LA_AT(a, i, k) * LA_AT(b, k, j);
            }
            LA_AT(out, i, j) = sum;
        }
    }
    return LA_OK;
}
