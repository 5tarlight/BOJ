import sys
input = sys.stdin.readline

v, e = map(int, input().split())
k = int(input())
graph = [[int(1e9)] * (v + 1) for _ in range(v + 1)]
dist = [int(1e9)] * (v + 1)
visited = [False] * (v + 1)

for _ in range(e):
    u, vv, w = map(int, input().split())
    graph[u][vv] = min(graph[u][v], w)

dist[k] = 0
for _ in range(1, v + 1):
    minIdx = -1
    for j in range(1, v + 1):
        if not visited[j] and (minIdx == -1 or dist[j] < dist[minIdx]):
            minIdx = j

    if minIdx == -1:
        break
    visited[minIdx] = True

    for j in range(1, v + 1):
        if not visited[j] and graph[minIdx][j] != int(1e9):
            dist[j] = min(dist[j], dist[minIdx] + graph[minIdx][j])

for i in range(1, v + 1):
    if dist[i] == int(1e9):
        print("INF")
    else:
        print(dist[i])