x=10
sum=0
for i in range(1,x+1):
  for j in range(1,x+1):
    if (i != j):
      sum += i*j

sq=0
for k in range(1,x+1):
  sq+=k

print "sum of squares is",(sq*sq-sum)
print "diff is",sum
