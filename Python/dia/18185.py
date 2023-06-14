n = int(input())
nums = list(map(int, input().split()))

cost = 0

while sum(nums) != 0:
    for i in range(len(nums)):
        if i < len(nums) - 2:
            if nums[i + 1] > 0 and nums[i + 2] > 0:
                if nums[i + 1] <= nums[i + 2]:
                    value = min(nums[i:i + 3])
                    cost += 7 * value
                    nums[i] -= value
                    nums[i + 1] -= value
                    nums[i + 2] -= value

                    value = min(nums[i], nums[i + 1])
                    cost += 5 * value
                    nums[i] -= value
                    value[i + 1] -= value
                else:
                    value = min(nums[i], nums[i + 1] - nums[i + 2])
                    cost += 5 * value
                    nums[i] -= value
                    nums[i + 1] -= value

                    value = min(nums[i:i + 3])
                    cost += 7 * value
                    nums[i] -= value
                    nums[i + 1] -= value
                    nums[i + 2] -= value
            elif nums[i + 1] > 0:
                value = min(nums[i], nums[i + 1])
                cost += 5 * value
                nums[i] -= value
                nums[i + 1] -= value
        elif i < len(nums) - 1:
            if nums[i + 1] > 0:
                value = min(nums[i], nums[i + 1])
                cost += 5 * value
                nums[i] -= value
                nums[i + 1] -= value
            else:
                cost += 3 * nums[i]
                nums[i] = 0
        else:
            cost += 3 * nums[i]
            nums[i] = 0

print(cost)
