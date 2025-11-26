import sys

p, k = map(int, input().split())

for n in range(2, k):
    if p % n == 0:
        print("BAD", n)
        sys.exit(0)

print("GOOD")