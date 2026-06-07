/**
"Input"
The input consists of several test cases. The first line contains the number of test cases.
輸入包含數個測試資料集（test cases）。第一行包含測試資料集的數量

For each test case you will be given the integer number of relatives r (0 < r < 500) and the
street numbers (also integers) s1, s2, . . . , si, . . . , sr where they live (0 < si < 30000 ). 
對於每個測試資料集，您將會得到一個代表親戚數量的整數 r 以及他們所居住的街道門牌號碼（亦為整數）

Note that several relatives could live in the same street number.
請注意，可能會有數個親戚住在同一個街道門牌號碼。

"Output"
For each test case your program must write the minimal sum of distances from the optimal Vito’s house
to each one of his relatives.
對於每個測試資料集，您的程式必須寫出（輸出）從 Vito 最理想的家，到他每一個親戚家的最小距離總和

The distance between two street numbers si and sj is dij = |si − sj |.
兩個街道門牌號碼 s_i 與 s_j 之間的距離為

題目核心主要是由三個部分所組成
第一個 總專案數量 總迴圈次數
第二個 親戚的數量 一次測試有幾個個數 
第三個 街道號碼   個數分別是多少

**/


#include <bits/stdc++.h> 
/** 「一鍵打包」C++ 所有常用的標準函式庫（像是 iostream, vector, algorithm 等），讓你不用一條一條分開寫
     缺點： 因為一次載入太多東西，編譯時間會稍微變長，且不是所有編譯器（如微軟的 MSVC）都預設支援。**/

using namespace std;

int main(){
    int T;
    cin >> T;
    /**
    為甚麼外層會需要一個t 因為:題目要求
    The input consists of several test cases. 
    The first line contains the number of test cases.**/
    while (T--){
        int r;
        cin >> r;
      /**
      For each test case you will be given the integer number of relatives
      r不是一個數字而已他是由使用者去決定數量的 
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
      //這裡的r是使用者輸入的每個個數 而不是一開始輸入的總數r 
     /**
     ex:
       如果r = 5，5 / 2 的結果是 2。因為陣列索引從 0 開始（0, 1, 2, 3, 4），s[2] 
       剛好就是正中間的那一個數。
     **/
      
        int result = 0;
        
        for (int i = 0; i < r; ++i){
            result += abs(median - s[i]);
          //result是會累積相加數的   
          /**abs 是絕對值。這行在計算「中位數」與「第 i 個數字」之間的距離（保證是正數）
          
          s = [1, 3, 7] 的例子:
          第一輪 (i = 0, 點是 1)：
          算出距離是 2。
          result += 2 意思是 result = 0 + 2，所以 result 變成 2。
          
          第二輪 (i = 1, 點是 3)：
          算出距離是 0。
          result += 0 意思是 result = 2 + 0，所以 result 依然是 2。
         （這裡是用舊的 2 去加，沒有被覆蓋喔！）
         
          第三輪 (i = 2, 點是 7)：
          算出距離是 4。
          result += 4 意思是 result = 2 + 4，所以 result 變成 6。
          
          
          **/
        }
        
        cout << result << '\n';//印出最後的總距離，並換行（\n 比 endl 快）
    }
    return 0;
}
