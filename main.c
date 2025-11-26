#include <stdio.h>
#include <stdbool.h>

#include "input.h"
#include "linalg.h"
#include "stats.h"

//function prototypes
static void main_menu(void);

int main(void) {
    main_menu();
    return 0;
}

static void main_menu(void) {
  bool running = true;
  
  while (running) {
    printf("\n==== Numerical Toolkit ====\n ");
    printf("1. Linear Algebera Tool\n ");
    printf("2. Statistics Tool\n ");
    printf("0. Exit\n");
    printf("===========================\n ");

    int selection = 0;
    scanf("%d", &selection);

    switch (selection) {
        case 1:
            printf("Sub menu for linear algrea placeholder\n");
            break;
        case 2:
            printf("Sub menu for statistics placeholder\n");
            break;
        case 0:
            printf("EXITING PROGRAM");
            running = false;
            break;
        default:
            printf("Invalid Option. Try again.\n");
            break;
    }
  }
}