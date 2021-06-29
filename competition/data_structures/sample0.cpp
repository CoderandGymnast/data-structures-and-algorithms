#include <iostream>
#include <set>
using namespace std;
typedef set<int>::iterator SIter;
int main() {
    set<int> s;
    s.insert(0);
    s.insert(-1);
    s.insert(10);
    s.insert(100);
    SIter i;
    for(i=s.begin();i!=s.end();++i){
        cout << *i << "  ";
    }
}