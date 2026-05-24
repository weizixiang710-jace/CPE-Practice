/**
Input
The input will consist of a series of pairs of integers i and j, 
one pair of integers per line. All integerswill be less than 10,000 and greater than 0.
輸入將由一系列整數對 i 和 j 組成，每行一對整數。所有整數 都將小於 10,000 且大於 0。

You should process all pairs of integers and for each pair deter 
mine the maximum cycle length overall integers between and including i and j.
你應該處理所有的整數對，並針對每一對整數，確定在所有 介於 i 和 j 之間（且包含 i 和 j）
的整數之中的最大循環長度。

You can assume that no operation overflows a 32-bit integer.
你可以假設沒有任何運算會超出 32 位元整數的溢位範圍。
-------------------------------------------------------------------------------
Output
For each pair of input integers i and j you should output i, j, 
and the maximum cycle length for integers between and including i and j.
對於每對輸入整數 i 和 j，你應該輸出 i、j，以及介於 i 和 j 之間（且包含 i 和 j)的整數的最大循環長度。

These three numbers should be separated by at least one space with all
three numbers on one line and with one line of output for each line of input. 
這三個數字應該用至少一個空格隔開，且所有三個數字都要在同一行，且每行輸入對應一行輸出。

The integers i and j mustappear in the output in the same order in which they appeared
in the input and should be followed by the maximum cycle length (on the same line).
整數 i 和 j 必須以它們在輸入中出現的相同順序出現在輸出中，並且其後應該緊接著
最大循環長度（在同一行上）。

**/


#include <bits/stdc++.h>

using namespace std;
/**
int getCycleLength(int n)
  這是一個計數器 將下面程式碼回傳的值去做全部的計算
  比較特別的是 下面的值是i 這裡的值卻是n 那是因為 "參數傳遞" 
  
  甚麼是 "參數傳遞"
  電腦其實是把 i 裡面的數值（也就是 6）複製一份，然後像外送一樣 
  把這個 6 送進 getCycleLength 函式的門口getCycleLength(int n) 門口的警衛看到外送送來了 6
  就會立刻在自己的地盤宣告一個名字叫 n 的整數變數，並且把 6 填進去
  **/
int getCycleLength(int n){
    int count = 1;
  //count也是計數器 是用來記錄數字的被計算次數
    while (n != 1){
      /**
      因為題目說 所有整數都必須小於 10,000 且大於 0
      **/
        if (n % 2 == 1) n = 3 * n + 1;
        else n /= 2;
        count++;
      /**
      這是整個計算公式
      在這裡要注意的是count會無條件的加一
      除了遇到等於一的條件 他會一直加
      **/
    }
    return count;
  /**
  先說說這個return count的功能
  只要一執行到 return，這個函式就會立刻結束 後面的程式碼就算有寫也不會跑了
  直接把控制權交回給 main
  
  很重要的是這裡回傳的值 是直接回至 cyle_length
  **/
}

int main(){
    int i, j;
    while (cin >> i >> j){
        int from = min(i, j);
      /**
         因為題目沒有說ij誰一定是最大最小 
         所以要用這兩個去判斷誰是最大最小 與之前的sort(s.begin(), s.end());不同
         這次是兩數去進行比較 而sort是用一串數字去做排序
      **/
        int to = max(i, j);
        int max_cycle = 0;
        for (int i = from; i <= to; ++i){
          //最小到最大
            int cycle_length = getCycleLength(i);
            if (cycle_length > max_cycle) max_cycle = cycle_length;
          /**
          因為這是一個循環所以要一直疊加 一直疊加 
          int max_cycle = 0; 他不太像計數器 更像是一個容器去裝下新的物品 直到裝到最大值
          **/
        }
        cout << i << " " << j << " " << max_cycle << '\n';
    }
    return 0;
}
