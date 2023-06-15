n = int(input())
nums = []

for _ in range(n):
    nums.append(int(input()))

print('\n'.join(map(str, sorted(nums))))
