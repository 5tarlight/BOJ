n, m, x, y = map(int, input().split())
_, h_mid = input().split()
h_mid = int(h_mid)

scores = []
for _ in range(n - 1):
    sid, mid = input().split()
    mid = int(mid)
    if sid.startswith("2024"):
        pred = max(0, y - x + mid)
        scores.append(mid + pred)

if len(scores) < m:
    print("YES")
    print(0)
else:
    scores.sort(reverse=True)
    threshold = scores[m - 1]
    needed = max(0, threshold - h_mid)
    if needed > y:
        print("NO")
    else:
        print("YES")
        print(needed)
