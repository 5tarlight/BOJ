import sys

dp = [0] * 10001
dp[1] = dp[2] = 1
for i in range(3, 10001):
    dp[i] = dp[i - 1] + dp[i - 2]

t = int(sys.stdin.readline().strip())
for i in range(1, t + 1):
    p, q = map(int, sys.stdin.readline().strip().split())
    print(f'Case #{i}:', dp[p] % q)