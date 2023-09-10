n, r, c = map(int, input().split())

answer = 0

while n != 0:
    n -= 1

    #1|2
    #---
    #3|4
    if r < 2**n and c < 2**n:
        pass
    elif r < 2**n and c >= 2**n:
        answer += 2**n * 2**n
        c -= 2**n
    elif r >= 2**n and c < 2**n:
        answer += 2**n * 2**n * 2
        r -= 2**n
    elif r >= 2**n and c >= 2**n:
        answer += 2**n * 2**n * 3
        r -= 2**n
        c -= 2**n

print(answer)
