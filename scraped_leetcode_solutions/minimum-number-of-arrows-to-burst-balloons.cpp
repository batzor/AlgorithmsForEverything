class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int min_end = INT_MAX;
        int arr_cnt = 0;
        for(auto p: points){
            if(p[0] > min_end){
                ++arr_cnt;
                min_end = p[1];
            }else{
                min_end = min(min_end, p[1]);
            }
        }
        ++arr_cnt;
        return arr_cnt;
    }
};