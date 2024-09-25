class Line:
    def __init__(self, a: int, b: int, s: float = 0):
        self.a = a
        self.b = b
        self.s = s


def cross(f: Line, g: Line) -> float:
    return (g.b - f.b) / (f.a - g.a)


MAX = 100000
dp = [0] * MAX
s = []

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

for i in range(1, n):
    g = Line(b[i - 1], dp[i - 1])

    while len(s) >= 1:
        g.s = cross(g, s[-1])
        if g.s < s[-1].s:
            s.pop()
        else:
            break

    s.append(g)

    x = a[i]
    fpos = 0

    left = 0
    right = len(s) - 1
    while left <= right:
        mid = (left + right) // 2
        if s[mid].s < x:
            fpos = mid
            left = mid + 1
        else:
            right = mid - 1

    dp[i] = s[fpos].a * x + s[fpos].b

print(dp[n - 1])
