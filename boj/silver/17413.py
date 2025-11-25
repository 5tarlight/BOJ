st = input()

isInTag = False
arr = []
tmp = ''

for s in st:
    if isInTag:
        tmp += s
        if s == '>':
            isInTag = False
            arr.append(tmp)
            tmp = ''
        continue

    if s == ' ' and not isInTag:
        arr.append(tmp[::-1])
        arr.append(' ')
        tmp = ''
        continue

    if s == '<':
        if tmp:
            arr.append(tmp[::-1])
            tmp = ''
        isInTag = True
        tmp += s
        continue

    tmp += s

arr.append(tmp[::-1])
print(''.join(arr))
