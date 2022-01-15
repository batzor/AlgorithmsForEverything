#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string addBinary(string a, string b) {
      int ia = a.length() - 1;
      int ib = b.length() - 1;
      bool carry = false;
      string ret;
      while(ia >= 0 && ib >= 0){
        pair<char, bool> tmp = addBit(a[ia], b[ib], carry);
        ret = ret + tmp.first;
        carry = tmp.second;
        --ia;
        --ib;
      }
      while(ia >= 0){
        pair<char, bool> tmp = addBit(a[ia], '0', carry);
        ret = ret + tmp.first;
        carry = tmp.second;
        --ia;
      }
      while(ib >= 0){
        pair<char, bool> tmp = addBit(b[ib], '0', carry);
        ret = ret + tmp.first;
        carry = tmp.second;
        --ib;
      }
      if(carry)
        ret += '1';
      reverse(ret.begin(), ret.end());
      return ret;
    }

    pair<char, bool> addBit(char a, char b, bool carry){
      if(a == '1'){
        if(b == '0')
          if(carry)
            return {'0', true};
          else
            return {'1', false};
        else
          if(carry)
            return {'1', true};
          else
            return {'0', true};
      }else
        if(b == '0')
          if(carry)
            return {'1', false};
          else
            return {'0', false};
        else
          if(carry)
            return {'0', true};
          else
            return {'1', false};
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
