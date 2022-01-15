#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int bitwiseComplement(int n) {
      if(n == 0)
        return 1;
      int mask = 0;
      long long tmp = 1;
      while(tmp <= n){
        mask += tmp;
        tmp *= 2;
      }
      return mask ^ n;
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
