def find(parent, x):
    if parent[x] != x:
        parent[x] = find(parent, parent[x])
    return parent[x]

def union(parent, rank, x, y):
    rootX = find(parent, x)
    rootY = find(parent, y)

    if rootX != rootY:
        if rank[rootX] > rank[rootY]:
            parent[rootY] = rootX
        elif rank[rootX] < rank[rootY]:
            parent[rootX] = rootY
        else:
            parent[rootY] = rootX
            rank[rootX] += 1

def count_sets(A, B, P):
    parent = list(range(B - A + 1))
    rank = [0] * (B - A + 1)

    sieve = [True] * (B + 1)
    for i in range(2, int(B**0.5) + 1):
        if sieve[i]:
            for j in range(i * i, B + 1, i):
                sieve[j] = False

    primes = [i for i in range(P, B + 1) if sieve[i]]

    for p in primes:
        start = max(p * p, (A + p - 1) // p * p)
        for multiple in range(start, B + 1, p):
            union(parent, rank, multiple - A, start - A)

    root_count = len(set(find(parent, i) for i in range(B - A + 1)))
    return root_count

A, B, P = map(int, input().split())
print(count_sets(A, B, P))
