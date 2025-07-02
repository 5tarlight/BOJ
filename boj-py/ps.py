a, p = map(int, input().split())
s = set()
arr = [a]

prev = a
for _ in range(1000):
    nxt = 0
    for c in str(prev):
        nxt += int(c) ** p

    prev = nxt
    arr.append(nxt)

