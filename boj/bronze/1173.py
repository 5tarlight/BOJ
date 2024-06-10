N, m, M, T, R = map(int, input().split())

if m + T > M:
    print(-1)
    exit(0)

cur = m
cnt = 0
ans = 0
while cnt < N:
    if cur + T <= M:
        cur += T
        cnt += 1
    else:
        cur -= R
        cur = max(cur, m)
    ans += 1

print(ans)