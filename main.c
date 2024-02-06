
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include "arr.h"

int main(int argc, char** argv){
  int exp;
  if(argc == 1){
    printf("please give exp\n");
    exit(1);
  }
  sscanf(argv[1], "%d", &exp);
  int n = 1<<exp;

  rate("quicksort", quicksort, n);
  rate("heapsort", heapsort, n);
  return 0;
}
