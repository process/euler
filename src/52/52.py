#!/usr/bin/env python

def are_permutations(nums):
  num_chars = [tuple(sorted([d for d in str(n)])) for n in nums]
  num_set = set(num_chars)
  return len(num_set) == 1

# Main Code #

n = 1
while True:
  if are_permutations([n, 2*n, 3*n, 4*n, 5*n, 6*n]):
    print n
    break
  n += 1
