len = int(input())
scores = list(map(int, input().split()))
m = max(scores)
s = []

for score in scores:
    s.append(score / m * 100)

print(sum(s) / len)
