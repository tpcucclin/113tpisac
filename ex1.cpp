#include <iostream>
#include <vector>

using namespace std;

// 函數：找到冠軍學徒的編號
int find_champion(int N, int S, int K) {
    // 初始化學徒編號和淘汰次數
    vector<int> students(N); // 學徒編號從 1 到 N
    vector<int> elimination_count(N, 0); // 每個學徒的淘汰次數，初始為 0
    
    for (int i = 0; i < N; i++) {
        students[i] = i + 1;  // 學徒編號為 1 到 N
    }
    
    int current_index = 0;  // 開始的位置

    // 模擬淘汰過程
    while (students.size() > 1) { // 當學徒人數大於1時，繼續進行遊戲
        // 找到要淘汰的學徒，經過 S-1 個學徒之後
        current_index = (current_index + S - 1) % students.size();
        int eliminated_student = students[current_index];
        
        // 增加該學徒的淘汰次數
        elimination_count[eliminated_student - 1] += 1;
        
        // 檢查該學徒是否達到淘汰次數 K 次
        if (elimination_count[eliminated_student - 1] >= K) {
            // 永久移除該學徒
            students.erase(students.begin() + current_index);
        } else {
            // 如果還沒達到 K 次淘汰，移動到下一個學徒
            current_index = (current_index + 1) % students.size();
        }
    }
    
    // 返回剩下的唯一一個學徒，也就是冠軍
    return students[0];
}

int main() {
    int N = 5;  // 學徒數量
    int S = 3;  // 每次 S 個咒語
    int K = 2;  // 淘汰次數

    int champion = find_champion(N, S, K);
    cout << "冠軍學徒的編號是：" << champion << endl;

    return 0;
}
