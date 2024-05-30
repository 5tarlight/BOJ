from itertools import combinations

def gcd(a, b):
    return gcd(b, a % b) if b else a

def lcm2(a, b):
    return a * b // gcd(a, b)

def lcm(a, b, c):
    return lcm2(lcm2(a, b), c)

i = map(int, input().split())

ans = 10 ** 9
for p in combinations(i, 3):
    ans = min(ans, lcm(*p))

print(ans)