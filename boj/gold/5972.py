import sys
import heapq

input = sys.stdin.readline

n, m = map(int, input().split())
graph = [[] for _ in range(n + 1)]
for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((c, b))
    graph[b].append((c, a))

dist = [1e9] * (n + 1)
dist[1] = 0
pq = [] # ( cost, next )
heapq.heappush(pq, (dist[1], 1))

while len(pq) != 0:
    cost, x = heapq.heappop(pq)

    if cost > dist[x]:
        continue

    for (nxtCost, nxt) in graph[x]:
        if dist[nxt] > dist[x] + nxtCost:
            dist[nxt] = dist[x] + nxtCost
            heapq.heappush(pq, (dist[nxt], nxt))

print(dist[n])