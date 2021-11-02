import sys
sys.setrecursionlimit(100000)

N, M = map(int, input().split())

G = [[] for _ in range(N)]

for _ in range(M):
    A, B = map(int, input().split())
    G[A-1].append(B-1)


def dfs(v):
    if visited[v]:
        return
    visited[v] = True
    for next in G[v]:
        dfs(next)

ans = 0
for i in range(N):
    visited = [False] * N
    dfs(i)
    ans += sum(visited)

print(ans)