#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// 定義最大數量
const int MAXN = 100;

vector<int> graph[MAXN];  // 存儲圖
int match[MAXN];  // 配對結果
bool visited[MAXN];

// 匈牙利算法的 DFS，嘗試為 u 找到匹配
bool bpm(int u) {
    for (int v : graph[u]) {
        if (!visited[v]) {
            visited[v] = true;
            // 如果 v 還沒有匹配，或是 v 原來的匹配對象可以找到其他匹配
            if (match[v] == -1 || bpm(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

// 主函數：計算最大匹配
int maxBPM(int N1, int N2) {
    // 初始化匹配結果
    memset(match, -1, sizeof(match));
    int result = 0;
    
    // 嘗試為每一個眼睛保健營養品找到匹配
    for (int u = 0; u < N1; u++) {
        memset(visited, false, sizeof(visited));
        if (bpm(u)) {
            result++;
        }
    }
    
    return result;
}

int main() {
    int N1, N2, M;
    cin >> N1 >> N2 >> M;  // 讀取 N1, N2, M
    
    // 讀取不能同時服用的組合
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--;  // 調整為從 0 開始的索引
        y--;
        graph[x].push_back(y);  // 建立 x 到 y 的邊
    }

    // 計算最大匹配
    int max_pairs = maxBPM(N1, N2);
    
    // 輸出結果
    cout << N1 + N2 - max_pairs << endl;
    
    return 0;
}
