import sys

sys.setrecursionlimit(10 ** 7)

n = int(sys.stdin.readline())
cnt = [0] * n
child = [[] for _ in range(n)]

for i in range(1, n):
    type, island, parent = sys.stdin.readline().split()
    island = int(island)
    parent = int(parent)

    if type == 'W':
        cnt[i] = -island
    else:
        cnt[i] = island

    child[parent - 1].append(i)

def dfs(x):
    if len(child[x]) == 0:
        return max(0, cnt[x])

    ans = cnt[x]
    for c in child[x]:
        ans += dfs(c)
    return max(0, ans)

print(dfs(0))