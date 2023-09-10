y, m, d = map(int, input().split('-'))
l = int(input())

d += l
if d > 30:
    m += d // 30
    d %= 30

    if d == 0:
        d = 30
        m -= 1

if m > 12:
    y += m // 12
    m %= 12

    if m == 0:
        m = 12
        y -= 1


ms = str(m) if m >= 10 else '0' + str(m)
ds = str(d) if d >= 10 else '0' + str(d)

print(str(y) + '-' + ms + '-' + ds)
