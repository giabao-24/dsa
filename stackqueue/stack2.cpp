#include<iostream>
#include<stack>
using namespace std;
int main() {
  stack<int>st;
   int n;
   cin >> n;
   int a[n];
   for(int i = 0;i < n;i++) {
    cin >> a[i];
   }
   for(int i = 0;i < n;i++) {
     if(st.empty()) {
      st.push(a[i]);
     } else {
      if(st.top() < a[i]) {
         st.pop();
         st.push(a[i]);
      } else {
        st.push(a[i]);
      }
     }
   }
   while (!st.empty())
   {
    cout << st.top() << " ";
    st.pop();
    /* code */
   }
   

  return 0;
}