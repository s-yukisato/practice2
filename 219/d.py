N = int(input())

X, Y = map(int, input().split())

dp = [[[500]*301 for _ in range(301)] for _ in range(N+1)]
dp[0][0][0] = 0

for i in range(N):
    a, b = map(int, input().split())
    for j in range(a, 301):
        for k in range(b, 301):
            dp[i+1][j][k] = dp[i][j][k]
            dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j-a][k-b] + 1)


ans = 500
for i in range(X, 301):
    for j in range(Y, 301):
        ans = min(ans, dp[N][i][j])


print(ans if ans != 500 else -1)