import math

pairs = open("res/p099_base_exp.txt").readlines()
pairs = [[int(e) for e in pair.strip().split(',')] for pair in pairs]

max_val = 0
max_line = None

for index, pair in enumerate(pairs):
  base, exp = pair
  log_val = exp * math.log(base)
  if log_val > max_val:
    max_val = log_val
    max_line = index

print "ANSWER: ", max_line+1
