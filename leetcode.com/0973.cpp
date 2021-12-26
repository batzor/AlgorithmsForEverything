#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    static bool dist_cmp(vector<int> pt1, vector<int> pt2){
      return pt1[0] * pt1[0] + pt1[1] * pt1[1]
        < pt2[0] * pt2[0] + pt2[1] * pt2[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
      sort(points.begin(), points.end(), dist_cmp);
      vector<vector<int>> ret(&points[0], &points[0] + k);
      return ret;
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
