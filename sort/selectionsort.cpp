#include<iostream>
using namespace std;
//Ý tưởng:-Chọn phần tử nhỏ nhất trong mảng và hoán đổi nó với phần tử đầu tiên của mảng,
// sau đó chọn phần tử nhỏ nhất còn lại và hoán đổi nó với phần tử thứ hai của mảng, 
//và tiếp tục như vậy cho đến khi toàn bộ mảng được sắp xếp.
void selection_sort(int n,int a[]) {
   for(int i = 0;i < n-1;i++) {
    int min_pos = i;
    for(int j = i+1;j < n;j++) {
      if(a[j] < a[min_pos]) {
        min_pos = j;
      }
    }
    swap(a[i],a[min_pos]);
   }
}
int main() {
     int n;
     cin >> n;
     int a[n];
     for(int i = 0;i < n;i++) {
      cin >> a[i];
     }
     selection_sort(n,a);
     for(int i = 0;i < n;i++) {
      cout << a[i] << " ";
     }



  return 0;
}