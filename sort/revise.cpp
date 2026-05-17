#include<iostream>
using namespace std;
void binarySearch (int a[],int n,int target) {
    int left = 0;
    int right = n-1;
    while(left <= right) {
    int mid = (left+right)/2;
    if(a[mid] == target) {
      cout << "Found at " << mid;
      return;
    }
    if(a[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
    }
    cout << "Not found";
}
int main() {
  int n = 7;
  int a[n] = {1,2,3,4,5,6,7};
  binarySearch(a,n,3);


  return 0;
}