#!/usr/bin/python
from itertools import permutations

def matches_pattern(n):
  return int(n[1:4]) % 2 == 0 and \
         int(n[2:5]) % 3 == 0 and \
         int(n[3:6]) % 5 == 0 and \
         int(n[4:7]) % 7 == 0 and \
         int(n[5:8]) % 11 == 0 and \
         int(n[6:9]) % 13 == 0 and \
         int(n[7:10]) % 17 == 0

count = 0
pandigitals = permutations(xrange(10))
for num in pandigitals:
  num_str = ''.join(str(d) for d in num)
  if matches_pattern(num_str):
    count += int(num_str)
print count

