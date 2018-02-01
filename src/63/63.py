"""
10 is upper bound because 10^x will always be too big.
"""

count = 0
for n in range(1, 10):
  exp = 1
  while len(str(n**exp)) == exp:
    count += 1
    exp += 1

print "ANSWER: ", count
