s = list(input().split())
stack = []
ans = 0
cur = 0

for t in s:
    if t == '[':
        stack.append(cur)
        cur = 0
    elif t == ']':
        ans += 8 + cur
        cur = stack[-1]
        stack.pop()
    else:
        if t.isdigit():
            cur += 8
        else:
            cur += len(t) + 12
            
print(ans)
