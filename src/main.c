#include <stdio.h>
#include <string.h>
#include "dynarray.h"

int main(int argc, char *argv[]) {
    DynArray arr;
    da_init(&arr);

    // Fill the array with some data
    for (int i = 0; i < 5; i++) {
        da_push(&arr, i * 10);
    }

    printf("Original array: ");
    for (size_t i = 0; i < arr.size; i++) {
        printf("%d ", da_get(&arr, i));
    }
    printf("\n");

    DynArray arr2;
    da_init(&arr2);

    // Default mode: binary
    int useText = 0;
    if (argc > 1 && strcmp(argv[1], "text") == 0) {
        useText = 1;
    }

    if (useText) {
        da_save_text(&arr, "data.bin");
        da_load_text(&arr2, "data.bin");
    } else {
        da_save(&arr, "data.bin");
        da_load(&arr2, "data.bin");
    }

    printf("Loaded array: ");
    for (size_t i = 0; i < arr2.size; i++) {
        printf("%d ", da_get(&arr2, i));
    }
    printf("\n");

    da_free(&arr);
    da_free(&arr2);

    return 0;
}

