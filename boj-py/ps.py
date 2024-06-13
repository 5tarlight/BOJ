import sys

N = int(sys.stdin.readline())
a = list(map(int, sys.stdin.readline().split())) + [0, 0]
ans = 0

for i in range(N):
    if a[i + 1] > a[i + 2]:
        cnt = min(a[i], a[i + 1] - a[i + 2])
        ans += 5 * cnt

        a[i] -= cnt
        a[i + 1] -= cnt

        cnt = min(a[i:i+3])
        ans += 7 * cnt

        a[i] -= cnt
        a[i + 1] -= cnt
        a[i + 2] -= cnt
    else:
        cnt = min(a[i:i+3])
        ans += 7 * cnt

        a[i] -= cnt
        a[i + 1] -= cnt
        a[i + 2] -= cnt

        cnt = min(a[i:i+2])
        ans += 5 * cnt

        a[i] -= cnt
        a[i + 1] -= cnt
    ans += 3 * a[i]
    a[i] = 0

print(ans)
