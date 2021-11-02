N = int(input())

s = [list(map(int, input().split())) for _ in range(N)]

total_time = 0

half_time = 0
ans = 0

for a, b in s:
    total_time += a/b

half_time = total_time / 2

for a, b in s:
    if half_time >= a/b:
        ans += a
        half_time -= a/b
    else:
        ans += half_time * b
        half_time = 0

print(ans)