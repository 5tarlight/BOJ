test = int(input())

for _ in range(test):
    answer = input()
    score = 0
    total = 0
    for i in range(len(answer)):
        if answer[i] == 'O':
            score += 1
            total += score
        else:
            score = 0

    print(total)
