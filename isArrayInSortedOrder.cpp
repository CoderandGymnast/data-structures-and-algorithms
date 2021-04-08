#include <stdio.h>

int isSorted(int A[], int n);

int main() {
	int A[3] = {2,1,3};
	printf("%d", isSorted(A,3));
}

int isSorted(int A[], int n){
	if(n==1) return 1;
	return (A[n-1]<A[n-2]?0:isSorted(A, n-1));
}

// 1. if length of array is 1, the array is sorted.
// 2. else compare the last 2 elements of the array, if they are sorted (ascending or descending),
// check the remain array.
