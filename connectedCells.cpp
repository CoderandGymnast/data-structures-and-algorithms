#include <stdio.h>
#include <iostream>

using namespace std;

int getval(int (*A)[5], int i, int j, int L, int H) {
	if(i<0 || i>=L || j<0 || j>=H)
		return 0;
	else {
		return A[i][j];
	}
}


void findMaxBlock(int (*A)[5], int r, int c, int L, int H, int size, bool **cntarr, int &maxsize){
	if(r>=L || c >=H) // Check index out of bound.
		return;
	cntarr[r][c]=true; // Mark.
	size++;
	if(size>maxsize)
		maxsize = size;
	int direction[][2]={{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};
	for(int i=0; i<8; i++) {
		int newi = r+direction[i][0];
		int newj = c+direction[i][1];
		int val = getval(A, newi, newj, L, H); // Check both in-bound & out-bound
		if(val==1 && (cntarr[newi][newj]==false)){ // Avoid reconsidering.
			findMaxBlock(A, newi, newj, L, H, size, cntarr, maxsize);
		}
	}
	cntarr[r][c]=false;
}


bool** create2darr(int rmax, int colmax) { // Initialization.		
		bool **mat = new bool*[rmax];
		for(int i = 0; i < rmax; i++) mat[i] = new bool[colmax];
		return mat;
}


int getMaxOnes(int (*A)[5], int rmax, int colmax) { // (*A)[5]==A[5][5]; rmax, colmax: sizes.
	int maxsize = 0; // "Global" inside getMaxOnes.
	int size = 0; // Size of current connected cluster.
	bool **cntarr = create2darr(rmax, colmax); // Tracking: ~ cntarr[rmax][colmax] - declaration
	for(int i=0; i<rmax; i++){
		for(int j=0; j<colmax; j++){
			if(A[i][j] == 1){
				findMaxBlock(A, i, j, rmax, colmax, 0, cntarr, maxsize); // reset: size=0.
			}
		}
	}
	return maxsize;
}




int main(int argc, char *argv[]) {
	
	int zarr[][5] = {{1,1,0,0,0},{0,1,1,0,0},{0,0,1,0,1},{1,0,0,0,1},{0,1,1,1,1}};
	cout << "Number of maximum 1s are " << getMaxOnes(zarr, 5, 5) << endl;
	
	
}
