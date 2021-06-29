#include <iostream>

using namespace std;
#define MAX INT_MAX

void print(int n);
int factorial(int n);

int main()
{
    print(factorial(1));
    print(factorial(2));
    print(factorial(3));
}

void print(int n)
{
    cout << n << endl;
}

int factorial(int n)
{
    int dp[11];

    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1] * i;
    }
    return dp[n];
}