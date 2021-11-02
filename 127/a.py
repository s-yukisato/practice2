N = int(input())
A = list(map(int, input().split()))

ans = [0] * N

mn = -1
mn_idx = -1

mx = -1
mx_idx = -1

for i, a in enumerate(A[::-1]):
    if mn == -1:
        mn = a
        mn_idx = N-i-1
    elif mx < a and mn < a:
        mx = a
        mx_idx = N-i-1
    elif mx > a and mn < a:
        if mx != -1:
            ans[mx_idx] = 1
            ans[mn_idx] = 1
        mn = a
        mn_idx = N-i-1
        mx = -1
    elif mn >= a:
        if mx != -1:
            ans[mx_idx] = 1
            ans[mn_idx] = 1
        mn = a
        mn_idx = N-i-1
        mx = -1
else:
    if mx != -1:
        ans[mx_idx] = 1
        ans[mn_idx] = 1
print(*ans)
