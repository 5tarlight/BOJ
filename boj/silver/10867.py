input()
a = sorted(list(map(int, input().split())))
prev = -1
for v in a:
    if v == prev:
        continue
    print(v, end=' ')
    prev = v