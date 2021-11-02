N, P = map(int, input().split())

A = list(map(lambda x: 1 if int(x) < P else 0, input().split()))

print(sum(A))
