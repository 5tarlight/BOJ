from collections import deque

n, k, r = map(int, input().split())
blocked = [[set() for _ in range(n + 1)] for _ in range(n + 1)]

for _ in range(r):
    r1, c1, r2, c2 = map(int, input().split())
    blocked[r1][c1].add((r2, c2))
    blocked[r2][c2].add((r1, c1))

cows = [tuple(map(int, input().split())) for _ in range(k)]
dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]

def bfs(sr, sc):
    visited = [[False] * (n + 1) for _ in range(n + 1)]
    q = deque()
    q.append((sr, sc))
    visited[sr][sc] = True

    while q:
        r, c = q.popleft()
        for dr, dc in dirs:
            nr, nc = r + dr, c + dc
            if 1 <= nr <= n and 1 <= nc <= n:
                if not visited[nr][nc] and (nr, nc) not in blocked[r][c]:
                    visited[nr][nc] = True
                    q.append((nr, nc))

    return visited

reach = []
for r, c in cows:
    reach.append(bfs(r, c))

ans = 0
for i in range(k):
    for j in range(i + 1, k):
        r2, c2 = cows[j]
        if not reach[i][r2][c2]:
            ans += 1

print(ans)