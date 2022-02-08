class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0;
        unordered_map<int, int> first_enc;
        first_enc[0] = 0;
        int ans = 0;
        for(int i = 0; i < nums.size();++i){
            if(nums[i])
                ++sum;
            else
                --sum;
            if(first_enc.find(sum) == first_enc.end()){
                first_enc[sum] = i + 1;
            }else{
                ans = max(ans, i - first_enc[sum] + 1);
            }
        }
        return ans;
    }
};