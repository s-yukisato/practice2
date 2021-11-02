from collections import defaultdict

N = int(input())
A = list(map(lambda x: int(x)-1, input().split()))
B = list(map(lambda x: int(x)-1, input().split()))
C = list(map(lambda x: int(x)-1, input().split()))

count = defaultdict(int)
for i in range(N):
    count[B[C[i]]] += 1

ans = 0
for i in range(N):
    ans += count[A[i]]

print(ans)