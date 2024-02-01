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

void allocate_heap(int size_for_allocation) {
    int* number = malloc(sizeof(int) * size_for_allocation);

    *number = 1;

    printf("sizeof: %d", sizeof(*number));
    printf("%d\n", *number);

    free(number);

    return;
}

int main() {
    int size_for_allocation;

    scanf("%d", &size_for_allocation);

    allocate_stack();

    allocate_heap(size_for_allocation);

    return 0;
}