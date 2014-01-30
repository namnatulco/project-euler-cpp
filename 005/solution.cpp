#include<iostream>
using std::cout;
using std::endl;

const unsigned int GOAL = 20;

int main(){
  //brute force all the things
  unsigned long long val = (GOAL%2==0)?GOAL:GOAL+1;
  bool done=false;
  while(!done){
    int i;
    for(i=GOAL;i>0;i--){
      if(val%i !=0 ){
        break;
      }
    }
    if(i==0){//GOAL...1 was all divisible.
      done=true;
    }else{
      val+=2;
    }
  }
  cout << "Smallest positive int divisible by all integers between 1 and " << GOAL << " is: " << val << endl;
  return 0;
}
