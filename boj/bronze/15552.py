import sys

for _ in range(int(sys.stdin.readline().rstrip())):
    print(sum(map(int, sys.stdin.readline().rstrip().split())))

