#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isPowerOfThree(int n) {
      if(n <= 0)
        return false;
      int max3pow = pow(3, 19);
      if(max3pow % n == 0)
        return true;
      else
        return false;
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
