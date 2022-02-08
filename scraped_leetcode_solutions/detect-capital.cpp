class Solution {
public:
    bool is_cap(char c){
        return c > 64 && c < 91;
    }
    bool detectCapitalUse(string word) {
        bool first_cap = is_cap(word[0]);
        int cap_cnt = first_cap;
        for(int i = 1;i < word.length();++i){
            if(is_cap(word[i]))
                ++cap_cnt;
        }
        if(first_cap)
            return cap_cnt == 1 || cap_cnt == word.length();
        else
            return cap_cnt == 0;
    }
};