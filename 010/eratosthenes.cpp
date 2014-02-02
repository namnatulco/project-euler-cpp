#include<iostream>
using std::cout;
using std::endl;
#include<vector>
using std::vector;
#include<bitset>
using std::bitset;

const unsigned long long GOAL = 2000000;
bitset<GOAL+1> is_composite;
//the bitset represents a number with each bit.
//to check whether x is prime, after the sieve is done, we use is_prime[x].
//more (memory) efficiency could be achieved by only storing uneven numbers.
//the docs say bitset is constructed with all zeros.

int main(int argc, char** argv)
{
  //these technically aren't composite, but I cross them out since they're not prime..
  is_composite.set(0);
  is_composite.set(1);
  
  cout << "The sum of all primes under " << GOAL << " is ";
  unsigned long long sum =0;
  for(unsigned long long i=2; i <= GOAL; i++)
  {
    //grab the next item that isn't crossed out
    while(is_composite[i])
      i++;
    //i is a prime.
    sum = sum + i;
    //cross out all multiples of i
    unsigned long long j=0;
    while(j*i <= GOAL)
    {
      is_composite.set(j*i);
      j++;
    }
  }
  cout << sum << "." << endl;
}
