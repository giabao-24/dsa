#include<iostream>
using namespace std;
int dequi(int m,int n) {
  if(n==0) {
    return m; 
  }
  return dequi(n,m%n);
}
int main() {



  return 0;
}