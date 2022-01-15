#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool is_pal(string s){
      for(int i = 0; i < s.length() / 2;++i){
        if(s[i] != s[s.length() - 1 - i])
          return false;
      }
      return true;
    }
    vector<vector<string>> partition(string s) {
      int c = s[0];
      vector<vector<string>> v;
      if(s.length() == 1){
        vector<string> v1;
        v1.push_back(s);
        v.push_back(v1);
        return v;
      }
      for(int i = 0;i < s.length();++i){
        string s1 = s.substr(0, i + 1);
        if(is_pal(s1)){
          string s2 = s.substr(i + 1, s.length());
          if(s2.length() == 0){
            vector<string> v1;
            v1.push_back(s1);
            v.push_back(v1);
          }else{
            auto tmp = partition(s2);
            for(int j = 0; j < tmp.size();j++)
              tmp[j].insert(tmp[j].begin(), s1);
            v.insert(v.end(),tmp.begin(),tmp.end());
          }
        }
      }
      return v;
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
