import sys, bisect
sys.setrecursionlimit(200001)
 
n = int(input())
p = [-1] + [p - 1 for p in map(int, input().split())]
children = [[] for _ in range(n)]
for i in range(1, n):
    children[p[i]].append(i)
 
vertices = [[] for _ in range(n)]
s = [0] * n
e = [0] * n
def dfs(index, start, depth):
    vertices[depth].append(start)
    s[index] = start
    for c in children[index]:
        start = dfs(c, start + 1, depth + 1)
    e[index] = start
    return start
 
dfs(0, 0, 0)
print(vertices)
 
q = int(input())
for _ in range(q):
    u, d = map(int, input().split())
    print(bisect.bisect_left(vertices[d], e[u - 1] + 1) - bisect.bisect_left(vertices[d], s[u - 1]))