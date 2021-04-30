#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      unordered_map<char, int> letters;

      int maxlen = 0;
      int start = 0;
      for(int end = 0;end < s.length();end++){
        if(letters.find(s[end]) == letters.end() || letters[s[end]] == -1){
          maxlen = max(maxlen, end - start + 1);
          letters[s[end]] = end;
        }else{
          int new_start = letters[s[end]] + 1;
          while(start < new_start){
            letters[s[start]] = -1;
            start++;
          }
          letters[s[end]] = end;
        }
      }
      return maxlen;
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
