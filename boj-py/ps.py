def can_form_rectangle(a, b, c):
    if a % 2 != 0:
        return "No"
    total_area = a + 2 * b + 4 * c
    if total_area % 4 != 0:
        return "No"
    return "Yes"

t = int(input())
for _ in range(t):
    a, b, c = map(int, input().split())
    print(can_form_rectangle(a, b, c))
