cards = input().split(',')
a = list(map(lambda s: (int(s[0], 16), s[1] == 'b'), cards))
ans = []

for i in range(len(a)):
    for j in range(i + 1, len(a)):
        ans.append((a[i], a[j]))

def cmp(p1, p2):
    (n11, c11), (n12, c12) = p1
    (n21, c21), (n22, c22) = p2

    print(p1, p2)

ans.sort()