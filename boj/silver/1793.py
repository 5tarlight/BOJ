dp = [1] * 251

for i in range(2, 251):
    dp[i] = dp[i - 1] + dp[i - 2] * 2

while True:
    try:
        n = int(input())
        print(dp[n])
    except EOFError:
        break