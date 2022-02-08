class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<int, int> count;
        for(auto v: wall){
            if(v.size() == 1)
                continue;
            int sum = v[0];
            if(count.count(sum))
                count[sum] += 1;
            else
                count[sum] = 1;
            for(int i = 1;i < v.size() - 1;i++){
                sum += v[i];
                if(count.count(sum))
                    count[sum] += 1;
                else
                    count[sum] = 1;
            }
        }
        using pair_type = decltype(count)::value_type;
        auto max_val = max_element(
            begin(count), end(count),
            [] (const pair_type & p1, const pair_type & p2) {
                return p1.second < p2.second;
            }
        );
        return wall.size() - max_val->second;
    }
};