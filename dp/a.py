N = int(input())

p = list(map(int, input().split()))

dp = [[0] * (10000) for _ in range(N+1)]
dp[0][0] = 1
for i in range(N):
    for j in range(10000):
        dp[i+1][j] = dp[i][j]
        if j >= p[i]:
            dp[i+1][j] |= dp[i][j-p[i]]

print(sum(dp[N]))