/* A Naive recursive implementation of LCS problem */
#include <iostream>
#include <cstring>

using namespace std;

int max(int a, int b);
int dp[1000][1000];

void initDP();

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs(char *X, char *Y, int m, int n)
{
    if (dp[m][n] != -1)
        return dp[m][n];

    if (m == 0 || n == 0)
        return 0;
    if (X[m - 1] == Y[n - 1])
    {
        dp[m][n] = 1 + lcs(X, Y, m - 1, n - 1);
        return dp[m][n];
    }
    else
    {

        dp[m][n] = max(lcs(X, Y, m, n - 1), lcs(X, Y, m - 1, n));
        return dp[m][n];
    }
}

/* Utility function to get max of 2 integers */
int max(int a, int b)
{
    return (a > b) ? a : b;
}

/* Driver code */
int main()
{

    initDP();
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);

    cout << "Length of LCS is " << lcs(X, Y, m, n);

    return 0;
}

void initDP()
{
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            dp[i][j] = -1;
        }
    }
}