def dist(x1, y1, x2, y2):
    return abs(x1 - x2) + abs(y1 - y2)

INF = 1e11
d = [[INF] * 8 for _ in range(8)]
p = []

a, b = map(int, input().split())
p.append((a, b))
a, b = map(int, input().split())
p.append((a, b))

for i in range(3):
    i1 = 2 * i + 2
    i2 = 2 * i + 3

    x1, y1, x2, y2 = map(int, input().split())
    p.append((x1, y1))
    p.append((x2, y2))
    d[i1][i2] = 10
    d[i2][i1] = 10

for i in range(8):
    for j in range(8):
        d[i][j] = min(d[i][j], dist(p[i][0], p[i][1], p[j][0], p[j][1]))

for k in range(8):
    for i in range(8):
        for j in range(8):
            d[i][j] = min(d[i][j], d[i][k] + d[k][j])

print(d[0][1])