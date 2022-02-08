class Solution {
public:
    bool check(int (&a)[26]){
        for(int i = 0;i < 26;++i){
            if(a[i])
                return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        if(p.length() > s.length())
            return ret;
        
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        
        for(int i = 0;i < p.length();++i){
            ++cnt[p[i] - 97];
            --cnt[s[i] - 97];
        }
        if(check(cnt))
            ret.push_back(0);
        for(int i = p.length();i < s.length();++i){
            ++cnt[s[i - p.length()] - 97];
            --cnt[s[i] - 97];
            if(check(cnt))
                ret.push_back(i - p.length() + 1);
        }
        return ret;
    }
};