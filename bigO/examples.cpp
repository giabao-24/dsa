void khoiC(int n, int m) {
    int count = 0;
    
    // Phần 1
    for (int i = 0; i < n; i++) {
        count++;
    }  //O(n) do một vòng for
    
    // Phần 2
    for (int j = 0; j < m; j++) {
        for (int k = 0; k < m; k++) {
            count++;
        }
    } // O(m^2) do T(m) = O(m)*O(m) +  = O(m^2)
    //tong cong la O(m^2+n)  
}

void khoiB(int n) {
    int count = 0;
    for (int i = 1; i < n; i = i * 2) { //bước lặp nhân ở lý thuyết là O(logn)
        for (int j = 0; j < n; j++) { // 1 vòng lặp O(n) vậy nhân lại => Khối này O(nlogn)
            count++; 
        }
    } //Inconclusive T(n) = O(logn)*O(n) + O(logn) = O(nlogn)
}

void khoiA(int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) { 
            count++;
        }
    } //Inconclusive T(n) = O(n)*O(n) + O(n) = O(n^2)
}

//dequi
long long HamB(int n) {
    if (n <= 1) {
        return 1;
    }
    long long temp = HamB(n - 1); //ta thây rõ gọi đệ qui 1 vòng vậy O(n)
    return temp + temp; //in
}
long long HamA(int n) {
    if (n <= 1) {
        return 1;
    }
    return HamA(n - 1) + HamA(n - 1); //gọi 2 lần nên là T(n) = 2 * T(n-1) = O(2^n) 
}

void bai1(int n) {
    int count = 0;
    for (int i = 0; i < n; i++) { //O(n)
        for (int j = 1; j < n; j *= 2) { //vì *=2 nước nhảy nên là O(logn)
            count++;
        }
    }
}

void bai2(int n) {
    if (n <= 0) return;
    
    for (int i = 0; i < n; i++) {
        // Thực hiện một thao tác O(1)
        cout << i << " ";
    }
    
    bai2(n - 1);  //de qui O(n) và 1 vòng for vậy sẽ là O(n^2)
}

int bai3(int n) {
    if (n <= 1) return n;
    
    return bai3(n - 1) + bai3(n - 1); // độ phức tạp O(2^n)
}