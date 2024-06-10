from collections import deque
n, m = map(int, input().split())
a = [[] for _ in range(n + 1)]
deg = [0] * (n + 1)

for i in range(m):
    s, e = map(int, input().split())
    a[s].append(e)
    deg[e] += 1

dq = deque()

for i in range(1, n + 1):
    if deg[i] == 0:
        dq.append(i)

while dq:
    cur = dq.popleft()
    print(cur, end=' ')
    for nxt in  a[cur]:
        deg[nxt] -= 1
        if deg[nxt] == 0:
            dq.append(nxt)