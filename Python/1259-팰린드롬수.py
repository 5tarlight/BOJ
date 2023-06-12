num = input()

while num != '0':
    l = len(num)
    ok = True

    for i in range(l // 2):
        if num[i] != num[l - i - 1]:
            ok = False

    if ok:
        print('yes')
    else:
        print('no')

    num = input()
