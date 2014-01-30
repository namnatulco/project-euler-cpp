#Example brute-force solution in python

l={}
for i in range(999,99,-1):
  for j in range(999,99,-1):
    if str(i*j)==str(i*j)[::-1]:
      l[i*j]=[i,j]
l[max(l.keys())]

