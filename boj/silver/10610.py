num = input()
if num.count('0') == 0:
    print(-1)
else:
    if sum(map(int, num)) % 3 == 0:
        print(''.join(sorted(num, reverse=True)))
    else:
        print(-1)