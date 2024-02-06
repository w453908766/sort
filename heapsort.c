
#include "arr.h"

void heapadjust(int *a, int n, int i) {
  // tt++;
  while(1){
    int p = i;
    int l = 2 * i + 1;
    int r = l + 1;
    if (l < n) if (a[p] < a[l]) p = l;
    if (r < n) if (a[p] < a[r]) p = r;

    if (p == i) {
      return;
    } else {
      swap(&a[i], &a[p]);
      i = p;
    }
  }
}

void _makeheap(int *a, int n, int i) {
  while (i >= 0) {
    heapadjust(a, n, i);
    i = i - 1;
  }
}

void heapsort(int *a, int n) {
  _makeheap(a, n, ((n) + 1) / 2 + 1);
  while(n>1){
    swap(&a[0], &a[n - 1]);
    heapadjust(a, n - 1, 0);
    n = n - 1;
  }
}
