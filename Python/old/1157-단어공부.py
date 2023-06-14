word = input().lower()
letters = list(set(word))
count = []

for l in letters:
    c = word.count(l)
    count.append(c)

if count.count(max(count)) >= 2:
    print('?')
else:
    print(letters[count.index(max(count))].upper())
