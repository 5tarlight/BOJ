from itertools import combinations

n, k = map(int, input().split())
score = [0 for _ in range(n)]

for i in range(n):
    score[i] = list(map(int, input().split()))

ans = -1000000000000000
for c in combinations(range(n), k):
    tmp = 0
    for i in c:
        for j in c:
            if i < j:
                tmp += score[i][j]

    ans = max(tmp, ans)

print(ans)