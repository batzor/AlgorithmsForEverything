#include <bits/stdc++.h>
using namespace std;

unordered_map<char, string> m =
{
  {'2', "abc"},
  {'3', "def"},
  {'4', "ghi"},
  {'5', "jkl"},
  {'6', "mno"},
  {'7', "pqrs"},
  {'8', "tuv"},
  {'9', "wxyz"}
};
class Solution {
  public:
    vector<string> letterCombinations(string digits) {
      if(digits.size() == 0)
        return vector<string>();
      deque<string> v;
      for(int i = 0;i < m[digits[0]].length();++i){
        v.push_back(string(1,m[digits[0]][i]));
      }
      for(int i = 1;i < digits.length();++i){
        string front = v.front();
        while(front.length() == i){
          v.pop_front();
          for(int j = 0; j < m[digits[i]].length();++j){
            v.push_back(front + string(1, m[digits[i]][j]));
          }
          front = v.front();
        }
      }
      return {v.begin(), v.end()};
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
