/**
題目翻譯：

  Hashmat 是個勇敢的戰士，帶領著他的一群年輕士兵，從某地移動到另一個地方與敵人對抗。
  打仗之前他會計算一件事，就是他的士兵數量與敵對士兵數量的差距。這個差距會讓他決定要不要打。
  Hashmat 的士兵數量都不會大於敵對士兵。

  Input
The input contains two numbers in every line. These two numbers in each line denotes the number
soldiers in Hashmat’s army and his opponent’s army or vice versa. The input numbers are not greater
than 2
32. Input is terminated by ‘End of File’.
Output
For each line of input, print the difference of number of soldiers between Hashmat’s army and his
opponent’s army. Each output should be in seperate line
  
 **/


#include <bits/stdc++.h>

using namespace std;

int main(){
    long long h, o;
  /**long long：這是 C++ 的一種資料型態，比一般的 int 能容納更大的數字
  （通常最高可達約 $9 \times 10^{18}$，而 int 只能到約 $2 \times 10^9$）。**/
    while (cin >> h >> o){
        cout << abs(h - o) << '\n';
    }
    return 0;
}
