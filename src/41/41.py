#!/usr/bin/env python
from itertools import permutations
from math import sqrt

# Shitty prime check, but it doesn't matter
def is_prime(n):
  for d in range(2, int(sqrt(float(n)))):
    if n % d == 0:
      return False
  return True

# 8 and 9 digit pandigital numbers are divisble by 9, so there
# is no need to check them.
pandigitals_7d = permutations(range(1,8)) # 7 digit pandigitals
pandigitals_7d = list(pandigitals_7d)
pandigitals_7d.sort()
pandigitals_7d.reverse()
for num in pandigitals_7d:
  num = int(''.join(str(d) for d in num))
  if is_prime(num):
    print num
    break

