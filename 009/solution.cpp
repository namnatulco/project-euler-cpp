#include<iostream>
using std::cout;
using std::endl;

#include<stdlib.h>
//using atoi;

unsigned int GOAL = 1000;

int main(int argc, char** argv)
{
  if(argc == 2)
  {
    GOAL=atoi(argv[1]);
  }
  if(GOAL < 3)
  {
    cout << "Error, given target is too small." << endl;
    return 1;
  }
  //this method is taken from:
  //https://en.wikipedia.org/w/index.php?title=Pythagorean_triple&oldid=593417885#Generating_a_triple
  //the Pythagorean numbers
  unsigned long long a, b, c;
  //parameters of Euclid's formula
  unsigned long long m=2, n=1; 
  //requirement; a+b+c=GOAL = m^2-n^2+2mn+m^2+n^2 = 2(m^2+mn)=2m(m+n)
  //2m(m+n); 0<n<m; bound for m: n->0 ==> GOAL=2m(m+n) -> GOAL=2m^2.
  while(2*m*m < GOAL)
  {
    //here we just check for the 2m(m+n) formula.
    while(2*m*(m+n) < GOAL)
    {
      //we're not there yet, increment n
      n++;
     //Euclid's formula assumes m>n.
      if(m==n)
      {
        break;
      }
    }
    //now, 2*m*(m+n) >= GOAL. Check if we got a hit.
    if(n<m && 2*m*(m+n) == GOAL)
    { //we're done.
      cout << m << " " << n << endl;
      break;
    }else
    { //this m did not work, maybe the next one will.
      m++;
      n=1;
    }
  }
  
  a = m*m-n*n;
  b = 2*m*n;
  c = m*m+n*n;
  if(a+b+c == GOAL)
  {
  cout << "A Pythagorean triplet with sum " << GOAL << " is " << a << " " << b << " " << c << ". The product of these numbers is: " << a*b*c << "." << endl;
  }else
  {
  cout << "Could not find a Pythagorean triplet with the sum of " << GOAL << "." << endl;
  }
}
