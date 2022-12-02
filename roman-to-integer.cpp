#include <string>
#include <cassert>
#include <map>

class Solution{
    public:
    static int romanToInt(const std::string &romanNumber) {
        static const std::map<char,unsigned> romanNumeralToValue = 
        {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };

        unsigned result = 0;
        unsigned previousValue = 9999;

        for(auto character : romanNumber)
        {
            unsigned currentValue = romanNumeralToValue.at(character);
            if( previousValue < currentValue )
            {
                result -= 2*previousValue;
            }
            result += currentValue;
            previousValue=romanNumeralToValue.at(character);
        }
        return result;
    }
};

int main()
{
    assert(Solution::romanToInt("III") == 3);
    assert(Solution::romanToInt("LVIII") == 58);
    assert(Solution::romanToInt("MCMXCIV") == 1994);
    assert(Solution::romanToInt("DCXXI") == 621);
    return 0;
}
