#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i = 1; i < triangle.size(); i++){
            triangle[i][0] += triangle[i - 1][0];
            triangle[i].back() += triangle[i - 1].back();
            for(int j = 1; j < triangle[i].size() - 1; j++){
                triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
            }  
        }
        int ans = INT_MAX;
        for(int num: triangle.back()){
            if(ans > num)
                ans = num;
        }
        return ans;
    }
};

void solve() {
    Solution s;
    vector<int> row1{2};
    vector<int> row2{3,4};
    vector<int> row3{6, 5, 7};
    vector<int> row4{4, 1, 8, 3};
    vector<vector<int>> triangle{row1,row2,row3,row4};
    cout << s.minimumTotal(triangle) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
