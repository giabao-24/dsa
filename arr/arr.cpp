#include<iostream>
#include<algorithm>
using namespace std;
bool checkPalindrome(int arr[]) {
   for(int i = 0;i < 5/2;i++) {
    if(arr[i] != arr[5-i-1]) {
      return false;
    }
   }
   return true;
}
bool recusion(int arr[],int start,int end) {
  if(start >= end) {
    return true;
  }
  if(arr[start] != arr[end]) {
    return false;
  }
  return recusion(arr,start+1,end-1);
}
int main() {
   int arr [] = {1,2,3,2,1};
   cout << recusion(arr,0,5-1);


  return 0;
}