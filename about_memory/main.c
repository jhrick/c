#include <stdio.h>
#include <stdlib.h>

void allocate_stack() {
    int number1 = 0;
    int number2 = 1;

    int* pointer_num = &number1;

    // how the memory is sequential
    // just sum 1 to the address to the next
    // this is stack

    printf("number 1: %d\n", *pointer_num);
    printf("number 2: %d\n", *(pointer_num + 1));

    return;
}

void allocate_heap() {
    int* number = malloc(sizeof(int));

    *number = 10;

    printf("%d\n", *number);

    return;
}

int main() {
    allocate_stack();

    allocate_heap();

    return 0;
}