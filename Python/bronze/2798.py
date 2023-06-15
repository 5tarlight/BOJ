n, m = map(int, input().split())
nums = list(map(int, input().split()))

results = []

for i in range(n):
    for j in range(n):
        if i == j:
            continue
        for k in range(n):
            if i == k or j == k:
                continue

            s = nums[i] + nums[j] + nums[k]
            if s <= m:
                results.append(s)

print(max(results))
