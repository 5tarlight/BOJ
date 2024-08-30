t, w = map(int, input().split())
pos = [0] + [int(input()) for _ in range(t)]
dp = [[0] * (w + 1) for _ in range(t + 1)]

dp[1][0] = pos[1] % 2
dp[1][1] = pos[1] // 2

for t in range(2, t + 1):
    for w in range(w + 1):
        p = pos[t] % 2 if w % 2 == 0 else pos[t] // 2
        dp[t][w] = max(dp[t - 1][:w + 1]) + p

print(max(dp[-1]))