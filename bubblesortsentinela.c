#include <stdio.h>
// stable and adaptive
// O(n^2) 
void swap(int *x, int *y) {
  int t = *x;
  *x = *y;
  *y = t;
}

void bubbleSort(int A[], int n) {
  int flag;

  for (int i = 0; i<n-1; i++) {
    flag = 0;

    for(int j = 0; j<n-1-i; j++) {
      if (A[j] > A[j+1]){

        swap(&A[j], &A[j+1]);
        flag = 1;
      }
    }
    // if it didn't make any swap the array is already sorted so it breaks the for loop (i)
    if (!flag) {
      break;
    }
  }
}

int main () {
  int A[] = {2, 1, 8, 3, 4, 7, 6, 5};

  bubbleSort(A, 8);

  for (int i = 0; i<8; i++) {
    printf("%d ", A[i]);
  }

  return 0;
}