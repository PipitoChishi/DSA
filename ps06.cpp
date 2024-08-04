#include <iostream>

using namespace std;

int main()
{
  int velocity,count=0;

  cout<<" Pls enter initial fall velocity "<<endl;
  cin>>velocity;

  while(velocity!=0)
  {
    velocity=velocity/2;
    count++;
  }

  cout<<" Total jumps  before velocity turns zero "<<count<<endl;

}