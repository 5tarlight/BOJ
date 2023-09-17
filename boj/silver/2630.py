n = int(input())
arr = []

for _ in range(n):
    arr.append(list(map(int, input().split())))


def isUniform(a, x, y, n):
    target = a[x][y]

    for i in range(n):
        for j in range(n):
            if target != a[i + x][j + y]:
                return False
    return True


white = 0
blue = 0


def conq(a, x, y, n):
    global white
    global blue

    if isUniform(a, x, y, n):
        if a[x][y] == 0:
            white += 1
        else:
            blue += 1
        return
    else:
        conq(a, x, y, n // 2)
        conq(a, x + n // 2, y, n // 2)
        conq(a, x, y + n // 2, n // 2)
        conq(a, x + n // 2, y + n // 2, n // 2)


conq(arr, 0, 0, n)

print(white)
print(blue)
