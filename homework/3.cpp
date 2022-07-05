#include <iostream>
#include <algorithm>

bool checkSimpleNumber(size_t number)
{   
    if(number == 1)
        return false;

    if (number == 2 || number == 3)
        return true;

    if ((number * number) % 24 == 1)
        return true;

    return false;
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

size_t findSimpleNOD(size_t a, size_t b)
{
    size_t min = std::min(a, b);
    size_t max = std::max(a, b);

    size_t max_NOD = 1;

    for (size_t i = max; i > 0; i--)
    {
        if(checkSimpleNumber(i))
        {
            if(max_NOD < NOD(i * min, max))
                max_NOD = NOD(i * min, max);
        }
    }

    return max_NOD;
}

int main()
{
    size_t count;
    std::cin>>count;
    size_t *mas = nullptr;

    try
    {
        mas = new size_t[count];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    for (size_t i = 0; i < count; i++)
    {
        size_t a, b;

        std::cin>>a>>b;

        mas[i] = findSimpleNOD(a, b);
    }

    for (size_t i = 0; i < count; i++)
        std::cout << mas[i] << std::endl;

    delete[] mas;
    return 0;
}