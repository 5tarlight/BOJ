t = 64
n = int(input())

while n % 2 == 0:
    t -= 1
    n //= 2

print(t)