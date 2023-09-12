n, m = map(int, input().split())

h = []
s = []

for _ in range(n):
    h.append(input())
for _ in range(m):
    s.append(input())

un = []

if h <= s:
    for heard in h:
        if heard not in s:
            un.append(heard)
else:
    for seen in s:
        if seen not in h:
            un.append(seen)

print(len(un))

for u in un:
    print(u)
