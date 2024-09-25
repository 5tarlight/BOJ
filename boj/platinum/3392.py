tree = [0] * 30001 * 2 * 4
cnt = [0] * 30001 * 2 * 4

def update(node, s, e, l, r, v):
    if e < l or s > r: return
    if l <= s and e <= r:
        cnt[node] += v
    else:
        mid = (s + e) // 2
        update(2 * node, s, mid, l, r, v)
        update(2 * node + 1, mid + 1, e, l, r, v)

    if cnt[node] > 0:
        tree[node] = e - s + 1;
    else:
        tree[node] = tree[2 * node] + tree[2 * node + 1]

p = []
n = int(input())
for _ in range(n):
    x1, y1, x2, y2 = map(int, input().split())
    p.append((x1, y1, y2 - 1, 1))
    p.append((x2, y1, y2 - 1, -1))

p.sort()
ans = 0

update(1, 0, 30000, p[0][1], p[0][2], p[0][3])

for i in range(1, 2 * n):
    diff = p[i][0] - p[i - 1][0]
    ans += diff * tree[1]
    update(1, 0, 30000, p[i][1], p[i][2], p[i][3])

print(ans)
