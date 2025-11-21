import heapq

pq = []
heapq.heapify(pq)

n = int(input())

for _ in range(n):
    a = int(input())
    heapq.heappush(pq, (abs(a), a))

while pq:
    print(heapq.heappop(pq)[1], end=' ')
