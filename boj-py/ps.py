dp = [-1] * 100001

# // 2 -> 1
# // 3 -> 7
# // 4 -> 4
# // 5 -> 5
# // 6 -> 9
# // 7 -> 8

dp[2] = 1
dp[3] = 7
dp[4] = 4
dp[5] = 5
dp[6] = 9
dp[7] = 8

for i in range(8, 101):
    for j in range(2, 8):
        if dp[i - j] == -1: continue

        dp[i] = max(dp[i], dp[i - j] * 10 + dp[j])

print(dp[15])