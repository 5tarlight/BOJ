t = int(input())
for _ in range(t):
    cnt = [0] * 10
    all = 0
    for i in range(1, 10):
        cnt[i] = int(input())
        all += cnt[i]

    cnt[9] += cnt[6]
    cnt[6] = 0

    idx = 9
    ans = [0] * all
    for i in range(all):
        while cnt[idx] == 0:
            idx -= 1
        if i % 2 == 0:
            ans[i // 2] = idx
        else:
            ans[all - i // 2 - 1] = idx
        cnt[idx] -= 1

    print(' '.join(map(str, ans)))