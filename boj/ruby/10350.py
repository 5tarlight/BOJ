import math
import sys

input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))

s = [0]
for i in range(n * 2):
    s.append(s[-1] + a[i % n])

ans = 0

for i in range(n - 1):
    for j in range(1, n + 1):
        if s[j + i] < s[j - 1]:
            ans += math.ceil(abs(s[j + i] - s[j - 1]) / s[n])

print(ans)