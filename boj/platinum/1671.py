class Shark:
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c

    def __eq__(self, other):
        return self.a == other.a and self.b == other.b and self.c == other.c

    def __gt__(self, other):
        return self.a < other.a or self.b < other.b or self.c < other.c

def dfs(a):
    visited[a] = True
    for i in range(n):
        if arr[a] == arr[i] and a < i:
            continue
        if i == a or arr[a] > arr[i]:
            continue
        if B[i] == -1 or (not visited[B[i]] and dfs(B[i])):
            B[i] = a
            return True
    return False

n = int(input())
arr = [None] * 55
B = [-1] * 55
visited = [False] * 55

for i in range(n):
    a, b, c = map(int, input().split())
    arr[i] = Shark(a, b, c)

ans = 0
for i in range(n):
    for _ in range(2):
        visited = [False] * 55
        if dfs(i):
            ans += 1

print(n - ans)
