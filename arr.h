
#ifndef ARR_H
#define ARR_H

extern int arr[1<<28];

void swap(int* a,int* b);
int condswap(int* a,int* b);
int order(int* arr,int n);
void makearr(int* a,int n);
void putx(int x);
void putarr(int* a,int n);
void rate(char* name, void (*f)(int*, int), int n);

void quicksort(int *a, int n);
void quicksort1(int *a, int n);
void heapsort(int *a, int n);

#endif
