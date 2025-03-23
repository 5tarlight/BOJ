b, n, m = map(int, input().split())
p = {}

for _ in range(n):
    name, price = input().split()
    p[name] = int(price)

for _ in range(m):
    name = input()
    b -= p[name]

if b >= 0:
    print("acceptable")
else:
    print("unacceptable")