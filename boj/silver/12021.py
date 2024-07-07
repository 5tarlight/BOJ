x, y = map(int, input().split())

for _ in range(100000):
    x, y = (x + y) / 2, 2 * x * y / (x + y)

print(x, y)