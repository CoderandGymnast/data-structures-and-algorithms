#include <stdio.h>
#include <stdlib.h>

int N = 1;
int* A = (int*) malloc(N*sizeof(int)); 

void process(int n);
void print(int* A, int n);

int main() {
	process(N);	
}

void process(int n) {
	if(n<1) print(A, N);
	else {
		A[n-1]=0;
		process(n-1);
		A[n-1]=1;
		process(n-1);
	}
}

void print(int* A, int n) {
	for(int i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}
