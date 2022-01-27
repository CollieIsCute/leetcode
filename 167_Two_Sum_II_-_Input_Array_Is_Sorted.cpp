class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        const int NUM_SIZE = numbers.size();
        int big = NUM_SIZE-1, small = 0;
        vector<int> ret;
        while(big > small){
            if(numbers[small] + numbers[big] > target)
                big--;
            else if(numbers[small] + numbers[big] < target)
                small++;
            else{
                ret = {small+1, big+1};
                return ret;
            }
        }
        return vector<int>();
    }
};