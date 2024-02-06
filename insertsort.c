
#include "arr.h"

void insert(int *arr, int i) {
  while (i > 0) {
    if (arr[i - 1] < arr[i]) {
      return;
    } else {
      swap(&arr[i - 1], &arr[i]);
      i = i - 1;
    }
  }
}

void insertsort(int *arr, int n) {
  for(int i=1;i<n;i++){
    insert(arr, i);
  }
}
