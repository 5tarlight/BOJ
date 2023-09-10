n = int(input())

for _ in range(n):
    n, m = map(int, input().split())
    queue = list(map(int, input().split()))

    seq = 0
    while len(queue) > 0:
        if queue[0] >= max(queue):
            seq += 1
            if m == 0:
                print(seq)
                break
            queue.pop(0)
            m -= 1
        else:
            p = queue.pop(0)
            queue.append(p)

            if m == 0:
                m = len(queue) - 1
            else:
                m -= 1
