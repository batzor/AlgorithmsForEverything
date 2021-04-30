#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int myAtoi(string s) {
      long long ret = 0;
      int i = 0;
      int sign = 1;
      while(s[i] == ' ') i++;

      if(s[i] == '-'){
        sign = -1;
        i++;
      }else if(s[i] == '+'){
        i++;
      }else if(!isdigit(s[i]))
        return 0;

      while(isdigit(s[i])){
        ret = ret * 10 + sign * stoi(s.substr(i, 1));
        i++;
        if(ret > INT_MAX)
          return INT_MAX;
        if(ret < INT_MIN)
          return INT_MIN;
      }

      return (int) ret;
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
