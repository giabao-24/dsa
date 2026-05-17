#include<iostream>
using namespace std;
//Mục đích của thuật toán sắp xếp nổi bọt là sắp xếp một mảng bằng 
//cách lặp đi lặp lại qua phần tử của mảng, so sánh từng cặp phần tử liền kề và 
//hoán đổi chúng nếu chúng ở sai thứ tự. Quá trình này được lặp lại cho đến khi không còn
// cặp phần tử nào cần hoán đổi, có nghĩa là mảng đã được sắp xếp.
void sortBubble(int arr[],int size_of_arr) {
  int n = size_of_arr;
  for(int i = 0;i < size_of_arr-1;i++) {
    for(int j = 0;j < size_of_arr - i - 1;j++) {
      if(arr[j] > arr[j+1]) {
        swap(arr[j],arr[j+1]);
      }
    }
  }
}
int main() {
  int arr [] = {1,5,2,10,3,9};
  sortBubble(arr,6);
  for(int c : arr) {
    cout << c << " ";
  }
  /* i = 0
     j = 0 -> j = 6-1-0
     1 2 5 3 9 10
     i = 1
     j = 0 -> j = 6-1-1
     1 2 3 5 9 10
     ....
  
  */


  return 0;
}