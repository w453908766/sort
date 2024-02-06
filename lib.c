
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int arr[1 << 28];

void swap(int *a, int *b) {
  int c;
  c = *a;
  *a = *b;
  *b = c;
}

int condswap(int *a, int *b) {
  if (*a <= *b) {
    return 0;
  } else {
    swap(a, b);
    return 1;
  }
}

int order(int *arr, int n) {
  for (int i = 0; i + 1 < n; i++) {
    if (arr[i] > arr[i + 1]) {
      return 0;
    }
  }
  return 1;
}

void makearr(int *a, int n) {
  for (int i = 0; i < n; i++) {
    a[i] = rand() % (1 << 30lu);
  }
}

void putx(int x) { printf("%d\n", x); }

void putarr(int *a, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

uint64_t getClockTime() {
  struct timespec t;
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t);
  // return ms
  return t.tv_sec * 1000 + t.tv_nsec / 1000000;
}

void rate(char *name, void (*f)(int *, int), int n) {
  makearr(arr, n);
  uint64_t start = getClockTime();
  f(arr, n);
  uint64_t end = getClockTime();
  if(order(arr, n)){
    printf("%s %lu\n", name, end - start);
  } else {
    printf("%s sort err\n", name);
  }
}
