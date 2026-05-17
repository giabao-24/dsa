#include<iostream>
using namespace std;
int dequi(int a) {
  if(a == 0) {
    return 0;
  } 
  return a + dequi(a - 1);
}
int main() {
  int n;
  cin >> n;
  cout << dequi(n);
  return 0;
}