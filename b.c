#include <stdio.h>
#include <stdlib.h>

// Dinamikus tömb struktúra
typedef struct {
    int *data;
    size_t size;
} DynArray;

// Függvény a dinamikus tömb inicializálásához
void init_dyn_array(DynArray *arr, size_t initial_size) {
    arr->data = (int *)malloc(initial_size * sizeof(int));
    arr->size = 0;
}

// Függvény a dinamikus tömb elem hozzáadásához
void add_to_dyn_array(DynArray *arr, int value) {
    arr->data[arr->size++] = value;
}

// Függvény a dinamikus tömb felszabadításához
void free_dyn_array(DynArray *arr) {
    free(arr->data);
}

// Függvény a számok átlagának kiszámításához
double da_average(const DynArray *self) {
    double sum = 0;
    for (size_t i = 0; i < self->size; ++i) {
        sum += self->data[i];
    }
    return sum / self->size;
}

int main() {
    // Dinamikus tömb inicializálása
    DynArray numbers;
    init_dyn_array(&numbers, 100);

    // Fájl megnyitása olvasásra
    FILE *file = fopen("numbers.txt", "r");
    if (file == NULL) {
        printf("Hiba a fájl megnyitásakor.\n");
        return 1;
    }

    // Fájl beolvasása a dinamikus tömbbe
    int number;
    while (fscanf(file, "%d", &number) == 1) {
        add_to_dyn_array(&numbers, number);
    }

    // Fájl bezárása
    fclose(file);

    // Átlag kiszámítása és kiírása
    double average = da_average(&numbers);
    printf("A számok átlaga: %.2lf\n", average);

    // Dinamikus tömb felszabadítása
    free_dyn_array(&numbers);

    return 0;
}