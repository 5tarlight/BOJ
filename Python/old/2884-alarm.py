h, m = map(int, input().split())

if m < 45:
    h -= 1
    m = 15 + m
else:
    m -= 45

if h == -1:
    h = 23

print(h, m)
