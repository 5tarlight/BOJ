t = int(input())
for _ in range(t):
    a, b = input().split()
    print(len(a.replace(b,'a')))