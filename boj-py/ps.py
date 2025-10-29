import sys

input = sys.stdin.readline
INF = int(1e9)

n, m = map(int, input().split())
graph = [[] for _ in range(n + 1)] # {vertex, weight}

for _ in range(m):
    a, b, w = map(int, input().split())
    graph[a].append((b, w))

dist = [INF for _ in range(n + 1)]
dist[1] = 0

for k in range(1, n + 1):
    for i in range(1, n + 1):
        for nxt, cost in graph[i]:
            if dist[i] != 1e9 and dist[nxt] > dist[i] + cost:
                dist[nxt] = dist[i] + cost

                if k == n:
                    print(-1)
                    sys.exit(0)

for i in range(2, n + 1):
    if dist[i] == 1e9: print(-1)
    else: print(dist[i])
