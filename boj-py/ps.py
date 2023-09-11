from collections import deque

n, m = map(int, input().split())
graph = []

for i in range(n):
    graph.append([])

for _ in range(m):
    a, b = map(int, input().split())
    graph[a-1].append(b)
    graph[b-1].append(a)

steps = []


def bfs(s, t):
    q = deque()
    visited = [s]
    q.append(q)
    st = [0] * n

    while q:
        a = q.popleft()

        for i in graph[a]:
            if i not in visited:
                st[i-1] = st[a-1]
                visited.append(i)
                q.append(i)

    return sum(st)
