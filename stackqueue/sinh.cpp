#include<iostream>
using namespace std;
//khoi tao cau hinh dau tien
//while(khi chua phai cuoi cung)
// <in ra cau hinh hien tai>
// <sinh ra cau hinh tiep theo>
int n,a[100],ok;
void ktao() {
  for(int i = 1;i <= n;i++) {
    a[i] = 0;
  }
}
// 1 1 1 // 1 1 0 // 1 0 0
void sinh() {
  //bat dau tu bit cuoi cung
  int i = n;
  while(i >= 1 && a[i] == 1) {
      a[i] = 0;
      i--;
  }
  if(i == 0) {
    ok = 0; //la cau hinh cuoi cung
  } else {
    a[i] = 1;
  }
}
int main() {
    cin >> n;
    ok = 1;
    ktao();
    while(ok) {
      for(int i = 1;i <= n;i++) {
        cout << a[i];
      }
      cout << endl;
      sinh();
    }

  return 0;
}