prize = int(input())
s = 0

for _ in range(int(input())):
    a, b = map(int, input().split())
    s += a * b
    
if prize == s:
    print('Yes')
else:
    print('No')
