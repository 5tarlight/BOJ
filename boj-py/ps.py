import math

def div(a, b):
    tmp = a / b
    return float(f'{tmp:.4f}'[:3])

n = int(input())
avg = [float(input()) for _ in range(n)]

def ok(x):
    for a in avg:
        l = 0
        r = 10 * x

        while l <= r:
            mid = (l + r) // 2
            cur = div(mid, x)

            if cur == a:
                return

for ans in range(1, 1000):
    if ok(ans):
        print(ans)
        break