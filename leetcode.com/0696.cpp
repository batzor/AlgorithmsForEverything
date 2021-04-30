#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int countBinarySubstrings(string s) {
            if(s.length() == 0)
                return 0;
            char initchar = s[0];
            int count = 1;
            int count1 = 0;
            int index = 1;
            int ans = 0;
            while(s[index] == initchar){
                count += 1;
                index += 1;
            }
            while(index < s.length()){
                while(s[index] != initchar && index < s.length()){
                    count1 += 1;
                    index += 1;
                }
                ans += min(count, count1);
                count = count1;
                count1 = 0;
                initchar = s[index - 1];
            }
            return ans;
        }
};

void solve() {
    Solution s;
    cout << s.countBinarySubstrings("00110011") << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
