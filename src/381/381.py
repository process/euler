"""
(p-1)! = -1 mod p, due to Wilson's theorem
(p-2)! = 1 mod p, since we can divide (p-1) out of -1 mod p
These cancel out, leaving S(p) = (p-3)! + (p-4)! + (p-5)! mod p

The rest can be computed using modular arithmetic

Given (p-2)! mod p = 1
(p-2)! = (p-2) * (p-3)! mod p
1 = (p-2) * (p-3)! mod p
(p-3)! = 1 / (p-2) mod p

Use the extended Euclidean algorithm to find the multiplicative inverse of (p-2),
and you've got the answer.

For later iterations, note that

ax = b mod p
a = b / x mod p
a = b * (1 / x) mod p

We can use the Euclidean algorithm to solve for 1 / x mod p as needed.
"""

import math

PRIME_LIMIT = 10**8
primes = range(PRIME_LIMIT)
primes[0], primes[1] = 0, 0
for i in range(int(math.sqrt(PRIME_LIMIT))):
  if primes[i]:
    for j in range(i*2, PRIME_LIMIT, i):
      primes[j] = 0

print "Primes generated"

def is_prime(n):
  return primes[n]

def xgcd(b, n):
  x0, x1, y0, y1 = 1, 0, 0, 1
  while n != 0:
    q, b, n = b // n, n, b % n
    x0, x1 = x1, x0 - q * x1
    y0, y1 = y1, y0 - q * y1
  return b, x0, y0

def S(p):
  r = 0
  n = 1
  for i in range(p-2, p-4-1, -1):
      n = xgcd(i, p)[1] * n
      r += n
  return r % p

result = 0
for n in range(5, 10**8):
  if n % 10**6 == 0:
    print "Progress: ", n, "/", 10**8
  if is_prime(n):
    result += S(n)

print "ANSWER:", result
