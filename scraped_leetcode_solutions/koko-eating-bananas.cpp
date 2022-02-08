class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = INT_MAX;
        
        while(left < right){
            long long int mid = ((long long int)left + right) / 2;
            int val = 0;
            for(auto i: piles){
                val += (i + mid - 1) / mid;
            }
            if(val > h){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return left;
    }
};