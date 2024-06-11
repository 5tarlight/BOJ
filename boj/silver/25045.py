n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

a.sort(reverse=True)
b.sort()

ans = 0
for i in range(min(n, m)):
    ans += max(0, a[i] - b[i])

print(ans)