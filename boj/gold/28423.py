import sys
sys.setrecursionlimit(10**6)

cache = {}
used = {}

def solve(n):
    if n in cache:
        return cache[n]
    used[n] = True

    digits = list(map(int, str(n)))
    a = sum(digits)

    b = 1
    for d in digits:
        b *= d

    tmp = int(str(a) + str(b))
    if tmp > 100000:
        cache[n] = -1
        return -1

    if tmp == n:
        cache[n] = 1
        return 1

    if tmp in used:
        cache[n] = 0
        return 0


    used[tmp] = True
    cache[n] = solve(tmp)
    return cache[n]

l, r = map(int, input().split())

ans = 0
for i in range(l, r + 1):
    cache = {}
    used = {}
    ans += solve(i)

print(ans)
