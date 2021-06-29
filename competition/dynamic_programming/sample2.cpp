#include <iostream>

using namespace std;
int dp[10];
void print(int n); 
int factorial(int n); 
int main() {
for(int i=10;i>=0;--i){
    print(factorial(i));    
}

}
void print(int n) {
    cout << n << endl;
}
int factorial(int n) {
    if(n==0) return 1;
    if(dp[n])return dp[n];

    dp[n]=n*factorial(n-1);
    return dp[n];
}