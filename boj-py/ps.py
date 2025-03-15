from math import lcm

n = int(input())
a = map(int, [input() for _ in range(n)])
print(lcm(*a))
