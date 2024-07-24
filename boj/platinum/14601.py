n = int(input())
graph = [[0] * (1 << n) for _ in range(1 << n)]
tx, ty = map(int, input().split())
tx -= 1
ty = (1 << n) - ty
cnt = 1

def draw(x, y, dir, d):
    global cnt

    if d == 1:
        for i in range(2):
            for j in range(2):
                if i * 2 + j == dir:
                    continue
                graph[y + i][x + j] = cnt
        cnt += 1
        return

    l = 1 << (d - 1)
    draw(x + l // 2, y + l // 2, dir, d - 1)

    for i in range(2):
        for j in range(2):
            nxtDir = i * 2 + j
            if nxtDir == dir:
                continue
            draw(x + l * j, y + l * i, 3 - nxtDir, d - 1)

def conquer(x, y, d):
    if not d:
        graph[y][x] = -1
        return

    l = 1 << (d - 1)

    for i in range(2):
        for j in range(2):
            dir = i * 2 + j
            ax = x + l * j
            ay = y + l * i

            if ax <= tx < ax + l and ay <= ty < ay + l:
                conquer(ax, ay, d - 1)
                draw(x, y, dir, d)
                return

conquer(0, 0, n)
for m in graph:
    print(*m)