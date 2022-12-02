#include <string>
#include <cassert>
#include <iostream>
#include <map>

std::map<char,unsigned> romanNumeralToValue = 
{
    {'I',1},
    {'V',5},
    {'X',10},
    {'L',50},
    {'C',100},
    {'D',500},
    {'M',1000}
};

int romanToInt(const std::string &romanNumber) {
    unsigned result = 0;
    unsigned previousValue = 9999;
    for(auto character : romanNumber)
    {
        unsigned currentValue = romanNumeralToValue[character];
        if( previousValue < currentValue )
        {
            result -= 2*previousValue;
        }
        result += currentValue;
        previousValue=romanNumeralToValue[character];
    }
    std::cout << result << std::endl;
    return result;
}

int main()
{
    assert(romanToInt("III") == 3);
    assert(romanToInt("LVIII") == 58);
    assert(romanToInt("MCMXCIV") == 1994);
    assert(romanToInt("DCXXI") == 621);
    return 0;
}
