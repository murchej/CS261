#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

struct dynarray{
    void** data;
    int size;
    int capacity;
};


struct dynarray* dyn_create(){
    struct dynarray* arr = malloc(sizeof(struct dynarray));
    
    arr->data = malloc (8* sizeof (void*));
    arr->size = 0;
    arr->capacity = 8;
    return arr;
}

void dyn_free(struct dynarray* da){
 
   free(da->data);
    free(da);
}

int compare_ints(void* x, void* y){
    int* a = x, *b = y;
    return *a > *b ? 1 : 0;
}


void dyn_sort(struct dynarray* da, int(*cmp)(void*, void*)){
    int i = 0, j = 0, id_temp = 0, score_temp = 0;
    for (i = 0; i < da->size; i++){
        for (j = i+1; j < da->size; j++){
            if (cmp(da->data[i], da->data[j])){

                void* temp = da->data[i];
                da->data[i] = da->data[j];
                da->data[j] = temp;
            }
        }
    }
    return;
}

void dyn_print(struct dynarray *da, void(*prt)(int, void**)){
    prt(da->size, da->data);
}

void print_ints(int size, void** data){
    int**temp = (int**)data;
    for (int i = 0; i < size; ++i)
    {
        printf("%d\t", *temp[i]);
    }
    printf("\n");

    
}

void dyn_insert(struct dynarray *da, void* val){
    if(da->size < da->capacity){
        da->size++;
        da->data[da->size-1] = val;
    }
}


int main()
{
    int *a, n = 8, i;

    struct dynarray *da = dyn_create(); 

    int* temp = malloc(n * sizeof(int));

    for (i = 0; i < n; i++){
        temp[i] = n-i;
        dyn_insert(da, (void*) &temp[i]);
    }
    
    printf("before sorting: \n");
    dyn_print(da, print_ints);


    dyn_sort(da, compare_ints);
    
    printf("sort ascending: \n");
    dyn_print(da, print_ints);

    free(temp);
    
    dyn_free(da);
    return 0;
}
