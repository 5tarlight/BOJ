s = input()
l = len(s)
d = {}

cnt = 0
for i in range(l + 1):
    for j in range(i + 1, l + 1):
        sub = s[i:j]
        if not sub in d:
            cnt += 1
            d[sub] = 1

print(cnt)
