class Solution {
public:
    int mySqrt(const long long x) {
        long long sqrt = x >> 1;
        while (sqrt * sqrt > x) {
            sqrt = sqrt >> 1;
        }
        if (sqrt * sqrt == x)
            return sqrt;
        while ((sqrt + 1) * (sqrt + 1) <= x) {
            ++sqrt;
        }
        return sqrt;
    }
};
