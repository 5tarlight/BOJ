from itertools import combinations

nums = []

for n in range(1, 11):
    for c in combinations(range(10), n):
        num = int(''.join(map(str, sorted(c, reverse=True))))
        nums.append(num)

nums.sort()

n = int(input())
if n >= len(nums):
    print(-1)
else:
    print(nums[n])
