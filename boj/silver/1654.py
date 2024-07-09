import sys

k, n = map(int, sys.stdin.readline().split())
a = [int(sys.stdin.readline().rstrip()) for _ in range(k)]
left, right = 1, max(a)

ans = 0
while left <= right:
    mid = (left + right) // 2

    cnt = 0
    for v in a:
        cnt += v // mid

    if cnt >= n:
        left = mid + 1
        ans = mid
    else:
        right = mid - 1

print(ans)