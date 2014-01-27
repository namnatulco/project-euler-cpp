#include<iostream>
using std::cout;
using std::endl;

//Check numbers 1..THRESHOLD
const unsigned long long THRESHOLD = 4000000; //=4 million

int main(){
  unsigned long long sum = 0;
  unsigned long long left = 1;
  unsigned long long right= 2;
  while(right < THRESHOLD){
    if(right%2==0){ //is the newly generated element even?
      sum = sum + right;
    }
    unsigned long long tmp = left + right;
    left = right;
    right= tmp;
  }
  cout << "The sum of even Fibonacci sequence numbers below " << THRESHOLD << " is " << sum << endl;
  return 0;
}
