import sys
from collections import defaultdict

sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

MAX = 100005
PMAX = 18

n, M = 0, 0
graph = defaultdict(list)
depth = [-1] * MAX
p = [[-1] * PMAX for _ in range(MAX)]

def init(curr):
    for next_node in graph[curr]:
        if depth[next_node] == -1:
            depth[next_node] = depth[curr] + 1
            p[next_node][0] = curr
            init(next_node)


def lca(u, v):
    if depth[u] < depth[v]:
        u, v = v, u
    diff = depth[u] - depth[v]
    j = 0

    while diff > 0:
        if diff % 2:
            u = p[u][j]
        diff //= 2
        j += 1

    if u != v:
        for j in range(PMAX - 1, -1, -1):
            if p[u][j] != -1 and p[u][j] != p[v][j]:
                u = p[u][j]
                v = p[v][j]
        u = p[u][0]

    return u


n = int(input())
for _ in range(n - 1):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

depth[1] = 0
init(1)

for j in range(PMAX - 1):
    for i in range(1, n + 1):
        if p[i][j] != -1:
            p[i][j + 1] = p[p[i][j]][j]

M = int(input())
for _ in range(M):
    r, u, v = map(int, input().split())
    uv = lca(u, v)
    ur = lca(u, r)
    vr = lca(v, r)
    ans = uv
    ans = ur if depth[ans] < depth[ur] else ans
    ans = vr if depth[ans] < depth[vr] else ans
    print(ans)
