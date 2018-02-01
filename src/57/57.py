import math

num, den = 3, 2

iteration = 1
count = 0

while iteration <= 1000:
  iteration += 1
  if math.floor(math.log10(num)) > math.floor(math.log10(den)):
    count += 1

  num, den = 2*den + num, den + num

print "ANSWER: ", count
