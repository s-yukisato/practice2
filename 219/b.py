S1 = input()
S2 = input()
S3 = input()
num = list(input())

ans = ""
for i in num:
    if i == "1":
        ans += S1
    elif i == "2":
        ans += S2
    else:
        ans += S3

print(ans)
