class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int max_dist = 0;
        int cur = 0;
        int i = 0;
        while(seats[i] == 0)
            i++;
        max_dist = i;
        
        for(;i < seats.size();++i){
            if(seats[i]){
                max_dist = max(max_dist, (cur + 1) / 2);
                cur = 0;
            }else{
                ++cur;
            }
        }
        max_dist = max(max_dist, cur);
        return max_dist;
    }
};