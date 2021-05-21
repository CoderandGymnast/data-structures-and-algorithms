// #include <stdio.h>

// int isSorted(int A[], int n);

// int main() {
// 	int A[3] = {2,1,3};
// 	printf("%d", isSorted(A,3));
// }

// int isSorted(int A[], int n){
// 	if(n==1) return 1;
// 	return (A[n-1]<A[n-2]?0:isSorted(A, n-1));
// }

#include <stdio.h>
//#include<iostream>

//using namespace std;

int Check(int arr[], int i)
{
	if (i>sizeof(arr)/sizeof(arr[0]))
		return 1;
	return(arr[i]>arr[i+1]?0:Check(arr, i+1));
};

int main(){
	// printf("[FIX BUG]: Sometimes, need to uncomment this line:)");
	int arr1[] = {1,4,3,5,6,2};
	int arr2[] = {1,2,3,4,4,6};
	int ans1 = Check(arr1, 0);
	int ans2 = Check(arr2, 0);
	printf("%d",ans1);
	printf("%d",ans2);
}

// 1. if length of array is 1, the array is sorted.
// 2. else compare the last 2 elements of the array, if they are sorted (ascending or descending),
// check the remain array.
