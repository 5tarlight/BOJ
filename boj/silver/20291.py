n = int(input())

d = dict()

for _ in range(n):
    ext = input().split('.')[1]
    if ext not in d:
        d[ext] = 1
    else:
        d[ext] += 1

s = sorted(d.items(), key=lambda x: x[0])

for (k, v) in s:
    print(k, v)