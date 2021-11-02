import math


def comb(n, r):
    return math.factorial(n) // (math.factorial(n - r) * math.factorial(r))


A, B, K = map(int, input().split())
K-=1
ans = ""

while A or B:
    if A:
        if K < comb(A+B-1, B):
            ans += "a"
            A-=1
        else:
            ans += "b"
            K-= comb(A+B-1, B)
            B-=1
    else:
        ans += "b"
        B-=1

print(ans)

