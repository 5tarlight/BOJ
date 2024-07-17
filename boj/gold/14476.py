from math import gcd

n = int(input())
a = list(map(int, input().split()))
lgcd = [a[0]]
for i in range(1, n):
    lgcd.append(gcd(lgcd[-1], a[i]))
rgcd = [a[-1]]
for i in range(n - 2, -1, -1):
    rgcd.append(gcd(rgcd[-1], a[i]))

ans = -1
maxGcd = -1
if a[-1] % lgcd[-2] != 0:
    ans = a[-1]
    maxGcd = lgcd[-2]
if a[0] % rgcd[-2] != 0 and maxGcd < rgcd[-2]:
    ans = a[0]
    maxGcd = rgcd[-2]

for i in range(1, n - 1):
    nxt = gcd(lgcd[i - 1], rgcd[n - i - 2])
    if a[i] % nxt != 0 and nxt > maxGcd:
        maxGcd = nxt
        ans = a[i]

if ans == -1:
    print(-1)
else:
    print(maxGcd, ans)
