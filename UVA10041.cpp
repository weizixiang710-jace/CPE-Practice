

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int test_cases;
    cin >> test_cases;
    
    while (test_cases--) {
        int r;
        cin >> r;
        vector<int> streets(r);
        
        for (int i = 0; i < r; i++) {
            cin >> streets[i];
        }
        
        // 關鍵步驟：排序以尋找中位數
        sort(streets.begin(), streets.end());
        int median = streets[r / 2];
        
        // 計算總距離
        int total_distance = 0;
        for (int i = 0; i < r; i++) {
            total_distance += abs(streets[i] - median);
        }
        
        cout << total_distance << endl;
    }
    return 0;
}
