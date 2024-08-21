k = int(input())
d1, d2 = map(int, input().split())
d1 /= 2
d2 /= 2
print((k**2 - (d1 - d2)**2))