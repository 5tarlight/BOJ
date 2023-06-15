a, b, c = -1, -1, -1

while True:
    a, b, c = map(int, input().split())

    if a == 0 and b == 0 and c == 0:
        break

    if a == max(a, b, c) and a ** 2 == b ** 2 + c ** 2 \
            or b == max(a, b, c) and b ** 2 == a ** 2 + c ** 2 \
            or c == max(a, b, c) and c ** 2 == a ** 2 + b ** 2:
        print('right')
    else:
        print('wrong')
