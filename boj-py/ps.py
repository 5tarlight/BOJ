import sys

n = int(input())
a = []
for i in range(n):
    a.append(list(map(int, input().split())))

for i in range(1, n + 1):
    d = set()
    for arr in a:
        d.add(''.join(map(str, arr[:i])))
    print(d)
    if len(d) == n:
        print(i)
        sys.exit(0)