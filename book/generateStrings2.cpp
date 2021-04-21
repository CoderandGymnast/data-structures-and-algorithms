#include <stdio.h>
#include <stdlib.h>

void print();
void process(int n,int k);

int N=2;
int K=2;

int*A=(int*)malloc(N*sizeof(int));

int main() {
	process(-1,K);
}

void print() {
	for(int i=0;i<N;i++){
		printf("%d",A[i]);
	}
	printf("\n");
}

void process(int n,int k) {
	if(n>=N-1) print();
	else {
		for(int i=0;i<k;i++){
			A[n+1]=i;
			process(n+1,k);
		}
	}
}

// 1. Define base case (Non-recursive case).
// 2. Create all possible solution for the first (0) place. For each possible place, recall the function.
