class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4) 
            return vector<vector<int>>();
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        for(int i = 0; i < nums.size() - 3;++i){
            for(int j = i + 1;j < nums.size() - 2;j++){
                int left = j + 1;
                int right = nums.size() - 1;
                while(left < right){
                    long long sum = ((long long) nums[i]) + nums[j] + nums[left] + nums[right];
                    if(sum == target){
                        ans.insert({nums[i], nums[j], nums[left], nums[right]});
                        ++left;
                    }else if(sum < target)
                        ++left;
                    else
                        --right;
                }
            }
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};