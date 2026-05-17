#include<iostream>
using namespace std;
//Chia danh sách 2 nửa,sau đó tìm kiếm phần tử ở nửa nào có thể chứa phần tử cần tìm,
//tiếp tục chia nửa đó thành 2 nửa nhỏ hơn và lặp lại quá trình cho đến khi tìm thấy 
//phần tử hoặc không còn phần tử nào để chia nữa.//(chỉ hoạt động trên mảng đã được sắp xếp)
//Độ phức tạp:O(logn) **nhanh
int binarySearch(int arr[],int n,int target) {
  int left = 0;
  int  right = n - 1;
  while(left <= right) {
    int mid = (left+right)/2;
    if(arr[mid] == target) {
      return mid;
    }
    else if(arr[mid] < target) {
      left = mid + 1;
    }
    else {
      right = mid - 1;
    }
  }
  return -1; //nếu không tìm thấy phần tử
}
int main() {
  int arr[] = {1,2,3,4,5,6,7,8,9};
  int target = 1;
  int n = 9;
  int result = binarySearch(arr,n,target);
  if(result != -1) {
    cout << "Element found at index: " << result << endl;
  }
  else {
    cout << "Element not found in the array." << endl;
  }


  return 0;
}