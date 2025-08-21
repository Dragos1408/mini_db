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
}

void da_save(const DynArray *arr, const char *filename){
	FILE *file = fopen(filename, "wb");
	if(!file){
		perror("Error openin file");
		return;
}
	fwrite(&arr->size, sizeof(size_t), 1 ,file);
	fwrite(arr->data, sizeof(int), arr->size, file);
	fclose(file);
}

void da_load(DynArray *arr, const char *filename){
	FILE *file= fopen(filename, "rb");
	if(!file){
		perror("Error opening file");
		return;
}
	fread(&arr->size, sizeof(size_t), 1, file);
	arr->capacity = arr->size;
	arr->data = malloc(arr->capacity * sizeof(int));
	fread(arr->data, sizeof(int), arr->size, file);
	fclose(file);
}

void da_save_text(const DynArray *arr, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file");
        return;
    }
    fprintf(file, "%zu\n", arr->size);  // Save size as text
    for (size_t i = 0; i < arr->size; i++) {
        fprintf(file, "%d\n", arr->data[i]);  // Save each int as text
    }
    fclose(file);
}

void da_load_text(DynArray *arr, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }
    fscanf(file, "%zu", &arr->size);
    arr->capacity = arr->size;
    arr->data = malloc(arr->capacity * sizeof(int));
    for (size_t i = 0; i < arr->size; i++) {
        fscanf(file, "%d", &arr->data[i]);
    }
    fclose(file);
}

