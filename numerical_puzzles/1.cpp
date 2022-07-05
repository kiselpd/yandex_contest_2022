#include <iostream>

const char SPACE = ' ';
const char FIRST_LETTER = 'a';

size_t decodeValue(size_t start_value, size_t encoded_value)
{
    size_t i = 0;

    while ((start_value % 2) == (encoded_value % 2))
    {
        i++;
        start_value = start_value >> 1;
        encoded_value = encoded_value >> 1;
    }

    return i;
}

char getDecodedChar(size_t i)
{   
    if(i == 26)
        return SPACE;

    return FIRST_LETTER + i;
}

int main()
{
    
    size_t count;
    size_t start_value = 0;
    std::string answer;

    std::cin >> count;

    for (size_t i = 0; i < count; i++)
    {
        size_t encoded_value;
        std::cin >> encoded_value;

        answer = answer + getDecodedChar(decodeValue(start_value, encoded_value));
        start_value = encoded_value;
    }

    std::cout << answer;
    
    return 0;
}