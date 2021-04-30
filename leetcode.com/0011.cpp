#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxArea(vector<int>& height) {
      int left = 0;
      int right = height.size() - 1;
      int ans = min(height[left], height[right]) * (right - left);
      while(left != right){
        if(height[left] < height[right]){
          left++;
        }else{
          right--;
        }
        ans = max(ans, min(height[left], height[right]) * (right - left));
      }
      return ans;
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
