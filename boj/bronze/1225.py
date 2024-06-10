n1, n2 = input().split()

def mul(c1, c2):
    return int(c1) * int(c2)

ans = 0
l1, l2 = len(n1), len(n2)
for i in range(l1):
    for j in range(l2):
        ans += mul(n1[i], n2[j])

print(ans)