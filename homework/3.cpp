#include <iostream>

bool checkSimpleNumber(size_t number)
{   
    if(number == 1)
        return false;

    for(int i = 2; i <= number/2; i++) 
        if((number % i) == 0)
            return false;

    return true;
}

size_t NOD(size_t a, size_t b)
{
    while(a > 0 && b > 0)
    {
        if(a > b)
            a %= b;
        else
            b %= a;
    }
 
    return a + b;
}