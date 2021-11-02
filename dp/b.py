a, b = map(int, input().split())

A = list(map(int, input().split()))
B = list(map(int, input().split()))

dp = [[0] * (b+1) for _ in range(a+1)]
dp[a][b] = 0

for i in reversed(range(a)):
    for j in reversed(range(b)):
        if i == a and j == b:
            continue

        # 先攻
        dp[i][j] = 0
        if (i+j) % 2 == 0:
            if i == a: # Aの山がない
                dp[i][j] = B[j] + dp[i][j+1]
            elif i == b: # Bの山がない
                dp[i][j] = A[i] + dp[i+1][j]
            else:
                # 先攻のスコアを最大化
                dp[i][j] = max(A[i] + dp[i+1][j], B[j] + dp[i][j+1])
        else:
            if i == a:
                dp[i][j] = dp[i][j+1]
            elif i == b:
                dp[i][j] = dp[i+1][j]
            else:
                dp[i][j] = min(dp[i+1][j], dp[i][j+1])

print(dp)
print(dp[0][0])