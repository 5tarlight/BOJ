s = ''.join(map(lambda x: bin(int(x))[2:].zfill(3),input())).lstrip('0')
print(s if s else '0')
