a = int(input())
m, n = map(int, input().split())

print(min(max(m / a, n), m * 2 / a, max(m, n / a), n * 2 / a))
