"""
    7 0 1
    6   2
    5 4 3
"""
dr = [-1, -1, 0, 1, 1, 1, 0 ,-1]
dc = [0, 1, 1, 1, 0, -1, -1, -1]

N, M, K = map(int, input().split())

fireballs = []
for _ in range(M):
    r, c, m, s, d = map(int, input().split())
    fireballs.append([r-1, c-1, m, s, d])

for _ in range(K):
    maps = [[[]for _ in range(N)]for _ in range(N)]

    for r,c,m,s,d in fireballs:
        mr = (r + dr[d] * s) % N
        mc = (c + dc[d] * s) % N
        maps[mr][mc].append([m, s, d])

    next_fireballs = []

    for r_idx in range(N):
        for c_idx in range(N):
            if not maps[r_idx][c_idx]:
                continue
            elif len(maps[r_idx][c_idx]) == 1:
                m,s,d = maps[r_idx][c_idx]
                next_fireballs.append(maps[r_idx][c_idx])
            else :
                sum_m = 0
                sum_s = 0
                count = len(maps[r_idx][c_idx])

                odd_count = 0
                even_count = 0

                for m, s, d in maps[r_idx][c_idx]:
                    sum_m += m
                    sum_s += s
                    count += 1
                    if d % 2 == 0:
                        even_count += 1
                    else :
                        odd_count += 1

                new_m = sum_m // 5

                if new_m == 0 :
                    continue

                new_s = sum_s // count

                if odd_count == count or even_count == count:
                    new_dir = [0,2,4,6]
                else :
                    new_dir = [1,3,5,7]

                for new_d in new_dir :
                    next_fireballs.append([r_idx, c_idx, new_m, new_s, new_d])

            fireballs = next_fireballs

total_mess = 0
for r,c,m,s,d in fireballs:
    total_mess += m

print(total_mess)
