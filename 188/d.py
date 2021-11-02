N, C = map(int ,input().split())

event = []

for _ in range(N):  
    a, b, c = map(int,input().split())
    event.append((a-1, c))
    event.append((b, -c))

event.sort()

ans = 0
fee = 0
t = 0

for x, y in event:
    if x != t:
        ans += min(C, fee) *(x-t)
        t = x
    fee += y

print(ans)