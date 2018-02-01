import operator as op
from decimal import *
getcontext().prec = 12

BITS = 32

class Memoize:
    def __init__(self, f):
        self.f = f
        self.memo = {}
    def __call__(self, *args):
        if not args in self.memo:
            self.memo[args] = self.f(*args)
        return self.memo[args]

@Memoize
def ncr(n, r):
    r = min(r, n-r)
    if r == 0: return 1
    numer = reduce(op.mul, xrange(n, n-r, -1))
    denom = reduce(op.mul, xrange(1, r+1))
    return numer//denom

@Memoize
def get_numerator(bits, iteration):
    if iteration == 1 or bits == 1:
        return 1
    total = 0
    for n in range(bits):
        total += ncr(bits, n) * get_numerator(bits-n, iteration-1) * (2**(n*(iteration-1)))
    return total

running_total = Decimal()
for n in range(1, 100):
    numerator = get_numerator(BITS, n)
    denominator = ((2**BITS)**n)
    new_value = Decimal(n) * (Decimal(numerator) / Decimal(denominator))
    running_total += new_value
    if new_value < 10**-11:
        print "accurate value on iteration", n
        break

print running_total

#
# # check expected value of n
# n = 0
# bits = 4
# iter = 5000000
# for i in range(iter):
#     x = 0
#     while x != (2**bits)-1:
#         x |= random.randrange(0,2**bits)
#         n += 1
#
# print float(n) / iter
#
# # get prob. of N equaling a target
# iter = 5000000
# count = 0
# bits = 3
# target_n = 5
# for i in range(iter):
#     x, n = 0, 0
#     while x != (2**bits)-1:
#         x |= random.randrange(0,2**bits)
#         n += 1
#     if n == target_n:
#         count += 1
#
# print (float(count) / iter) * ((2**bits)**target_n)
