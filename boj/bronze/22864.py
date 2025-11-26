a, b, c, m = map(int, input().split())
x = 0
ans = 0

for _ in range(24):
    if x + a <= m:
        x += a
        ans += b
    else:
        x -= c
        x = max(x, 0)

print(ans)