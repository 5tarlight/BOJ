import sys

n = int(sys.stdin.readline().strip())
a = list(map(int, sys.stdin.readline().strip().split()))

l = r = 0

ans = 0
for r in range(n):
    if r < n - 1 and a[r] > a[r + 1]:
        cnt = r - l + 1
        ans += cnt * (cnt + 1) // 2
        l = r + 1

cnt = r - l + 1
ans += cnt * (cnt + 1) // 2

print(ans)