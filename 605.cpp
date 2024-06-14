class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        auto available = 0;
        if (flowerbed.size() < 2) {
            return !flowerbed.front() >= n;
        }
        if (!flowerbed[0] && !flowerbed[1]) {
            flowerbed[0] = 1;
            ++available;
        }
        if (!flowerbed[flowerbed.size() - 1] &&
            !flowerbed[flowerbed.size() - 2]) {
            flowerbed[flowerbed.size() - 1] = 1;
            ++available;
        }
        for (auto i = 1; i < flowerbed.size() - 1; i++) {
            if (!flowerbed[i - 1] && !flowerbed[i] && !flowerbed[i + 1]) {
                flowerbed[i] = 1;
                ++available;
            }
        }
        return available >= n;
    }
};
