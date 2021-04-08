#include <stdio.h>

void process(int n, char from, char to, char aux);

int main() {
	process(3, 'A', 'C', 'B');	
}

void process(int n, char from, char to, char aux) {
	if(n==1){
		printf("\nMove disk 1 from %c to %c", from, to);
		return;
	}
	
	process(n-1, from, aux, to);
	
	printf("\nMove disk %d from %c to %c", n, from, to);
	process(n-1, aux, to, from);
}



