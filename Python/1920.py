input()
src = list(map(int, input().split()))
input()
cmp = list(map(int, input().split()))

result = []
for c in cmp:
    if c in src:
        result.append('1')
    else:
        result.append('0')

print('\n'.join(result))
