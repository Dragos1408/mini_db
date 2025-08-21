#ifndef DYNARRAY_H
#define DYNARRAY_H

#include <stddef.h>  // for size_t

typedef struct {
    int *data;       // pointer to the array
    size_t size;     // number of elements stored
    size_t capacity; // allocated space
} DynArray;

void da_init(DynArray *arr);
void da_push(DynArray *arr, int value);
int da_get(const DynArray *arr, size_t index);
void da_free(DynArray *arr);
void da_save(const DynArray *arr, const char *filename);
void da_load(DynArray *arr, const char *filename);

//Added text load and save
void da_save_text(const DynArray *arr, const char *filename);
void da_load_text(DynArray *arr, const char *filename);

#endif

