from math import pi

a, b, h = map(int, input().split())

a, b = min(a, b), max(a, b)

if a == b:
    print(-1)
    exit(0)

fullH = -1
if a == 0:
    fullH = h
else:
    fullH = h / (b - a) * b
    
a1 = fullH ** 2 + b ** 2
a2 = (fullH - h) ** 2 + a ** 2

print((a1 - a2) * pi)
