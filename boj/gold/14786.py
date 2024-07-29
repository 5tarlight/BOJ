import sys
from decimal import *

input = sys.stdin.readline

getcontext().prec = 50
getcontext().rounding = ROUND_HALF_UP

a, b, c = map(Decimal, map(int, input().split()))
pi = Decimal("3.14159265358979323846264338327950288419716939937510")

def sin(x):
    x = x % (2 * pi)
    getcontext().prec += 2

    i = 1
    l = 0
    s = x
    f = 1
    num = x
    sign = 1

    while s != l:
        l = s
        i += 2
        f *= i * (i - 1)
        num *= x * x
        sign *= -1
        s += num / f * sign

    getcontext().prec -= 2
    return s

l, r = (c - b) / a, (c + b) / a

while r - l > Decimal(1e-21):
    mid = (l + r) / 2
    if a * mid + b * sin(mid) < c:
        l = mid
    else:
        r = mid

print(r)