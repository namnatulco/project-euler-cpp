#include<iostream>
using std::cout;
using std::endl;
#include<vector>
using std::vector;

const int GOAL = 6;

vector<unsigned long long> primes;

int main()
{
  primes.push_back(2);
  unsigned long long value = 3;
  
  while(primes.size() < 10001)
  {
    //a simple primality test: iterate over the known primes, check for 
    //divisibility. This only works if all primes less than the number are 
    //known. Since we're building that list this way, that's not a problem.
    bool found_divisor = false;
    for(auto p = primes.begin(); (!found_divisor) && (p != primes.end()); p++)
    {
      if(value % (*p) == 0){
        found_divisor=true;
      }
    }
    if(!found_divisor)
      primes.push_back(value);
    value = value + 2;
  }
  cout << "A list of 10001 primes follows." << endl;
  for(auto p = primes.begin(); p != primes.end(); p++)
  {
    cout << (*p) << " ";
  }
  cout << endl;
}
