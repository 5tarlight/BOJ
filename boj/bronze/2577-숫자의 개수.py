a = int(input())
b = int(input())
c = int(input())
result = a * b * c

digits = []
while result > 0:
    digits.append(result % 10)
    result //= 10

for i in range(10):
    print(digits.count(i))
