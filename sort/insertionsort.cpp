#include<iostream>
using namespace std;

void insertionSort(int a[], int n) { // 1 0 3 2 // 0 1 3 2 // 0 1 3 2 // 0 1 2 3 
    for(int i = 1; i < n; i++) { //i = 1 => i = 2 => i = 3 stop because i = 3 is max index of array
        int key = a[i]; //temp = 0(value) => temp = 3(value) => temp = 2 
        int j = i - 1; // j = 0(pos) => j = 1(pos) => j = 2(pos)
        while(j >= 0 && a[j] > key) {
            a[j + 1] = a[j]; //a[j+1(1)] == 1 replace value 0 => a[2] = 1 < key = 3 (no replace because it's true) => 
            j--;   // a[j+1(3)] == 3 > key = 2 replace 
        }
        a[j + 1] = key; // a[j+1] == 0 true => a[j+1] = 2
    }  
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    insertionSort(a, n);

    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
