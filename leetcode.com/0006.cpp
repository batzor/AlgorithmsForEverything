#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string convert(string s, int numRows) {
      string a = s;
      int ptr = 0;
      int step1, step2;
      if(numRows >= s.length())
        numRows = s.length();
      for(int n = 0; n < numRows; n++){
        a[ptr] = s[n];
        ptr++;
        for(int i = n;;){
          step1 = (numRows - n - 1) * 2;
          step2 = n * 2;
          if(step1 != 0){
            i += step1;
            if(i >= s.length())
              break;
            a[ptr] = s[i];
            ptr++;
          }

          if(step2 != 0){
            i += step2;
            if(i >= s.length())
              break;
            a[ptr] = s[i];
            ptr++;
          }

          if(step1 == 0 && step2 == 0)
            return a;
        }

      }
      return a;
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
