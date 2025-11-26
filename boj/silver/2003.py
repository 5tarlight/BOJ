n, m = map(int, input().split())
a = list(map(int, input().split()))

sum = [0]
for i in range(n):
    sum.append(sum[-1] + a[i])

ans = 0
l = 0
for r in range(1, n + 1):
    cur = sum[r] - sum[l]
    while cur > m and l < n:
        cur -= a[l]
        l += 1

    if cur == m:
        ans += 1

print(ans)
