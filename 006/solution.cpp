#include<iostream>
using std::cout;
using std::endl;

const int GOAL = 100;

int main()
{
  unsigned long long difference = 0;
  for(int i=1;i<=GOAL;i++)
  {
    for(int j=1;j<=GOAL;j++)
    {
      if(i != j)
      {
        difference = difference + i*j;
      }
    }
  }
  unsigned long long sum= 0;
  
  for(int i=1;i<=GOAL;i++)
  {
    sum = sum + i;
  }

  cout << "The sum of all squares is " << (sum*sum - difference) << ", and the square of the sum is " << sum*sum << " which gives a difference of " << difference << "." << endl;
}
