N = int(input())
print(sum(list(map(lambda x: max(0, int(x)-10), input().split()))))