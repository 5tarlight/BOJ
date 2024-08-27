score = 0

for _ in range(8):
    l = input()
    score += l.count('P') * 1
    score -= l.count('p') * 1
    score += l.count('N') * 3
    score -= l.count('n') * 3
    score += l.count('B') * 3
    score -= l.count('b') * 3
    score += l.count('R') * 5
    score -= l.count('r') * 5
    score += l.count('Q') * 9
    score -= l.count('q') * 9

print(score)
