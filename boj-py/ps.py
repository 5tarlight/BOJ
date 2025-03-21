n = int(input())

dp = [-1, -1, -1, 1, -1, 1]

for i in range(6, n + 1):
    tmp = 10 ** 9
    if dp[i - 3] != -1:
        tmp = min(tmp, dp[i - 3] + 1)
    if dp[i - 5] != -1:
        tmp = min(tmp, dp[i - 5] + 1)
    if tmp == 10 ** 9:
        dp.append(-1)
    else:
        dp.append(tmp)

print(dp[n])