W, H, f, c, x1, y1, x2, y2 = map(int, input().split())

resultX = max(f, W - f)
resultY = H // (c + 1)

s = 0
for x in range(resultX):
    if x < min(f, W - f):
        for y in range(resultY):
            if x in range(x1, x2) and y in range(y1, y2):
                s += 2 * (c + 1)
    else:
        for y in range(resultY):
            if x in range(x1, x2) and y in range(y1, y2):
                s += c + 1

print(W * H - s)
