
#include "arr.h"

int *partition(int *, int, int);
int *partition1(int *a, int n, int x) {
  if (n == 1) {
    a[0] = x;
    return a;
  } else if (a[0] <= x)
    return partition1(a + 1, n - 1, x);
  else {
    a[n - 1] = a[0];
    return partition(a, n - 1, x);
  }
}
int *partition(int *a, int n, int x) {
  if (n == 1) {
    a[0] = x;
    return a;
  } else if (a[n - 1] >= x)
    return partition(a, n - 1, x);
  else {
    a[0] = a[n - 1];
    return partition1(a + 1, n - 1, x);
  }
}
void quicksort(int *a, int n) {
  int i;
  if (n > 1) {
    i = partition(a, n, a[0]) - a;
    quicksort(a, i);
    quicksort(a + i + 1, n - i - 1);
  }
}
/*
int* part1(int* a,int n,int x){
        if(n==1){a[0]=x;return a;}
        else if(_cmp(a[0],x)<=0)return part1(a+1,n-1,x);
        else{
                a[n-1]=a[0];
                a[0]=a[n-2];
                return part1(a,n-1,x);
        }
}*/

int *part1(int *a, int n, int x) {
  while (1) {
    if (n == 1) {
      a[0] = x;
      return a;
    } else if (a[0] <= x) {
      a = a + 1;
      n = n - 1;
    } else {
      a[n - 1] = a[0];
      a[0] = a[n - 2];
      n = n - 1;
    }
  }
}

void quicksort1(int *a, int n) {
  int i;
  if (n > 1) {

    i = part1(a, n, a[n - 1]) - a;
    quicksort1(a, i);
    quicksort1(a + i + 1, n - i - 1);
  }
}