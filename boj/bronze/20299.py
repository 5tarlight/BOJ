import sys

n, k, l = map(int, sys.stdin.readline().strip().split())

ans = []
for _ in range(n):
    lst = list(map(int, sys.stdin.readline().strip().split()))
    if sum(lst) >= k and min(lst) >= l:
        ans.extend(lst)

print(len(ans) // 3)
print(' '.join(map(str, ans)))