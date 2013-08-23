#!/usr/bin/env python

def is_pandigital(n):
  if len(str(n)) != 9:
    return False
  for d in range(1, 10):
    if str(d) not in str(n):
      return False
  return True

def concatenated_product(n):
  product_str = ""
  mult = 1
  while len(product_str) < 9:
    product_str += str(n * mult)
    mult += 1
  return int(product_str)

# Main Code #

max_pandigital = 0

# We can assume that the number will start with a 9
nums = [9] + range(90, 100) + range(900, 1000) + range(9000, 10000)

for n in nums:
  c_p = concatenated_product(n)
  if c_p > max_pandigital and is_pandigital(c_p):
    max_pandigital = c_p

print max_pandigital
