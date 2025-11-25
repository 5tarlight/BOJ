n = int(input())
a = list(map(int, input().split()))

ans = []
for i in a:
    if i < 250: ans.append(4)
    elif i < 275: ans.append(3)
    elif i < 300: ans.append(2)
    else: ans.append(1)

print(' '.join(map(str, ans)))
