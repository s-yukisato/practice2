from heapq import heappop, heappush

N, M = map(int, input().split())

indeg = [0] * (N+1)
out = [[] for _ in range(N+1)]

for _ in range(M):
    A, B = map(int, input().split())
    indeg[B] += 1
    out[A].append(B)

h = []

for i in range(1, N+1):
    if indeg[i] == 0:
        heappush(h, i)

ans = []

while h:
    now = heappop(h)
    ans.append(now)
    for num in out[now]:
        indeg[num] -= 1
        if indeg[num] == 0:
            heappush(h, num)

if len(ans) == N:
    print(*ans)
else:
    print(-1)