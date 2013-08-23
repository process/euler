#!/usr/bin/env python
# Get primes using sieve of Eratosthenes
def get_primes_less_than(n):
  nums = range(n)
  primes = [2]
  for n in nums[3:]:
    primes.append(n)
    for p in primes[:-1]:
      if n % p == 0:
        primes.pop()
        break
  return primes

def are_permutations(a, b, c):
  a = [ch for ch in str(a)]
  b = [ch for ch in str(b)]
  c = [ch for ch in str(c)]

  a.sort()
  b.sort()
  c.sort()

  return a == b == c

# Main Code #

primes = get_primes_less_than(10000)
for p in primes:
  if p < 1000:
    continue
  for inc in range(1, (10000-p)/2):
    if p + inc in primes and \
       p + (2 * inc) in primes and \
       are_permutations(p, p + inc, p + (2 * inc)):
         print str(p) + str(p + inc) + str(p + (2 * inc))


