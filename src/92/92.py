#!/usr/bin/env python

def chains_to_89(n):
  while True:
    if n == 89:
      return True
    elif n == 1:
      return False
    else:
      n = sum([int(d)**2 for d in str(n)])

# Main Code #

count = 0
for n in xrange(1, 10000001):
  if chains_to_89(n):
    count +=1
print count
