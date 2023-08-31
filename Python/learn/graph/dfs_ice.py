# N x M 크기의 틀에 얼음이 얼어 있다. 상하좌우로 연결된 어름을 한 덩어리로 취급할때 총 덩어리의 수는?
# 첫줄에 N, M [1, 1000]
# 얼음이 있는 부분은 0

n, m = map(int, input().split())

graph = []
for _ in range(n):
    graph.append(list(map(int, input())))


def dfs(x, y):
    if x < 0 or x >= n or y < 0 or y >= m:
        return False
    if graph[x][y] == 1:
        return False
    else:
        graph[x][y] = 1

        dfs(x - 1, y)
        dfs(x, y - 1)
        dfs(x + 1, y)
        dfs(x, y + 1)

        return True


count = 0
for i in range(n):
    for j in range(m):
        if dfs(i, j):
            count += 1

print(count)
