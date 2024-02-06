
#include "arr.h"

void insert(int *arr, int i, int s) {
  if (i == 0)
    return;
  else if (arr[s * (i - 1)] < arr[s * i])
    return;
  else {
    swap(&arr[s * (i - 1)], &arr[s * i]);
    insert(arr, i - 1, s);
  }
}
void insertsort(int *arr, int n, int i, int s) {
  if (i == n)
    return;
  else {
    insert(arr, i, s);
    insertsort(arr, n, i + 1, s);
  }
}

void shellsort(int *arr, int n, int s) {
  if (n > 1) {
    shellsort(arr, n - n / 2, 2 * s);
    shellsort(arr + s, n / 2, 2 * s);
    insertsort(arr, n, 0, s);
  }
}