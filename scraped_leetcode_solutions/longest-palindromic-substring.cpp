class Solution {
public:
    string longestPalindrome(string s) {
        int max_len = 1;
        string max_str = s.substr(0, 1);
        for(int i = 1; i < s.length();i++){
            int pal_len = 1;
            for(int j = 1;;j++){
                if(i - j < 0 || i + j >= s.length())
                    break;
                if(s[i - j] != s[i + j])
                    break;
                pal_len += 2;
            }
            if(max_len < pal_len){
                max_str = s.substr(i - pal_len / 2, pal_len);
                max_len = pal_len;
            }
            
            if(s[i - 1] == s[i]){
                pal_len = 2;
                for(int j = 1;;j++){
                    if(i - j - 1 < 0 || i + j >= s.length())
                        break;
                    if(s[i - j - 1] != s[i + j])
                        break;
                    pal_len += 2;
                }   
            }
            
            if(max_len < pal_len){
                max_str = s.substr(i - pal_len / 2, pal_len);
                max_len = pal_len;
            }
        }
        return max_str;
    }
};