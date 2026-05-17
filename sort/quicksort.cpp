#include<iostream>
using namespace std;
//Time complexity: O(nlogn) in average and best case, O(n^2) in worst case
//Space complexity: O(logn) in average and best case, O(n) in worst case
//Explanation: -First step: We choose a privot element from any position in the array(in this case
//we choose the middle element),
//-Second step: We partition the array into two sub-arrays, one with elements less than
// the privot and the other with elements greater than the privot.
//-Third step: We recursively apply the above steps to the sub-arrays until we
// reach the base case of an array with one or zero elements, which is already sorted.
// Mục tiêu sắp xếp các phần tử nhỏ hơn pivot về bên trái,lớn hơn về bên phải
//,đồng thời đảm bảo rằng pivot nằm ở vị trí đúng của nó trong mảng đã sắp xếp.
//sau đó đệ quy áp dụng thuật toán cho hai phần mảng con bên trái và bên phải của pivot.

void quicksort(int arr[],int low,int high) {
    int privot = arr[(low+high)/2];
    int i = low;
    int j = high;
    //8 3 1 7 0 10 2
    //privot = 7
    //i = 0, j = 6 => 8 > 7 => j = 5 => 2 < 7 => i = 1 => 3 < 7 => i = 2 => 1 < 7 => i = 3 => 7 == 7 => swap(7,2) => i = 4, j = 4

    while(i < j) {
      while(arr[i] < privot) {
        i++;
      }
      while(arr[j] > privot) {
        j--;
      }
      if(i <= j) {
        int temp = arr[i];
			  arr[i] = arr[j];
		   	arr[j] = temp; //an other easy way is swap(arr[i],arr[j]);
		  	i++;
		  	j--;
      }
    }
    if (i < high){
		quicksort(arr, i, high);
	}
	  if (low < j){
		quicksort(arr, low, j);
	}
}
int main() {
  int arr[7] = {8,3,1,7,0,10,2};
  int n = 7;
  quicksort(arr,0,n-1);
  cout << "Sorted array: ";
    for(int k = 0; k < n; k++) {
        cout << arr[k] << " ";
    }
    cout << endl;


  return 0;
}