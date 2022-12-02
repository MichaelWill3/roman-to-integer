#include <string>
#include <cassert>

int romanToInt(const std::string &s) {
    unsigned result = 0;

    for(auto c : s)
    {
        switch(c)
        {
            case 'I': result+=1; break;
            default: break;
        }
    }
    return result;
}

int main()
{
    assert(romanToInt("III") == 3);
    assert(romanToInt("LVIII") == 58);
    assert(romanToInt("MCMXCIV") == 1994);
    return 0;
}
