import sys

while True:
    a = sorted(list(map(int, sys.stdin.readline().split())))
    if len(a) == 1:
        exit(0)

    n1 = n2 = 0
    first = True
    for n in a:
        if first:
            n1 = 10 * n1 + n
        else:
            n2 = 10 * n2 + n
        first = not first

    print(n1 + n2)