class Solution {
public:
    inline bool is_letter(char c){
        return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z');
    }
    string reverseOnlyLetters(string s) {
        int l = 0, r = s.length() - 1;
        while(l < r){
            while(l <= r && !is_letter(s[l]))
                ++l;
            while(r >= l && !is_letter(s[r]))
                --r;
            
            if(l >= r)
                break;
            char tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
            ++l;
            --r;
        }
        return s;
    }
};