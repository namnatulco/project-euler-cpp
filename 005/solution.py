done=False
x=20#smallest positive that evenly divides 1..19.
while not done:
  for i in range(20,0,-1):
    if not x%i == 0:
      break
  if i == 1:
    done=True;
  else:
    x+=2 #there's probably a better way than this...
print x
