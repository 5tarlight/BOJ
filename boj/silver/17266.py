n = int(input())
m = int(input())
loc = list(map(int, input().split()))

l, r = 1, 100000

def can(mid):
    covered = -1

    for x in loc:
        ll = max(0, x - mid)
        rr = min(n - 1, x + mid - 1)

        if covered < ll - 1:
            return False

        covered = max(covered, rr)

    return covered >= n - 1

ans = 100000
while l <= r:
    mid = (l + r) // 2
    if can(mid):
        ans = min(ans, mid)
        r = mid - 1
    else:
        l = mid + 1

print(ans)
