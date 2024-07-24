x, y, p1, p2 = map(int, input().split())
rx = set(range(p1, 10 ** 6, x))
ry = set(range(p2, 10 ** 6, y))

r = rx & ry
print(min(r) if r else -1)