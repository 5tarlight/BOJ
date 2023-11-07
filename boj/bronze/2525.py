h, m = map(int, input().split())
d = int(input())

h += (m + d) // 60
h %= 24
m = (m + d) % 60

print(h, m)
