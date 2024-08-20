primes = {2, 3, 5, 7, 11, 13, 17}

a = int(input()) / 100
b = int(input()) / 100

dp = [[[0 for _ in range(19)] for _ in range(19)] for _ in range(19)]
dp[0][0][0] = 1

for i in range(1, 19):
    for a_goals in range(19):
        for b_goals in range(19):
            dp[i][a_goals][b_goals] += dp[i-1][a_goals][b_goals] * (1 - a) * (1 - b)
            if a_goals > 0:
                dp[i][a_goals][b_goals] += dp[i-1][a_goals-1][b_goals] * a * (1 - b)
            if b_goals > 0:
                dp[i][a_goals][b_goals] += dp[i-1][a_goals][b_goals-1] * (1 - a) * b
            if a_goals > 0 and b_goals > 0:
                dp[i][a_goals][b_goals] += dp[i-1][a_goals-1][b_goals-1] * a * b

result = 0
for a_goals in range(19):
    for b_goals in range(19):
        if a_goals in primes or b_goals in primes:
            result += dp[18][a_goals][b_goals]

print(f"{result:.12f}")
