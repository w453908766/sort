
#include "arr.h"

int less(int x, int y) { return x < y; }

int more(int x, int y) { return x > y; }

typedef int (*CMPT)(int, int);

void heapadjust(int *arr, int n, int i, CMPT cmp) {
  // tt++;
  while (1) {
    int cmpest = i;
    int l = 2 * i + 1;
    int r = l + 1;
    if (l < n && cmp(arr[l], arr[cmpest]))
      cmpest = l;
    if (r < n && cmp(arr[r], arr[cmpest]))
      cmpest = r;

    if (cmpest == i) {
      return;
    } else {
      swap(&arr[i], &arr[cmpest]);
      i = cmpest;
    }
  }
}

void makeheap(int *arr, int n, CMPT cmp) {
  int i = (n + 1) / 2 + 1;
  while (i >= 0) {
    heapadjust(arr, n, i, cmp);
    i = i - 1;
  }
}

void heapsort(int *arr, int n) {
  makeheap(arr, n, more);
  while (n > 1) {
    swap(&arr[0], &arr[n - 1]);
    heapadjust(arr, n - 1, 0, more);
    n = n - 1;
  }
}
