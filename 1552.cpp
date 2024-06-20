class Solution {
    bool check_distance(const vector<int>& position, int distance, int m){
        auto prev_p = position.front();
        --m;
        for(auto p: position){
            if(p - prev_p>= distance){
                prev_p = p;
                --m;
            }
        }
        return m <= 0;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        std::sort(position.begin(), position.end());
        auto max_dist = position.back()/(m-1);
        decltype(max_dist) min_dist = 1;
        while(max_dist > min_dist){
            auto current = (max_dist+min_dist)>>1;
            if(check_distance(position, current, m)){
                min_dist = current+1;
            }
            else{
                max_dist = current;
            }
        }
        if(check_distance(position, min_dist, m))return min_dist;
        return min_dist-1;
    }
};
