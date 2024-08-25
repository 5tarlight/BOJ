import math

x1, y1, x2, y2, x3, y3 = map(int, input().split())

p1, p2, p3 = sorted([(x1, y1), (x2, y2), (x3, y3)])


def area(p1, p2):
    if p1[0] == p2[0]:
        return 0

    a = (p1[1] - p2[1]) / (p1[0] - p2[0])
    b = p1[1] - a * p1[0]
    t1 = a*a/3*p2[0]**3 + a*b*p2[0]**2 + b*b*p2[0]
    t2 = a*a/3*p1[0]**3 + a*b*p1[0]**2 + b*b*p1[0]
    return (t1 - t2) * math.pi


t1 = area(p1, p3)
t2 = area(p1, p2)
t3 = area(p2, p3)
ans1 = abs(t1 - (t2 + t3))

p1 = (p1[1], p1[0])
p2 = (p2[1], p2[0])
p3 = (p3[1], p3[0])
p1, p2, p3 = sorted([p1, p2, p3])

t1 = area(p1, p3)
t2 = area(p1, p2)
t3 = area(p2, p3)
ans2 = abs(t1 - (t2 + t3))

print(ans1, ans2)