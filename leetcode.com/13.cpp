#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int romanToInt(string s) {
      int ret = 0;
      size_t pos;
      pos = s.find("CM");
      if(pos != std::string::npos){
        ret += 900;
        s.replace(pos, 2, "");
      }
      pos = s.find("CD");
      if(pos != std::string::npos){
        ret += 400;
        s.replace(pos, 2, "");
      }
      pos = s.find("XC");
      if(pos != std::string::npos){
        ret += 90;
        s.replace(pos, 2, "");
      }
      pos = s.find("XL");
      if(pos != std::string::npos){
        ret += 40;
        s.replace(pos, 2, "");
      }
      pos = s.find("IX");
      if(pos != std::string::npos){
        ret += 9;
        s.replace(pos, 2, "");
      }
      pos = s.find("IV");
      if(pos != std::string::npos){
        ret += 4;
        s.replace(pos, 2, "");
      }
      for(int i = 0;i < s.length();i++){
        switch(s[i]){
          case 'M':
            ret += 1000;
            break;
          case 'D':
            ret += 500;
            break;
          case 'C':
            ret += 100;
            break;
          case 'L':
            ret += 50;
            break;
          case 'X':
            ret += 10;
            break;
          case 'V':
            ret += 5;
            break;
          case 'I':
            ret += 1;
            break;
        }
      }
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
