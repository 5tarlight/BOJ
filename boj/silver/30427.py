import sys

input = sys.stdin.readline

input()
n = int(input())
s = set()

for _ in range(n):
    name = input().strip()
    s.add(name)
    if name == 'dongho':
        print('dongho')
        exit(0)

m = int(input())
v = set()

for _ in range(m):
    name = input().strip()
    v.add(name)

s = s.difference(v)

if len(s) == 1:
    print(list(s)[0])
elif 'bumin' in s:
    print('bumin')
elif 'cake' in s:
    print('cake')
elif 'lawyer' in s:
    print('lawyer')
else:
    l = list(sorted(s))
    if len(l) == 0:
        print('swi')
    else:
        print(l[0])