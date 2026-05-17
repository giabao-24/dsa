#include<iostream>
#include<stack>
using namespace std;
void daoNguoc(int arr[],int n,stack<int>st) {
   for(int i = 0;i < n;i++) {
    st.push(arr[i]);
   }
   for(int i = 0;i < n;i++) {
     arr[i] = st.top();
     st.pop();
   }
   for(int i = 0;i < n;i++) {
    cout << arr[i] << " ";
   }
}
void demCapNghichDao(int arr[],int n) {
  int count = 0;
  for(int i = 0;i < n-1;i++) {
    for(int j = i;j < n;j++) {
      if(arr[i] > arr[j]) {
        count++;
      }
    }
  }
  cout << count << " " << endl;
}
int main() {
  stack<int>st;
  int n;
  cin >> n;
  int arr[n];
  for(int i = 0;i < n;i++) {
    cin >> arr[i];
  }
  daoNguoc(arr,n,st);
  demCapNghichDao(arr,n);


  return 0;
}