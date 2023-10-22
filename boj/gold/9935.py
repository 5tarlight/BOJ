ori = input()
exp = input()
stack = []

for i in range(len(ori)):
    stack.append(ori[i])
    
    if ''.join(stack[-len(exp):]) == exp:
        for _ in range(len(exp)):
            stack.pop()
        
if stack:
    print(''.join(stack))
else:
    print('FRULA')
