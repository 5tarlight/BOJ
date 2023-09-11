from sys import stdin

m, n = map(int, stdin.readline().rstrip().split())

a = ['Missing No.']
d = {}

for i in range(m):
    name = stdin.readline().rstrip()
    a.append(name)
    d[name] = i + 1

for _ in range(n):
    i = stdin.readline().rstrip()
    if i.isnumeric():
        print(a[int(i)])
    else:
        print(d[i])
