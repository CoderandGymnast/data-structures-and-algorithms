#include <iostream>
#include <set>

using namespace std;

typedef set<pair<int,int>> S;
typedef S::iterator Iter;

int main() {
    S s;
    s.insert(make_pair(0,2));
    s.insert(make_pair(1,1));
    s.insert(make_pair(0,1));
    s.insert(make_pair(1,0));
    s.insert(make_pair(0,0));
    Iter i;
    for(i=s.begin();i!=s.end();++i){
   cout << i->first << " " << i->second << endl; 
    }
}