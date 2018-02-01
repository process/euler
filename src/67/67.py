triangle = open("res/p067_triangle.txt").readlines()
triangle = [[int(n) for n in line.strip().split()] for line in triangle]

for n in range(-2,-len(triangle)-1,-1):
  triangle[n] = [max(triangle[n][m] + triangle[n+1][m],
                     triangle[n][m] + triangle[n+1][m+1])
                     for m in range(len(triangle[n]))]

print "ANSWER:", triangle[0][0]
