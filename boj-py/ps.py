import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))
a.sort()

mid = (len(a) + 1) // 2

ans = 1
for i in range(mid):
    while a[i] > 1:
        a[i] //= 2
        ans += 1

print(ans)
