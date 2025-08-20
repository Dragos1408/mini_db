#include "dynarray.h"
#include <stdlib.h>
#include <stdio.h>

void da_init(DynArray *arr) {
    arr->data = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

void da_push(DynArray *arr, int value) {
    if (arr->size == arr->capacity) {
        size_t new_capacity = arr->capacity == 0 ? 4 : arr->capacity * 2;
        int *new_data = realloc(arr->data, new_capacity * sizeof(int));
        if (!new_data) {
            perror("Failed to allocate memory");
            exit(1);
        }
        arr->data = new_data;
        arr->capacity = new_capacity;
    }
    arr->data[arr->size++] = value;
}

int da_get(const DynArray *arr, size_t index) {
    if (index >= arr->size) {
        fprintf(stderr, "Index out of range\n");
        exit(1);
    }
    return arr->data[index];
}

void da_free(DynArray *arr) {
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

