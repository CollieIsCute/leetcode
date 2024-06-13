class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        std::sort(seats.begin(), seats.end());
        std::sort(students.begin(), students.end());
        auto ret = std::inner_product(
            seats.begin(), seats.end(), students.begin(), 0, std::plus<>(),
            +[](int a, int b) { return abs(a - b); });
        return ret;
    }
};
