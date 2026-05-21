#include <bits/stdc++.h>

using namespace std;

int main(){
    
    long long n1, n2;
    
    while (cin >> n1 >> n2 && (n1 || n2)){
    //第一層會先做第一次 是否為0的判斷 主要是針對接收新的數字 新題目直到接收到 00

        int carry = 0, operation = 0;
     //carry=進位的數字 並且參與計算到下一位 
     //opertion=這裡是設定成一個計數器 計算最後多少次
        
        while (n1 > 0 || n2 > 0){
        //第二層做計算過程 與第一層做著完全不一樣的內容
            int digit_1 = n1 % 10, digit_2 = n2 % 10;
        //先處理個位數字
            
            int sum = digit_1 + digit_2 + carry;
        //將個位數字全數加起來 這裡要注意的是上面有說過的要將carry加入去做計算
            
            sum >= 10 ? carry = 1, operation++ : carry = 0;
        //這裡就是簡單的if else簡化版本 
        //如果大於10會進位 所以計步器增加
            n1 /= 10, n2 /= 10;
        /**把數字轉換成十位數字 雙位數 
            例如:430-->43
            轉換後就繼續迴圈直到變成00
        **/
        
        }
        
        if (operation){
        //利用程式語言的0否1是的方式去做判斷 如果計數器等於0 直接跳到else
            cout << operation << (operation > 1 ? " carry operations." : " carry operation.");
        //去判斷是單數還是複數
        }
        else{
            cout << "No carry operation.";
        }
        
        cout << '\n';
        
    }
    return 0;
}
