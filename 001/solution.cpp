#include<iostream>
#include<vector>
using std::vector;

//Check numbers 1..THRESHOLD
const int THRESHOLD = 1000;
//This vector should be sorted incrementally for maximum efficiency
vector<int> bases {3, 5}; 

int main(){
  int sum = 0;
  for(int i=1;i<THRESHOLD;i++){
    for(auto base : bases){
      if(i%base==0){ //does base divide i?
        //then we don't need to search any further and go with the next element.
        sum = sum + i;
        break;
      }
    }
  }
  std::cout << "The sum of positive integers below " << THRESHOLD << " that are multiples of at least one of {";
  for(auto base: bases){
    std::cout << base << ", ";
  }
  std::cout << "} is: " << sum <<  "." << std::endl;
  return 0;
}
