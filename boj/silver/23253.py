import sys

n, m = map(int, sys.stdin.readline().strip().split())

ok = True
for _  in range(m):
    k = int(sys.stdin.readline())
    l = list(map(int, sys.stdin.readline().strip().split()))
    prev = l[0]
    for i in range(1, len(l)):
        if l[i] > prev:
            ok = False
            break
        prev = l[i]

print('Yes' if ok else 'No')