#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int leastBricks(vector<vector<int>>& wall) {
            map<int, int> count;
            for(auto v: wall){
                if(v.size() == 1)
                    continue;
                int sum = v[0];
                if(count.count(sum))
                    count[sum] += 1;
                else
                    count[sum] = 1;
                for(int i = 1;i < v.size() - 1;i++){
                    sum += v[i];
                    if(count.count(sum))
                        count[sum] += 1;
                    else
                        count[sum] = 1;
                }
            }
            using pair_type = decltype(count)::value_type;
            auto max_val = max_element(
                    begin(count), end(count),
                    [] (const pair_type & p1, const pair_type & p2) {
                    return p1.second < p2.second;
                    }
                    );
            return wall.size() - max_val->second;
        }
};

void solve() {
    vector<int> row1{1,2,2,1};
    vector<int> row2{3,1,2};
    vector<int> row3{1,3,2};
    vector<int> row4{2,4};
    vector<int> row5{3,1,2};
    vector<int> row6{1,3,1,1};
    vector<vector<int>> triangle{row1,row2,row3,row4,row5,row6};
    Solution s;
    cout << s.leastBricks(triangle) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
