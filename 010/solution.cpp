#include<iostream>
using std::cout;
using std::endl;
#include<vector>
using std::vector;

//C libs
#include<stdlib.h>
//using strtoll

unsigned long long GOAL = 2000000;

vector<unsigned long long> primes;

int main(int argc, char** argv)
{
  if(argc==2)
  {
    GOAL = strtoll(argv[1], NULL, 10);
  }
  primes.push_back(2);
  unsigned long long value = 3;
  
  while(value < GOAL)
  {
    //a simple primality test: iterate over the known primes, check for 
    //divisibility. This only works if all primes less than the number are 
    //known. Since we're building that list this way, that's not a problem.
    bool found_divisor = false;
    for(auto p = primes.begin(); (!found_divisor) && (p != primes.end()); p++)
    {
     unsigned long long prime = (*p);
      if(prime>value/2)
      { //at this point, prime can never divide value.
        //interesting side-note; this saves ~50% time for GOAL=500000
        break;
      }
      if(value % (prime) == 0)
      {
        found_divisor=true;
      }
    }
    if(!found_divisor)
    {
      primes.push_back(value);
    }
    value = value + 2;
  }
  cout << "The sum of all primes under " << GOAL << " is ";
  unsigned long long sum =0;
  for(auto p = primes.begin(); p != primes.end(); p++)
  {
    sum = sum + (*p);
  }
  cout << sum << "." << endl;
}
