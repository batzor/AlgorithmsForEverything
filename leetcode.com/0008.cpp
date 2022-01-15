#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int myAtoi(string s) {
      int iter = 0;
      bool negative = false;
      while(s[iter] == ' ')
        ++iter;
      if(s[iter] == '-'){
        ++iter;
        negative = true;
      }else if(s[iter] == '+')
        ++iter;

      long long ans = 0;
      bool done = false;
      while(!done && iter < s.length()){
        if(ans > ((long long)INT_MAX) + 1)
          break;
        switch(s[iter]){
          case '0':
            ans *= 10;
            ans += 0;
            break;
          case '1':
            ans *= 10;
            ans += 1;
            break;
          case '2':
            ans *= 10;
            ans += 2;
            break;
          case '3':
            ans *= 10;
            ans += 3;
            break;
          case '4':
            ans *= 10;
            ans += 4;
            break;
          case '5':
            ans *= 10;
            ans += 5;
            break;
          case '6':
            ans *= 10;
            ans += 6;
            break;
          case '7':
            ans *= 10;
            ans += 7;
            break;
          case '8':
            ans *= 10;
            ans += 8;
            break;
          case '9':
            ans *= 10;
            ans += 9;
            break;
          default:
            done = true;
            break;
        }
        ++iter;
      }
      ans = negative ? -ans : ans;
      if(ans > INT_MAX)
        return INT_MAX;
      if(ans < INT_MIN)
        return INT_MIN;
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
