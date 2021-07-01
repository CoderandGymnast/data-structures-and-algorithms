// C++ Implemenatation of the above approach
#include <iostream>
#include <set>

using namespace std;
typedef set<long long int>::iterator Iter;

void print(set<long long int> s) {
    Iter i;
for(i=s.begin();i!=s.end();i++) {
    cout << *i << endl;
}
}

int nthUglyNumber(int n)
{
    // Base cases...
     if (n == 1 || n == 2 || n == 3 || n == 4 || n == 5)
        return n;
 
    set<long long int> s;
    s.insert(1);
    n--;
print(s);
cout << endl; 
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
        print(s);
        cout << "n" << n << endl;
        return 0;
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