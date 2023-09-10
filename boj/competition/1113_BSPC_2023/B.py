t = int(input())

for i in range(t):
    n = int(input())
    if n > 4500:
        print('Case #' + str(i+1) + ': Round 1')
    elif n > 1000:
        print('Case #' + str(i+1) + ': Round 2')
    elif n > 25:
        print('Case #' + str(i+1) + ': Round 3')
    else:
        print('Case #' + str(i+1) + ': World Finals')
