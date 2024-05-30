d = {
    "AA" : "A", "AG" : "C", "AC" : "A", "AT" : "G", "GA" : "C","GG" : "G",
    "GC" : "T", "GT" : "A", "CA" : "A", "CG" : "T", "CC" : "C", "CT" : "G",
    "TA" : "G", "TG" : "A", "TC" : "G","TT" : "T"
}

n = int(input())
s = list(input())

while len(s) > 1:
    t = ''.join(s[-2:])

    if t in d:
        del s[-2:]
        s.append(d[t])

print(*s)