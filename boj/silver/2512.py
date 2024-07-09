import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))
m = int(input())

ans = 0
left, right = 1, max(a)

while left <= right:
    mid = (left + right) // 2

    total = 0
    for v in a:
        total += min(mid, v)

    if total > m:
        right = mid - 1
    else:
        left = mid + 1
        ans = mid

print(ans)