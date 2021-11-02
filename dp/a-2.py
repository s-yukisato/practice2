N = int(input())
s = 1
for a in input().split():
    s |= s << int(a)

print(bin(s).count("1"))
