#include <stdio.h>
#include <stdbool.h>

#include "input.h"
#include "linalg.h"

static void print_menu(void);

int main(void) {
    int selection;
    bool running = true;

    while (running) {
        print_menu();

        selection = get_int("Enter an option: ");
        switch (selection) {
            case 1: linalg_add_n();       break;
            case 2: linalg_sub_n();       break;
            case 3: linalg_multiply_n();  break;
            case 4: linalg_transpose();   break;
            case 5: linalg_determinant(); break;
            case 0:
                printf("EXIT\n");
                running = false;
                break;
            default:
                printf("Unknown option.\n");
                break;
        }
    }
    return 0;
}

static void print_menu(void) {
        printf("\n===== Linear Algebra Calculator =====\n");
        printf("1. Add n matrices\n");
        printf("2. Subtract N matrices\n");
        printf("3. Multiply N matrices together\n");
        printf("4. Transpose a function\n");
        printf("5. Determinant of a matrix\n");
        printf("0. Exit\n");
        printf("=====================================\n");
}
