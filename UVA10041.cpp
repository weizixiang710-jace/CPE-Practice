/**
題目翻譯：

世界知名的黑幫 Vito Deadstone 要搬到紐約了。他在那邊有個大家族，他們全部都住在 Lamafia 大街上。
因為他時常要拜訪他所有的親戚，所以他想要找一間離他們很近的房子。
Vito 想最小化與他們的距離和，然後還威脅你要寫個程式幫他解決這個問題。

Input
The input consists of several test cases. The first line contains the number of test cases.
For each test case you will be given the integer number of relatives r (0 < r < 500) and the
street numbers (also integers) s1, s2, . . . , si
, . . . , sr where they live (0 < si < 30000 ). Note that several
relatives could live in the same street number.

Output
For each test case your program must write the minimal sum of distances from the optimal Vito’s house
to each one of his relatives. The distance between two street numbers si and sj is dij = |si − sj |.**/


#include <bits/stdc++.h> 
/** 「一鍵打包」C++ 所有常用的標準函式庫（像是 iostream, vector, algorithm 等），讓你不用一條一條分開寫
     缺點： 因為一次載入太多東西，編譯時間會稍微變長，且不是所有編譯器（如微軟的 MSVC）都預設支援。**/

using namespace std;

int main(){
    int T;
    cin >> T;
    
    while (T--){
        int r;
        cin >> r;
      /**r不是一個數字而已他是由使用者去決定數量的 
      因為vector <int> s(r);讓他變成一個陣列**/
      //例如: 2 2 4
        
        vector <int> s(r);
        //準備一個可以裝 r 個整數的s抽屜（陣列）。
        for (int i = 0; i < r; ++i){
        //從第 0 個抽屜開始，一個一個走到第 r-1 個抽屜。
            cin >> s[i];
        //把使用者輸入的數字放進當前的抽屜裡。
        }
        
        sort(s.begin(), s.end());//把陣列 s 裡面所有的數字，由小到大（升冪）重新排好
        
        int median = s[r/2];
      //因為前面已經排好序，所以直接取正中間位置的數字作為中位數。
      //這裡的r不是使用者輸入的每個個數 而是一開始輸入的總數r 
      
        int result = 0;
        
        for (int i = 0; i < r; ++i){
            result += abs(median - s[i]);
          //abs 是絕對值。這行在計算「中位數」與「第 i 個數字」之間的距離（保證是正數）
        }
        
        cout << result << '\n';//印出最後的總距離，並換行（\n 比 endl 快）
    }
    return 0;
}
