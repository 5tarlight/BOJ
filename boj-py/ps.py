import sys

v = int(sys.stdin.readline().rstrip())

graph = [[]] * (v + 1)

for _ in range(v):
    nums = list(map(int, sys.stdin.readline().rstrip().split()))

    r = nums[0]
    for i in range(len(nums)):
        if i == 0:
            continue
        if nums[i] == -1:
            break

        if i % 2 == 1:
            graph[r].append((nums[i], nums[i + 1]))
        else:
            continue

print(graph[2])
