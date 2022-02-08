class Solution {
public:
    char findTheDifference(string s, string t) {
        int cnt[26] = {0};
        int i = 0;
        for(;i < s.length();i++){
            ++cnt[s[i] - 97];
            --cnt[t[i] - 97];
        }
        --cnt[t[i] - 97];
        for(i = 0;i < 26;++i)
            if(cnt[i])
                return (char) i + 97;
        return '\n';
    }
};