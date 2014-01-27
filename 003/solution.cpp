#include<iostream>
using std::cout;
using std::endl;
#include<vector>
using std::vector;

//shortcut. Could be replaced by a big integer implementation.
typedef unsigned long long ull; 

const ull TARGET = 600851475143;

vector<ull> primes;

//this approach is very slow. There are many better ways, but for this question, it is
//more than sufficient to "simply" brute-force the prime factors. In real scenarios, we
//typically deal with primes that are very large, which means it will take a long time
//to even find the first one.
ull find_factor(ull number){
  if(number %2 ==0){
    primes.push_back(2);
    return (number/2);
  }else{
    ull i;
    if(primes.empty()){
      i = 3;
    } else {
      i = primes.back();
    }
    //rounded down due to integer division
    //we can increment by 2, since we're already sure that number is not even.
    for(;i<(number/2);i=i+2){
      if(number%i==0){
        //we found a new prime factor!
        primes.push_back(i);
        return (number/i);
      }
    }
  }
  //we can't go any further.
  return number;
}

int main(){
  ull intermediate=TARGET;
  // this condition is only useful when we happen to operate on powers of two.
  while(intermediate>1){
    ull result = find_factor(intermediate);
    if(result*2 > intermediate){
      primes.push_back(result);
      break; //this extra check saves us testing primes[primes.size()-2]..result again.
    }
    intermediate = result;
  }
  cout << "Factorization of the number " << TARGET << " resulted in the primes {";
  for(auto prime : primes){
    cout << prime << ", ";
  }
  cout << "}. Therefore, the biggest prime factor of " << TARGET << " is " << primes.back() << endl;
  return 0;
}
