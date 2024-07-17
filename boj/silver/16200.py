n = int(input())
a = sorted(map(int, input().split()), reverse=True)

ans = 1
cnt = 0
for i in a:
    if i <= cnt:
        cnt = 1
        ans += 1
    else:
        cnt += 1

print(ans)