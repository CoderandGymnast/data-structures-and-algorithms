#include <iostream>
using namespace std;
int search(int arr[], int target, int len);
void print(int arr[],int len); 
int main()
{
    int arr[]={1,3,5,7,9};
   int i=search(arr,9,sizeof(arr)/sizeof(int)); 
cout << i << endl;
}
void print(int arr[],int len) {
    for(int i=0;i<len;i++) {
        cout << arr[i] << " ";
    }
}
int search(int arr[], int target, int len)
{
    int l = 0;
    int r = len - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (target < arr[mid])
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}