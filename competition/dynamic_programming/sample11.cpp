
// C++ Implemenatation of the above approach
#include <iostream>
#include <set>

using namespace std;
 
int nthUglyNumber(int n)
{
    // Base cases...
    if (n == 1 || n == 2 || n == 3 || n == 4 || n == 5)
        return n;
 
    set<long long int> s;
    s.insert(1);
    n--;
 
    while (n) {
        auto it = s.begin();
 
        // Get the beginning element of the set
        long long int x = *it;
 
        // Deleting the ith element
        s.erase(it);
 
        // Inserting all the other options
        s.insert(x * 2);
        s.insert(x * 3);
        s.insert(x * 5);
        n--;
    }
 
    // The top of the set represents the nth ugly number
    return *s.begin();
}
 
// Driver Code
int main()
{
    int n = 150;
 
    // Function call
    cout << nthUglyNumber(n);
}