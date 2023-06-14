test = int(input())

for _ in range(test):
    n, s = input().split()
    for i in s:
        print(i * int(n), end='')
    print()
