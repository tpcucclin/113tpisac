def find_champion(N, S, K):
    # 初始化學徒編號和淘汰計數
    students = list(range(1, N + 1))  # 學徒編號從 1 到 N
    elimination_count = [0] * N  # 每個學徒的淘汰次數，初始為 0
    
    current_index = 0  # 開始的位置
    
    # 模擬淘汰過程
    while len(students) > 1:  # 當學生人數大於1時，繼續進行遊戲
        # 找到要淘汰的學徒，經過 S-1 個學徒之後
        current_index = (current_index + S - 1) % len(students)
        eliminated_student = students[current_index]
        
        # 增加該學徒的淘汰次數
        elimination_count[eliminated_student - 1] += 1
        
        # 檢查該學徒是否達到淘汰次數 K 次
        if elimination_count[eliminated_student - 1] >= K:
            # 永久移除該學徒
            students.pop(current_index)
        else:
            # 如果還沒達到 K 次淘汰，移動到下一個學徒
            current_index = (current_index + 1) % len(students)

    # 返回剩下的唯一一個學徒，也就是冠軍
    return students[0]

# 測試範例
N = 5  # 學徒數量
S = 3  # 每次 S 個咒語
K = 2  # 淘汰次數

champion = find_champion(N, S, K)
print(f"冠軍學徒的編號是：{champion}")
