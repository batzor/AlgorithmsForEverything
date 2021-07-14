#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums){
            sort(nums.begin(), nums.end());

            vector<vector<int>> ret;
            for(int i = 0; i < ((int) nums.size()) - 2;i++){
                for(int j = i + 1; j < ((int) nums.size()) - 1;j++){
                    int target = 0 - nums[i] - nums[j];
                    if(nums.begin() + j + 1 == nums.end())
                    auto it = lower_bound(nums.begin() + j + 1, nums.end(), target);
                    if(it != nums.end() && (*it) == target)
                        ret.push_back(vector<int>{nums[i], nums[j], target});
                    while(j < nums.size() - 1 && nums[j] == nums[j + 1])
                        j++;
                }
                while(i < nums.size() - 1 && nums[i] == nums[i + 1])
                    i++;
            }
            
            return ret;
        }
};

void solve() {
    Solution s;
    vector<int> test{1, 2, -2, -1};
    auto ret = s.threeSum(test);
    for(auto r: ret){
        cout << r[0] << " " << r[1] << " " << r[2] << endl;
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
