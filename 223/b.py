S = list(input())

memo = set()

for i in range(len(S)):
    S = S[1:] + S[:1]
    memo.add("".join(S))

memo = sorted(list(memo))
print(memo[0])
print(memo[-1])