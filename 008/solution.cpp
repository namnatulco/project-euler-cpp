#include<iostream>
using std::cout;
using std::endl;
#include<string>
using std::string;
#include<sstream>
using std::stringstream;

//for atoi, we need the C header.
#include<stdlib.h>

int chartoint(const char& x){
  char tmp[2];
  tmp[0]=x;
  tmp[1]='\0';
  return atoi(tmp);
}

const string number = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";

//looking for the largest product produced by a sequence of length:
const int sequence_length = 5;

unsigned long long max_product;

int main()
{
  if (sequence_length > number.size())
  {
    cout << "Invalid sequence length " << sequence_length << " for the number " << number << endl;
    return 1;
  }
  
  //this is the number _after_ the current sequence:
  //for a length of 5, this will be the 6th element (number[5]).
  auto next_number = number.begin();
  next_number += (sequence_length); 
  
  //initialize the product with [0..length].
  unsigned long long product=1;
  for(auto x = number.begin(); x != next_number; x++)
  {
    int v = chartoint(*x);
    product = product * (v );
  }
  max_product = product;
  cout << "First product: " << max_product << endl;
  
  while(next_number != number.end())
  {
    int value = chartoint(*(next_number-sequence_length));
    if(( value != 0))
    {
      product = product / (value);
      int vnext = chartoint(*next_number);
      product = product * vnext;
    } else
    {
      //the first number in the previous sequence was a 0. From here, it is no
      //longer part of the sequence, but the product is still 0. We need to re-
      //compute the sequence.
      product = 1;
      //use copy constructor to get a new iterator
      auto x(next_number - (sequence_length-1));
      for(; x != (next_number+1); x++)
      {
        int v = chartoint(*x);
        product = product * (v );
      }
    }
    if(product > max_product){
      max_product = product;
    }
    next_number++;
  }
  cout << "Biggest product of a sequence of " << sequence_length << " digits in the number " << number << " is " << max_product  << "." << endl;

}
