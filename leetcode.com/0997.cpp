#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n == 1)
            return trust.size() == 0;
        vector<int> deg(n, 0);
        for(auto i: trust){
            --deg[i[0] - 1];
            ++deg[i[1] - 1];
        }
        int idx = find(deg.begin(), deg.end(), n - 1) - deg.begin();
        return idx == n ? -1: idx + 1;
    }
};

void solve() {
  Solution s;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}
