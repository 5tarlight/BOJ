import sys

input = sys.stdin.readline

n, k = map(int, input().split())
a = []

for _ in range(n):
    idx, c, h = map(int, input().split())
    a.append((-h * 100000000 / c / 100000000, c, idx))

a.sort()

for i in range(k):
    print(a[i][2])