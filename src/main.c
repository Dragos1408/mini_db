#include <stdio.h>
#include "utils.h"
#include "dynarray.h"

int main() {
    printf("Mini DB starting...\n");

    char str[] = "   Hello  ";
    printf("'%s'\n", my_strtrim(str));

    DynArray arr;
    da_init(&arr);

    for (int i = 0; i < 10; i++) {
        da_push(&arr, i * 10);
    }

    for (size_t i = 0; i < arr.size; i++) {
        printf("%d ", da_get(&arr, i));
    }
    printf("\n");

    da_free(&arr);
    return 0;
}

