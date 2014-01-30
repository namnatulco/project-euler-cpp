#Example brute-force solution in python

l=[]
m=0;
for i in range(9999,999,-1):
  for j in range(9999,999,-1):
    if i*j>m and str(i*j)==str(i*j)[::-1] :
      m=i*j
      l=[i,j]
print m, l
