s = input()
t = s.split('-')

answer = 0
if s[0] == '-':
    answer -= sum(map(int, t[0].split('+')))
else:
    answer += sum(map(int, t[0].split('+')))

for p in t[1:]:
    answer -= sum(map(int, p.split('+')))

print(answer)
