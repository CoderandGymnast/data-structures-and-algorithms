#include <iostream>

using namespace std;

int factorial(int n);
void print(int n); 

int main() {
   print(factorial(1)); 
   print(factorial(2));
   print(factorial(3));
}

void print(int n) {
    cout << n << endl;
}

int factorial(int n){
    if(n==1)return 1;
    return n*factorial(n-1);
}