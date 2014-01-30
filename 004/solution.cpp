#include<iostream>
using std::cout;
using std::endl;
#include<string>
using std::string;
#include<sstream>
using std::ostringstream;


unsigned int maximum_value=0;
unsigned int maximum_array[2]={0,0};

//checks whether x is a palindrome by string conversion.
bool is_palindrome(unsigned int x){
  ostringstream ss;
  ss << x;
  string converted = ss.str();
  //the above should be roughly the same as char* res = malloc(...); sprintf(res, "%d", x);
  //the below should be roughly the same as for(int i=0;run && i<strlen(res);i++) run = (res[i] == res[strlen(res)-i-1];
  string::iterator it=converted.begin();
  string::reverse_iterator rit=converted.rbegin();
  while(*it == *rit && it != converted.end()){
    it++;
    rit++;
  }
  //did we reach the end?
  return it==converted.end();
}

int main(){
  //brute force all the things
  for(unsigned int i=999;i>99;i--){
    for(unsigned int j=999;j>99;j--){
      if(i*j>maximum_value && is_palindrome(i*j)){
        maximum_value = i*j;
        maximum_array[0]=i;
        maximum_array[1]=j;
      }
    }
  }
  
  cout << "Biggest palindrome that is a product of 2 3-digit numbers is "<< maximum_value <<"=" << maximum_array[0] << "*" << maximum_array[1] <<"." << endl;
  return 0;
}
