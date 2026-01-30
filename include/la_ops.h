#ifndef LA_OPS_H
#define LA_OPS_H

#include "la_matrix.h"

la_status la_add(Matrix *out, const Matrix *a, const Matrix *b);
la_status la_sub(Matrix *out, const Matrix *a, const Matrix *b);
la_status la_transpose(Matrix *out, const Matrix *a);
la_status la_mul(Matrix *out, const Matrix *a, const Matrix *b);

#endif
