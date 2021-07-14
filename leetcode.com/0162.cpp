#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int findPeakElement(vector<int> &nums){
            vector<pair<int, int>> v;
            for(int i = 0;i < nums.size();i++){
                v.push_back({nums[i], i});
            }
            sort(v.begin(), v.end());
            return(v.back().second);
        }
};

void solve() {
    Solution s;
    vector<int> test = {1, 2, 3, 1};
    vector<int> test2 = {1, 2, 1, 3, 5, 6, 4};
    cout << s.findPeakElement(test) << endl;
    cout << s.findPeakElement(test2) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
