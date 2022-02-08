class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int diff[1001] = {0};
        int last = 0;
        for(auto trip: trips){
            diff[trip[1]] += trip[0];
            diff[trip[2]] -= trip[0];
            last = max(last, trip[2]);
        }
        int curr = 0;
        for(int i = 0; i <= last;++i){
            curr += diff[i];
            if(curr > capacity)
                return false;
        }
        
        return true;
    }
};