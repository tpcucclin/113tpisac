from collections import defaultdict

# 定義一個二分圖匹配算法
def bpm(graph, u, matchR, seen):
    # 嘗試為 u 配對
    for v in graph[u]:
        if not seen[v]:
            seen[v] = True
            # 如果 v 沒有被配對，或被配對的 u 可以換其他匹配
            if matchR[v] == -1 or bpm(graph, matchR[v], matchR, seen):
                matchR[v] = u
                return True
    return False

def maxBPM(graph, N1, N2):
    # matchR[v] 是與 v 配對的 u，初始值為 -1
    matchR = [-1] * N2
    result = 0
    for u in range(N1):
        # 為每個 u 嘗試配對
        seen = [False] * N2
        if bpm(graph, u, matchR, seen):
            result += 1
    return result

# 讀取輸入
N1, N2, M = map(int, input().split())
graph = defaultdict(list)

# 讀取不能一起服用的組合
for _ in range(M):
    i, j = map(int, input().split())
    graph[i - 1].append(j - 1)  # 將索引轉成從 0 開始

# 計算最大匹配
max_pairs = maxBPM(graph, N1, N2)

# 輸出結果
print(N1 + N2 - max_pairs)
