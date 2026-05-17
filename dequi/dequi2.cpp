#include<iostream>
using namespace std;
int dequi(int n) {
    if(n == 1) {
      return 1;
    }
    return dequi(n - 1) + 2*n;
}
/*
f=5,f4,f3,f2,f1 2*5+2*4+2*3+2*2+1
*/ 
int main() {
 int n;
 cin >> n;
 cout << dequi(n);



  return 0;
}
