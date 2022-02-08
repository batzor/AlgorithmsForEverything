class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ret = 0;
        for(auto v : accounts){
            ret = max(accumulate(v.begin(), v.end(),
                                decltype(v)::value_type(0)), ret);
        }
        return ret;
    }
};