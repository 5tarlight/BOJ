from collections import deque


def bfs(start, target, grid, H, W):
    queue = deque([start])
    visited = [[False] * W for _ in range(H)]
    visited[start[0]][start[1]] = True
    distance = [[0] * W for _ in range(H)]

    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

    while queue:
        x, y = queue.popleft()

        if (x, y) == target:
            return distance[x][y]

        for dx, dy in directions:
            nx, ny = x + dx, y + dy

            if 0 <= nx < H and 0 <= ny < W and not visited[nx][ny] and grid[nx][ny] != 'X':
                visited[nx][ny] = True
                distance[nx][ny] = distance[x][y] + 1
                queue.append((nx, ny))

    return -1


def find_min_time(H, W, N, grid):
    cheese_positions = {}
    start = None

    for i in range(H):
        for j in range(W):
            if grid[i][j] == 'S':
                start = (i, j)
            elif grid[i][j] in '123456789':
                cheese_positions[int(grid[i][j])] = (i, j)

    current_position = start
    total_time = 0

    for cheese in range(1, N + 1):
        target_position = cheese_positions[cheese]
        time_to_cheese = bfs(current_position, target_position, grid, H, W)
        total_time += time_to_cheese
        current_position = target_position

    return total_time


H, W, N = map(int, input().split())
grid = [input().strip() for _ in range(H)]

print(find_min_time(H, W, N, grid))
