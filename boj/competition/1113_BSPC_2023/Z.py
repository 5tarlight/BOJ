db = '''Never gonna give you up
Never gonna let you down
Never gonna run around and desert you
Never gonna make you cry
Never gonna say goodbye
Never gonna tell a lie and hurt you
Never gonna stop'''.split('\n')

n = int(input())
good = True

for _ in range(n):
    if not input() in db:
        good = False
        break

if good:
    print("No")
else:
    print("Yes")
