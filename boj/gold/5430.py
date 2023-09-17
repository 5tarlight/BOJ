t = int(input())

for _ in range(t):
    p = input()
    n = int(input())
    raw = input()

    if n == 0:
        if 'D' in p:
            print('error')
        else:
            print('[]')
        continue

    arr = list(map(int, raw[1:-1].split(',')))

    re = False
    a = 0
    b = n

    err = False
    for op in p:
        if op == 'R':
            re = not re
        else:
            if re:
                b -= 1
            else:
                a += 1

        if b < a:
            print('error')
            err = True
            break

    if err:
        continue
    if re:
        print('[' + ','.join(map(str, list(reversed(arr[a:b])))) + ']')
    else:
        print('[' + ','.join(map(str, arr[a:b])) + ']')
