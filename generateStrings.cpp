#include <stdio.h>
#include <stdlib.h>

int N=2;
int K=2;

int* A = (int*) malloc(N*sizeof(int));

void print();
void process(int n, int k);

int main() {
	process(N, K);
}

void print() {
	for (int i = 0; i < N; i++){
		printf("%d", A[i]);
	}
	printf("\n");
}

void process(int n, int k) {
	if(n<1) print();
	else{
		for (int i=0;i<k;i++){
			A[n-1]=i;
			process(n-1,k);
		}
	}
}
