n = int(input())

stack = []
nums = []
for _ in range(n):
    nums.append(int(input()))

good = True
stack = []
result = []
i = 1

for num in nums:
    while i <= num:
        stack.append(i)
        i += 1
        result.append('+')

    if stack[-1] == num:
        stack.pop()
        result.append('-')
    else:
        good = False
        break

if good:
    print("\n".join(result))
else:
    print('NO')
