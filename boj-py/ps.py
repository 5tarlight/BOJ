class Op:
    def __init__(self, a, b, op):
        self.a = a
        self.b = b
        self.op = op

    def toString(self):
        return self.a + self.b + self.op


s = input()
