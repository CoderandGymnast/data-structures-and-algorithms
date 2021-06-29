#include <iostream>

using namespace std;

int fib(int i);
int main() {
for(int i=0;i<10;i++){
    cout << fib(i)<< " ";
}
}

int fib(int i){
   int a=0;
   int b=1;
   int temp;
   if(i==a)return a;
   if(i==b)return b;
   for(int c=2;c<=i;++c){
       temp=b;
       b=a+b;
       a=temp;
   } 
   return b;
}