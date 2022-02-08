class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> running_sum;
        for(int num: nums){
            if(running_sum.empty())
                running_sum.push_back(num);
            else
                running_sum.push_back(running_sum.back() + num);
        }
        return running_sum;
    }
};