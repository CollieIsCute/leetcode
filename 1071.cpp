#include <numeric>
#include <string>
using namespace std;

class Solution {
public:
    bool is_divisible(const string& dividend, const string& divisor){
        const int n = dividend.size(), m = divisor.size();
        if(n%m)
            return false;
        for(int i = 0; i < n; i++)
            if(dividend[i] != divisor[i%m])
                return false;
        return true;
    }

    string gcdOfStrings(string str1, string str2) {
        int gcd_size = gcd(str1.size(), str2.size());
        string gcd_str = str1.substr(0, gcd_size);
        if (is_divisible(str1, gcd_str) && is_divisible(str2, gcd_str))
            return gcd_str;
        return "";
    }
};
