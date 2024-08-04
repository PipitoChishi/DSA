#include <iostream>
using namespace std;

int main()
{
    int number, power, result=1;
    int increased_value, i;

    cout<<"enter number and power "<<endl;
    cin>>number>>power;

    if (power % 2 == 0) 
    {
        increased_value = number * number;
        for (i = 0; i < (power / 2) ; i++)
        {
            result = result * increased_value;
        }
    }

    else if(power % 2!=0)
    {
        increased_value=number*number;
        for(i=0;i<power/2;i++)
        {
           result=result*increased_value;
        }
        result=result*number;
    }

    cout<<"Result is "<<result<<endl;
}