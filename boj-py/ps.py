word = input().lower()
cnt = []
abc = 'abcdefghijklmnopqrstuvwxyz'
for i in abc:
    cnt.append(word.count(i))

Max = max(cnt)

if cnt.count(Max) >= 2:
    print('?')
else:
    print(abc[cnt.index(Max)].upper())

