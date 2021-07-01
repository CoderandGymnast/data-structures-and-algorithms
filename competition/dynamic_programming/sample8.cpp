#include <iostream>

using namespace std;

bool isUgly(int n,int p); 
int main(int argc, char *argv[]) {
    int num = atoi(argv[1]);
cout << isUgly(num,2) << endl;
}

bool isUgly(int n,int p) {
    if(n==1) return true;
int primeFactors[3]={2,3,5};
bool ans=n%p?false:true;
if(ans){
    n=n/p;
    ans=ans||isUgly(n,p);
}

for(int i:primeFactors){
    if(i!=p)
    ans=ans||isUgly(n,i);
}
return ans;
}