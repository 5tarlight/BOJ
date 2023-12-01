def getScore(grade):
    if grade == 'A+':
        return 4.5
    elif grade == 'A0':
        return 4
    elif grade == 'B+':
        return 3.5
    elif grade == 'B0':
        return 3
    elif grade == 'C+':
        return 2.5
    elif grade == 'C0':
        return 2
    elif grade == 'D+':
        return 1.5
    elif grade == 'D0':
        return 1
    else:
        return 0
        

s = 0
scoreSum = 0
for _ in range(20):
    __, subject, score = input().split()
    if score == 'P':
        continue
    
    subject = float(subject)
    score = getScore(score)
    s += subject
    scoreSum += subject * score

print(scoreSum / s)
